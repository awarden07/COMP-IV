// Copyright Adam Warden 2023
#define BOOST_TEST_MODULE NBodyTests
#include <iostream>
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "CelestialBody.hpp"

// Test the CelestialBody class default constructor
BOOST_AUTO_TEST_CASE(default_constructor_test) {
    CelestialBody body;

    BOOST_CHECK_EQUAL(body.getPositionX(), 0.0);
    BOOST_CHECK_EQUAL(body.getPositionY(), 0.0);
    BOOST_CHECK_EQUAL(body.getVelocityX(), 0.0);
    BOOST_CHECK_EQUAL(body.getVelocityY(), 0.0);
    BOOST_CHECK_EQUAL(body.getMass(), 0.0);
    BOOST_CHECK_EQUAL(body.imageFileName, "");
}

// Test the CelestialBody class parameterized constructor
BOOST_AUTO_TEST_CASE(setters_test) {
    CelestialBody body;

    body.setPositionX(5.0);
    body.setPositionY(6.0);
    body.setVelocityX(7.0);
    body.setVelocityY(8.0);
    body.setMass(9.0);
    body.imageFileName = "test.gif";

    BOOST_CHECK_EQUAL(body.getPositionX(), 5.0);
    BOOST_CHECK_EQUAL(body.getPositionY(), 6.0);
    BOOST_CHECK_EQUAL(body.getVelocityX(), 7.0);
    BOOST_CHECK_EQUAL(body.getVelocityY(), 8.0);
    BOOST_CHECK_EQUAL(body.getMass(), 9.0);
    BOOST_CHECK_EQUAL(body.imageFileName, "test.gif");
}

// Test the CelestialBody class copy constructor
BOOST_AUTO_TEST_CASE(copy_constructor_test) {
    CelestialBody original(1.0, 2.0, 3.0, 4.0, 5.0, "test.gif");
    CelestialBody copy = original;

    BOOST_CHECK_EQUAL(copy.getPositionX(), original.getPositionX());
    BOOST_CHECK_EQUAL(copy.getPositionY(), original.getPositionY());
    BOOST_CHECK_EQUAL(copy.getVelocityX(), original.getVelocityX());
    BOOST_CHECK_EQUAL(copy.getVelocityY(), original.getVelocityY());
    BOOST_CHECK_EQUAL(copy.getMass(), original.getMass());
    BOOST_CHECK_EQUAL(copy.imageFileName, original.imageFileName);
}

// Test the CelestialBody class updatePosition function
BOOST_AUTO_TEST_CASE(update_position_test) {
    CelestialBody body(1.0, 1.0, 2.0, 3.0, 5.0, "test.gif");

    // Simulate movement for 1 time unit
    body.updatePosition(1.0);

    BOOST_CHECK_EQUAL(body.getPositionX(), 3.0);  // 1.0 + 2.0
    BOOST_CHECK_EQUAL(body.getPositionY(), 4.0);  // 1.0 + 3.0
}
