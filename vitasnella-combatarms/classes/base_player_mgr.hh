#pragma once
#include <cstdint>
#include "weapon_base.hh"
#include "../utils/utils.hh"

struct movement_manager_t {
	OFFSET( float, gravity( ), 0xb8 )
};

struct base_player_mgr_t {
	static base_player_mgr_t* get( ) {
		return reinterpret_cast<base_player_mgr_t*>( 0x383B3638 );
	}

	weapon_base_t* get_current_client_weapon( ) {
		auto* const get_current_client_weapon_fn = reinterpret_cast<weapon_base_t*( __fastcall* )( uintptr_t )>( 0x373DF810 );
		if ( !get_current_client_weapon_fn )
			return nullptr;

		return get_current_client_weapon_fn( reinterpret_cast<uintptr_t>( this ) );
	}

	int get_current_weaponid( ) {
		auto* test = *reinterpret_cast<void**>( this + 0x18 );
		if ( !test )
			return 0;
		
		const auto get_current_weaponid_fn = reinterpret_cast<int( __fastcall* )( void* )>( 0x374BC7C0 )( test );
		if ( !get_current_weaponid_fn )
			return 0;

		return get_current_weaponid_fn;
	}

	OFFSET( movement_manager_t*, movement_manager( ), 0x10 )
};