/**
 * @file HelixExceptions.cpp
 * @author Florian LOPITAUX
 * @brief This file contains many custom exceptions classes implementation.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#include "../../include/exceptions/HelixExceptions.h"


/*
* ---------------------------------------------
* CUSTOM EXCEPTIONS
* ---------------------------------------------
*/

nsHelix::nsExceptions::HelixException::HelixException(const std::string & message) : msg(message) {}

const char * nsHelix::nsExceptions::HelixException::what() {
    return this->msg.c_str();
}

// --------------------------------------------

nsHelix::nsExceptions::HelixInitializationException::HelixInitializationException(const std::string & message) : msg(message) {}

const char * nsHelix::nsExceptions::HelixInitializationException::what() {
    return this->msg.c_str();
}

// --------------------------------------------

nsHelix::nsExceptions::NullPointerException::NullPointerException(const std::string & name) : name(name) {}

const char * nsHelix::nsExceptions::NullPointerException::what() {
    const std::string msg = "Exception thorwn because the '" + this->name + "' is null";

    return msg.c_str();
}

// --------------------------------------------

nsHelix::nsExceptions::FileNotFoundException::FileNotFoundException(const std::string & path) : path(path) {}

const char * nsHelix::nsExceptions::FileNotFoundException::what() {
    const std::string msg = "Exception thrown because the file : " + this->path + " doesn't found.";

    return msg.c_str();
}

// --------------------------------------------

nsHelix::nsExceptions::NegativeValueException::NegativeValueException(const std::string & name, const int value)
    : name(name), value(value) {}

const char * nsHelix::nsExceptions::NegativeValueException::what() {
    const std::string msg = "Exception thrown because the '" + this->name +
        "' canno't be negative. (actual value : " + std::to_string(this->value) + ")";

    return msg.c_str();
}

// --------------------------------------------

nsHelix::nsExceptions::IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string & arrayName, const unsigned value, const unsigned maxValue)
    : arrayName(arrayName), value(value), maxValue(maxValue) {} 

const char * nsHelix::nsExceptions::IndexOutOfBoundsException::what() {
    const std::string msg = "Exception thrown because we try to access to the '" + this->arrayName + "' array with the index (" +
        std::to_string(this->value) + ") which is out of bounds. (array size = " + std::to_string(this->maxValue) + ')';
    
    return msg.c_str();
}
