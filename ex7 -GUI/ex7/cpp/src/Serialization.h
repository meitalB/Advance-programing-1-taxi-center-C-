//
// Created by noam on 29/12/16.
//

#ifndef TAXI_CENTER_SERIALIZATION_H
#define TAXI_CENTER_SERIALIZATION_H

#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace std;
using namespace boost::archive;
using namespace boost::iostreams;
//deserialize an object
template<class T>
T *deserialize(string serial_str) {
    T *p;
    unsigned long x = serial_str.size();
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), x);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s(device);
    boost::archive::binary_iarchive ia(s);
    ia >> p;

    return p;
}
// serialize an object
template<class T>
string serialize(T *object) {
    std::string serial_str;

    boost::iostreams::back_insert_device<std::string> insertDevice(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(insertDevice);
    boost::archive::binary_oarchive oa(s);
    oa << object;
    s.flush();

    return serial_str;
}

#endif //TAXI_CENTER_SERIALIZATION_H
