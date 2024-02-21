// Copyright Adam Warden 2023

#include "CelestialBody.hpp"
#include <iostream>

CelestialBody::CelestialBody() : positionX(0), positionY(0), velocityX(0),
velocityY(0), bodyMass(0) { }

CelestialBody::CelestialBody(double posX, double posY, double velX,
double velY, double mass, const std::string& file)
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

void CelestialBody::updateVelocity(double forceX, double forceY, double deltaTime) {
    if (bodyMass == 0) {
        std::cerr << "Error, the mass is zero, unable to update the velocity." << std::endl;
        return;
    }
    velocityX += forceX / bodyMass * deltaTime;
    velocityY += forceY / bodyMass * deltaTime;
}

void CelestialBody::updatePosition(double deltaTime) {
    positionX += velocityX * deltaTime;
    positionY += velocityY * deltaTime;
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

double CelestialBody::getPositionX() const {
    return positionX;
}

double CelestialBody::getPositionY() const {
    return positionY;
}

double CelestialBody::getMass() const {
    return bodyMass;
}

double CelestialBody::getVelocityX() const {
    return velocityX;
}

double CelestialBody::getVelocityY() const {
    return velocityY;
}

void CelestialBody::setVelocityX(double velX) {
    velocityX = velX;
}

void CelestialBody::setVelocityY(double velY) {
    velocityY = velY;
}

void CelestialBody::setPositionX(double posX) {
    positionX = posX;
}

void CelestialBody::setPositionY(double posY) {
    positionY = posY;
}

void CelestialBody::setMass(double mass) {
    bodyMass = mass;
}
