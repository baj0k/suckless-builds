/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx		= 0;	/* border pixel of windows */
static const unsigned int gappx			= 10;	/* gaps between windows */
static const unsigned int snap			= 32;	/* snap pixel */
static const int swallowfloating		= 0;	/* 1 means swallow floating windows by default */
static const int showbar				= 1;	/* 0 means no bar */
static const int topbar					= 1;	/* 0 means bottom bar */
static const int viewonrulestag			= 1;	/* Follow applications when opened in tags defined by rules*/
static const Bool viewontag				= True;	/* Follow window when sent to another tag */
static const double activeopacity		= 0.95f;/* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity		= 0.9f;	/* Window opacity when it's inactive (0 <= opacity <= 1) */
static		 Bool bUseOpacity			= True;	/* Starts with opacity on any unfocused windows */


static const char font[]				= "monospace 10";
static const char dmenufont[]			= "monospace:size=10";
static const char col_gray1[]			= "#222222";
static const char col_gray2[]			= "#444444";
static const char col_gray3[]			= "#bbbbbb";
static const char col_gray4[]			= "#eeeeee";
static const char col_cyan[]			= "#005577";
static const unsigned int baralpha		= 0xd0;
static const unsigned int borderalpha	= OPAQUE;
static const char *colors[][3]			= {
	/*					fg			bg		border	*/
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]	 = { col_gray4, col_cyan,  col_cyan	 },
};
static const unsigned int alphas[][3]	= {
	/*					fg		bg		border		*/
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]	 = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* class     instance	title           tags mask	isfloating  isterminal  noswallow	monitor	float x,y,w,h */
	{ "St",      NULL,		NULL,           0,			0,           1,          0,			-1,		-1,-1,-1,-1			},
	{ "firefox", NULL,		NULL,           1 << 1,		0,           0,          0,			 1,		-1,-1,-1,-1			},
	{ "mpv",	 NULL,		NULL,			0,			1,			 0,			 0,			-1,		2055,1150,500,275	},
	{ "Spotify", NULL,		NULL,			1 << 8,		1,			 0,			 0,			 1,		-1,-1,-1,-1			},
	{ "Caprine", NULL,		NULL,			0,			1,			 0,			 0,			-1,		-1,-1,-1,-1			},
	{ "Signal",	 NULL,		NULL,			0,			1,			 0,			 0,			-1,		-1,-1,-1,-1			},
	{ NULL,      NULL,		"Event Tester", 0,			0,			 0,          1,			-1,		-1,-1,-1,-1			}, /* xev */
};

