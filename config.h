static const unsigned short int left = 7;      // no. of left aligned blocks
static const unsigned short int centre = 0;    // no. of centre aligned blocks
static const unsigned short int right = 1;    // no. of right aligned blocks

static const Block blocks[] = {
    {
        "cpu",                  // command
        10,                     // update interval
        1,                      // update signal
        NULL,                   // bg color
        NULL,                   // fg color
        true,                   // underline
        false,                  // overline
        NULL                    // underline or overline color
    },

    {
        "mem",
        60,
        2,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "cpu-tempt",
        10,
        3,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "vol",
        0,
        4,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "brightness-indicator",
        0,
        5,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "battery",
        60,
        6,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "wifi-indicator",
        0,
        7,
        NULL,
        NULL,
        true,
        false,
        NULL
    },

    {
        "clock",
        60,
        8,
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
