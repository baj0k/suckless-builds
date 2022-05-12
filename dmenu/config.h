/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *colors[SchemeLast][2] = {
	/*				           fg         bg       */
	[SchemeNorm]	   	  = { "#00BBBB", "#020202" },
	[SchemeSel]		   	  = { "#00DDDD", "#512200" },
	[SchemeOut] 	   	  = { "#000000", "#945500" },
    [SchemeNormHighlight] = { "#C4A000", "#020202" },
    [SchemeSelHighlight]  = { "#00DDDD", "#512200" },
    [SchemeOutHighlight]  = { "#945500", "#020202" },
};

static const unsigned int alpha	= 0xCC; /* opacity */
static const unsigned int alphas[SchemeLast][2] = {
	   /*			    fg      bg    */
       [SchemeNorm] = { OPAQUE, alpha },
       [SchemeSel]  = { OPAQUE, alpha },
       [SchemeOut]  = { OPAQUE, alpha },
};

static const char *fonts[] = { "Liberation Mono:pixelsize=25:antialias=true:autohint=true",
							   "JoyPixels:pixelsize=15:antialias=true:autohint=true"
};

static const unsigned int border_width	= 2;	/* Size of the window border */
static const char worddelimiters[]		= " ";	/* Characters not considered part of a word while deleting words */
static int min_width					= 500;  /* minimum width when centered */
static unsigned int lines      			= 5;	/* -l option; if nonzero, dmenu uses vertical list */
static const char *prompt				= NULL; /* -p  option; prompt to the left of input field */
