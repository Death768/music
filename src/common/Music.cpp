#include "Music.hpp"
#include <iostream>

Music::Music(std::string path)
{
	if (!music.openFromFile(path))
	{
		std::cerr << "Error loading music from file: " << path << "\n";
	}
}

Music::~Music()
{
}

void Music::play() { music.play(); }
void Music::stop() { music.stop(); }
void Music::pause() { music.pause(); }

void Music::setVolume(float volume)
{
	music.setVolume(volume);
}

bool Music::isPlaying()
{
	return music.getStatus() == sf::Music::Playing;
}