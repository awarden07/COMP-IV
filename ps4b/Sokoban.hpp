// Copyright Adam Warden 2023

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum Direction {Up, Down, Left, Right};

class Sokoban: public sf::Drawable {
 public:
    Sokoban();
    void movePlayer(Direction d);
    friend std::istream& operator>>(std::istream& in, Sokoban& s);
    friend std::ostream& operator<<(std::ostream& out, const Sokoban& s);
    int getX() const;
    int getY() const;
    const bool isWon() const;
    void reset(Sokoban& s);
    Sokoban(const Sokoban& s);
    void loadMap(const std::string& filename, Sokoban& s);
    ~Sokoban();
    Sokoban& operator=(const Sokoban& s);
    void Sokoban::timer(std::string& time);
 private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int x;
    int y;
    char *map;
};
