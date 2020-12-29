#pragma once

struct weapon_t {
	OFFSET( float, min_perturb( ), 0x2b8 )
	OFFSET( float, max_perturb( ), 0x2bc )
	OFFSET( float, perturb_inc_speed( ), 0x310 )
	OFFSET( float, perturb_dec_speed( ), 0x314 )
	OFFSET( float, duck_perturb( ), 0x2C0 )
	OFFSET( float, duck_move_perturb( ), 0x2C4 )
};
