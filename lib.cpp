#include "lib.h"

#include "version.h"

#include <algorithm>
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

namespace details {    

template <class T>
lib::IpPool filter(const lib::IpPool& pool, T pred)
{
    std::vector<lib::IpAddress> result{};
    result.reserve(pool.size());

    std::copy_if(pool.begin(), pool.end(), std::back_inserter(result), pred);

    result.shrink_to_fit();
    
    return result;
}

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

std::vector<lib::IpAddress> lib::readIpStream(std::istream& in) 
{
    constexpr size_t ipPartsCount = 4;

    std::vector<IpAddress> result;
 
    // Читаем ip адрес до символа табуляции(\t), потом, после тела цикла до конца строки(\n)
    for (std::string line; std::getline(in, line, '\t'); std::getline(in, line))
    {
        if (line.empty())     
            continue;

        auto ipParts = lib::split(line, '.');

        if (ipParts.size() != ipPartsCount) 
            continue;

        result.push_back({
            stoi(ipParts[0]),
            stoi(ipParts[1]),
            stoi(ipParts[2]),
            stoi(ipParts[3])
            });
    }

    return result;
}

lib::IpPool lib::filter(int number, const IpPool& ipPool)
{
    auto pred = [number](const auto& ip) { return ip[0] == number; };
    return details::filter(ipPool, pred);
}

lib::IpPool lib::filter(int number1, int number2, const IpPool& ipPool)
{
    auto pred = [number1, number2](const auto& ip) { return ip[0] == number1 && ip[1] == number2; };
    return details::filter(ipPool, pred);
}

lib::IpPool lib::filter_any(int number, const IpPool& ipPool)
{
    auto pred = [number](const auto& ip) { 
        return std::any_of(ip.begin(), ip.end(), [number](auto& n) { return n == number; });
    };
    return details::filter(ipPool, pred);
}