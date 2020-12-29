#pragma once
#include "weapon.hh"

struct weapon_mgr_t {
	static weapon_mgr_t* get( ) {
		auto* const get_weapon_mgr_fn = reinterpret_cast<weapon_mgr_t*>( 0x3840E7A0 );
		if ( !get_weapon_mgr_fn )
			return nullptr;
		
		return get_weapon_mgr_fn;
	}

	weapon_t* get_weapon( const int index ) {
		if ( index < 0 || index >= this->num_weapons( ) )
			return nullptr;
		
		return this->weapon_list( )[index];
	}
	
	OFFSET( weapon_t**, weapon_list( ), 0x15e0 )
	OFFSET( int, num_weapons( ), 0x15e4 )
};
