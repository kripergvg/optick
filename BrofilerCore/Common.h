#pragma once

#include "Platform.h"
#include "Types.h"

#if BRO_PLATFORM_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#include "Brofiler.h"


// MEMORY //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BRO_CACHE_LINE_SIZE 64
#define BRO_ALIGN_CACHE BRO_ALIGN(BRO_CACHE_LINE_SIZE)
#define BRO_ARRAY_SIZE(ARR) (sizeof(ARR)/sizeof((ARR)[0]))
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define BRO_UNUSED(x) (void)(x)

#ifdef _DEBUG
	#define BRO_ASSERT(arg, description) if (!(arg)) { BRO_DEBUG_BREAK; }
	#define BRO_VERIFY(arg, description, operation) if (!(arg)) { BRO_DEBUG_BREAK; operation; }
	#define BRO_FAILED(description) { BRO_DEBUG_BREAK; }
#else
	#define BRO_ASSERT(arg, description)
	#define BRO_VERIFY(arg, description, operation)
	#define BRO_FAILED(description)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// OVERRIDE keyword warning fix ////////////////////////////////////////////////////////////////////////////////////////////////
#if _MSC_VER >= 1600 // >= VS 2010 (VC10)
	#pragma warning (disable: 4481) //http://msdn.microsoft.com/en-us/library/ms173703.aspx
#else
	#define override
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
