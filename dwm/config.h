/* See LICENSE file for copyright and license details. */

/* constants */
#define FORCE_VSPLIT 1 /* nrowgrid layout: force two clients to always split vertically */
#define TERM "st"

/* appearance */
static const float mfact			= 0.55;	  /* factor of master area size [0.05..0.95] */
static const int nmaster			= 1;      /* number of clients in master area */
static const int resizehints		= 0;      /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen 	= 0;	  /* 1 will force focus on the fullscreen window */
static Bool bUseOpacity			    = 1;      /* Default inactive opacity */
static const double activeopacity	= 0.95f;  /* Focused window opacity */
static const double inactiveopacity	= 0.9f;   /* Inactive window opacity */
static const unsigned int snap	   	= 32;     /* snap pixel */
static const unsigned int gappx    	= 10;     /* gap between windows */
static const int swallowfloating	= 0;      /* swallow floating windows */
static const unsigned int baralpha	= 0xb0;	  /* statusbar opacity */

static char *fonts[] = { "monospace:size=11", "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true" };
static const char *colors[][2] = {
   /*					fg         bg       */
   [SchemeStatus]   = { "#DDDDDD", "#333333" }, // Statusbar right
   [SchemeTagsSel]  = { "#DDDDDD", "#004444" }, // Tagbar left selected
   [SchemeTagsNorm] = { "#BBBBBB", "#112222" }, // Tagbar left unselected
};
static const unsigned int alphas[][2]   = {
   /*					fg      bg		*/
   [SchemeStatus]	= { OPAQUE, baralpha },
   [SchemeTagsSel]  = { OPAQUE, baralpha },
   [SchemeTagsNorm] = { OPAQUE, baralpha },
};

static const char *tags[]				  = { /*~0*/ "1", "2", "3", "4", "5", "6", "7", "8", "9" }; /* tagging */
static int def_layouts[1 + LENGTH(tags)]  = {    4,   0,   3,   0,   0,   0,   0,   0,   0,   4  }; /* default layout per tag */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class		 instance	title			tags mask   isfloating   isterminal  noswallow	monitor float x,y,w,h */
	{ TERM,			 NULL,      NULL,       	0,          0,           1,          0,         -1,		-1,-1,-1,-1 },
    { "mpv",		 NULL,		NULL,           ~0,		    1,           0,          0,          1,		4625,1155,490,275 },
    { "firefox",	 NULL,		NULL,           1 << 1,		0,           0,          0,			 1, 	-1,-1,-1,-1 },
    { "Thunderbird", NULL,		NULL,           1 << 1,		0,           0,          0,			 1, 	-1,-1,-1,-1 },
    { "Spotify",	 NULL,		NULL,           1 << 8,     0,           0,          0,          1, 	-1,-1,-1,-1 },
    { "Caprine",	 NULL,		NULL,           1 << 8,     0,           0,          0,          1, 	-1,-1,-1,-1 },
    { "discord",	 NULL,		NULL,           1 << 8,     0,           0,          0,          1, 	-1,-1,-1,-1 },
    { "Signal",		 NULL,		NULL,           1 << 8,     0,           0,          0,          1, 	-1,-1,-1,-1 },
	{  NULL,		 NULL,      "Event Tester", 0,          0,           0,          1,         -1, 	-1,-1,-1,-1 },
};

