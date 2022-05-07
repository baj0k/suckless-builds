//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon		Command				Interval	Signal*/
	//{"",		"sb-brightness",	0,			4  },
	{"",		"sb-weather",		3600,		9  },
	{"",		"sb-music",			0,			8  },
	{"",		"sb-audio",			0,			7  },
	{"🌏",		"sb-network",		0,			6  },
	{"⏫",		"sb-traffic",		1,			5  },
	{"🤖",		"sb-tasks",			0,			2  },
	{"🏠",		"sb-system",		5,			4  },
	{"📅",		"sb-clock",			1,			3  },
	{"🤔",		"sb-update",		600,		1  },
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";
