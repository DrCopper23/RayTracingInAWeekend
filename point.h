#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>
#include <array>

class Vector {
    public:
        Vector(): m_vector{0, 0, 0} {}
        Vector(float i, float j, float k): m_vector{i, j, k} {}

        float getXDirection() const { return m_vector.at(0); }
        float getYDirection() const { return m_vector.at(1); }
        float getZDirection() const { return m_vector.at(2); }

        Vector operator-() const;
        Vector& operator+=(const Vector& other) = delete;
        Vector& operator*=(const float& scale);
        Vector& operator/=(const float& scale);

        friend Vector operator*(const float& scale, const Vector& v);
        friend Vector operator*(const Vector&v, const float& scale);
        friend Vector operator/(const Vector&v, const float& scale);
        friend float dot(const Vector& v, const Vector& u);
        friend Vector cross(const Vector& v, const Vector& u);

        float length() const;
        Vector unit_vector();

    private:
        std::array<float, 3> m_vector;
};


#endif
