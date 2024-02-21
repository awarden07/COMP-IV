// Copyright 2023 Adam Warden
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png")) {
        return EXIT_FAILURE;
    }

    sf :: Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(400, 400);

    sprite.setScale(0.4f, 0.4f);

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, 0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-0.1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(0.1, 0);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            shape.setFillColor(sf::Color::Red);
        } else {
            shape.setFillColor(sf::Color::Green);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            sprite.rotate(0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            sprite.rotate(-0.1);
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
