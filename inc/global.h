#ifndef __GLOBAL_H__
#define __GLOBAL_H__

//
//  Lua
//
//  Embeddable scripting language solely for C/C++ projects.
//  See: https://www.lua.org
//
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"

//
//  Duktape
//
//  Simple, embeddable JavaScript engine for C/C++ projects.
//  See: https://duktapge.org
//
#include "duktape/duktape.h"

//
//  Tiny Garbage Collector
//
//  A tiny garbage collector based on Cello Garbage Collector.
//  See: https://github.com/orangeduck/tgc
//
#include "tgc/tgc.h"

#include <string.h>
#include <stdio.h>
#include <switch.h>

#endif