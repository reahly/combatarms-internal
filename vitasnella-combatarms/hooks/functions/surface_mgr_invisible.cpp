#include "../hooks.hh"

char __stdcall hooks::surface_mgr_invisible( int type ) {
	return true;
}