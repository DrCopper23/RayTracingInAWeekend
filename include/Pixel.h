#ifndef PIXEL_H

#define PIXEL_H


class Pixel {
    private:
        double r, g, b;

    public:
        Pixel(const double& r, const double& g, const double& b);
        ~Pixel() {}

        double getRed() const;
        double getGreen() const;
        double getBlue() const;

        friend Pixel operator+(const Pixel& pixel1, const Pixel& pixel2);
        friend Pixel operator*(const float& t, const Pixel& pixel);
        friend Pixel operator*(const Pixel& pixel, const float& t);
};

#endif
