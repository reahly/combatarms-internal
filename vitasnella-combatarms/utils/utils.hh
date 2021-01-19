#pragma once
#include <cstdint>
#include <Windows.h>

#include "vector3d.hh"

#define PI 3.14159265359
#define PI2 1.57079632679489661923
#define OFFSET( type, func, offset ) type& func { return *reinterpret_cast<type*>( reinterpret_cast<uintptr_t>( this ) + offset ); }  // NOLINT
#define RESOLVE_RVA( Instr ) (SIZE_T)*(DWORD*)(Instr + 7)

namespace utils {
	uint8_t* find_pattern( const char*, const char* module_name = "CShell.dll" );
	vec3_t calc_angle( vec3_t, vec3_t );
}