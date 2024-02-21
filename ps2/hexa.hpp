// Copyright 2023 Adam Warden

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Hexa : public sf::Drawable {
 public:
    Hexa(double L, int N);

 private:
    std::vector<sf::ConvexShape> hexaflake(double L, int N, sf::Vector2f center);
    sf::ConvexShape createHexagon(double L, sf::Vector2f center);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
    std::vector<sf::ConvexShape> hexagons;
};
