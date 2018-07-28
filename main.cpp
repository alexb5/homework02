#include "lib.h"

#include <algorithm>
#include <iostream>


int main(int argc, char const *argv[])
{
    auto ipPool = lib::readIpStream(std::cin);

    std::sort(ipPool.begin(), ipPool.end(), std::greater<>());

    lib::printIp(ipPool, std::cout);
    lib::printIp(lib::filter(1, ipPool), std::cout);
    lib::printIp(lib::filter(46, 70, ipPool), std::cout);
    lib::printIp(lib::filter_any(46, ipPool), std::cout);

    return 0;
}
