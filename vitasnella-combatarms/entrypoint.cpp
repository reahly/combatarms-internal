#include <string>
#include <thread>
#include <Windows.h>
#include "classes/base_player_mgr.hh"
#include "features/esp.hh"
#include "classes/interface_mgr.hh"
#include "features/misc.hh"

uintptr_t shell_address;

void __stdcall init( ) {
	while ( true ) {
		while ( !shell_address ) {
			shell_address = reinterpret_cast<uintptr_t>( GetModuleHandleA( "CShell.dll" ) );

			Sleep( 250 );
		}

		auto* const interface_mgr = interface_mgr_t::get( );
		if ( !interface_mgr )
			continue;

		if ( interface_mgr->in_game( ) ) {
			misc::init( );
			esp::init( );

			auto* const base_player_mgr = base_player_mgr_t::get( );
			if ( !base_player_mgr )
				continue;

			base_player_mgr->unk( )->fly( ) = 1149861888;
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

