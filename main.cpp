#include "lib.h"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        if (argv[1] == "--version") {
            std::cout << lib::version();
            return 0;
        } else {
            std::cout << "Unknown option. Use --version.";
            return 1;
        }
    }
    else if (argc == 0) {
        auto iplist = lib::loadIpStream();
        
    }

    return 0;
}