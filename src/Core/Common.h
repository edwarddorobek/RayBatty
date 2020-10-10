#pragma once

#include <limits>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h> 

using std::cos;
using std::sin;
using std::asin;
using std::tan;
using std::atan2;

using std::sqrt;
using std::clamp;

namespace Batty {
    constexpr auto Infinity = std::numeric_limits<double>::infinity();
    constexpr auto Pi = static_cast<double>(3.1415926535897932385);
    constexpr TwoPi = Pi * static_cast<double>(2);
    constexpr HalfPi = Pi / static_cast<double>(2);

    inline double degToRad(const double deg)
    {
        return deg * Pi / 180.0;
    }

    inline double schlick(const double cosine, const double ref_idx)
    {
        const double alpha = 1 - cosine;
        const double beta = alpha*alpha*alpha*alpha*alpha;

        double r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0*r0;

        return r0 + ((1-r0) * beta);
    }

}



