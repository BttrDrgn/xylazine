#pragma once

class TrackStreamer
{
public:
	char padding[0x84c];

	void ServiceNonGameState();
	void HandleLoading();
	void CheckLoadingBar();
};

extern TrackStreamer& TheTrackStreamer;