#include "hooks.hh"
#include "library/minhook.h"

void hooks::init( ) {
	MH_Initialize( );

	MH_CreateHook( reinterpret_cast<void*>( 0x373E3EE0 ), &start_weapon_recoil, nullptr );
	//MH_CreateHook( reinterpret_cast<void*>( 0x374F7CF0 ), &update_ammo_from_fire, &original_update_ammo_from_fire );

	MH_EnableHook( nullptr );
}
