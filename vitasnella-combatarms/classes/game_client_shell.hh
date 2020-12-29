#pragma once
#include "../utils/utils.hh"
#include "entity.hh"

struct list_t {
	entity_t** entity;
	DWORD pad_01;
	DWORD max_index;
	DWORD pad_02;
};

struct entity_info_t {
	DWORD pad_01;
	list_t list[0x3d];
};

struct game_client_shell_t {
	static game_client_shell_t* get( ) {
		return reinterpret_cast<game_client_shell_t*>( 0x383972D0 );
	}

	entity_info_t* sfx_mgr( ) {
		return reinterpret_cast<entity_info_t*>( this + 0x1C8FC );
	}
};
