#ifndef _HELIX_EXCEPTIONS_H
#define _HELIX_EXCEPTIONS_H

#include <iostream>


namespace nsHelix {
    namespace nsExceptions {
        class HelixException : public std::exception {
            private:
                const std::string msg;

            public:
                HelixException(const std::string & message);
                const char * what();
        };

        class HelixInitializationException : public std::exception {
            private:
                const std::string msg;

            public:
                HelixInitializationException(const std::string & message);
                const char * what();
        };

        class NullPointerException : public std::exception {
            private:
                const std::string name;
            
            public:
                NullPointerException(const std::string & name);
                const char * what();
        };

        class FileNotFoundException : public std::exception {
            private:
                const std::string path;
            
            public:
                FileNotFoundException(const std::string & path);
                const char * what();
        };

        class NegativeValueException : public std::exception {
            private:
                const std::string name;
                const unsigned value;
            
            public:
                NegativeValueException(const std::string & name, const int value);
                const char * what();
        };

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
