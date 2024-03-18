//
// Created by Grigorescu Alexandru on 10.03.2024.
//

#include "vec2.h"

namespace egc {
    float vec2::length() const {
        return sqrt(x*x + y*y);
    }

    vec2 &vec2::normalize() {
        float const length = this->length();
        x /= length;
        y /= length;

        return *this;
    }

    vec2 vec2::operator-() const {
        return {-x, -y};
    }

    vec2 vec2::operator*(float scalarValue) const {
        return {x * scalarValue, y * scalarValue};
    }

    vec2 vec2::operator+(const vec2 &srcVector) const {
        return {x + srcVector.x, y + srcVector.y};
    }

    vec2 &vec2::operator+=(const vec2 &srcVector) {
        x += srcVector.x;
        y += srcVector.y;

        return *this;
    }

    vec2 vec2::operator-(const vec2 &srcVector) const {
        return {x - srcVector.x, y - srcVector.y};
    }

    vec2 &vec2::operator-=(const vec2 &srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;

        return *this;
    }
}
