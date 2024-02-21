// Copyright Adam Warden 2023

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

// 2 unit tests for operator<<
BOOST_AUTO_TEST_CASE(testOperator1) {
  FibLFSR l("1011011000110110");
  std::stringstream ss;
  ss << l;
  BOOST_REQUIRE_EQUAL(ss.str(), "1011011000110110");
}

BOOST_AUTO_TEST_CASE(testOperator2) {
  FibLFSR l("1011011000110110");
  std::stringstream ss;
  ss << l;
  BOOST_REQUIRE_EQUAL(ss.str(), "1011011000110110");
}

// 2 new tests for constructor
BOOST_AUTO_TEST_CASE(testConstructor1) {
  BOOST_REQUIRE_THROW(FibLFSR l(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testConstructor2) {
  BOOST_REQUIRE_THROW(FibLFSR l("101101100011011"), std::invalid_argument);
}
