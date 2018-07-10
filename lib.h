#pragma once

#include <vector>
#include <array>

namespace lib {

int version_major();
int version_minor();
int version_patch();
std::vector<std::array<int, 4>> loadIpStream();

} // namespace lib
