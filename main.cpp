#include "lib.h"
#include <boost/program_options.hpp>

#include <iostream>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description description("Allowed options");
    description.add_options()
        ("help", "produce help message")
        ("version", "print program version")
        ;

    po::variables_map optionMap;
    po::store(po::parse_command_line(argc, argv, description), optionMap);
    po::notify(optionMap);    

    if (optionMap.count("help")) {
        std::cout << description << "\n";
        return 1;
    }

    if (optionMap.count("version")) {
        std::cout << "Program version is: " << lib::version_major() << "." << lib::version_minor() << "." << lib::version_patch()  << std::endl;
        return 1;
    }  
 
    return 0;
}