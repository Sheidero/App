//
// Created by Артём Гавриков on 28.12.2022.
//
#include "../inc/Blocks.hpp"
#include <SFML/Graphics.hpp>

Blocks::Blocks(int x, int y, float delta) {
    m_x = x;
    m_y = y;
    block.setSize(sf::Vector2f(delta, 50.f));
    block.setFillColor(sf::Color::White);

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
void Blocks::Change(int y, float delta, float wide, short int i) {
    block.setSize(sf::Vector2f(delta, wide));
    m_y = wide * i;
}
