#include <string>
#include <thread>
#include <Windows.h>
#include "classes/interface_mgr.hh"
#include "features/esp.hh"
#include "features/misc.hh"
#include "hooks/hooks.hh"
#include <xorstr.hh>
#include <lazy_importer.hh>

#include "features/aimbot.hh"

uintptr_t shell_address;

void __stdcall init( ) {
	while ( true ) {
		while ( !shell_address ) {
			shell_address = reinterpret_cast<uintptr_t>( LI_FN( GetModuleHandleA ).cached( )( _( "CShell.dll" ) ) );

			LI_FN( Sleep ).cached( )( 250 );
		}

		if ( static auto done = false; !done ) {
			hooks::init( );

			done = true;
		}

		auto* const interface_mgr = interface_mgr_t::get( );
		if ( !interface_mgr )
			continue;

		if ( interface_mgr->in_game( ) ) {
			aimbot::init( );
			misc::init( );
			esp::init( );
		}
	}
}

bool __stdcall DllMain( HMODULE, const DWORD reason, LPVOID ) {
	if ( reason != DLL_PROCESS_ATTACH )
        return false;

	AllocConsole( );
	FILE* fp;
	freopen_s( &fp, _( "CONOUT$" ), _( "w" ), stdout );
	
	std::thread( &init ).detach( );
	
    return true;
}

