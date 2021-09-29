static const unsigned short int left = 9;      // no. of left aligned blocks
static const unsigned short int centre = 0;    // no. of centre aligned blocks
static const unsigned short int right = 1;    // no. of right aligned blocks

static const Block blocks[] = {
    {
        "lemonbar_crypto",      // command
        3600,                   // update interval
        1,                      // update signal
        NULL,                   // bg color
        NULL,                   // fg color
        true,                   // underline
        false,                  // overline
        NULL                    // underline or overline color
    },

    {
        "lemonbar_cpu",
        60,
        2,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_mem",
        60,
        3,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_cpu-tempt",
        60,
        4,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_unread_mail",
        3600,
        5,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_vol",
        0,
        10,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_brightness-indicator",
        0,
        14,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_battery",
        60,
        8,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_wifi-indicator",
        0,
        12,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "lemonbar_clock",
        60,
        16,
        NULL,
        NULL,
        true,
        false,
        NULL
    },
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static const char *delim = "  ";
static const unsigned int delim_length = 3;
