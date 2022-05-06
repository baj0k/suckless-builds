//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon		Command				Interval	Signal*/
	{"",		"sb-weather",		3600,		14 },
	{"",		"sb-brightness",	0,			13 },
	{"🔉",		"sb-audio",			0,			12 },
	{"🎵",		"sb-music",			0,			5  },
	{"🌏",		"sb-network",		0,			4  },
	{"🏠",		"sb-system",		5,			3  },
	{"📅",		"sb-clock",			1,			2  },
	{"🤔",		"sb-update",		600,		1  },
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";
