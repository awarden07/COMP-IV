// Copyright Adam Warden 2023

#pragma once

#include <vector>
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>

class Universe : public sf::Drawable {
 private:
    std::vector<CelestialBody> spaceEntities;
    double uniScale;
    int viewportDimension;

 public:
    Universe();
    ~Universe();

    void addCelestialBody(const CelestialBody& entity);
    int getEntityCount() const;
    void setUniverseScale(double scale);
    void setViewportDimension(int dimension);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    friend std::istream& operator>>(std::istream& input, Universe& uni);
    friend std::ostream& operator<<(std::ostream& output, const Universe& uni);
};
