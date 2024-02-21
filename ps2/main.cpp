// Copyright 2023 Adam Warden

#include <iostream>
#include <SFML/Graphics.hpp>
#include "hexa.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <L> <N>\n";
        return 1;
    }

    double L = std::stod(argv[1]);  // length of the side of the hexagon
    int N = std::stoi(argv[2]);  // number of iterations

    sf::RenderWindow window(sf::VideoMode(4 * L, 4 * L), "Hexaflake");
    Hexa hexa(L, N);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(hexa);
        window.display();
    }

    return 0;
}
