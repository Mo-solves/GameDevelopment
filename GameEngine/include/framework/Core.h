#pragma once
#include <stdio.h>

namespace gdev {
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}