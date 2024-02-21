// Copyright Adam Warden 2023

#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
 public:
    CelestialBody();
    CelestialBody(double posX, double posY, double velX, double velY,
    double mass, const std::string& imageFile);
    ~CelestialBody();

    void setWindowSize(int dimension);
    void setUniverseScale(double scale);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    friend std::istream &operator>>(std::istream &input, CelestialBody &arg);
    friend std::ostream &operator<<(std::ostream &output, const CelestialBody &arg);

    void setPositionX(double x) { positionX = x; }
    void setPositionY(double y) { positionY = y; }
    void setVelocityX(double x) { velocityX = x; }
    void setVelocityY(double y) { velocityY = y; }
    void setMass(double m) { bodyMass = m; }

    double getPositionX() const { return positionX; }
    double getPositionY() const { return positionY; }
    double getVelocityX() const { return velocityX; }
    double getVelocityY() const { return velocityY; }
    double getMass() const { return bodyMass; }
    const std::string& getImageFile() const { return imageFile; }

 private:
    double uniScale;
    int viewportDimension;
    double positionX, positionY;
    double velocityX, velocityY;
    double bodyMass;
    sf::Texture textureObj;
    std::string imageFile;
    std::string fileName;
    sf::Sprite spriteObj;
};
