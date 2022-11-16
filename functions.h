#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "complex.h"

void print(const complex& number){
    if(number.re() == 0){
        if(number.im() == 0){
            std::cout << 0;
            return;
        }

        if(number.im() != 1 && number.im() != -1)
            std::cout << number.im();
        std::cout << 'i' << std::endl;
        return;
    }
    std::cout << number.re();
    if(number.im() == 0) return;
    if(number.im() > 0) std::cout << '+';
    if(number.im() == -1) std::cout << '-';
    if(number.im()*number.im() != 1)
        std::cout << number.im();
    std::cout << 'i' << std::endl;
}

#endif