/* layout(s) */
static const Layout layouts[]	= {
	/* symbol   arrange function */
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
	{ MODKEY,					XK_Escape,          quit,           {0} },
	{ MODKEY|ShiftMask,			XK_Escape,          quit,           {1} },
    { 0,						XK_Print,           spawn,          SHCMD("prtsc") },
    { ShiftMask,        		XK_Print,           spawn,		    SHCMD("scrot -s /tmp/screenshot-$(date +%F_%T).png -e 'xclip -selection c -t image/png < $f'") },
    //{ MODKEY,					XK_minus,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_minus,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_equal,		    spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_equal,			spawn,          SHCMD("") }, // Unused
    { MODKEY,			        XK_BackSpace,       view,           {0} },
    //{ MODKEY|ShiftMask,		XK_BackSpace,       tag,			{.ui = 0 } }, // TODO: doesn't work atm
	{ MODKEY,					XK_Tab,				shiftview,		{ .i = +1 } },
	{ MODKEY|ShiftMask,			XK_Tab,				shiftview,		{ .i = -1 } },
    //{ MODKEY,					XK_q,				spawn,          SHCMD("") }, // Unused
	{ MODKEY|ShiftMask,			XK_q,				killclient,		{0} },
    //{ MODKEY,					XK_w,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_w,				spawn,          SHCMD("") }, // Unused
    { MODKEY,					XK_e,				spawn,          SHCMD("-e ranger") },
    //{ MODKEY|ShiftMask,		XK_e,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_r,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_r,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_t,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_t,				spawn,          SHCMD("") }, // Unused
    { MODKEY,					XK_y,				spawn,          SHCMD("yt") },
    //{ MODKEY|ShiftMask,		XK_y,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_u,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_u,				spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_i,				incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,         XK_i,				resetnmaster,   {0} },
	{ MODKEY,					XK_o,				incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_o,				toggleopacity,  {0} },
	{ MODKEY,					XK_p,				spawn,			SHCMD("pw") }, //TODO: checkout passmenu
	{ MODKEY|ShiftMask,			XK_p,				spawn,			SHCMD("2fa") },
	{ MODKEY,					XK_bracketleft,		setlayout,		{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,			XK_bracketleft,		setlayout,		{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,					XK_bracketright,	setlayout,		{.v = &layouts[2]} }, /* deck */
	{ MODKEY|ShiftMask,			XK_bracketright,	setlayout,		{.v = &layouts[3]} }, /* monocle */
	{ MODKEY,					XK_backslash,		setlayout,		{.v = &layouts[4]} }, /* horizgrid */
	{ MODKEY|ShiftMask,			XK_backslash,		view,			{0} },
    { MODKEY,                   XK_a,				winview,        {0} },
	{ MODKEY|ShiftMask,			XK_a,				view,			{.ui = ~0 } },
	{ MODKEY,					XK_s,				togglesticky,	{0} },
    //{ MODKEY|ShiftMask,		XK_s,				spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_d,				spawn,          SHCMD("dmenu_run") },
    //{ MODKEY|ShiftMask,		XK_d,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_f,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_f,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_g,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_g,				spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_h,				focusmon,		{.i = -1 } },
	{ MODKEY|ShiftMask,			XK_h,				tagmon,			{.i = -1 } },
	{ MODKEY,					XK_l,				focusmon,		{.i = +1 } },
	{ MODKEY|ShiftMask,			XK_l,				tagmon,			{.i = +1 } },
    //{ MODKEY,					XK_semicolon,		spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_semicolon,		spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_apostrophe,		spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_apostrophe,		spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_Return,			spawn,			{.v = termcmd } },
    { MODKEY|ShiftMask,			XK_Return,			zoom,           {0} }, // TODO: bind to a function to open terminal in CWD
    //{ MODKEY,					XK_z,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_z,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_x,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_x,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_c,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_c,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_v,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_v,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_b,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_b,				spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_n,				spawn,			SHCMD(TERM " -e ncmpcpp") },
	{ MODKEY|ShiftMask,			XK_n,				spawn,			SHCMD(TERM " -e newsboat; pkill -RTMIN+6 dwmblocks") },
    //{ MODKEY,					XK_m,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_m,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_comma,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_comma,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_period,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_period,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_slash,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_slash,			spawn,          SHCMD("") }, // Unused
	//{ MODKEY,					XK_space,			spawn,          SHCMD("") }, // Unused
	{ MODKEY|ShiftMask,			XK_space,			togglefloating,	{0} },
    //{ MODKEY,					XK_Up,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_Up,				spawn,          SHCMD("") }, // Unused
    //{ MODKEY,					XK_Down,			spawn,          SHCMD("") }, // Unused
    //{ MODKEY|ShiftMask,		XK_Down,			spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_Left,			setmfact,		{.f = -0.05} },
    //{ MODKEY|ShiftMask,		XK_Left,			spawn,          SHCMD("") }, // Unused
	{ MODKEY,					XK_Right,			setmfact,      	{.f = +0.05} },
    //{ MODKEY|ShiftMask,		XK_Right,			spawn,          SHCMD("") }, // Unused


//{ 0,	XK_XF86AudioRaiseVolume,    spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+12") },
//{ 0,	XK_XF86AudioLowerVolume,    spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+12") },
//{ 0,	XK_XF86AudioMute,           spawn,	SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+12") },
//{ 0,	XK_XF86AudioMicMute,        spawn,	SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+12") },
    { 0,	XF86XK_AudioRaiseVolume,    spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
    { 0,	XF86XK_AudioLowerVolume,    spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
    { 0,	XF86XK_AudioMute,           spawn,	SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
    { 0,	XF86XK_AudioMicMute,        spawn,	SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

// bindcode 171 exec --no-startup-id mpc next && pkill -RTMIN+11 i3blocks
// bindcode 172 exec --no-startup-id mpc toggle && pkill -RTMIN+11 i3blocks
// bindcode 173 exec --no-startup-id mpc prev && pkill -RTMIN+11 i3blocks
// bindcode 174 exec --no-startup-id mpc stop && pkill -RTMIN+11 i3blocks

  	{ 0,	XF86XK_AudioPrev,			spawn,	SHCMD("mpc prev") },
  	{ 0, 	XF86XK_AudioNext,			spawn,	SHCMD("mpc next") },
  	{ 0, 	XF86XK_AudioPlay,			spawn,	SHCMD("mpc toggle") },
  	{ 0, 	XF86XK_AudioStop,			spawn,	SHCMD("mpc stop") },


//{ MODKEY,				XK_grave,					spawn,	SHCMD("dmenuunicode") },
//{ MODKEY,				XK_BackSpace,				spawn,	SHCMD("sysact") },
//{ MODKEY|ShiftMask,	XK_BackSpace,				spawn,	SHCMD("sysact") },
//{ MODKEY|ShiftMask,	XK_w,						spawn,	SHCMD(TERM " -e sudo nmtui") },
//{ MODKEY,				XK_r,						spawn,	SHCMD(TERM " -e lfub") },
//{ MODKEY|ShiftMask,	XK_r,						spawn,	SHCMD(TERM " -e htop") },
//{ MODKEY,				XK_minus,					spawn,	SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
//{ MODKEY|ShiftMask,	XK_minus,					spawn,	SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
//{ MODKEY,				XK_equal,					spawn,	SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
//{ MODKEY|ShiftMask,	XK_equal,					spawn,	SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
//{ MODKEY|ShiftMask,	XK_m,						spawn,	SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
//{ MODKEY,				XK_comma,					spawn,	SHCMD("mpc prev") },
//{ MODKEY|ShiftMask,	XK_comma,					spawn,	SHCMD("mpc seek 0%") },
//{ MODKEY,				XK_period,					spawn,	SHCMD("mpc next") },
//{ MODKEY|ShiftMask,	XK_period,					spawn,	SHCMD("mpc repeat") },
//{ MODKEY,				XK_p,						spawn,	SHCMD("mpc toggle") },
//{ MODKEY|ShiftMask,	XK_p,						spawn,	SHCMD("mpc pause ; pauseallmpv") },
//{ MODKEY,				XK_bracketleft,				spawn,	SHCMD("mpc seek -10") },
//{ MODKEY|ShiftMask,	XK_bracketleft,				spawn,	SHCMD("mpc seek -60") },
//{ MODKEY,				XK_bracketright,			spawn,	SHCMD("mpc seek +10") },
//{ MODKEY|ShiftMask,	XK_bracketright,			spawn,	SHCMD("mpc seek +60") },
//{ MODKEY,				XK_F3,						spawn,	SHCMD("displayselect") },
//{ MODKEY,				XK_F4,						spawn,	SHCMD(TERM " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
//{ MODKEY,				XK_F6,						spawn,	SHCMD("torwrap") },
//{ MODKEY,				XK_F7,						spawn,	SHCMD("td-toggle") },
//{ MODKEY,				XK_F8,						spawn,	SHCMD("mw -Y") },
//{ MODKEY,				XK_F9,						spawn,	SHCMD("dmenumount") },
//{ MODKEY,				XK_F10,						spawn,	SHCMD("dmenuumount") },
//{ MODKEY,				XK_F11,						spawn,	SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
//{ 0,					XK_Print,					spawn,	SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
//{ ShiftMask,			XK_Print,					spawn,	SHCMD("maimpick") },
//{ MODKEY,				XK_Print,					spawn,	SHCMD("dmenurecord") },
//{ MODKEY|ShiftMask,	XK_Print,					spawn,	SHCMD("dmenurecord kill") },
//{ MODKEY,				XK_Delete,					spawn,	SHCMD("dmenurecord kill") },
//{ MODKEY,				XK_Scroll_Lock,				spawn,	SHCMD("killall screenkey || screenkey &") },
//{ 0,					XF86XK_AudioMute,			spawn,	SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
//{ 0, 					XF86XK_AudioRaiseVolume,	spawn,	SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
//{ 0, 					XF86XK_AudioLowerVolume,	spawn,	SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
//{ 0, 					XF86XK_AudioStop,			spawn,	SHCMD("mpc stop") },
//{ 0, 					XF86XK_AudioRewind,			spawn,	SHCMD("mpc seek -10") },
//{ 0, 					XF86XK_AudioForward,		spawn,	SHCMD("mpc seek +10") },
//{ 0, 					XF86XK_AudioMedia,			spawn,	SHCMD(TERM " -e ncmpcpp") },
//{ 0, 					XF86XK_AudioMicMute,		spawn,	SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
//{ 0, 					XF86XK_PowerOff,			spawn,	SHCMD("sysact") },
//{ 0, 					XF86XK_Calculator,			spawn,	SHCMD(TERM " -e bc -l") },
//{ 0, 					XF86XK_Sleep,				spawn,	SHCMD("sudo -A zzz") },
//{ 0, 					XF86XK_WWW,					spawn,	SHCMD("$BROWSER") },
//{ 0, 					XF86XK_DOS,					spawn,	SHCMD(TERM) },
//{ 0, 					XF86XK_ScreenSaver,			spawn,	SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
//{ 0, 					XF86XK_TaskPane,			spawn,	SHCMD(TERM " -e htop") },
//{ 0, 					XF86XK_Mail,				spawn,	SHCMD(TERM " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
//{ 0, 					XF86XK_MyComputer,			spawn,	SHCMD(TERM " -e lfub /") },
//{ 0, 					XF86XK_Battery,				spawn,	SHCMD("") },
//{ 0, 					XF86XK_Launch1,				spawn,	SHCMD("xset dpms force off") },
//{ 0, 					XF86XK_TouchpadToggle,		spawn,	SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
//{ 0, 					XF86XK_TouchpadOff,			spawn,	SHCMD("synclient TouchpadOff=1") },
//{ 0, 					XF86XK_TouchpadOn,			spawn,	SHCMD("synclient TouchpadOff=0") },
//{ 0, 					XF86XK_MonBrightnessUp,		spawn,	SHCMD("xbacklight -inc 15") },
//{ 0, 					XF86XK_MonBrightnessDown,	spawn,	SHCMD("xbacklight -dec 15") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        MODKEY,			Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        MODKEY,			Button2,        spawn,			SHCMD(TERM " -e nvim ~/repos/suckless-builds/dwmblocks/blocks.h") },
	{ ClkStatusText,        MODKEY,			Button3,        sigdwmblocks,   {.i = 7} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,			MODKEY,			Button2,		togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,			0,				Button4,		shiftview,		{.i = -1} },
	{ ClkTagBar,			0,				Button5,		shiftview,		{.i = 1} },
};
