#include "aimbot.hh"
#include "../classes/client_info_mgr.hh"
#include "../classes/game_client_shell.hh"

float get_fov( const vec3_t& va, const vec3_t& aimpos ) {
	auto ang = aimpos - va;
	while ( ang.y <= -180.0f ) ang.y += 360.0f;
	while ( ang.y > 180.0f ) ang.y -= 360.0f;

	return sqrtf( ang.x * ang.x + ang.y * ang.y );
}

entity_t* get_closest_entity( camera_t* camera, client_info_t* local_player ) {
	auto best_distance = FLT_MAX;
	entity_t* best_target = nullptr;
	for ( auto i = 0; i < game_client_shell_t::get( )->sfx_mgr( )->list[0x18].max_index; i++ ) {
		auto* entity = game_client_shell_t::get( )->sfx_mgr( )->list[0x18].entity[i];
		if ( !entity || entity->dead( ) || !entity->obj( ) || entity->team( ) == local_player->team( ) )
			continue;

		const auto calced_fov = get_fov( camera->position( ), utils::calc_angle( camera->position( ), camera->position( ) ) );
		printf( "calced_fov: %f \n", calced_fov );
		
		const auto calculated_distance = camera->position( ).dist_to( entity->obj( )->position( ) );
		if ( calculated_distance > best_distance )
			continue;

		best_distance = calculated_distance;
		best_target = entity;
	}

	return best_target;
}

void aimbot::init( ) {
	if ( !GetAsyncKeyState( VK_XBUTTON2 ) )
		return;

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

	const auto pos = entity->obj( )->position( );
	if ( const auto aimangle = utils::calc_angle( pos, camera->position( ) ); !aimangle.empty( ) )
		player_mgr->viewangles( ) = aimangle;
}
