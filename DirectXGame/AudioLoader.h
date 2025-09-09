#pragma once
#include <KamataEngine.h>
class AudioLoader
{
public:
	AudioLoader();

	uint32_t GetFanfare() { return fanfare_; }
	uint32_t GetPaperBrake_() { return paperBrake_; }

private:
	uint32_t fanfare_ = 0;
	uint32_t paperBrake_ = 0;
};

