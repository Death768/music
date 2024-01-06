#include "MusicPlayer.hpp"
#include <iostream>
#include <thread>

MusicPlayer::MusicPlayer()
{
	volume = 100;
	paused = false;
}

void MusicPlayer::keepMusicPlaying()
{
	while (true)
	{
		if (music.getStatus() == sf::Music::Stopped && !musicQueue.empty())
		{
			play();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void MusicPlayer::main()
{
	std::thread musicThread(&MusicPlayer::keepMusicPlaying, this);
	while (true)
	{
		std::string input;
		std::cin >> input;

		if (input == "stop")
		{
			stop();
		}
		else if (input == "pause")
		{
			setPaused(true);
		}
		else if (input == "play")
		{
			setPaused(false);
		}
		else if (input == "volume")
		{
			std::cin >> input;
			setVolume(std::stoi(input));
		}
		else if (input == "queue")
		{
			std::cin.ignore(INT16_MAX, '\n');
			std::getline(std::cin, input);
			std::cout << "Queuing " << input << "\n";
			queueMusic("../src/music/" + input);
		}
		else if (input == "viewqueue")
		{
			std::queue<std::string> tempQueue = musicQueue;
			while (!tempQueue.empty())
			{
				std::cout << tempQueue.front() << "\n";
				tempQueue.pop();
			}
		}
		else if (input == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Invalid input\n";
		}
	}
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
