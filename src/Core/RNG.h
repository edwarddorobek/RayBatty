#pragma once

#include "Vec3.h"
#include <string>
#include <random>
#include "Common.h"

namespace Batty {
    class RNGEng
    {
    public:
        RNGEng(const std::stirng& seed) :

    private:
        std::uniform_real_distribution<double> RNGDist;
        std::string seed;
        std::mt19937 rng;
    };
}