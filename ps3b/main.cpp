// Copyright Adam Warden 2023

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include "Universe.hpp"

class SpaceSimulation {
 private:
    int winDim = 500;
    double spaceSize;
    std::vector<CelestialBody> bodies;
    const double G = 6.67e-11;  // Gravitational constant

 public:
    void getBodyCount(int &count) {
        std::string inputLine;
        std::getline(std::cin, inputLine);
        count = std::stoi(inputLine);
    }

    void getSpaceDimensions(double &dim) {
        std::string inputLine;
        std::getline(std::cin, inputLine);
        dim = std::stod(inputLine);
    }

    void step(double deltaTime) {
        for (auto &body1 : bodies) {
            double netforceX = 0.0, netforceY = 0.0;
            for (auto &body2 : bodies) {
                if (&body1 != &body2) {
                    double dx = body2.getPositionX() - body1.getPositionX();
                    double dy = body2.getPositionY() - body1.getPositionY();
                    double distance = std::sqrt(dx * dx + dy * dy);
                    double force = (G * body1.getMass() * body2.getMass()) / (distance * distance);
                    netforceX += force * (dx / distance);
                    netforceY += force * (dy / distance);
                }
            }
            body1.setVelocityX(body1.getVelocityX() + (netforceX / body1.getMass()) * deltaTime);
            body1.setVelocityY(body1.getVelocityY() + (netforceY / body1.getMass()) * deltaTime);
        }
        for (auto &body : bodies) {
            body.setPositionX(body.getPositionX() + body.getVelocityX() * deltaTime);
            body.setPositionY(body.getPositionY() + body.getVelocityY() * deltaTime);
        }
    }

    void run() {
        int numBodies;
        getBodyCount(numBodies);
        getSpaceDimensions(spaceSize);

        Universe universe;
        universe.setViewportDimension(winDim);
        universe.setUniverseScale(spaceSize);

        bodies.resize(numBodies);

        for (int i = 0; i < numBodies; ++i) {
            CelestialBody body;
            std::cin >> body;
            body.setWindowSize(winDim);
            body.setUniverseScale(spaceSize);
            universe.addCelestialBody(body);
        }

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("galaxy.png")) {
            std::cout << "Image could not load" << std::endl;
        }

        sf::Sprite background(backgroundTexture);

        sf::RenderWindow window(sf::VideoMode(winDim, winDim), "Universe");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            step(25000.0 / 2);  // Adjust this value or get it from user input

            window.clear();
            window.draw(background);
            window.draw(universe);

            window.display();
        }
    }
};

int main() {
    SpaceSimulation sim;
    sim.run();
    return 0;
}
