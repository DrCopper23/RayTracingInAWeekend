#ifndef RAY_H
#define RAY_H

#include "vector.h"
#include "point.h"

class Ray {
    public:
        Ray() {}
        Ray(const Point& origin, const Vector& direction)
            : m_origin(origin), m_direction(direction) {}

        const Point origin() const { return m_origin; }
        const Vector direction() const { return m_direction; }

        Point at(float t) const {
            return m_origin + t*m_direction;
        }


    private:
        Point m_origin;
        Vector m_direction;
};

#endif
