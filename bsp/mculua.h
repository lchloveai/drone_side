#ifndef __MCULUA_H
#define __MCULUA_H	 

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "string.h"
#include "uartthread.h"   

#define LUA_MAXINPUT		512
#define LUA_PROMPT		"> "
#define LUA_PROMPT2		">> "

void lua_main(void);			    

#endif
