// Copyright Adam Warden 2023

#define BOOST_TEST_MODULE NBodyTests
#include <boost/test/included/unit_test.hpp>
#include "CelestialBody.hpp"

BOOST_AUTO_TEST_CASE(test_position_and_velocity) {
    CelestialBody body(1.0, 2.0, 3.0, 4.0, 5.0, "earth.gif");

    BOOST_CHECK_CLOSE(body.getPositionX(), 1.0, 0.01);
    BOOST_CHECK_CLOSE(body.getPositionY(), 2.0, 0.01);
    BOOST_CHECK_CLOSE(body.getVelocityX(), 3.0, 0.01);
    BOOST_CHECK_CLOSE(body.getVelocityY(), 4.0, 0.01);
}

BOOST_AUTO_TEST_CASE(test_mass) {
    CelestialBody body(1.0, 2.0, 3.0, 4.0, 5.0, "earth.gif");

    BOOST_CHECK_CLOSE(body.getMass(), 5.0, 0.01);
}

BOOST_AUTO_TEST_CASE(test_image_file) {
    CelestialBody body(1.0, 2.0, 3.0, 4.0, 5.0, "earth.gif");

    BOOST_CHECK_EQUAL(body.getImageFile(), "earth.gif");
}
