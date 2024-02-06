#include "../include/vector.h"

Vector Vector::operator-() const {
  return Vector(-m_vector[0], -m_vector[1], -m_vector[2]);
}

Vector& Vector::operator*=(const float& scale) {
    m_vector[0] *= scale;
    m_vector[1] *= scale;
    m_vector[2] *= scale;

    return *this;
}

Vector& Vector::operator/=(const float& scale) {
    m_vector[0] /= scale;
    m_vector[1] /= scale;
    m_vector[2] /= scale;

    return *this;
}

Vector operator*(const float& scale, const Vector& v) {
    return Vector(scale*v.m_vector[0], scale*v.m_vector[1], scale*v.m_vector[2]);
}

Vector operator*(const Vector& v, const float& scale) {
    return scale*v;
}

Vector operator/(const Vector&v, const float& scale) {
    return (1/scale)*v;
}

float dot(const Vector& v, const Vector& u) {
    return u.m_vector[0]*v.m_vector[0] +
           u.m_vector[1]*v.m_vector[1] +
           u.m_vector[2]*v.m_vector[2];
}

Vector cross(const Vector& v, const Vector& u) {
    return Vector(u.m_vector[1] * v.m_vector[2] - u.m_vector[2] * v.m_vector[1],
            u.m_vector[2] * v.m_vector[0] - u.m_vector[0] * v.m_vector[2],
            u.m_vector[0] * v.m_vector[1] - u.m_vector[1] * v.m_vector[0]);
}

float Vector::length() const {
    auto length_squared = [&]() { return m_vector[0]*m_vector[0] + m_vector[1]*m_vector[2] + m_vector[3]*m_vector[3]; };
    return std::sqrt(length_squared());
}

Vector Vector::unitVector() const {
    return *this/this->length();
}
