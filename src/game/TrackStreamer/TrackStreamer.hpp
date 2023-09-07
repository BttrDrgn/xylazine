#pragma once

//Size = 51
class TrackStreamer
{
public:
	void ServiceNonGameState();
	void HandleLoading();
	void CheckLoadingBar();
};

extern TrackStreamer& TheTrackStreamer;