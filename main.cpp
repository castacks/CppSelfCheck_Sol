
#include <filesystem>
#include <iostream>
#include <string>

#include <Eigen/Dense>

#include <opencv2/opencv.hpp>

#include "Concrete/ConcreteLibrary.hpp"
#include "HeaderOnly/HeaderOnlyLibrary.hpp"

// External functions.
cv::Mat process_image(const cv::Mat& img);

static
void test_libraries() {
    const auto c = concrete::ConcreteClass();
    c.show();

    std::cout << std::endl;

    const auto h = header::HeaderOnlyClass<float>();
    h.show();

    std::cout << std::endl;
}

static
void test_image_processing(const std::string& input_img_path) {
    std::cout << "Input image: " << input_img_path << "\n";

    // Read an image from file.
    const cv::Mat img = cv::imread(input_img_path, cv::IMREAD_UNCHANGED);
    std::cout << "Size of img [H, W]: [ " 
              << img.rows << ", " 
              << img.cols << " ] \n";

    // Process the image.
    const auto img_processed = process_image(img);
    std::cout << "Size of img_processed [H, W]: [ " 
              << img_processed.rows << ", " 
              << img_processed.cols << " ] \n";

    // Save the file back to its directory.
    const std::string new_path = 
        std::filesystem::path(input_img_path)
            .parent_path()
            .append("processed.png")
            .string();
    
    cv::imwrite(new_path, img_processed);

    std::cout << "Save the processed image to: " << new_path << "\n";
}

int main( int argc, char** argv ) {

    std::cout << "Hello, CppSelfCheck! \n\n";

    // Test the libraries.
    test_libraries();

    // Test image processing.
    if ( argc == 1 ) {
        std::cout << "No input image. \n";
        return 1;
    }

    test_image_processing(argv[1]);

    return 0;
}
