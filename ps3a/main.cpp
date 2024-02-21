// Copyright Adam Warden 2023

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include "Universe.hpp"

int main() {
    int winDim = 500;
    double spaceSize;
    std::vector<CelestialBody> bodies;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("galaxy.png")) {
        std::cout << "Image could not load" << std::endl;
    }

    sf::Sprite background(backgroundTexture);

    int numBodies;
    std::cin >> numBodies;

    std::cin >> spaceSize;

    Universe universe;
    universe.setViewportDimension(winDim);
    universe.setUniverseScale(spaceSize);

    for (int i = 0; i < numBodies; ++i) {
        CelestialBody body;
        std::cin >> body;
        body.setWindowSize(winDim);
        body.setUniverseScale(spaceSize);
        universe.addCelestialBody(body);
    }

    sf::RenderWindow window(sf::VideoMode(winDim, winDim), "Universe");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(universe);

        window.display();
    }

    return 0;
}
