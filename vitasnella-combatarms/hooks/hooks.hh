#pragma once

inline void* original_update_ammo_from_fire;

namespace hooks {
	void init( );

	void __fastcall start_weapon_recoil( void* );
	char __stdcall surface_mgr_invisible( int );
	int __fastcall update_ammo_from_fire( void*, bool );
}