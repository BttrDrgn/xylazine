#include "TrackStreamer.hpp"
#include "memory.hpp"

extern std::uint32_t& TheTrackStreamer = *reinterpret_cast<std::uint32_t*>(0x0088EB00);

//THUNK : 0x005E79A0
void TrackStreamer::ServiceNonGameState(TrackStreamer* _this)
{
	reinterpret_cast<void(__thiscall*)(TrackStreamer*)>(0x005E79A0)(_this);
}
