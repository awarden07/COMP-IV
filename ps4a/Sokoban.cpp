// Copyright Adam Warden 2023

#include <algorithm>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"

Sokoban::Sokoban() {
    _level = "";
}

Sokoban::Sokoban(std::string file) : _level(file) {
    _level = file;
    if (!pSouthTexture.loadFromFile(pSouth) ||
        !emptyGroundTexture.loadFromFile(emptyGround) ||
        !blockTexture.loadFromFile(block) ||
        !crateTexture.loadFromFile(crate) ||
        !storageGroundTexture.loadFromFile(storageGround) ||
        !environmentTexture.loadFromFile(environment)) {
        std::cout << "Error loading texture" << std::endl;
        return;
    }

    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> *this;
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
}

int Sokoban::width() { return _width; }

int Sokoban::height() { return _height; }

std::istream& operator>>(std::istream& in, Sokoban& sokoban) {
    std::string line;
    std::getline(in, line);

    std::istringstream iss(line);
    iss >> sokoban._height >> sokoban._width;
    sokoban.level.resize(sokoban._height, std::vector<char>(sokoban._width));

    for (int i = 0; i < sokoban._height; ++i) {
        std::getline(in, line);
        for (int j = 0; j < sokoban._width; ++j) {
            char cell = line[j];
            sokoban.level[i][j] = cell;
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& os, const Sokoban& sokoban) {
    for (int i = 0; i < sokoban._width; ++i) {
        for (int j = 0; j < sokoban._height; ++j) {
            char cell = sokoban.level[i][j];

            switch (cell) {
                case '.':
                    os << ".";
                    break;
                case '#':
                    os << "#";
                    break;
                case 'A':
                    os << "A";
                    break;
                case 'a':
                    os << "a";
                    break;
                case '@':
                    os << "@";
                    break;
                default:
                    break;
            }
        }
        os << std::endl;
    }
    return os;
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    std::map<char, sf::Texture> textureMap;
    textureMap['#'] = loadTexture("block_06.png");
    textureMap['.'] = loadTexture("ground_01.png");
    textureMap['A'] = loadTexture("crate_03.png");
    textureMap['a'] = loadTexture("ground_04.png");
    textureMap['@'] = loadTexture("player_05.png");

    int spriteSize = 64;

    auto drawCell = [&](char cell, int x, int y) {
        sf::Sprite sprite(textureMap[cell]);
        sprite.setPosition(x * spriteSize, y * spriteSize);
        target.draw(sprite);
    };

    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            char cell = level[i][j];
            drawCell(cell, j, i);
        }
    }
}

sf::Texture Sokoban::loadTexture(const std::string& filePath) const {
    sf::Texture texture;
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Error loading texture: " << filePath << std::endl;
    }
    return texture;
}


void Sokoban::movePlayer(Direction direction) {
    int playerRow = 0;
    int playerCol = 0;

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            if (getCell(i, j) == '@') {
                playerRow = i;
                playerCol = j;
            }
        }
    }

    switch (direction) {
        case Up:
            if (getCell(playerRow - 1, playerCol) == '.') {
                level[playerRow - 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow - 1, playerCol) == 'A' &&
                       getCell(playerRow - 2, playerCol) == '.') {
                level[playerRow - 2][playerCol] = 'A';
                level[playerRow - 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow - 1, playerCol) == 'A' &&
                       getCell(playerRow - 2, playerCol) == 'a') {
                level[playerRow - 2][playerCol] = 'A';
                level[playerRow - 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow - 1, playerCol) == 'a' &&
                       getCell(playerRow - 2, playerCol) == '.') {
                level[playerRow - 2][playerCol] = 'a';
                level[playerRow - 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow - 1, playerCol) == 'a' &&
                       getCell(playerRow - 2, playerCol) == 'a') {
                level[playerRow - 2][playerCol] = 'a';
                level[playerRow - 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            }
            break;
        case Down:
            if (getCell(playerRow + 1, playerCol) == '.') {
                level[playerRow + 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow + 1, playerCol) == 'A' &&
                       getCell(playerRow + 2, playerCol) == '.') {
                level[playerRow + 2][playerCol] = 'A';
                level[playerRow + 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow + 1, playerCol) == 'A' &&
                       getCell(playerRow + 2, playerCol) == 'a') {
                level[playerRow + 2][playerCol] = 'A';
                level[playerRow + 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow + 1, playerCol) == 'a' &&
                       getCell(playerRow + 2, playerCol) == '.') {
                level[playerRow + 2][playerCol] = 'a';
                level[playerRow + 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow + 1, playerCol) == 'a' &&
                       getCell(playerRow + 2, playerCol) == 'a') {
                level[playerRow + 2][playerCol] = 'a';
                level[playerRow + 1][playerCol] = '@';
                level[playerRow][playerCol] = '.';
            }
            break;
        case Right:
            if (getCell(playerRow, playerCol + 1) == '.') {
                level[playerRow][playerCol + 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol + 1) == 'A' &&
                       getCell(playerRow, playerCol + 2) == '.') {
                level[playerRow][playerCol + 2] = 'A';
                level[playerRow][playerCol + 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol + 1) == 'A' &&
                       getCell(playerRow, playerCol + 2) == 'a') {
                level[playerRow][playerCol + 2] = 'A';
                level[playerRow][playerCol + 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol + 1) == 'a' &&
                       getCell(playerRow, playerCol + 2) == '.') {
                level[playerRow][playerCol + 2] = 'a';
                level[playerRow][playerCol + 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol + 1) == 'a' &&
                       getCell(playerRow, playerCol + 2) == 'a') {
                level[playerRow][playerCol + 2] = 'a';
                level[playerRow][playerCol + 1] = '@';
                level[playerRow][playerCol] = '.';
            }
            break;
        case Left:
            if (getCell(playerRow, playerCol - 1) == '.') {
                level[playerRow][playerCol - 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol - 1) == 'A' &&
                       getCell(playerRow, playerCol - 2) == '.') {
                level[playerRow][playerCol - 2] = 'A';
                level[playerRow][playerCol - 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol - 1) == 'A' &&
                       getCell(playerRow, playerCol - 2) == 'a') {
                level[playerRow][playerCol - 2] = 'A';
                level[playerRow][playerCol - 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol - 1) == 'a' &&
                       getCell(playerRow, playerCol - 2) == '.') {
                level[playerRow][playerCol - 2] = 'a';
                level[playerRow][playerCol - 1] = '@';
                level[playerRow][playerCol] = '.';
            } else if (getCell(playerRow, playerCol - 1) == 'a' &&
                       getCell(playerRow, playerCol - 2) == 'a') {
                level[playerRow][playerCol - 2] = 'a';
                level[playerRow][playerCol - 1] = '@';
                level[playerRow][playerCol] = '.';
            }
            break;
    }
}

bool Sokoban::isWon() const {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            if (level[i][j] == 'A') {
                return false;
            }
        }
    }
    return true;
}
