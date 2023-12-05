#include "MusicPlayer.hpp"
#include <iostream>

MusicPlayer::MusicPlayer()
{
	volume = 100;
	paused = false;
}

void MusicPlayer::play()
{
	if (music.getStatus() != sf::Music::Playing)
	{
		if (!music.openFromFile(musicQueue.front()))
		{
			std::cerr << "Error loading music from file: " << musicQueue.front() << "\n";
		}
		music.setVolume(volume);
		music.play();
		musicQueue.pop();
	}
}

void MusicPlayer::stop()
{
	music.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	music.pause();
}

void MusicPlayer::setVolume(float volume)
{
	this->volume = volume;
	music.setVolume(volume);
}

void MusicPlayer::queueMusic(std::string path)
{
	musicQueue.push(path);
}

bool MusicPlayer::isPlaying()
{
	return music.getStatus() == sf::Music::Playing;
}

float MusicPlayer::getVolume()
{
	return volume;
}
