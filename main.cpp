#include "include/ImageWriter.h"
#include "include/vector.h"
#include "include/Ray.h"
#include "src/vector.cpp"
#include "src/point.cpp"


Pixel rayColor(const Ray& ray) {
    const Vector unit_direction = ray.direction().unitVector();
    size_t t = 0.5*(unit_direction.getYDirection() + 1.0);
    return Pixel(0,0,0);
}

ImageData generateData(const int height, const int width){
    ImageData data;
    for (int j = height; j>=0; j--) {
        std::vector<Pixel> row;
        for (int i = 0; i < width; i++) {
            auto r = double(i) / (width - 1);
            auto b = 0.5;
            auto g = double(j) / (height - 1);
            const Pixel p(r, g, b);
            row.push_back(p);
        }
        data.push_back(row);
    }
    return data;
}

ImageData generateData(const int height, const int width, const Point& lower_left_corner,
        const Vector& horizontal, const Vector& vertical, const Point& origin){
    ImageData data;
    for (int j = height; j>=0; j--) {
        std::vector<Pixel> row;
        for (int i = 0; i < width; i++) {
            auto u = double(i) / (width - 1);
            auto v = double(j) / (height - 1);
            Ray r(origin, u*horizontal + v*vertical);
            Pixel p = rayColor(r);
            row.push_back(p);
        }
        data.push_back(row);
    }
    return data;
}

int main (int argc, char *argv[])
{

    const int height = 512;
    const int width = 512;
    const float aspect_ratio = static_cast<float>(width)/height;

    const float viewport_height = 2;
    const float viewport_width = aspect_ratio * viewport_height;
    const float focal_length = 1;

    const Point origin(0,0,0);
    const Vector horizontal(viewport_width, 0, 0);
    const Vector vertical(0, viewport_height, 0);

    const Point lower_left_corner = origin + Point(-viewport_width/2, -viewport_height/2, -focal_length);

    ImageWriter im(height, width, "test.ppm");
    ImageData data = generateData(height, width);
    im.SetData(data);
    im.WriteImage();
    return 0;
}
