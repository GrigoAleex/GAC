//
// Created by Grigorescu Alexandru on 14.03.2024.
//

#include "mat3.h"

namespace  egc {

    mat3 &mat3::operator=(const mat3 &srcMatrix) {
        for (int i = 0; i < 9; ++i) {
            this->matrixData[i] = srcMatrix.matrixData[i];
        }

        return *this;
    }

    mat3 mat3::operator *(float scalarValue) const {
        mat3 _new;

        for (int i = 0; i < 9; ++i) {
            _new.matrixData[i] = this->matrixData[i] * scalarValue;
        }

        return  _new;
    }
    mat3 mat3::operator *(const mat3& srcMatrix) const {
        mat3 _new;
        for (int i = 0; i < 9; ++i) {
            float sum = 0;
            for (int j = 0; j < 3; ++j) {
                 sum += this->matrixData[i / 3 + j] * srcMatrix.matrixData[3 * j + i % 3];
            }
            _new.matrixData[i] = sum;
        }

        return _new;
    }
    vec3 mat3::operator *(const vec3& srcVector) const {
        vec3 _new;

        _new.x += this->matrixData[0] * srcVector.x + this->matrixData[1] * srcVector.y + this->matrixData[2] * srcVector.z;
        _new.x += this->matrixData[3] * srcVector.x + this->matrixData[4] * srcVector.y + this->matrixData[5] * srcVector.z;
        _new.x += this->matrixData[6] * srcVector.x + this->matrixData[7] * srcVector.y + this->matrixData[8] * srcVector.z;

        return  _new;
    };
    mat3 mat3::operator +(const mat3& srcMatrix) const {
        mat3 _new;

        for (int i = 0; i < 9; ++i) {
            _new.matrixData[i] = this->matrixData[i] + srcMatrix.matrixData[i];
        }

        return _new;
    }

    float& mat3::at(int i, int j) {
        return this->matrixData[i + 3*j];
    }

    const float& mat3::at(int i, int j) const {
        return this->matrixData[i + 3*j];
    };
    float mat3::determinant() const {
        const std::vector<float>& m = this->matrixData;
        return (m[0] * (m[4] * m[8] - m[5] * m[7])) -
               (m[1] * (m[3] * m[8] - m[5] * m[6])) +
               (m[2] * (m[3] * m[7] - m[4] * m[6]));
    }

    mat3 mat3::inverse() const {
        const std::vector<float>& m = this->matrixData;
        float det = determinant();
        if (det == 0) {
            return *this;
        }

        float invDet = 1.0f / det;
        mat3 invMat;

        invMat.matrixData[0] = (m[4] * m[8] - m[5] * m[7]) * invDet;
        invMat.matrixData[1] = (m[2] * m[7] - m[1] * m[8]) * invDet;
        invMat.matrixData[2] = (m[1] * m[5] - m[2] * m[4]) * invDet;
        invMat.matrixData[3] = (m[5] * m[6] - m[3] * m[8]) * invDet;
        invMat.matrixData[4] = (m[0] * m[8] - m[2] * m[6]) * invDet;
        invMat.matrixData[5] = (m[2] * m[3] - m[0] * m[5]) * invDet;
        invMat.matrixData[6] = (m[3] * m[7] - m[4] * m[6]) * invDet;
        invMat.matrixData[7] = (m[1] * m[6] - m[0] * m[7]) * invDet;
        invMat.matrixData[8] = (m[0] * m[4] - m[1] * m[3]) * invDet;

        return invMat;
    };
    mat3 mat3::transpose() const {
        const std::vector<float>& m = this->matrixData;
        mat3 transposedMat;

        transposedMat.matrixData[0] = m[0];
        transposedMat.matrixData[1] = m[3];
        transposedMat.matrixData[2] = m[6];
        transposedMat.matrixData[3] = m[1];
        transposedMat.matrixData[4] = m[4];
        transposedMat.matrixData[5] = m[7];
        transposedMat.matrixData[6] = m[2];
        transposedMat.matrixData[7] = m[5];
        transposedMat.matrixData[8] = m[8];

        return transposedMat;
    };
}
