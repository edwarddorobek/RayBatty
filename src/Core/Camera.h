#pragma once

#include "Common.h"

namespace Batty {
    class Camera
    {
        public:
        Camera(const VEC3& lookFrom, const VEC3& lookAt, const VEC3& up, const double vfov,
            const double aspect, const double aperature, const double focusDist);

        Ray getRay(const RNGEng& rng, const double s, const double t) const; 

        private:
    };
}