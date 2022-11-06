#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Car.h"
#include <vector>
int getnext100(int x, int dir) {
    x = x + dir;
    if (x <= 0) {
        return x + 100;
    }
    if (x >= 101) {
        return x - 100;
    }
    return x;
}

Obstacle::Obstacle() {
    main = Coord(0, 0);
    num = 0;
    hitbox = nullptr;
    speed = 0;
    direct = 1;
}

void Obstacle::move() {
    Sleep(speed);
    main.x = getnext100(main.x, direct);
}

Car::Car() {
    num = 5;
    main = Coord(0, 0);
    hitbox = new Coord[num];
    upmainC();
    speed = 0;
    direct = 1;
}
Car::Car(int x, int y, int sp, int dir) {
    num = 5;
    main = Coord(x, y);
    hitbox = new Coord[num];
    upmainC();
    speed = sp;
    direct = dir;
}

void Car::upmainC() {
    if (direct == 1) {
        hitbox[0] = Coord(main.x, main.y);
        hitbox[1] = Coord(main.x + 1, main.y);
        hitbox[2] = Coord(main.x + 2, main.y);
        hitbox[3] = Coord(main.x, main.y + 1);
        hitbox[4] = Coord(main.x + 1, main.y + 1);
    }
    else {
        hitbox[0] = Coord(main.x, main.y);
        hitbox[1] = Coord(main.x + 1, main.y);
        hitbox[2] = Coord(main.x + 2, main.y);
        hitbox[3] = Coord(main.x + 2, main.y + 1);
        hitbox[4] = Coord(main.x + 1, main.y + 1);
    }
}

void Car::moveC() {
    move();
    upmainC();
}

int Car::getmainx() {
    return main.x;
}
CarLane::CarLane() {
    num = 0;
    speed = 0;
    direct = 1;
}

CarLane::CarLane(int yLane, int number, int speed, int direct) {
    num = number;
    int dis = 100 / num;
    for (int i = 0; i < num; i++) {
        Car add(dis * i, yLane, speed, direct);
        Lane.push_back(add);
    }
    this->speed = speed;
    this->direct = direct;
    pos = new int[number];
    yLSFML = 50 * yLane;
}

void CarLane::moveL() {
    for (int i = 0; i < num; i++) {
        Lane[i].moveC();
    }
}

void CarLane::sfml(sf::RenderWindow& window) {
    sf::Texture pic;
    pic.loadFromFile("car.png");
    sf::Sprite* out = new sf::Sprite[num];
    for (int i = 0; i < num; i++) {
        pos[i] = Lane[i].getmainx() * 10;
        out[i].setTexture(pic);
        out[i].setPosition(pos[i], yLSFML);
    }
    for (int i = 0; i < num; i++) {
        window.draw(out[i]);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    CarLane L(4, 5, 20, 1);
    CarLane T(8, 3, 20, -1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        L.sfml(window);
        T.sfml(window);
        
        window.display();
        L.moveL();
        T.moveL();
    }

    return 0;
}