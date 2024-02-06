#include "../include/Pixel.h"

Pixel::Pixel(const double& r,
        const double& g,
        const double& b)
    : r(r), g(g), b(b) {
}

double Pixel::getRed() const {
    return r;
}

double Pixel::getGreen() const {
    return g;
}

double Pixel::getBlue() const {
    return b;
}

Pixel operator+(const Pixel& pixel1, const Pixel& pixel2) {
    return Pixel(pixel1.r + pixel2.r,
            pixel1.g + pixel2.g,
            pixel1.b + pixel2.b);
}

Pixel operator*(const float& t, const Pixel& pixel) {
    return Pixel(t*pixel.r, t*pixel.g, t*pixel.b);
}

Pixel operator*(const Pixel& pixel, const float& t) {
    return t*pixel;
}
