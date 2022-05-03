//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/			/*Update Interval*/	/*Update Signal*/
	{"",		"sb-weather",		1800,				14 },
	{"",		"sb-brightness",	0,					13 },
	{"🔉",		"sb-audio",			0,					12 },
	{"🌏",		"sb-openvpn",		0,					11 },
	{"🎵",		"sb-music",			10,					9  },
	{"🌏",		"sb-network",		0,					3  },
	{"💻",		"sb-system",		0,					3  },
	{"🕓",		"sb-clock",			1,					2  },
	{"🤔",		"sb-update",		1800,				1  },
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";
