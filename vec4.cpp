//
// Created by Grigorescu Alexandru on 10.03.2024.
//
#include "vec4.h"

//
// Created by Grigorescu Alexandru on 10.03.2024.
//

#include "vec4.h"

//
// Created by Grigorescu Alexandru on 10.03.2024.
//

#include "vec4.h"

namespace egc {
    float vec4::length() const {
        return sqrt(x*x + y*y + z*z);
    }

    vec4 &vec4::normalize() {
        float const length = this->length();
        x /= length;
        y /= length;
        z /= length;
        w /= length;

        return *this;
    }

    vec4 vec4::operator-() const {
        return {-x, -y, -z, -w};
    }

    vec4 vec4::operator*(float scalarValue) const {
        return {x * scalarValue, y * scalarValue, z * scalarValue, w * scalarValue};
    }

    vec4 vec4::operator+(const vec4 &srcVector) const {
        return {x + srcVector.x, y + srcVector.y, z + srcVector.z, w + srcVector.w};
    }

    vec4 &vec4::operator+=(const vec4 &srcVector) {
        x += srcVector.x;
        y += srcVector.y;
        z += srcVector.z;
        w += srcVector.w;

        return *this;
    }

    vec4 vec4::operator-(const vec4 &srcVector) const {
        return {x - srcVector.x, y - srcVector.y, z - srcVector.z, w - srcVector.w};
    }

    vec4 &vec4::operator-=(const vec4 &srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;
        z -= srcVector.z;
        w -= srcVector.w;

        return *this;
    }

    vec4 &vec4::operator=(const vec4 &srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        z = srcVector.z;
        w = srcVector.w;

        return *this;
    }

}
