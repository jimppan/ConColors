#ifndef _INCLUDE_CONCOLOR_H_
#define _INCLUDE_CONCOLOR_H_

#include <Windows.h>


class ConColorHandler
{
public:
	ConColorHandler();
	~ConColorHandler();

	void SetConsolePrintColor(WORD background, WORD foreground);
	void SetConsolePrintColorEx(WORD attributes);

	void ResetConsolePrintColor();
	void ResetPreviousConsolePrintColor();

	HANDLE m_hStdin;
	HANDLE m_hStdout;
	CONSOLE_SCREEN_BUFFER_INFO m_csbi;
	CONSOLE_SCREEN_BUFFER_INFO m_orgCsbi;
};

#endif //_INCLUDE_CONCOLOR_H_