#pragma once
#include <Windows.h>

namespace utils {
}

#define OFFSET( type, func, offset ) type& func { return *reinterpret_cast<type*>( reinterpret_cast<uintptr_t>( this ) + offset ); }  // NOLINT
