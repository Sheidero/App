#include <SFML/Graphics.hpp>
#include <iostream>
#include "inc/Blocks.hpp"
#include "inc/Platforma.hpp"
#include "inc/func.hpp"

int main()
{
    sf::Texture texture;
    texture.loadFromFile("image.png");
    sf::RenderWindow window(sf::VideoMode(2000, 1500), "Stack");
    sf::Image image;
    image.loadFromFile("image.png");

    std::vector<Blocks> blocks = {};
    Platforma plat;
    sf::Clock clock;
    short int current_step = 1;
    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = clock.getElapsedTime();
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
                            }
                            blocks.clear();
                            clock.restart();
                            blocks.push_back(Blocks(800,1450,400));
                            std::cout << "perfect" << std::endl;
                            break;
                        }
                    else {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            if (plat.MoveUp()) {
                                blocks.push_back(Blocks(plat.Getleftx(), plat.Gety() + 50, plat.Getdelta()));
                                clock.restart();
                            }
                            else {
                                current_step = 3;
                            }
                        }
                    }
                    std::cout << "ideal" << std::endl;
                    break;

                    // we don't process other types of events
                default:
                    break;
            }
        }

        window.clear();

        switch (current_step) {
            case 1:
                blocks.clear();
                clock.restart();
                blocks.push_back(Blocks(800,1450,400));
                break;

            case 2:
                if (plat.Move(time.asSeconds())) {
                    clock.restart();
                }
                for (int i = 0; i < blocks.size(); i++) {
                    window.draw(blocks[i].GetBlock());
                }
                window.draw(plat.GetPlatform());
                Lowit(&blocks,&plat);

                break;

            case 3:
                for (int i = 0; i < blocks.size(); i++) {

                }
                break;

            default:
                break;
        }

        window.display();
    }

    return 0;
}
