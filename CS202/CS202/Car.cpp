#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

struct Coord {
    int x, y;
    Coord() {
        x = 0;
        y = 0;
    }
    Coord(int a, int b) {
        x = a;
        y = 4;
    }
};

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

class Obstacle {
protected:
    Coord main;
    Coord* hitbox;
    int num;
    int speed;
    int direct;// 1: right, -1: left
public:
    Obstacle();
    void move();
};

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

class Vehicle : public Obstacle {
protected:
    bool light;
public:
};

class Car : public Vehicle {
public:
    Car();
    Car(int x, int y, int sp, int dir);
    void upmainC();
    void moveC();
};
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
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}