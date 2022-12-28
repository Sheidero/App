//
// Created by Артём Гавриков on 28.12.2022.
//

#ifndef PROJECT_PLATFORMA_HPP
#define PROJECT_PLATFORMA_HPP
#include <SFML/Graphics.hpp>

class Platforma {
private:
    int m_x;
    int m_y;
    int m_leftx;
    int m_rightx;
    int curlen;
    bool flag;
    float delta;
    sf::RectangleShape platform;
    short int level;
    short int stack;
public:
    Platforma();
    Platforma(int x, int y);
    sf::RectangleShape GetPlatform();
    int Getx();
    int Gety();
    bool Move(float time);
    bool MoveUp();
    short int Getleftx();
    short int Getrightx();
    float Getdelta();
    short int Getstack();
    void Low();
};

#endif //PROJECT_PLATFORMA_HPP
