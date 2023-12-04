#include <string>
#include <SFML/Audio.hpp>

class Music
{
public:
	Music(std::string path);
	~Music();
	void play();
	void stop();
	void pause();
	void setVolume(float volume);

	bool isPlaying();

private:
	sf::Music music;
};