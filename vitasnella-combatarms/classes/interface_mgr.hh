#pragma once
#include "shell.hh"

struct interface_mgr_t {
	static interface_mgr_t* get( ) {
		return reinterpret_cast<interface_mgr_t*>( reinterpret_cast<uintptr_t>( shell_t::get( ) ) + 0x12AE290 );
	}
	
	bool in_game( ) {
		return reinterpret_cast<bool( __thiscall* )( void* )>( reinterpret_cast<uintptr_t>( shell_t::get( ) ) + 0x31E7E0 )( this );
	}
};