/* layout(s) */
static const float mfact		= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster		= 1;	/* number of clients in master area */
static const int resizehints	= 1;	/* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0;	/* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol	 arrange function */
	{ "|-",		 tile },			/* first entry is default */
	{ "><",	 	 NULL },			/* no layout function means floating behavior */
	{ "[M]", 	 monocle },
	{ "[+]", 	 horizgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,							KEY,	view,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,				KEY,	toggleview,	{.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,					KEY,	tag,		{.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask,		KEY,	toggletag,	{.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier			key							function				argument */
	{ MODKEY,			XK_Return,					spawn,					{.v = termcmd } },
	{ MODKEY,			XK_d,						spawn,					{.v = dmenucmd } },
	{ MODKEY,			XK_b,						togglebar,				{0} },
	{ MODKEY,			XK_j,						focusstack,				{.i = +1 } },
	{ MODKEY,			XK_k,						focusstack,				{.i = -1 } },
	{ MODKEY,			XK_i,						incnmaster,				{.i = +1 } },
	{ MODKEY|ShiftMask,	XK_i,						incnmaster,				{.i = -1 } },
	{ MODKEY,			XK_o,						resetnmaster,			{0} },
	{ MODKEY,			XK_h,						setmfact,				{.f = -0.05} },
	{ MODKEY,			XK_l,						setmfact,				{.f = +0.05} },
	{ MODKEY|ShiftMask,	XK_Return,					zoom,					{0} },
	{ MODKEY,			XK_BackSpace,				view,					{0} },
	{ MODKEY,			XK_a,						toggleopacity,			{0} },
	{ MODKEY|ShiftMask,	XK_q,						killclient,				{0} },
	{ MODKEY,			XK_t,						setlayout,				{.v = &layouts[0]} },
	{ MODKEY,			XK_m,						setlayout,				{.v = &layouts[2]} },
	{ MODKEY,			XK_g,						setlayout,				{.v = &layouts[3]} },
	{ MODKEY,			XK_space,					setlayout,				{0} },
	{ MODKEY|ShiftMask,	XK_space,					togglefloating,			{0} },
	{ MODKEY|ShiftMask,	XK_u,						togglealwaysontop,		{0} },
	{ MODKEY,			XK_f,						togglecanfocusfloating,	{0} },
	{ MODKEY|ShiftMask,	XK_f,						fullscreen,				{0} },
	{ MODKEY,			XK_s,						togglesticky,			{0} },
	{ MODKEY,			XK_0,						view,					{.ui = ~0 } },
	{ MODKEY|ShiftMask,	XK_0,						tag,					{.ui = ~0 } },
	{ MODKEY,			XK_comma,					focusmon,				{.i = -1 } },
	{ MODKEY,			XK_period,					focusmon,				{.i = +1 } },
	{ MODKEY|ShiftMask,	XK_comma,					tagmon,					{.i = -1 } },
	{ MODKEY|ShiftMask,	XK_period,					tagmon,					{.i = +1 } },
	{ MODKEY,			XK_Tab,						shiftview,				{.i = +1 } },
	{ MODKEY|ShiftMask,	XK_Tab,						shiftview,				{.i = -1 } },
	{ MODKEY|ShiftMask,	XK_Tab,						shiftview,				{.i = -1 } },
	{ MODKEY,			XK_o,						winview,				{0} },
	{ MODKEY|ShiftMask,	XK_e,						quit,					{0} },
	{ MODKEY|ShiftMask,	XK_r,						quit,					{1} },
	TAGKEYS(			XK_1,												0)
	TAGKEYS(			XK_2,												1)
	TAGKEYS(			XK_3,												2)
	TAGKEYS(			XK_4,												3)
	TAGKEYS(			XK_5,												4)
	TAGKEYS(			XK_6,												5)
	TAGKEYS(			XK_7,												6)
	TAGKEYS(			XK_8,												7)
	TAGKEYS(			XK_9,												8)
	{ MODKEY,			XK_y,						spawn,					SHCMD("yt") },
	{ 0,				XK_Print,					spawn,					SHCMD("prtsc") },
	{ ShiftMask,		XK_Print,					spawn,					SHCMD("scrot -s /tmp/screenshot-$(date +%F_%T).png -e 'xclip -selection c -t image/png < $f'") },
	/*{ 0,				XK_XF86AudioRaiseVolume,	spawn,					SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+12") },
	{ 0,				XK_XF86AudioLowerVolume,	spawn,					SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+12") }, //TODO: check if need to be changed for pipewire
	{ 0,				XK_XF86AudioMute,			spawn,					SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+12") },
	{ 0,				XK_XF86AudioMicMute,		spawn,					SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+12") }, */
	{ 0,				XF86XK_AudioRaiseVolume,	spawn,					SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
	{ 0,				XF86XK_AudioLowerVolume,	spawn,					SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
	{ 0,				XF86XK_AudioMute,			spawn,					SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
	{ 0,				XF86XK_AudioMicMute,		spawn,					SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click			event mask	button		function		argument */
	{ ClkLtSymbol,		0,			Button1,	setlayout,		{0} },
	{ ClkLtSymbol,		0,			Button3,	setlayout,		{.v = &layouts[2]} },
	{ ClkWinTitle,		0,			Button2,	zoom,			{0} },
	{ ClkStatusText,    0,          Button1,    sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,    0,          Button2,    sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,    0,          Button3,    sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,    0,          Button4,    sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,    0,          Button5,    sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,    ShiftMask,  Button1,    sigdwmblocks,   {.i = 6} },
	{ ClkClientWin,		MODKEY,		Button1,	movemouse,		{0} },
	{ ClkClientWin,		MODKEY,		Button2,	togglefloating,	{0} },
	{ ClkClientWin,		MODKEY,		Button3,	resizemouse,	{0} },
	{ ClkTagBar,		0,			Button1,	view,			{0} },
	{ ClkTagBar,		0,			Button3,	toggleview,		{0} },
	{ ClkTagBar,		MODKEY,		Button1,	tag,			{0} },
	{ ClkTagBar,		MODKEY,		Button3,	toggletag,		{0} },
	{ ClkTabBar,		0,			Button1,	focuswin,		{0} },
};

