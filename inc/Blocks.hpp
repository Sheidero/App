//
// Created by Артём Гавриков on 28.12.2022.
//

#ifndef PROJECT_BLOCKS_HPP
#define PROJECT_BLOCKS_HPP
#include <SFML/Graphics.hpp>

class Blocks {
private:
    int m_x;
    int m_y;
    sf::RectangleShape block;
    float m_delta;
    sf::Texture kirpich;
public:
    Blocks(int x, int y, float delta,short int t);
    sf::RectangleShape GetBlock();
    int Getx();
    int Gety();
    void Low();
    void Change(float wide, short int i);
};

#endif //PROJECT_BLOCKS_HPP