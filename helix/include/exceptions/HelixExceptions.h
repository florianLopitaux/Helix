/**
 * @file HelixExceptions.h
 * @author Florian LOPITAUX
 * @brief This file contains many custom exceptions classes declaration.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#ifndef _HELIX_EXCEPTIONS_H
#define _HELIX_EXCEPTIONS_H

#include <iostream>


/**
 * @namespace nsHelix
 * @brief Base namespace that contains all contents of the Helix library.
*/
namespace nsHelix {

    /**
     * @namespace nsExceptions
     * @brief Sub-namesapce that contains all custom exceptions classes used by the Helix library
    */
    namespace nsExceptions {

        /**
         * @class HelixException "exceptions/HelixException.h"
         * @brief Generic exception raise when the case doesn't have a specefic exception to used.
        */
        class HelixException : public std::exception {
            private:
                const std::string msg;

            public:
                HelixException(const std::string & message);
                const char * what();
        };

        /**
         * @class HelixInitializationException "exceptions/HelixException.h"
         * @brief Raise when the library failed to initialize a component (generally due to SDL initialization error).
        */
        class HelixInitializationException : public std::exception {
            private:
                const std::string msg;

            public:
                HelixInitializationException(const std::string & message);
                const char * what();
        };

        /**
         * @class NullPointerException "exceptions/HelixException.h"
         * @brief Raise when we try to access or use a variable not yet set.
        */
        class NullPointerException : public std::exception {
            private:
                const std::string name;
            
            public:
                NullPointerException(const std::string & name);
                const char * what();
        };

        /**
         * @class FileNotFoundException "exceptions/HelixException.h"
         * @brief Raise when we try to read or write in file which doesn't exist (generally bad given path).
        */
        class FileNotFoundException : public std::exception {
            private:
                const std::string path;
            
            public:
                FileNotFoundException(const std::string & path);
                const char * what();
        };

        /**
         * @class NegativeValueException "exceptions/HelixException.h"
         * @brief Raise when we pass to a function a number that can't be negative (check the function documentation).
        */
        class NegativeValueException : public std::exception {
            private:
                const std::string name;
                const unsigned value;
            
            public:
                NegativeValueException(const std::string & name, const int value);
                const char * what();
        };

        /**
         * @class IndexOutOfBoundsException "exceptions/HelixException.h"
         * @brief Raise when we try to access at an element of an array with an index too huge.
        */
        class IndexOutOfBoundsException : public std::exception {
            private:
                const std::string arrayName;
                const unsigned value;
                const unsigned maxValue;
            
            public:
                IndexOutOfBoundsException(const std::string & arrayName, const unsigned value, const unsigned maxValue);
                const char * what();
        };
    }
}

#endif
