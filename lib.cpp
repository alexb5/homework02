#include "lib.h"

#include "version.h"

#include <iostream>
#include <string>

int lib::version_major() {
    return PROJECT_VERSION_MAJOR;
}

int lib::version_minor() {
    return PROJECT_VERSION_MINOR;
}

int lib::version_patch() {
    return PROJECT_VERSION_PATCH;
}

std::vector<std::string> lib::split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<lib::IpAddress> lib::readIpStream() 
{
    constexpr size_t ipPartsCount = 4;

    std::vector<IpAddress> result;
 
    // Читаем ip адрес до символа табуляции(\t), потом, после тела цикла до конца строки(\n)
    for (std::string line; std::getline(std::cin, line, '\t'); std::getline(std::cin, line))
    {
        if (line.empty())     
            continue;

        auto ipParts = lib::split(line, '.');

        if (ipParts.size() != ipPartsCount) 
            continue;

        IpAddress ip{stoi(ipParts[0]), stoi(ipParts[1]), stoi(ipParts[2]), stoi(ipParts[3])};

        result.push_back(ip);
    }

    return result;
}
