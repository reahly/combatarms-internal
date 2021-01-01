#include "aimbot.hh"
#include "../classes/client_info_mgr.hh"
#include "../classes/game_client_shell.hh"

entity_t* get_closest_entity( camera_t* camera, client_info_t* local_player ) {
	auto best_distance = FLT_MAX;
	entity_t* best_target = nullptr;
	for ( auto i = 0; i < game_client_shell_t::get( )->sfx_mgr( )->list[0x18].max_index; i++ ) {
		auto* entity = game_client_shell_t::get( )->sfx_mgr( )->list[0x18].entity[i];
		if ( !entity || entity->dead( ) || !entity->obj( ) || entity->team( ) == local_player->team( ) )
			continue;

		const auto calculated_distance = camera->position( ).dist_to( entity->obj( )->position( ) );
		if ( calculated_distance > best_distance )
			continue;

		best_distance = calculated_distance;
		best_target = entity;
	}
	
	return best_target;
}

void aimbot::init( ) {
	auto* player_mgr = base_player_mgr_t::get( );
	if ( !player_mgr )
		return;

	auto* camera = player_mgr->camera( );
	if ( !camera )
		return;
	
	auto* local_player = client_info_mgr_t::get( )->get_local_player( );
	if ( !local_player )
		return;

	auto* entity = get_closest_entity( camera, local_player );
	if ( !entity )
		return;

	printf( "found best entity with hp: %i \n", entity->health( ) );
}
