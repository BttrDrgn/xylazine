#pragma once

//Size = 51
class TrackStreamer
{
public:
	static void ServiceNonGameState(TrackStreamer* _this);
	static void HandleLoading(TrackStreamer* _this);
	static void CheckLoadingBar(TrackStreamer* _this);
};

extern std::uint32_t& TheTrackStreamer;