#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include "complex.h"

class complex::cartesian{
    public:
        using value_type = double;
        using reference = value_type&;
        using const_reference = value_type const&;

        value_type re() const {return re_;}
        value_type im() const {return im_;}

        cartesian()
            : re_(0) {}
        
        cartesian(const_reference re)
            : re_(re) {}

        cartesian(const_reference re, const_reference im)
            : re_(re)
            , im_(im) {}
        
        cartesian& operator += (const cartesian& other){
            re_ += other.re_;
            im_ += other.im_;
            return *this;
        }

        cartesian& operator *= (const cartesian& other){
            value_type re = re_*other.re_ - im_*other.im_;
            im_ = re_*other.im_ + im_*other.re_;
            re_ = re;
            return *this;
        }

        cartesian& operator -= (const cartesian& other){
            re_ -= other.re_;
            im_ -= other.im_;
            return *this;
        }

        cartesian& operator /= (const cartesian& other){
            value_type re = re_*other.re_ + im_*other.im_;
            value_type mod = other.re_*other.re_ + other.im_*other.im_;
            im_ = (re_*other.im_ - im_*other.re_)/mod; 
            re_ = re/mod;
            return *this;
        }

        cartesian operator - () const{
            return cartesian(-re_,-im_);
        }

        cartesian operator ~ () const{
            return cartesian(re_,-im_);
        }

    private:
        value_type re_;
        value_type im_;
};


complex::complex()
    : impl_(new cartesian()){}

complex::complex(const_reference re)
    : impl_(new cartesian(re)) {}

complex::complex(const_reference re, const_reference im)
    : impl_(new cartesian(re,im)) {}

complex::~complex() = default;

double complex::re() const {return impl_->re();}
double complex::im() const {return impl_->im();}

complex& complex::operator += (const complex& other){
    impl_ -> operator += (*other.impl_);
    return *this;
}
complex& complex::operator *= (const complex& other){
    impl_ -> operator *= (*other.impl_);
    return *this;
}

complex& complex::operator -= (const complex& other){
    impl_ -> operator -= (*other.impl_);
    return *this;
}

complex& complex::operator /= (const complex& other){
    impl_ -> operator /= (*other.impl_);
    return *this;
}

complex operator + (complex lhs, const complex& rhs){
    lhs+=rhs;
    return lhs;
}


complex operator * (complex lhs, const complex& rhs){
    lhs*=rhs;
    return lhs;
}


complex operator - (complex lhs, const complex& rhs){
    lhs-=rhs;
    return lhs;
}



complex operator / (complex lhs, const complex& rhs){
    lhs/=rhs;
    return lhs;
}

#endif