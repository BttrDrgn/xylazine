#include "TrackStreamer.hpp"
#include "Platform/Platform.hpp"
#include "RaceCoordinator/RaceCoordinator.hpp"
#include "memory.hpp"

extern TrackStreamer& TheTrackStreamer = *reinterpret_cast<TrackStreamer*>(0x0088EB00);

//DONE : 0x005E79A0
void TrackStreamer::ServiceNonGameState()
{
	GetDebugRealTime();
	TrackStreamer::HandleLoading();
	TrackStreamer::CheckLoadingBar();
	GetDebugRealTime();
}

//THUNK : 0x005E6A70
void TrackStreamer::HandleLoading()
{
	call<void(TrackStreamer*)>(0x005E6A70)(this);
}

//THUNK : 0x005DF810
void TrackStreamer::CheckLoadingBar()
{
	call<void(TrackStreamer*)>(0x005DF810)(this);
}