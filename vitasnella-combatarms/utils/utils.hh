#pragma once
#include <Windows.h>

#define PI 3.14159265359

namespace utils {
}

#define OFFSET( type, func, offset ) type& func { return *reinterpret_cast<type*>( reinterpret_cast<uintptr_t>( this ) + offset ); }  // NOLINT
