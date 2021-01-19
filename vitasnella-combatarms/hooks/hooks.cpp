#include "hooks.hh"
#include <xorstr.hh>
#include "../utils/utils.hh"
#include "library/minhook.h"

void hooks::init( ) {
	auto* const addr = utils::find_pattern( _( "83 EC 10 55 8B E9" ) );
	if ( !addr ) {
		MessageBoxA( nullptr, _( "failed finding start_weapon_recoil" ), nullptr, 0 );
		return;
	}
	
	MH_Initialize( );

	MH_CreateHook( reinterpret_cast<void*>( 0x373E3EE0 ), &start_weapon_recoil, nullptr );

	MH_EnableHook( nullptr );
}
