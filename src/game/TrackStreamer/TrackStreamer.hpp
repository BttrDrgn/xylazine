#pragma once

//Size = 51
class TrackStreamer
{
public:
	static void ServiceNonGameState(TrackStreamer* _this);
	char padding[5000];
};

extern std::uint32_t& TheTrackStreamer;