//
// Created by noam on 24/01/17.
//

#include "InputParser.h"

InputParser::InputParser() {
    this->regexes = new map<string, regex>();
}

InputParser::~InputParser() {
    delete this->regexes;
}

void InputParser::addRegex(string key, string regex) {
    boost::regex r = boost::regex(regex);
    (*this->regexes)[key] = r;
}

bool InputParser::checkInput(string regexKey, string input) {
    regex regex =  (*this->regexes)[regexKey];
    return regex_match(input, regex);
}

bool InputParser::checkInput(boost::regex r, string input) {
    return regex_match(input, r);
}

