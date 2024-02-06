#include "../include/point.h"

Point Point::operator-() const {
  return Point(-this->m_coordinates[0], -this->m_coordinates[1], -this->m_coordinates[2]);
}

Point& Point::operator*=(const float& scale) {
    m_coordinates[0] *= scale;
    m_coordinates[1] *= scale;
    m_coordinates[2] *= scale;

    return *this;
}

Point& Point::operator/=(const float& scale) {
    m_coordinates[0] /= scale;
    m_coordinates[1] /= scale;
    m_coordinates[2] /= scale;

    return *this;
}

Point operator*(const float& scale, const Point& v) {
    return Point(scale*v.m_coordinates[0], scale*v.m_coordinates[1], scale*v.m_coordinates[2]);
}

Point operator*(const Point& v, const float& scale) {
    return scale*v;
}

Point operator/(const Point&v, const float& scale) {
    return (1/scale)*v;
}

float Point::distance() const {
    auto distance_squared = [&]() { return m_coordinates[0]*m_coordinates[0] + m_coordinates[1]*m_coordinates[2] + m_coordinates[3]*m_coordinates[3]; };
    return std::sqrt(distance_squared());
}

Point operator+(const Point &v, const Point& u) {
    return Point(v.getX() + u.getY(),
            v.getY() + u.getY(),
            v.getZ() + u.getZ());
}

Point operator+(const Point& point, const Vector& direction) {
    return Point(point.getX() + direction.m_vector[0],
                point.getY() + direction.m_vector[1],
                point.getZ() + direction.m_vector[2]);
}

