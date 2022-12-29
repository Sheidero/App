//
// Created by Артём Гавриков on 28.12.2022.
//

#include "../inc/Textbox.hpp"
#include <Sfml/Graphics.hpp>

Textbox::Textbox(int size,float x, float y){
    m_font.loadFromFile("../res/Montserrat/Montserrat-Regular.ttf");
    m_message.setFont(m_font);
    m_message.setString("");
    m_message.setCharacterSize(size);
    m_message.setFillColor(sf::Color(255,255,255,255));
    m_message.setPosition(sf::Vector2f(x,y));
    m_message.setStyle(sf::Text::Bold | sf::Text::Underlined);
}
void Textbox::Change(std::string str) {
    m_message.setString(str);
}
sf::Text Textbox::Gettext() {
    return m_message;
}
