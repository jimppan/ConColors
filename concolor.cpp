#include "concolor.h"

ConColorHandler::ConColorHandler()
{
	m_hStdin = GetStdHandle(STD_INPUT_HANDLE);
	m_hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(m_hStdout, &m_orgCsbi);
}

ConColorHandler::~ConColorHandler()
{
	FlushConsoleInputBuffer(m_hStdin);
}

void ConColorHandler::SetConsolePrintColor(WORD background, WORD foreground)
{
	GetConsoleScreenBufferInfo(m_hStdout, &m_csbi);
	SetConsoleTextAttribute(m_hStdout, (16 * background) + foreground);
}

void ConColorHandler::SetConsolePrintColorEx(WORD attributes)
{
	GetConsoleScreenBufferInfo(m_hStdout, &m_csbi);
	SetConsoleTextAttribute(m_hStdout, attributes);
}

void ConColorHandler::ResetConsolePrintColor()
{
	SetConsoleTextAttribute(m_hStdout, m_orgCsbi.wAttributes);
}

void ConColorHandler::ResetPreviousConsolePrintColor()
{
	SetConsoleTextAttribute(m_hStdout, m_csbi.wAttributes);
}