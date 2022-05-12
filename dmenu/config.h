/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *colors[SchemeLast][2] = {
	/*				  fg         bg       */
	[SchemeNorm] = { "#00FFFF", "#000000" },
	[SchemeSel]	 = { "#00FFFF", "#000000" },
	[SchemeOut]  = { "#000000", "#000000" },
//    [SchemeSelHighlight] = { "#C4A000", "#000000" },
//    [SchemeNormHighlight] = { "#FF0000", "#000000" },
};

static const unsigned int alpha	= 0xBB; /* opacity */
static const unsigned int alphas[SchemeLast][2] = {
	   /*			    fg      bg    */
       [SchemeNorm] = { OPAQUE, alpha },
       [SchemeSel]  = { OPAQUE, alpha },
       [SchemeOut]  = { OPAQUE, alpha },
};

static const char *fonts[] = { "Liberation Mono:pixelsize=25:antialias=true:autohint=true",
							   "JoyPixels:pixelsize=15:antialias=true:autohint=true"
};

static const char worddelimiters[]	= " ";	/* Characters not considered part of a word while deleting words */
static int min_width				= 500;  /* minimum width when centered */
static const char *prompt			= NULL; /* -p  option; prompt to the left of input field */
static unsigned int lines      		= 4;	/* -l option; if nonzero, dmenu uses vertical list */

//static const unsigned int border_width = 2;
