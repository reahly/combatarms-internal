#include "esp.hh"
#include "../classes/shell.hh"

void chams( ) {
	shell_t::get( )->set_convar_float( _( "SkelModelStencil" ), 2.f );
}

void esp::init( ) {
	chams( );
}
