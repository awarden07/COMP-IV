// Copyright Adam Warden 2023

#include <iostream>
#include "CelestialBody.hpp"

CelestialBody::CelestialBody() : positionX(0), positionY(0), velocityX(0),
velocityY(0), bodyMass(0) { }

CelestialBody::CelestialBody(double posX, double posY, double velX, double velY,
double mass, const std::string& file)
    : positionX(posX), positionY(posY), velocityX(velX), velocityY(velY),
    bodyMass(mass), imageFile(file) {
    if (!textureObj.loadFromFile(file)) {
        std::cout << "Image could not load: '" << file << "'. Can't open file" << std::endl;
    } else {
        spriteObj.setTexture(textureObj);
    }
}

CelestialBody::~CelestialBody() { }

void CelestialBody::setWindowSize(int dimension) {
    viewportDimension = dimension;
}

void CelestialBody::setUniverseScale(double scale) {
    uniScale = scale;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Sprite sprite_temp = spriteObj;

    double ratio = (viewportDimension / 2) / uniScale;
    double rxpos = positionX * ratio + (viewportDimension / 2);
    double rypos = positionY * ratio + (viewportDimension / 2);

    sprite_temp.setPosition(rxpos, rypos);
    target.draw(sprite_temp);
}

std::istream &operator>>(std::istream &input, CelestialBody &body) {
    input >> body.positionX >> body.positionY >> body.velocityX >> body.velocityY >>
    body.bodyMass >> body.imageFile;

    if (!body.textureObj.loadFromFile(body.imageFile)) {
        std::cout << "Image could not load: '" << body.imageFile << "'. Can't open file" <<
        std::endl;
    } else {
        body.spriteObj.setTexture(body.textureObj);
    }

    return input;
}

std::ostream &operator<<(std::ostream &output, const CelestialBody &body) {
    output << body.positionX << " " << body.positionY << " " << body.velocityX << " "
    << body.velocityY << " " << body.bodyMass << " " << body.imageFile;

    return output;
}
