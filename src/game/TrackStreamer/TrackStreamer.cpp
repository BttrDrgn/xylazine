#include "TrackStreamer.hpp"
#include "Platform/Platform.hpp"
#include "RaceCoordinator/RaceCoordinator.hpp"
#include "memory.hpp"

extern std::uint32_t& TheTrackStreamer = *reinterpret_cast<std::uint32_t*>(0x0088EB00);

//DONE : 0x005E79A0
void TrackStreamer::ServiceNonGameState(TrackStreamer* _this)
{
	GetDebugRealTime();
	TrackStreamer::HandleLoading(_this);
	TrackStreamer::CheckLoadingBar(_this);
	GetDebugRealTime();
}

//THUNK : 0x005E6A70
void TrackStreamer::HandleLoading(TrackStreamer* _this)
{
	call<void(TrackStreamer*)>(0x005E6A70)(_this);
}

//THUNK : 0x005DF810
void TrackStreamer::CheckLoadingBar(TrackStreamer* _this)
{
	call<void(TrackStreamer*)>(0x005DF810)(_this);
}