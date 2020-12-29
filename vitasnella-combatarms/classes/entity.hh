#pragma once
#include "clt_base.hh"
#include "../utils/vector3d.hh"

struct entity_t {
	OFFSET( void*, obj( ), 0x10 )
	OFFSET( WORD, health( ), 0x5cc )
	OFFSET( byte, team( ), 0x5D0 )
	OFFSET( bool, dead( ), 0x559 )

	static vec3_t* get_object_pos( void* obj, vec3_t* pos ) {
		const auto get_object_pos_fn = reinterpret_cast<vec3_t*( __fastcall* )( void*, vec3_t*, void* )>( 0x37482B70 );
		if ( !get_object_pos_fn )
			return nullptr;

		return get_object_pos_fn( ctl_base_t::get( ), pos, obj );
	}
};
