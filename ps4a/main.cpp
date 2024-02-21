// Copyright Adam Warden 2023

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"

int main(int argc, char* argv[]) {
    sf::Clock time;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
        return 1;
    }

    if (argc != 2) {
        std::cout << "Usage: ./Sokoban (filename.txt)" << std::endl;
        return 1;
    }

    Sokoban sokoban(argv[1]);

    sf::RenderWindow window(sf::VideoMode(sokoban.width() * 64, sokoban.height() * 64), "Sokoban");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                // Handle player movement based on arrow keys
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        sokoban.movePlayer(Direction::Up);
                        break;
                    case sf::Keyboard::Down:
                        sokoban.movePlayer(Direction::Down);
                        break;
                    case sf::Keyboard::Left:
                        sokoban.movePlayer(Direction::Left);
                        break;
                    case sf::Keyboard::Right:
                        sokoban.movePlayer(Direction::Right);
                        break;
                    default:
                        break;
                }
            }
        }

        // Check for win condition
        if (sokoban.isWon()) {
            std::cout << "You win!" << std::endl;
            window.close();
        }
        sf::Time elapsed = time.getElapsedTime();
        int seconds = elapsed.asSeconds();
        int minutes = seconds / 60;
        seconds %= 60;
        text.setString(std::to_string(minutes) + ":" + std::to_string(seconds));

        window.clear();
        window.draw(sokoban);
        window.draw(text);
        window.display();
    }

    return 0;
}
