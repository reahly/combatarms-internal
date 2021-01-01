#include "misc.hh"
#include <cstdio>
#include "../classes/base_player_mgr.hh"
#include "../classes/shell.hh"
#include "../classes/weapon.hh"
#include "../classes/weapon_mgr.hh"

void high_jump( ) {
	shell_t::get( )->jump_value( ) = 1500;
}

void speed_hack( ) {
	shell_t::get( )->speed_value( ) = 3000.f;
}

void fly( ) {
	auto* const base_player_mgr = base_player_mgr_t::get( );
	if ( !base_player_mgr )
		return;

	auto* const movement_manager = base_player_mgr->movement_manager( );
	if ( !movement_manager )
		return;

	movement_manager->gravity( ) = LI_FN( GetAsyncKeyState ).cached( )( VK_SPACE ) ? 1100.f : -1100.f;
}

void nospread( ) {
	auto* weapon_mgr = weapon_mgr_t::get( );
	if ( !weapon_mgr )
		return;
	
	auto* const base_player_mgr = base_player_mgr_t::get( );
	if ( !base_player_mgr )
		return;

	auto* weapon = weapon_mgr->get_weapon( base_player_mgr->get_current_weaponid( ) );
	if ( !weapon )
		return;

	weapon->perturb_dec_speed( ) = 0.f;
	weapon->perturb_inc_speed( ) = 0.f;
	weapon->max_perturb( ) = 0.f;
	weapon->min_perturb( ) = 0.f;
	weapon->duck_perturb( ) = 0.f;
	weapon->duck_move_perturb( ) = 0.f;
}

void misc::init( ) {
	fly( );
	high_jump( );
	speed_hack( );
	nospread( );
}
