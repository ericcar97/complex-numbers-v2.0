#include<iostream>
#include<blaze/Blaze.h>
#include<math.h>
/*
namespace Dense{
    using size_type = std::size_t;
    using blaze::rowMajor;
    using blaze::aligned;
    using blaze::padded;

    template<typename Type, size_type Rows, size_type Columns>
    using Matrix = blaze::StaticMatrix<Type,Rows,Columns,rowMajor,aligned,padded>;
};
*/

namespace Base{
    template<typename Type>
    class Complex{
        public:
            using value_type = Type;

            value_type re() const {return number_[0][0];}
            value_type im() const {return number_[1][0];}

            Complex()
                : number_{}
                {}
            Complex(double re, double im)
                : number_{{re,-im},
                          {im,re}}
                {}
            ~Complex()
                {}
        protected:
        Type number_[2][2];
    };       
};

namespace Cartesian{
    template<typename Type>
    struct Complex : public Base::Complex<Type>{
        using Base::Complex<Type>::Complex;
    };
};

namespace Polar{
    using std::cos;
    using std::sin;
    template<typename Type>
    struct Complex : public Base::Complex<Type>{
        Complex(Type rho, Type theta)
            : Base::Complex<Type>::Complex(rho*cos(theta), rho*sin(theta))
            {}
    };
};


template<typename Type>
void print(const Cartesian::Complex<Type>& number){
    std::cout << number.re() << " + i" << number.im();
}



int main(){
    Polar::Complex<double> C1(1,1);
    Cartesian::Complex<double> C2;
    return 0;
}