// Copyright 2023 Adam Warden

#pragma once

#include <iostream>
#include <algorithm>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

// use PhotoMagic namespace
namespace PhotoMagic {
    // transform function
    void transform(sf::Image& image, FibLFSR* lfsr);
}
