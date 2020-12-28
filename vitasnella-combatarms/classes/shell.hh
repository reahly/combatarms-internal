#pragma once
#include "../utils/utils.hh"

struct shell_t {
	static shell_t* get( ) {
		return reinterpret_cast<shell_t*>( GetModuleHandleA( "CShell.dll" ) );
	}
	
	void set_convar_float( const char* name, const float value ) {
		reinterpret_cast<void( __cdecl* )( const char*, float )>( this + 0x35F850 )
			( name, value );	
	}

	void set_convar_int( const char* name, const int value ) {
		reinterpret_cast<void( __cdecl* )( const char*, int )>( this + 0x35F730 )
			( name, value );	
	}

	OFFSET( float, jump_value( ), 0x126D434 )
	OFFSET( float, speed_value( ), 0x126D3C8 )
	OFFSET( float, unknown( ), 0x126D410 )
};