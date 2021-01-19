#include "utils.hh"
#include <lazy_importer.hh>
#include <vector>

uint8_t* utils::find_pattern( const char* signature, const char* module_name ) {
	static auto pattern_to_byte = [ ]( const char* pattern ) {
		auto bytes = std::vector<int>{ };
		auto* const start = const_cast<char*>( pattern );
		auto* const end = const_cast<char*>( pattern ) + strlen( pattern );

		for ( auto* current = start; current < end; ++current ) {
			if ( *current == '?' ) {
				++current;
				if ( *current == '?' )
					++current;
				bytes.push_back( -1 );
			} else {
				bytes.push_back( strtoul( current, &current, 16 ) );
			}
		}
		return bytes;
	};

	auto* const module_addr = LI_FN( GetModuleHandleA ).cached( )( module_name );
	
	auto* const dos_headers = reinterpret_cast<PIMAGE_DOS_HEADER>( module_addr );
	if ( !dos_headers )
		return nullptr;

	auto* const nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>( reinterpret_cast<std::uint8_t*>( module_addr ) + dos_headers->e_lfanew );

	auto pattern_bytes = pattern_to_byte( signature );
	auto* const scan_bytes = reinterpret_cast<std::uint8_t*>( module_addr );

	const auto s = pattern_bytes.size( );
	auto* const d = pattern_bytes.data( );

	for ( auto i = 0ul; i < nt_headers->OptionalHeader.SizeOfImage - s; ++i ) {
		auto found = true;
		for ( auto j = 0ul; j < s; ++j ) {
			if ( scan_bytes[i + j] != d[j] && d[j] != -1 ) {
				found = false;
				break;
			}
		}
		if ( found ) {
			return &scan_bytes[i];
		}
	}
	return nullptr;
}

vec3_t utils::calc_angle( const vec3_t pos, const vec3_t camera_pos ) {
	vec3_t Length;
	vec3_t kamera( 0, 0, 0 );
	kamera = camera_pos;

	Length.x = pos.x - kamera.x;
	Length.y = pos.z - kamera.z;
	Length.z = pos.y - kamera.y;

	const auto dist = static_cast<double>( sqrt( Length.x * Length.x + Length.y * Length.y ) );
	auto pitch = static_cast<double>( atan2f( Length.z, dist ) );
	auto yaw = static_cast<double>( atanf( Length.y / Length.x ) );

	if ( Length.x >= 0 && Length.y >= 0 )
		yaw -= PI2;

	if ( Length.x < 0 && Length.y >= 0 )
		yaw += PI2;

	if ( Length.x < 0 && Length.y < 0 )
		yaw += PI2;

	if ( Length.x >= 0 && Length.y < 0 )
		yaw -= PI2;

	pitch *= -1;
	yaw *= -1;

	return vec3_t( pitch, yaw, 0.f );
}