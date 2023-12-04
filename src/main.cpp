#include "Music.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string musicfile = "Meteor (Edit).wav";
	Music music(musicfile);

	music.play();
	while (music.isPlaying())
	{
		std::cout << "Playing music...\n";
	}

	return 0;
}