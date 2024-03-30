//
// Created by yaoyu on 7/27/20.
//

#ifndef HEADERONLYLIBRARY_INCLUDES_HEADERONLY_HEADERONLYLIBRARY_HPP
#define HEADERONLYLIBRARY_INCLUDES_HEADERONLY_HEADERONLYLIBRARY_HPP

#include <iostream>

#include <Eigen/Dense>

namespace header
{

    template < typename RealT >
    class HeaderOnlyClass {
    public:
        HeaderOnlyClass()
        : member{123.0}
        {}

        ~HeaderOnlyClass() = default;

        // Definition will be outside class definition.
        void show() const;

        // Inline function.
        const RealT& get() const {
            return member;
        }

        RealT get() {
            return member;
        }

    private:
        RealT member;
        Eigen::Matrix3f fixedSizeMat;

    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    };

    template < typename RealT >
    void HeaderOnlyClass<RealT>::show() const {
        std::cout << "This is HeaderOnlyClass. \n";
        std::cout << "member = " << member << "\n";
        std::cout << fixedSizeMat << "\n";
    }

}

#endif //HEADERONLYLIBRARY_INCLUDES_HEADERONLY_HEADERONLYLIBRARY_HPP
