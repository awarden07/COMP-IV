// Copyright Aaron Roche 2023

#include "Universe.hpp"

Universe::Universe() : uniScale(0.0), viewportDimension(0) { }

Universe::~Universe() { }

int Universe::getEntityCount() const {
    return spaceEntities.size();
}

void Universe::addCelestialBody(const CelestialBody& entity) {
    spaceEntities.push_back(entity);
}

void Universe::setUniverseScale(double scale) {
    uniScale = scale;
    for (auto& entity : spaceEntities) {
        entity.setUniverseScale(scale);
    }
}

void Universe::setViewportDimension(int dimension) {
    viewportDimension = dimension;
    for (auto& entity : spaceEntities) {
        entity.setWindowSize(dimension);
    }
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& entity : spaceEntities) {
        target.draw(entity, states);
    }
}

std::istream& operator>>(std::istream& input, Universe& uni) {
    int n;
    double uniScale;
    input >> n >> uniScale;

    uni.setUniverseScale(uniScale);
    for (int i = 0; i < n; i++) {
        CelestialBody entity;
        input >> entity;
        uni.addCelestialBody(entity);
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Universe& uni) {
    output << uni.getEntityCount() << "\n" << uni.uniScale << "\n";
    for (const auto& entity : uni.spaceEntities) {
        output << entity << "\n";
    }

    return output;
}
