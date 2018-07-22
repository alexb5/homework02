#include "lib.h"
#include "version.h"

int lib::version_major() {
    return PROJECT_VERSION_MAJOR;
}

int lib::version_minor() {
    return PROJECT_VERSION_MINOR;
}

int lib::version_patch() {
    return PROJECT_VERSION_PATCH;
}

std::vector<std::array<int, 4>> lib::loadIpStream() {
    return std::vector<std::array<int, 4>>();
}
