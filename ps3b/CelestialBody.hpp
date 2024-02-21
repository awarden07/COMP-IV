// Copyright Adam Warden 2023

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
 public:
    CelestialBody();
    CelestialBody(double posX, double posY, double velX, double velY,
    double mass, const std::string& file);
    ~CelestialBody();

    void setWindowSize(int dimension);
    void setUniverseSize(double size);
    void setUniverseScale(double scale);
    void setVelocityX(double velX);
    void setVelocityY(double velY);
    void setPositionX(double posX);
    void setPositionY(double posY);
    void setMass(double mass);
    std::string imageFileName;


    void updateVelocity(double forceX, double forceY, double deltaTime);
    void updatePosition(double deltaTime);

    // Add these getters
    double getPositionX() const;
    double getPositionY() const;
    double getMass() const;
    double getVelocityX() const;
    double getVelocityY() const;

    friend std::istream &operator>>(std::istream &input, CelestialBody &body);
    friend std::ostream &operator<<(std::ostream &output, const CelestialBody &body);

 private:
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double bodyMass;
    std::string imageFile;

    sf::Texture textureObj;
    sf::Sprite spriteObj;
    int viewportDimension;
    double uniScale;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
