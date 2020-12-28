#include "esp.hh"
#include "../classes/shell.hh"

void chams( ) {
	shell_t::get( )->set_convar_float( "SkelModelStencil", 2.f );
}

void esp::init( ) {
	chams( );
}
