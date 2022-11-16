#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include<memory>

class complex{
    public:
        using value_type = double;
        using reference = value_type&;
        using const_reference = value_type const&;

        complex();
        complex(const_reference);
        complex(const_reference, const_reference);
        ~complex();

        value_type re() const;
        value_type im() const;

        complex& operator += (const complex& other);
        complex& operator *= (const complex& other);
        complex& operator -= (const complex& other);
        complex& operator /= (const complex& other);

        complex operator - ();
        complex operator ~ ();
    private:
        class cartesian;
        std::shared_ptr<cartesian> impl_;
};

#include "implementation.h"
#include "functions.h"

#endif