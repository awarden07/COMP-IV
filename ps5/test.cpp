// Copyright Adam Warden 2023

#define BOOST_TEST_MODULE EDistanceTests
#include <boost/test/included/unit_test.hpp>
#include "EDistance.hpp"

BOOST_AUTO_TEST_CASE(defaultConstructorTest) {
    EDistance sequenceDistance;
    BOOST_CHECK_EQUAL(sequenceDistance.optDistance(), 0);
    BOOST_CHECK_EQUAL(sequenceDistance.alignment(), "");
}

BOOST_AUTO_TEST_CASE(valueConstructorTest) {
    EDistance sequenceDistance("hello", "world");
    BOOST_CHECK_EQUAL(sequenceDistance.optDistance(), 4);
    BOOST_CHECK_EQUAL(sequenceDistance.alignment(),
    "h w 1\ne o 1\nl r 1\nl l 0\no d 1\n");
}

BOOST_AUTO_TEST_CASE(penaltyTest) {
    BOOST_CHECK_EQUAL(EDistance::penalty('a', 'b'), 1);
    BOOST_CHECK_EQUAL(EDistance::penalty('a', 'a'), 0);
    BOOST_CHECK_EQUAL(EDistance::penalty('a', 'A'), 1);
    BOOST_CHECK_EQUAL(EDistance::penalty('a', ' '), 1);
    BOOST_CHECK_EQUAL(EDistance::penalty(' ', ' '), 0);
}

BOOST_AUTO_TEST_CASE(min3Test) {
    BOOST_CHECK_EQUAL(EDistance::min3(1, 2, 3), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(2, 1, 3), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(3, 2, 1), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(1, 1, 1), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(2, 2, 2), 2);
    BOOST_CHECK_EQUAL(EDistance::min3(5, 5, 5), 5);
    BOOST_CHECK_EQUAL(EDistance::min3(3, 1, 2), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(5, 5, 3), 3);
    BOOST_CHECK_EQUAL(EDistance::min3(7, 3, 5), 3);
}

BOOST_AUTO_TEST_CASE(optDistanceTest) {
    EDistance sequenceDistance("kitten", "sitting");
    BOOST_CHECK_EQUAL(sequenceDistance.optDistance(), 3);
}

BOOST_AUTO_TEST_CASE(alignmentTest) {
    EDistance sequenceDistance("kitten", "sitting");
    BOOST_CHECK_EQUAL(sequenceDistance.alignment(),
    "k s 1\ni i 0\nt t 0\nt t 0\ne i 1\nn n 0");
}

BOOST_AUTO_TEST_CASE(calculateDifferenceTest) {
    BOOST_CHECK_EQUAL(EDistance::calculateDifference('a', 'b'), 1);
    BOOST_CHECK_EQUAL(EDistance::calculateDifference('a', 'a'), 0);
    BOOST_CHECK_EQUAL(EDistance::calculateDifference('a', 'A'), 1);
    BOOST_CHECK_EQUAL(EDistance::calculateDifference('a', ' '), 1);
    BOOST_CHECK_EQUAL(EDistance::calculateDifference(' ', ' '), 0);
}
