#pragma once

#include <vector>
#include <array>

namespace lib {

int version();
std::vector<std::array<int, 4>> loadIpStream();

} // namespace lib
