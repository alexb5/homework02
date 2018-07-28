#pragma once

#include <vector>
#include <array>

namespace lib {

int version_major();
int version_minor();
int version_patch();

using IpAddress = std::array<int, 4>;
using IpPool = std::vector<lib::IpAddress>;


std::vector<std::string> split(const std::string &str, char d);

IpPool readIpStream(std::istream&);

IpPool filter(int, const IpPool&);
IpPool filter(int, int,  const IpPool&);
IpPool filter_any(int, const IpPool&);

void printIp(const lib::IpPool& pool, std::ostream&);

} // namespace lib
