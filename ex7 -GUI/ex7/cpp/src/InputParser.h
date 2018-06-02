//
// Created by noam on 24/01/17.
//

#ifndef TAXI_CENTER_INPUTPARSER_H
#define TAXI_CENTER_INPUTPARSER_H

#include <boost/regex.hpp>
#include <string>
using namespace boost;
using namespace std;

class InputParser {
private:
    map<string, regex>* regexes;
//    const regex taxiCab = regex("\\d*,\\d*,[H,F,T,S],[R,B,G,W,P]");
//    const regex trip = regex("\\d*,\\d*,\\d*,\\d*,\\d*,\\d*,\\d*,\\d*");
//    const regex grid = regex("\\d* \\d*");
//    const regex driver = regex("\\d*,\\d*,[M,D,W,S],\\d*,\\d*");
public:
    InputParser();
    void addRegex(string key, string regex);
    bool checkInput(string regexKey, string input);
    bool checkInput(regex r, string input);
    ~InputParser();
};


#endif //TAXI_CENTER_INPUTPRASER_H
