#pragma once

struct ctl_base_t {
	static ctl_base_t* get( ) {
		return reinterpret_cast<ctl_base_t*>( 0x38397248 );
	}
};
