#ifndef _INCLUDE_CONCOLOR_NATIVES_H_
#define _INCLUDE_CONCOLOR_NATIVES_H_

#include "extension.h"


static cell_t sm_SetConsolePrintColor(IPluginContext *pContext, const cell_t *params)
{
	g_colorHandler.SetConsolePrintColor(params[1], params[2]);
	return 1;
}

static cell_t sm_SetConsolePrintColorEx(IPluginContext *pContext, const cell_t *params)
{
	g_colorHandler.SetConsolePrintColorEx(params[1]);
	return 1;
}

static cell_t sm_ResetConsolePrintColor(IPluginContext *pContext, const cell_t *params)
{
	g_colorHandler.ResetConsolePrintColor();
	return 1;
}

static cell_t sm_ResetPreviousConsolePrintColor(IPluginContext *pContext, const cell_t *params)
{
	g_colorHandler.ResetPreviousConsolePrintColor();
	return 1;
}

sp_nativeinfo_t g_conColorNatives[] =
{
	{ "SetConsolePrintColor",			sm_SetConsolePrintColor },
	{ "SetConsolePrintColorEx",			sm_SetConsolePrintColorEx },
	{ "ResetConsolePrintColor",			sm_ResetConsolePrintColor },
	{ "ResetPreviousConsolePrintColor",	sm_ResetPreviousConsolePrintColor },
	{ NULL, NULL },
};

#endif //_INCLUDE_CONCOLOR_NATIVES_H_