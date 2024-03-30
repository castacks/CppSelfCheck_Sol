
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

// Convenient type alias.
template <typename Scalar>
using MatrixX = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>;

template <typename Scalar>
using VectorX = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

// mesh_grid function similar to MATLAB, NumPy, and PyTorch.
template < typename Derived >
static 
std::tuple< MatrixX<typename Derived::Scalar>, MatrixX<typename Derived::Scalar> >
mesh_grid(const Eigen::MatrixBase<Derived>& x, const Eigen::MatrixBase<Derived>& y) {
    // Check the dimension of x and y.
    if ( x.cols() != 1 || y.cols() != 1 ) {
        throw std::runtime_error("x and y must be colum vectors. ");
    }
    
    // Get the size.
    const int W = x.rows();
    const int H = y.rows();

    // Create the two matrices.
    MatrixX<typename Derived::Scalar> xx = x.transpose().replicate(H, 1);
    MatrixX<typename Derived::Scalar> yy = y.replicate(1, W);    

    return std::make_tuple(xx, yy);
}

template <typename Real>
static
VectorX<Real> get_sample_locations(const int num, const Real& original_length) {
    return VectorX<Real>::LinSpaced(num, 0, original_length - 1);
}

cv::Mat process_image(const cv::Mat& img) {
    // Get the size of the input image.
    const int H = img.rows;
    const int W = img.cols;

    // Create the temporary x and y coordinates as column vectors.
    const auto x = get_sample_locations( W / 2, static_cast<float>( W ) );
    const auto y = get_sample_locations( H / 2, static_cast<float>( H ) );

    // Create the mesh grid.
    const auto [xx, yy] = mesh_grid(x, y);

    // Convert the mesh grid to cv::Mat.
    cv::Mat xx_cv, yy_cv;
    cv::eigen2cv(xx, xx_cv);
    cv::eigen2cv(yy, yy_cv);

    // Create the output image.
    auto img_out = cv::Mat();
    cv::remap(img, img_out, 
              xx_cv, yy_cv, 
              cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0) );

    return img_out;
}
