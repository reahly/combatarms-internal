#pragma once
#include "entity.hh"

struct client_info_mgr_t {
	static client_info_mgr_t* get( ) {
		return reinterpret_cast<client_info_mgr_t*>( 0x383B4004 );
	}
	
	void* get_client_by_id( const int id ) {
		static auto* addr = utils::find_pattern( _( "51 56 8B F1 83 7E 0C 00 74 2B" ) );
		if ( !addr )
			return nullptr;
		
		const auto get_client_by_id_fn = reinterpret_cast<void*( __fastcall* )( void*, int )>( addr );
		if ( !get_client_by_id_fn )
			return nullptr;

		return get_client_by_id_fn( this, id );
	}

	client_info_t* get_local_player( ) {
		static auto* addr = utils::find_pattern( _( "83 EC 08 56 8B F1 83 7E 0C 00 74 2A" ) );
		if ( !addr )
			return nullptr;
		
		const auto get_local_player_fn = reinterpret_cast<client_info_t*( __fastcall* )( void* )>( addr );
		if ( !get_local_player_fn )
			return nullptr;

		return get_local_player_fn( this );
	}
};
