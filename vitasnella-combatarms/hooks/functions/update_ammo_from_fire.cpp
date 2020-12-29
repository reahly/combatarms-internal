#include <cstdio>
#include "../hooks.hh"

int __fastcall hooks::update_ammo_from_fire( void* ecx, bool a ) {
	printf( "ammo: %p %i \n", ecx, a );
	return static_cast<int( __fastcall* )( void*, bool )>( original_update_ammo_from_fire )( ecx, false );
}