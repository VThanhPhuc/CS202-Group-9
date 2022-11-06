#pragma once
#include <vector>
struct Coord {
    int x, y;
    Coord() {
        x = 0;
        y = 0;
    }
    Coord(int a, int b) {
        x = a;
        y = b;
    }
};

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

class Vehicle : public Obstacle {
protected:
    bool light;
public:
    //Vehicle();
    //void update();
};

class Car : public Vehicle {
public:
    Car();
    Car(int x, int y, int sp, int dir);
    void upmainC();
    void moveC();
    int getmainx();
};

int getnext100(int x, int dir);

class CarLane: public Car  {
private: 
    std::vector <Car> Lane;
    int num;
    int speed;
    int direct;
    //sfml
    int* pos;
    int yLSFML;
public:
    CarLane();
    CarLane(int yLane, int number, int speed, int direct);
    void moveL();
    void sfml(sf::RenderWindow& window);
};