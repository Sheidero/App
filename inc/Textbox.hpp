//
// Created by Артём Гавриков on 28.12.2022.
//

#ifndef PROJECT_TEXTBOX_HPP
#define PROJECT_TEXTBOX_HPP
#include <SFML/Graphics.hpp>

class Textbox {
private:
    sf::Text m_message;
    sf::Font m_font;
public:
    Textbox(int size,float x, float y);
    void Change(std::string str);
    sf::Text Gettext();
};

#endif //PROJECT_TEXTBOX_HPP
