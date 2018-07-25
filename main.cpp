#include "lib.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void printIp(const lib::IpPool& pool)
{
        for(const auto& ip : pool)
        {
            for(const auto& ip_part : ip)
                std::cout << ip_part << ".";
            
            std::cout << std::endl;
        }
}

int main(int argc, char const *argv[])
{

    auto ipPool = lib::readIpStream(std::cin);
        
    std::sort(ipPool.begin(), ipPool.end(), std::greater<>());

    printIp(ipPool);
    printIp(lib::filter(1, ipPool));
    printIp(lib::filter(46, 70, ipPool));
    printIp(lib::filter_any(46, ipPool));

    return 0;
}
