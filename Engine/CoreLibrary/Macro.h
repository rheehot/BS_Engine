#pragma once

#include <cassert>

#define BS_API

#define check(expr) { assert(expr); }

#undef TEXT
#define TEXT(x) L ## x