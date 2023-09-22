#include "TrackStreamer.hpp"
#include "Platform/Platform.hpp"
#include "Unsorted/RaceCoordinator.hpp"
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
	reinterpret_cast<void(__thiscall*)(TrackStreamer*)>(0x005E6A70)(this);
}

//THUNK : 0x005DF810
void TrackStreamer::CheckLoadingBar()
{
	reinterpret_cast<void(__thiscall*)(TrackStreamer*)>(0x005DF810)(this);
}