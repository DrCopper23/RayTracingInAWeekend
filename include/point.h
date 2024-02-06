#ifndef POINT_H
#define POINT_H

#include <array>
#include <cmath>
#include <iostream>
#include "vector.h"

class Point {
public:
  Point() : m_coordinates{0, 0, 0} {}
  Point(float i, float j, float k) : m_coordinates{i, j, k} {}

  float getX() const { return m_coordinates.at(0); }
  float getY() const { return m_coordinates.at(1); }
  float getZ() const { return m_coordinates.at(2); }

  Point operator-() const;
  Point &operator+=(const Point &other) = delete;
  Point &operator*=(const float &scale);
  Point &operator/=(const float &scale);

  friend Point operator*(const float &scale, const Point &v);
  friend Point operator*(const Point &v, const float &scale);
  friend Point operator/(const Point &v, const float &scale);
  friend Point operator+(const Point &v, const Point& u);

  float distance() const;
  // Vector unit_vector();
  friend Point operator+(const Point& point, const Vector& direction);

private:
  std::array<float, 3> m_coordinates;
};

#endif // POINT_H
