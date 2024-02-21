// Copyright 2023 Adam Warden

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

int main(int argc, char* argv[]) {
    std :: string cmdline = "Use: ./PhotoMagic <input-file> <output-file> <password>";
    std :: cout << cmdline << std :: endl;
    std :: string input_file = argv[1];
    std :: string output_file = argv[2];
    std :: string password = argv[3];
    FibLFSR lfsr(password);
    sf :: Image image;
    if (!image.loadFromFile(input_file)) {
        std :: cout << "Error loading image" << std :: endl;
        return -1;
    }
    PhotoMagic::transform(image, &lfsr);
    if (!image.saveToFile(output_file)) {
        std :: cout << "Error saving image" << std :: endl;
        return -1;
    }
    sf :: Texture texture1;
    if (!texture1.loadFromFile(input_file)) {
        std :: cout << "Error loading texture" << std :: endl;
        return -1;
    }
    sf:: Sprite sprite_in;
    sprite_in.setTexture(texture1);
    sf :: Texture texture2;
    if (!texture2.loadFromFile(output_file)) {
        std :: cout << "Error loading texture" << std :: endl;
        return -1;
    }
    sf:: Sprite sprite_out;
    sprite_out.setTexture(texture2);
    sf :: RenderWindow window1(sf :: VideoMode(image.getSize().x, image.getSize().y), "Original");
    sf :: RenderWindow window2(sf :: VideoMode(image.getSize().x, image.getSize().y),
    "Transformed");
    while (window1.isOpen() && window2.isOpen()) {
        sf :: Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf :: Event :: Closed) {
                window1.close();
            }
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf :: Event :: Closed) {
                window2.close();
            }
        }
        window1.clear();
        window1.draw(sprite_in);
        window1.display();
        window2.clear();
        window2.draw(sprite_out);
        window2.display();
    }
    return 0;
}
