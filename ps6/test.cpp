// Copyright Adam Warden 2023

#define BOOST_TEST_MODULE RandWriterTests
#include <boost/test/included/unit_test.hpp>
#include "RandWriter.hpp"

BOOST_AUTO_TEST_CASE(test_order_and_length) {
    RandWriter rWriter("hello", 2, 5);
    BOOST_TEST(rWriter.getOrder() == 2);
}

BOOST_AUTO_TEST_CASE(test_alphabet) {
    RandWriter rWriter("hello", 2, 5);
    BOOST_TEST(rWriter.getAlphabet() == "helo");
}

BOOST_AUTO_TEST_CASE(test_ngram) {
    RandWriter rWriter("hello", 2, 5);
    BOOST_TEST(rWriter.getCurrentNgram().length() == 2);
}

BOOST_AUTO_TEST_CASE(test_generate_text) {
    RandWriter rWriter("hello", 2, 5);
    std::string generatedText = rWriter.generateText("he", 3);
    BOOST_TEST(generatedText.length() == 3);
}

BOOST_AUTO_TEST_CASE(test_frequency) {
    RandWriter rWriter("hello", 2, 5);
    BOOST_TEST(rWriter.getFrequency("he") == 1);
    BOOST_TEST(rWriter.getFrequency("he", 'l') == 1);
}

BOOST_AUTO_TEST_CASE(test_invalid_argument) {
    RandWriter rWriter("hello", 2, 5);
    BOOST_CHECK_THROW(rWriter.getFrequency("hello", 'l'), std::invalid_argument);
    BOOST_CHECK_THROW(rWriter.getFrequency("hello"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_mapping) {
    RandWriter rWriter("hello", 2, 5);
    rWriter.initializeMapping();
    // Add specific tests for mapping if needed
}

BOOST_AUTO_TEST_CASE(test_operator) {
    RandWriter rWriter("hello", 2, 5);
    std::stringstream ss;
    ss << rWriter;
    BOOST_TEST(ss.str() == "Order: 2\nLength: 5\nText: hello\n");
}
