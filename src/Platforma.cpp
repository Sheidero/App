#include "../inc/Platforma.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Platforma::Platforma() {
    m_x = 400;
    m_y = 1400;
    m_leftx = 800;
    m_rightx = 1200;
    level = 1;
    stack = 1;
    flag = true;
    delta = 400.f;
    platform.setSize(sf::Vector2f(delta, 50.f));
    platform.setFillColor(sf::Color(6*5,3*5,2*5));
    platform.setPosition(m_x,m_y);
}
Platforma::Platforma(int x, int y) {
    m_x = x;
    m_y = y;
    platform.setPosition(m_x,m_y);
}
sf::RectangleShape Platforma::GetPlatform() {
    platform.setSize(sf::Vector2f(delta, 50.f));
    platform.setPosition(m_x,m_y);
    return platform;
}
int Platforma::Getx() {
    return m_x;
}
int Platforma::Gety() {
    return m_y;
}
bool Platforma::Move(float time) {
    if (flag) {
        m_x = 400 + (100 + level * 20)*time;
    }
    else {
        m_x = 1200  - (100 + level * 20)*time;
    }
    if (m_x > 1200){
        flag = false;
        return true;
    }
    if (m_x < 400){
        flag = true;
        return true;
    }
    return false;
}
bool Platforma::MoveUp() {
    if (m_x >= m_leftx && m_x <= m_rightx) {
        level += 1;
        stack += 1;
        m_leftx = m_x;
        delta = m_rightx - m_leftx + 1;
        m_y -= 50;
        flag = not(flag);
        return true;
    }
    if (m_x + delta <= m_rightx && m_x + delta >=m_leftx){
        level += 1;
        stack += 1;
        m_rightx = m_x + delta;
        delta = m_rightx - m_leftx + 1;
        flag = not(flag);
        m_y -= 50;
        return true;
    }
    else {
        return false;
    }
}
short int Platforma::Getleftx(){
    return m_leftx;
}
short int Platforma::Getrightx(){
    return m_rightx;
}
float Platforma::Getdelta() {
    return delta;
}
short int Platforma::Getstack() {
    return stack;
}
void Platforma::Low(){
    m_y += 50;
    stack -= 1;
}
short int Platforma::Getlevel(){
    return level;
}
void Platforma::Setbase() {
    m_x = 400;
    m_y = 1400;
    m_leftx = 800;
    m_rightx = 1200;
    level = 1;
    stack = 1;
    flag = true;
    delta = 400.f;
    platform.setSize(sf::Vector2f(delta, 50.f));
}
void Platforma::Color(short int t) {
    platform.setFillColor(sf::Color(6*(t+5),3*(t+5),2*(t+5)));
}