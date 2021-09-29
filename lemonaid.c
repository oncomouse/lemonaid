#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define CMDLEN 50
#define LEN(X) sizeof(X)/sizeof(X[0])
#define FORBLOCKINBLOCKS for (unsigned int i = 0; i < LEN(blocks); i ++)

typedef struct {
    char *cmd;
    int interval;
    int signal;
    char *bg_color;
    char *fg_color;
    bool underline;
    bool overline;
    char *underline_color;
} Block;

#include "config.h"

static char statusbar[LEN(blocks)][CMDLEN] = {0};
static void sighandler(int signal);
static void update(unsigned long long int time);
static void run_cmd(unsigned int index, const Block *block, char block_text[]);
static void setup_sighandlers();
static void write_status();

static void bg(char *bg_color, char open_bg[], char close_bg[]);
static void fg(char *fg_color, char open_fg[], char close_fg[]);
static void line(bool underline, bool overline, char *underline_color, char open_line[], char close_line[]);

int main() {
    setup_sighandlers();
    unsigned long int time = 0;
    while (1) {
        update(time);
        time ++;
        sleep(1.0);
    }
}

void setup_sighandlers() {
    FORBLOCKINBLOCKS signal(SIGRTMIN + blocks[i].signal, sighandler);
}

void sighandler(int signal) {
    signal = signal - SIGRTMIN;

    FORBLOCKINBLOCKS {
        if (blocks[i].signal == signal) {
            run_cmd(i, &blocks[i], statusbar[i]);
            write_status();
            break;
        }
    }
}

void run_cmd(unsigned int index, const Block *block, char block_text[]) {
    FILE *cmdf = popen(block -> cmd, "r");
    if (!cmdf) return;

    char buffer[CMDLEN - delim_length];

    // Get output of the command
    fgets(buffer, CMDLEN - delim_length, cmdf);

    // remove newline char
    unsigned int len = strlen(buffer);
    if (buffer[len - 1] == '\n') buffer[len - 1] = '\0';

    char open_bg[15], close_bg[15], open_fg[15], close_fg[15], open_line[25], close_line[25];
    bg(block -> bg_color, open_bg, close_bg);
    fg(block -> fg_color, open_fg, close_fg);
    line(block -> underline, block -> overline, block -> underline_color, open_line, close_line);

    snprintf(
        block_text,
        CMDLEN - delim_length,
        "%s%s%s %s %s%s%s",
        open_bg,
        close_fg,
        open_line,
        buffer,
        close_line,
        close_fg,
        close_bg
    );

    // add the delimeter if block is not the last one
    if (index != LEN(blocks) - 1) strncat(block_text, delim, delim_length);

    pclose(cmdf);
}

void write_status() {
    char buffer[CMDLEN * LEN(blocks)];

    unsigned int i = 0;

    strcpy(buffer, "%{l}");
    for (; i < left; i ++)
        strcat(buffer, statusbar[i]);

    strcat(buffer, "%{c}");
    for (; i < centre + left; i ++)
        strcat(buffer, statusbar[i]);

    strcat(buffer, "%{r}");
    for (; i < right + left + centre; i ++)
        strcat(buffer, statusbar[i]);

    fprintf(stdout, "%s", buffer);
    fflush(stdout);
}

void update(unsigned long long int time) {
    bool write = false;
    FORBLOCKINBLOCKS {
        if ((blocks[i].interval != 0 && time % blocks[i].interval == 0) || time == 0) {
            run_cmd(i, &blocks[i], statusbar[i]);
            write = true;
        }
    }
    if (write) write_status();
}

void bg(char *bg_color, char open_bg[], char close_bg[]) {
    if (bg_color != NULL) {
        snprintf(open_bg, 15, "%%{B%s}", bg_color);
        snprintf(close_bg, 15, "%%{B}");
    } else {
        snprintf(open_bg, 2, "");
        snprintf(close_bg, 2, "");
    }
}

void fg(char *fg_color, char open_fg[], char close_fg[]) {
    if (fg_color != NULL) {
        snprintf(open_fg, 15, "%%{F%s}", fg_color);
        snprintf(close_fg, 15, "%%{F}");
    } else {
        snprintf(open_fg, 2, "");
        snprintf(close_fg, 2, "");
    }
}

// Look at this mess. TODO: refactor
void line(bool underline, bool overline, char *underline_color, char open_line[], char close_line[]) {
    if (underline && overline) {
        if (underline_color != NULL) {
            snprintf(open_line, 25, "%%{U%s}%%{+u}%%{+o}", underline_color);
            snprintf(close_line, 25, "%%{-o}%%{-u}%%{U}");
        } else {
            snprintf(open_line, 25, "%%{+u}%%{+o}");
            snprintf(close_line, 25, "%%{-o}%%{-u}");
        }
    } else if (underline) {
        if (underline_color != NULL) {
            snprintf(open_line, 25, "%%{U%s}%%{+u}", underline_color);
            snprintf(close_line, 25, "%%{-u}%%{U}");
        } else {
            snprintf(open_line, 25, "%%{+u}");
            snprintf(close_line, 25, "%%{-u}");
        }
    } else if (overline) {
        if (underline_color != NULL) {
            snprintf(open_line, 25, "%%{U%s}%%{+o}", underline_color);
            snprintf(close_line, 25, "%%{-o}%%{U}");
        } else {
            snprintf(open_line, 25, "%%{+o}");
            snprintf(close_line, 25, "%%{-o}");
        }
    } else {
            snprintf(open_line, 2, "");
            snprintf(close_line, 2, "");
    }
}
