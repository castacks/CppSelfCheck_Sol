//
// Created by yaoyu on 7/27/20.
//

#ifndef CONCRETELIBRARY_INCLUDES_CONCRETELIBRARY_HPP
#define CONCRETELIBRARY_INCLUDES_CONCRETELIBRARY_HPP

#include <Eigen/Dense>

namespace concrete
{
class ConcreteClass {
public:
    ConcreteClass();
    ~ConcreteClass();

    void show() const;

private:
    Eigen::Matrix3f fixedSizeMat;

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}

#endif //CONCRETELIBRARY_INCLUDES_CONCRETELIBRARY_HPP
