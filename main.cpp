#include <SFML/Graphics.hpp>
#include <iostream>
#include "inc/Blocks.hpp"
#include "inc/Platforma.hpp"
#include "inc/func.hpp"
#include "inc/Textbox.hpp"
#include <sstream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1500), "Stack");

    sf::Texture background;
    background.loadFromFile("../res/background.png");
    sf::Sprite backgrounds(background);
    backgrounds.setScale(1.7,2.1);

    std::vector<Blocks> blocks = {};
    int t = 0;
    Platforma plat;
    sf::Clock clock;
    short int current_step = 1;
    std::vector<Textbox> text;
    text.push_back(Textbox(20,20,20));
    text.push_back(Textbox(20,20,60));
    text[0].Change("Уровень башни  ");
    text[1].Change("Текущая длина платформы");


    sf::RectangleShape back;
    back.setSize(sf::Vector2f(500,300));
    back.setOutlineThickness(4.f);
    back.setOutlineColor(sf::Color::Black);
    back.setPosition(10.f,10.f);
    back.setFillColor(sf::Color(0,0,0,20));

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = clock.getElapsedTime();
        window.clear();
        while (window.pollEvent(event))
        {
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                    // key pressed
                case sf::Event::KeyPressed:
                    if (current_step == 1 || current_step == 3) {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                                current_step = 2;
                                plat.Setbase();
                                blocks.clear();
                                clock.restart();
                                blocks.push_back(Blocks(800, 1450, 400,t));
                            }
                            break;
                        }
                    else {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            if (plat.MoveUp()) {
                                t += 5;
                                plat.Color(t);
                                blocks.push_back(Blocks(plat.Getleftx(), plat.Gety() + 50, plat.Getdelta(),t));
                                clock.restart();
                                std::cout << "Уровень башни = " << plat.Getlevel() << std::endl;
                                std::cout << "Длина платформы = " << plat.Getdelta() << "\n" << "-----" << std::endl;
                            }
                            else {

                                int level = plat.Getlevel();
                                int wide = 50;
                                if (level >= 20) {
                                    wide = 1000 / level;
                                }
                                for (short int i = 0; i < blocks.size(); i++) {
                                    blocks[i].Change(wide, i);

                                }
                                current_step = 3;
                            }
                        }
                    }
                    break;

                    // we don't process other types of events
                default:
                    break;
            }
        }

        window.draw(backgrounds);
        window.draw(back);
        switch (current_step) {
            case 1:
                blocks.clear();
                clock.restart();
                plat.Color(t);
                blocks.push_back(Blocks(800,1450,400,t));
                break;

            case 2:
                if (plat.Move(time.asSeconds())) {
                    clock.restart();
                }
                for (int i = 0; i < blocks.size(); i++) {
                    window.draw(blocks[i].GetBlock());
                }
                window.draw(plat.GetPlatform());
                text[0].Change("Уровень башни = " + plat.Getlevel());
                text[1].Change("Текущая длина платформы " + (int)plat.Getdelta());
                Lowit(&blocks,&plat);

                break;

            case 3:
                for (int i = 0; i < blocks.size(); i++) {
                    window.draw(blocks[i].GetBlock());
                }
                break;
        }
        //window.draw(text[0].Gettext());
        //window.draw(text[1].Gettext());
        window.display();
    }
    blocks.clear();
    text.clear();

    return 0;
}
