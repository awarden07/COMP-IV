// Copyright Adam Warden 2023

#include "Sokoban.hpp"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[]) {
    std::ifstream map_level(argv[1]);
    if (!map_level) {
        std::cout << "File not found" << std::endl;
        return 0;
    }

    Sokoban sokoban;
    map_level >> sokoban;

    sf::RenderWindow window(sf::VideoMode(sokoban.getX() * 64, sokoban.getY() * 64), "Sokoban");
    Sokoban temp = sokoban;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    sokoban = temp;
                    sokoban.reset(temp);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        if (!sokoban.isWon()) {
            
            //display the clock
            sf::Clock clock;
            sf::Time time = clock.getElapsedTime();
            std::cout << time.asSeconds() << std::endl;            

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sokoban.movePlayer(Left);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                       sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sokoban.movePlayer(Right);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                       sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sokoban.movePlayer(Up);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                       sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sokoban.movePlayer(Down);
            }
        }

        window.clear();
        window.draw(sokoban);

        if (sokoban.isWon()) {
            sf::Font font;
            if (!font.loadFromFile("arial_bold.ttf")) {
                return EXIT_FAILURE;
            }
            sf::Text text("You Win!", font, 50);
            text.setFillColor(sf::Color::White);
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
            text.setPosition(sf::Vector2f(sokoban.getX() * 32, sokoban.getY() * 32));
            window.draw(text);
            window.display();
        }

        window.display();
    }
    return 0;
}
