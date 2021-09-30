/* Lemonaid does not do lemonbar specific formatting for you
 * This means you yourself have to add the format specifiers for bg, fg,
 * underline, overline, etc.
 * This gives the user much more control over how they want to setup their bar.
 * Lemonaid only handles the signals and runs your commands after the specified
 * time interval.
 * This makes lemonaid more akin to the unix philosophy and helps make the
 * codebase lean and clean
 */

static const unsigned short int left = 7;     // no. of left aligned blocks
static const unsigned short int centre = 0;   // no. of centre aligned blocks
static const unsigned short int right = 1;    // no. of right aligned blocks

static const Block blocks[] = {
    // command                  update interval(in s)   update signal
    { "cpu",                    10,                     1 },

    { "mem",                    60,                     2 },

    { "cpu-tempt",              10,                     3 },

    { "vol",                    0,                      4 },

    { "brightness-indicator",   0,                      5 },

    { "battery",                60,                     6 },

    { "wifi-indicator",         0,                      7 },

    { "clock",                  60,                     8 },
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static const char *delim = "  ";
static const unsigned int delim_length = 3;
