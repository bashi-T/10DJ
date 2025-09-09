#include "AudioLoader.h"

using namespace KamataEngine;

AudioLoader::AudioLoader()
{
	fanfare_ = Audio::GetInstance()->LoadWave("fanfare.wav");
	paperBrake_ = Audio::GetInstance()->LoadWave("paper.mp3");
}
