#include <string>
#include <thread>
#include <Windows.h>

#include "classes/clt_base.hh"
#include "classes/game_client_shell.hh"
#include "classes/interface_mgr.hh"
#include "features/esp.hh"
#include "features/misc.hh"
#include "hooks/hooks.hh"
#include "utils/vector3d.hh"

uintptr_t shell_address;

void __stdcall init( ) {
	while ( true ) {
		while ( !shell_address ) {
			shell_address = reinterpret_cast<uintptr_t>( GetModuleHandleA( "CShell.dll" ) );

			Sleep( 250 );
		}

		if ( static auto done = false; !done ) {
			hooks::init( );

			done = true;
		}

		auto* const interface_mgr = interface_mgr_t::get( );
		if ( !interface_mgr )
			continue;

		if ( interface_mgr->in_game( ) ) {
			hooks::init( );
			misc::init( );
			esp::init( );

			auto* game_client_shell = game_client_shell_t::get( );
			if ( !game_client_shell )
				continue;
			
			for ( auto i = 0; i < game_client_shell->sfx_mgr( )->list[0x18].max_index; i++ ) {
				auto* entity = game_client_shell->sfx_mgr( )->list[0x18].entity[i];
				if ( !entity || entity->dead( ) || !entity->obj( ) )
					continue;

				auto* ctl_base = ctl_base_t::get( );
				if ( !ctl_base )
					continue;

				auto pos = vec3_t( );
				entity_t::get_object_pos( entity->obj( ), &pos );

				printf( "%f | %f \n", pos.x, pos.y );
			}
		}
	}
}

bool __stdcall DllMain( HMODULE, const DWORD reason, LPVOID ) {
	if ( reason != DLL_PROCESS_ATTACH )
        return false;

	AllocConsole( );
	FILE* fp;
	freopen_s( &fp, ( "CONOUT$" ), "w", stdout );
	
	std::thread( &init ).detach( );
	
    return true;
}

