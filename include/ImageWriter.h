#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Pixel.h"


typedef std::vector<std::vector<Pixel>> ImageData;
class ImageWriter
{
    private:
        int m_height;
        int m_width;
        const std::string m_file_name;
        ImageData m_image_data;

    public:
        ImageWriter(const int height, const int width, const std::string& file_name);
        ~ImageWriter() {}
        void SetData(ImageData data);

        void WriteImage();

    private:
        std::stringstream GetDataStringStream();

};
