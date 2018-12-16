#if defined _concolors_included
 #endinput
#endif
#define _concolors_included

#define CON_COLOR_BLACK   0
#define CON_COLOR_BLUE    1
#define CON_COLOR_GREEN   2
#define CON_COLOR_CYAN    3
#define CON_COLOR_RED     4
#define CON_COLOR_MAGENTA 5
#define CON_COLOR_BROWN   6
#define CON_COLOR_WHITE   7

#define FOREGROUND_CON_COLOR_GRAY            8
#define FOREGROUND_CON_COLOR_INTENSE_BLUE    9
#define FOREGROUND_CON_COLOR_INTENSE_GREEN   10
#define FOREGROUND_CON_COLOR_INTENSE_CYAN    11
#define FOREGROUND_CON_COLOR_INTENSE_RED     12
#define FOREGROUND_CON_COLOR_INTENSE_MAGENTA 13
#define FOREGROUND_CON_COLOR_YELLOW          14
#define FOREGROUND_CON_COLOR_INTENSE_WHITE   15

/*
bit 0 - foreground blue
bit 1 - foreground green
bit 2 - foreground red
bit 3 - foreground intensity

bit 4 - background blue
bit 5 - background green
bit 6 - background red
bit 7 - background intensity
*/

/**
 * Sets the color of all future console output
 *
 * @param background	text background color
 * @param foreground	text foreground color
 * @return void
 */
native void SetConsolePrintColor(int background, int foreground);

/**
 * Sets the color of all future console output with custom attributes
 *
 * @param attributes	text attributes
 * @return void
 */
native void SetConsolePrintColorEx(int attributes);

/**
 * Resets the console print color to default (white)
 *
 * @return void
 */
native void ResetConsolePrintColor();

/**
 * Resets the console print color to the previous print color
 *
 * @return void
 */
native void ResetPreviousConsolePrintColor();

/**
 * Print a colored message to the server console
 *
 * @param background	text background color
 * @param foreground	text foreground color
 * @param fmt			format
 * @param any 			...
 * @return void
 */
stock void ColorPrintToServer(int background, int foreground, char[] fmt, any ...)
{
	SetConsolePrintColor(background, foreground);
	char szBuffer[1024];
	VFormat(szBuffer, sizeof(szBuffer), fmt, 4);
	PrintToServer(szBuffer);
	ResetPreviousConsolePrintColor();
}

/**
 * Print a colored message to the server console with custom attributes
 *
 * @param attributes	text attributes
 * @param fmt			format
 * @param any 			...
 * @return void
 */
stock void ColorPrintToServerEx(int attributes, char[] fmt, any ...)
{
	SetConsolePrintColorEx(attributes);
	char szBuffer[1024];
	VFormat(szBuffer, sizeof(szBuffer), fmt, 3);
	PrintToServer(szBuffer);
	ResetPreviousConsolePrintColor();
}

public Extension __ext_concolors = 
{
	name = "ConColors",
	file = "concolors.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};