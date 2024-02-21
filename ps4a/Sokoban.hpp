// Copyright Adam Warden 2023

#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#define pNorth "player_08.png"
#define pSouth "player_05.png"
#define pEast "player_17.png"
#define pWest "player_20.png"
#define emptyGround "ground_01.png"
#define block "block_06.png"
#define crate "crate_03.png"
#define storageGround "ground_04.png"
#define environment "environment_03.png"

typedef enum {
    Up, 
    Down, 
    Right, 
    Left
} Direction;

class Sokoban : public sf::Drawable {
 public:
    Sokoban();
    explicit Sokoban(std::string file);

    int width();
    int height();

    void movePlayer(Direction direction);

    friend std::istream& operator>> (std::istream& in, Sokoban& sokoban);
    friend std::ostream& operator<<(std::ostream& os, const Sokoban& sokoban);

    sf::Texture loadTexture(const std::string& filePath) const;

    int getHeight() const { return _height; } 
    int getWidth() const { return _width; }

    char getCell(int row, int col) const { return level[row][col]; }

    bool isWon() const;

 private:
    int _height;
    int _width;
    std::string _level;

    std::vector<std::vector<char>> level;

    sf::Texture pNorthTexture;
    sf::Texture pSouthTexture;
    sf::Texture pEastTexture;
    sf::Texture pWestTexture;
    sf::Texture emptyGroundTexture;
    sf::Texture blockTexture;
    sf::Texture crateTexture;
    sf::Texture storageGroundTexture;
    sf::Texture environmentTexture;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
