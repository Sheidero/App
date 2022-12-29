//
// Created by Артём Гавриков on 28.12.2022.
//
#include "../inc/Blocks.hpp"
#include <SFML/Graphics.hpp>

Blocks::Blocks(int x, int y, float delta, short int t) {
    m_x = x;
    m_y = y;
    m_delta = delta;
    block.setSize(sf::Vector2f(m_delta, 50.f));
    block.setFillColor(sf::Color(6*t,3*t,2*t));

}
sf::RectangleShape Blocks::GetBlock() {
    block.setPosition(m_x,m_y);
    return block;
}
int Blocks::Getx() {
    return m_x;
}
int Blocks::Gety() {
    return m_y;
}
void Blocks::Low() {
    m_y += 50;
}
void Blocks::Change(float wide, short int i) {
    block.setSize(sf::Vector2f(m_delta, wide));
    m_y = 1500 - (i+1) * wide;
}
