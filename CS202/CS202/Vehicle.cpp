#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Vehicle.h"

using namespace std;



void CVEHICLE::draw(sf::RenderWindow& window){}
int getnextmod150(int x, int sp) {
	x = x + sp;
	if (x < 0)
		return x + 150;
	else if (x > 150)
		return x + 150;
	else
		return x;
}
int CVEHICLE::getmX() {
	return mX;
}
int CVEHICLE::getmY() {
	return mY;
}
int CVEHICLE::getspeed() {
	return speed;
}
CVEHICLE::CVEHICLE() {
	mX = 0;
	mY = 0;
	speed = 1;
}
CVEHICLE::CVEHICLE(int x, int y, int sp) {
	mX = x;
	mY = y;
	speed = sp;
}
void CVEHICLE::move() {
	mX = getnextmod150(mX,speed);
}


 
void CCar::move() {
	CVEHICLE::move();
}
void CCar::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("car1.png");
	}
	else {
		pic.loadFromFile("car.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX()*10, getmY()*40);
	window.draw(out);
}


void CTruck::move() {
	CVEHICLE::move();
}
void CTruck::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("truck.png");
	}
	else {
		pic.loadFromFile("truck1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX() * 10, getmY() * 40);
	window.draw(out);
}
CANIMAL::CANIMAL() {
	mX = 0;
	mY = 0;
	speed = 1;
}
CANIMAL::CANIMAL(int x, int y, int sp) {
	mX = x;
	mY = y;
	speed = sp;
}

int CANIMAL::getmX() {
	return mX;
}
int CANIMAL::getmY() {
	return mY;
}
int CANIMAL::getspeed() {
	return speed;
}
void CANIMAL::move() {
	mX = getnextmod150(mX, speed);
}
void CANIMAL::draw(sf::RenderWindow& window) {}


void CBIRD::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("bird.png");
	}
	else {
		pic.loadFromFile("bird1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX() * 10, getmY() * 40);
	window.draw(out);
}


void CBIRD::move() {
	CANIMAL::move();
}
void CDINO::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("dino.png");
	}
	else {
		pic.loadFromFile("dino1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX() * 10, getmY() * 40);
	window.draw(out);
}

void CDINO::move() {
	CANIMAL::move();
}
void CANIMAL::tell(sf::SoundBuffer& Buffer, sf::Sound& S){}
void CDINO::tell(sf::SoundBuffer& Buffer, sf::Sound& S){

}
void CBIRD::tell(sf::SoundBuffer& Buffer, sf::Sound& S){
	Buffer.loadFromFile("birdsound.wav");
	S.setBuffer(Buffer);
	
}
CCar::CCar(int x, int y, int sp) :CVEHICLE(x, y, sp) {}
CTruck::CTruck(int x, int y, int sp) :CVEHICLE(x, y, sp) {}


int main() {
	CBIRD b;
	sf::SoundBuffer Buffer;

	sf::Sound s;
	b.tell(Buffer, s);
	while (true) {
		s.play();
		Sleep(2000);
	}

}




//int main() {
//	//sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
//	sf::SoundBuffer buffer;
//	buffer.loadFromFile("birdsound.wav");
//
//	sf::Sound sound;
//	sound.setBuffer(buffer);
//	sound.play();
//	CTruck c(5,10,10);
//	CBIRD b;
//	sound.setLoop(TRUE);
//	while (true) {
//		sound.play();
//	}
//	/*while (window.isOpen())
//		    {
//		        sf::Event event;
//		        while (window.pollEvent(event))
//		        {
//		            if (event.type == sf::Event::Closed)
//		                window.close();
//		        }
//		
//		        window.clear();
//				c.draw(window);
//		        window.display();
//				b.tell();
//				s.play();
//		    }*/
//
//}