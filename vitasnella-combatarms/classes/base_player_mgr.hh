#pragma once
#include "../utils/utils.hh"

struct base_player_mgr_unk_t {
	OFFSET( uintptr_t, fly( ), 0xb8 )
};

struct base_player_mgr_t {
	static base_player_mgr_t* get( ) {
		return reinterpret_cast<base_player_mgr_t*>( 0x383DE084 );
	}

	OFFSET( base_player_mgr_unk_t*, unk( ), 0x10 )
};