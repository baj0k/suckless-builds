/* See LICENSE file for copyright and license details. */

/* constants */
#define TERM "st"

/* appearance */
static const unsigned int borderpx	= 0;        /* border pixel of windows */
static const unsigned int snap     	= 32;       /* snap pixel */
static const unsigned int gappx    	= 10;       /* gap between windows */
static const int swallowfloating	= 0;        /* swallow floating windows */
static const int showbar			= 1;		/* 0 means no bar */
static const int topbar				= 1;       	/* 0 means bottom bar */

static char *fonts[] = { "monospace:size=10", "NotoColorEmoji:pixelsize=10:antialias=true:autohint=true"  };
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
   /*               fg         bg         border   */
   [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
   [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static       Bool bUseOpacity       	= True;     /* Default inactive opacity */
static const double activeopacity		= 1.0f;     /* Focused window opacity */
static const double inactiveopacity 	= 0.875f;   /* Inactive window opacity */
static const unsigned int baralpha		= 0xd0;		/* statusbar opacity */
static const unsigned int borderalpha	= OPAQUE;	/* border opacity */
static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* default layout per tags */
/* The first element is for all-tag view, following i-th element corresponds to */
/* tags[i]. Layout is referred using the layouts array index.*/
static int def_layouts[1 + LENGTH(tags)]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class	instance	title			tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",   NULL,       NULL,       	1 << 8,       0,           0,          0,        -1 },
	{ TERM,		NULL,       NULL,       	0,            0,           1,          0,        -1 },
	{ NULL,     NULL,       "Event Tester", 0,            0,           0,          1,        -1 },
	{ TERM,     "bg",       NULL,       	1 << 7,       0,           1,          0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */
	{ "[D]",	deck },			/* Master on left, slaves in monocle on right */
	{ "[M]",	monocle },		/* All windows on top of eachother */
    { "###",	horizgrid },	/* All windows in grid */
	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,  XK_m,   ACTION##stack,  {.i = 0 } }, \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,	XK_u,	ACTION##stack,	{.i = PREVSEL } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERM, NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                 key					function		argument */
	STACKKEYS(MODKEY,								focus)
	STACKKEYS(MODKEY|ShiftMask,						push)
	TAGKEYS(					XK_1,								0)
	TAGKEYS(					XK_2,								1)
	TAGKEYS(					XK_3,								2)
	TAGKEYS(					XK_4,								3)
	TAGKEYS(					XK_5,								4)
	TAGKEYS(					XK_6,								5)
	TAGKEYS(					XK_7,								6)
	TAGKEYS(					XK_8,								7)
	TAGKEYS(					XK_9,								8)
	{ MODKEY,					XK_0,				view,			{.ui = ~0 } },
	{ MODKEY|ShiftMask,			XK_0,				tag,			{.ui = ~0 } },
	{ MODKEY|ShiftMask,			XK_q,				killclient,		{0} },
	{ MODKEY,					XK_i,				incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,			XK_i,				incnmaster,     {.i = -1 } },
	{ MODKEY,					XK_bracketleft,		setlayout,		{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,			XK_bracketleft,		setlayout,		{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,					XK_bracketright,	setlayout,		{.v = &layouts[2]} }, /* deck */
	{ MODKEY|ShiftMask,			XK_bracketright,	setlayout,		{.v = &layouts[3]} }, /* monocle */
	{ MODKEY|ShiftMask,			XK_backslash,		setlayout,		{.v = &layouts[4]} }, /* horizgrid */
	{ MODKEY|ShiftMask,			XK_f,				setlayout,		{.v = &layouts[5]} }, /* floating - TODO: consider removing the binding?*/
	{ MODKEY,					XK_backslash,		view,			{0} },
	{ MODKEY,					XK_Tab,				shiftview,		{ .i = +1 } },
	{ MODKEY|ShiftMask,			XK_Tab,				shiftview,		{ .i = -1 } },
	{ MODKEY,					XK_h,				setmfact,		{.f = -0.05} },
	{ MODKEY,					XK_l,				setmfact,      	{.f = +0.05} },
	{ MODKEY,					XK_b,				togglebar,		{0} },
	{ MODKEY,					XK_Return,			spawn,			{.v = termcmd } },
	{ MODKEY,					XK_d,				spawn,          SHCMD("dmenu_run") },


    { MODKEY,                   XK_a,				winview,        {0} },
	{ MODKEY,                   XK_o,				toggleopacity,  {0} },
    { MODKEY|ShiftMask,         XK_o,				resetnmaster,   {0} },

	{ MODKEY|ShiftMask,			XK_d,				spawn,			SHCMD("passmenu") },
	{ MODKEY,					XK_Escape,			spawn,			SHCMD("killall Xorg") }, // TODO: cleanup after patching




	{ MODKEY,					XK_s,				togglesticky,	{0} },
	{ MODKEY,					XK_n,				spawn,			SHCMD(TERM " -e ncmpcpp") },
	{ MODKEY|ShiftMask,			XK_n,				spawn,			SHCMD(TERM " -e newsboat; pkill -RTMIN+6 dwmblocks") },
	//{ MODKEY,						XK_grave,			spawn,			SHCMD("dmenuunicode") },
	//{ MODKEY,			XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	//{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	//{ MODKEY,			XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	//{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	//{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("sysact") },
	//{ MODKEY|ShiftMask,		XK_BackSpace,	spawn,		SHCMD("sysact") },
	//{ MODKEY|ShiftMask,		XK_w,		spawn,		SHCMD(TERM " -e sudo nmtui") },
	//{ MODKEY,			XK_r,		spawn,		SHCMD(TERM " -e lfub") },
	//{ MODKEY|ShiftMask,		XK_r,		spawn,		SHCMD(TERM " -e htop") },
	//{ MODKEY,			XK_p,			spawn,		SHCMD("mpc toggle") },
	//{ MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("mpc pause ; pauseallmpv") },
	//{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("mpc seek -10") },
	//{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("mpc seek -60") },
	//{ MODKEY,			XK_bracketright,	spawn,		SHCMD("mpc seek +10") },
	//{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("mpc seek +60") },
	//{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	//	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc prev") },
	//	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc seek 0%") },
	//	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc next") },
	//	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc repeat") },

	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Insert,	spawn,		SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },

	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD(TERM " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mw -Y") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	{ MODKEY,			XK_F12,		spawn,		SHCMD("remaps & notify-send \\\"⌨️ Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") },
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },

	{ 0,				XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
	{ MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD(TERM " -e ncmpcpp") },
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") },
	{ 0, XF86XK_Calculator,		spawn,		SHCMD(TERM " -e bc -l") },
	{ 0, XF86XK_Sleep,		spawn,		SHCMD("sudo -A zzz") },
	{ 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		spawn,		SHCMD(TERM) },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		spawn,		SHCMD(TERM " -e htop") },
	{ 0, XF86XK_Mail,		spawn,		SHCMD(TERM " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ 0, XF86XK_MyComputer,		spawn,		SHCMD(TERM " -e lfub /") },
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
	{ 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERM " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkTabBar,            0,              Button1,        focuswin,	    {0} },
	{ ClkTagBar,			0,				Button4,		shiftview,		{.i = -1} },
	{ ClkTagBar,			0,				Button5,		shiftview,		{.i = 1} },
	{ ClkRootWin,			0,				Button2,		togglebar,		{0} },
};
