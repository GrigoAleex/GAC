//
// Created by Grigorescu Alexandru on 10.03.2024.
//

#include "vec3.h"

namespace egc {
    float vec3::length() const {
        return sqrt(x*x + y*y + z*z);
    }

    vec3 &vec3::normalize() {
        float const length = this->length();
        x /= length;
        y /= length;
        z /= length;

        return *this;
    }

    vec3 vec3::operator-() const {
        return {-x, -y, -z};
    }

    vec3 vec3::operator*(float scalarValue) const {
        return {x * scalarValue, y * scalarValue, z * scalarValue};
    }

    vec3 vec3::operator+(const vec3 &srcVector) const {
        return {x + srcVector.x, y + srcVector.y, z + srcVector.z};
    }

    vec3 &vec3::operator+=(const vec3 &srcVector) {
        x += srcVector.x;
        y += srcVector.y;
        z += srcVector.z;

        return *this;
    }

    vec3 vec3::operator-(const vec3 &srcVector) const {
        return {x - srcVector.x, y - srcVector.y, z - srcVector.z};
    }

    vec3 &vec3::operator-=(const vec3 &srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;
        z -= srcVector.z;

        return *this;
    }

    vec3 &vec3::operator=(const vec3 &srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        z = srcVector.z;

        return *this;
    }

}
