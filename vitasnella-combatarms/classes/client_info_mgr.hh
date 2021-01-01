#pragma once
#include "entity.hh"

struct client_info_mgr_t {
	static client_info_mgr_t* get( ) {
		return reinterpret_cast<client_info_mgr_t*>( 0x383B4004 );
	}
	
	void* get_client_by_id( const int id ) {
		const auto get_client_by_id_fn = reinterpret_cast<void*( __fastcall* )( void*, int )>( 0x371B6CD0 );
		if ( !get_client_by_id_fn )
			return nullptr;

		return get_client_by_id_fn( this, id );
	}

	client_info_t* get_local_player( ) {
		const auto get_local_player_fn = reinterpret_cast<client_info_t*( __fastcall* )( void* )>( 0x371B7CC0 );
		if ( !get_local_player_fn )
			return nullptr;

		return get_local_player_fn( this );
	}
};
