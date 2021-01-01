#pragma once
#include "../classes/base_player_mgr.hh"
#include "../utils/vector3d.hh"

struct entity_object_t {
	OFFSET( vec3_t, position( ), 0xC8 )
};

struct entity_t {
	OFFSET( entity_object_t*, obj( ), 0x10 )
	OFFSET( uint16_t, health( ), 0x5CC )
	OFFSET( uint16_t, team( ), 0x5D0 )
	OFFSET( bool, dead( ), 0x559 )
};

struct client_info_t {
	OFFSET( int32_t, id( ), 0x0 )
	OFFSET( int32_t, team( ), 0xc )
};