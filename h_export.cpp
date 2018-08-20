//
// HPB bot - botman's High Ping Bastard bot
//
// (http://planethalflife.com/botman/)
//
// h_export.cpp
//

#ifndef _WIN32
#include <string.h>
#endif

#include <extdll.h>
#include <dllapi.h>
#include <h_export.h>
#include <meta_api.h>

#include "bot.h"

char g_argv[1024];

DLL_FUNCTIONS gFunctionTable;
enginefuncs_t g_engfuncs;
globalvars_t  *gpGlobals;

static FILE *fp;
char z_welcome_msg[] = "HPB bot - http://planethalflife.com/botman";


extern int mod_id;


#ifdef _WIN32

// Required DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
   return TRUE;
}

#endif

void WINAPI GiveFnptrsToDll( enginefuncs_t* pengfuncsFromEngine, globalvars_t *pGlobals )
{
   char mod_name[256];

   // get the engine functions from the engine...
   memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
   gpGlobals = pGlobals;

   // find the directory name of the currently running MOD...
   GetGameDir (mod_name);

   if (strcmpi(mod_name, "valve") == 0)
   {
      mod_id = VALVE_DLL;
   }
   else if (strcmpi(mod_name, "tfc") == 0)
   {
      mod_id = TFC_DLL;
   }
   else if (strcmpi(mod_name, "cstrike") == 0)
   {
      mod_id = CSTRIKE_DLL;
   }
   else if (strcmpi(mod_name, "gearbox") == 0)
   {
      mod_id = GEARBOX_DLL;
   }
   else if (strcmpi(mod_name, "frontline") == 0)
   {
      mod_id = FRONTLINE_DLL;
   }
   else if (strcmpi(mod_name, "holywars") == 0)
   {
      mod_id = HOLYWARS_DLL;
   }
   else if (strcmpi(mod_name, "dmc") == 0)
   {
      mod_id = DMC_DLL;
   }
}

