#pragma once
#include <cstdint>
#include <xorstr.hh>

#include "weapon_base.hh"
#include "../utils/utils.hh"
#include "../utils/vector3d.hh"

struct movement_manager_t {
	OFFSET( float, gravity( ), 0xb8 )
};

struct camera_t {
	OFFSET( vec3_t, position( ), 0x18 )
};

struct base_player_mgr_t {
	static base_player_mgr_t* get( ) {
		return reinterpret_cast<base_player_mgr_t*>( 0x383B3638 );
	}

	weapon_base_t* get_current_client_weapon( ) {
		static auto* addr = utils::find_pattern( _( "8B 49 18 85 C9 74 05" ) );
		if ( !addr )
			return nullptr;
		
		auto* const get_current_client_weapon_fn = reinterpret_cast<weapon_base_t*( __fastcall* )( uintptr_t )>( addr );
		if ( !get_current_client_weapon_fn )
			return nullptr;

		return get_current_client_weapon_fn( reinterpret_cast<uintptr_t>( this ) );
	}

	int get_current_weaponid( ) {
		static auto* addr = utils::find_pattern( _( "83 79 0C FF 75 06" ) );
		if ( !addr )
			return 0;
		
		auto* test = *reinterpret_cast<void**>( this + 0x18 );
		if ( !test )
			return 0;
		
		const auto get_current_weaponid_fn = reinterpret_cast<int( __fastcall* )( void* )>( addr )( test );
		if ( !get_current_weaponid_fn )
			return 0;

		return get_current_weaponid_fn;
	}

	OFFSET( movement_manager_t*, movement_manager( ), 0x10 )
	OFFSET( vec3_t, viewangles( ), 0x54 )
	OFFSET( camera_t*, camera( ), 0x140 )
};