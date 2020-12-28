#include "misc.hh"
#include "../classes/shell.hh"

void high_jump( ) {
	shell_t::get( )->jump_value( ) = 1500;
}

void speed_hack( ) {
	shell_t::get( )->speed_value( ) = 3000.f;
}

void misc::init( ) {
	high_jump( );
	speed_hack( );
}
