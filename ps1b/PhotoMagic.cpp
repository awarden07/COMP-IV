// Copyright 2023 Adam Warden

#include <iostream>

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

void PhotoMagic::transform(sf::Image & image, FibLFSR* lfsr) {
    sf::Color p;
    for (unsigned int x = 0; x < image.getSize().x; x++) {
        for (unsigned int y = 0; y < image.getSize().y; y++) {
            p = image.getPixel(x, y);
            p.r = p.r ^ lfsr->generate(8);
            p.g = p.g ^ lfsr->generate(8);
            p.b = p.b ^ lfsr->generate(8);
            image.setPixel(x, y, p);
        }
    }
}
