#include "../include/ImageWriter.h"

ImageWriter::ImageWriter(const int height, const int width, const std::string& file_name)
    : m_height(height), m_width(width), m_file_name(file_name) {
}

void
ImageWriter::SetData(ImageData data) {
    m_image_data = data;
}

void
ImageWriter::WriteImage() {
    std::ofstream fp(m_file_name);
    fp << GetDataStringStream().str();
    fp.close();
}

std::stringstream ImageWriter::GetDataStringStream() {
    std::stringstream s;
    s << "P3\n" << m_width  << ' ' << m_height << "\n255\n";
    for (int j = m_height; j>=0; j--) {
        std::cout << "Scanlines remaining: " << j << std::endl;
        for (int i = 0; i < m_width; i++) {
            const Pixel& p = m_image_data[j][i];
            int ir = static_cast<int>(255.999 * p.getRed());
            int ib = static_cast<int>(255.999 * p.getBlue());
            int ig = static_cast<int>(255.999 * p.getGreen());
            s << ir << ' ' << ib << ' ' << ig << '\n';
        }
    }

    return s;

}
