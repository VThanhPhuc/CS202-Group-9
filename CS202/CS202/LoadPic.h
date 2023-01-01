#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <unordered_map>
#include "Constants.h"

using namespace std;
class LoadPic
{
private:
	LoadPic();
	LoadPic(const LoadPic&) {};
	LoadPic& operator = (const LoadPic&) {};
	void initTexture(string texFileName, bool isplayer = false);
	void initSound(string soundFileName);
public:
	static LoadPic& GetIns()
	{
		static LoadPic ins;
		return ins;
	}

	unordered_map<string, sf::Texture> texture;
	unordered_map<string, sf::SoundBuffer> sound;
};
