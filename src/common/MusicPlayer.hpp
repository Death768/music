#include <string>
#include <queue>
#include <SFML/Audio.hpp>

class MusicPlayer
{
public:
	MusicPlayer();

	void main();

	void play();
	void stop();

	void setPaused(bool paused);
	void setVolume(float volume);

	bool isPlaying();
	float getVolume();

	void queueMusic(std::string path);

private:
	sf::Music music;
	std::queue<std::string> musicQueue;
	float volume;
	bool paused;

	void keepMusicPlaying();
};