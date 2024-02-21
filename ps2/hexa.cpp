// Copyright 2023 Adam Warden

#include "hexa.hpp"
#include <cmath>

Hexa::Hexa(double L, int N) : hexagons(hexaflake(L, N, sf::Vector2f(L, L))) {}

std::vector<sf::ConvexShape> Hexa::hexaflake(double L, int N, sf::Vector2f center) {
    std::vector<sf::ConvexShape> hexagons;
    if (N == 0) {
        hexagons.push_back(createHexagon(L, center));
    } else {
        double newL = L / 3.0;  // length of the new hexagons
        for (int i = -1; i < 6; ++i) {  // iterate over the 6 hexagons that surround
            double angle = M_PI / 3.0 * i - M_PI / 2.0;  // angle of the current hexagon
            double dx = 2.0 * newL * cos(angle);  // x distance from the center of hexagons
            double dy = 2.0 * newL * sin(angle);  // y distance from the center of hexagons
            auto subHexagons = hexaflake(newL, N - 1, sf::Vector2f(center.x + dx, center.y + dy));
            hexagons.insert(hexagons.end(), subHexagons.begin(), subHexagons.end());
        }
    }
    return hexagons;
}

sf::ConvexShape Hexa::createHexagon(double L, sf::Vector2f center) {
    sf::ConvexShape hexagon(6);

    for (int i = 0; i < 6; ++i) {
        double angle = M_PI / 3.0 * i - M_PI / 2.0;  // angle of the current hexagon
        double dx = L * cos(angle);  // x distance from the center of the hexagons
        double dy = L * sin(angle);  // y distance from the center of the hexagons
        hexagon.setPoint(i, sf::Vector2f(center.x + dx, center.y + dy));
    }

    return hexagon;
}

void Hexa::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& hexagon : hexagons) {
        target.draw(hexagon, states);  // draw each hexagon
    }
}
