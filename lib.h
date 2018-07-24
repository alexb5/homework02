#pragma once

#include <vector>
#include <array>

namespace lib {

int version_major();
int version_minor();
int version_patch();

using  IpAddress = std::array<int, 4>;

std::vector<IpAddress> readIpStream();
std::vector<std::string> split(const std::string &str, char d);

} // namespace lib
