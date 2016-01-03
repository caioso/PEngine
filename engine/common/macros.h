#ifndef __MACROS__
#define __MACROS__

// Colors Macros
#define PPL_RGBA(R, G, B, A) ((R<<24)|(G<<16)|(B<<8)|A)
#define PPL_RGB(R, G, B) ((R<<24)|(G<<16)|(B<<8)|255)

// Color Constants
#define PPL_COLOR_WHITE PPL_RGBA(255, 255, 255, 255)
#define PPL_COLOR_RED PPL_RGBA(255, 0, 0, 255)
#define PPL_COLOR_GREEN PPL_RGBA(0, 255, 0, 255)
#define PPL_COLOR_BLUE PPL_RGBA(0, 0, 255, 255)
#define PPL_COLOR_YELLOW PPL_RGBA(255, 255, 0, 255)

#endif // __MACROS__