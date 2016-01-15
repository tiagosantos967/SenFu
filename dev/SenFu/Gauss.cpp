//
//  gauss.cpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include "Gauss.hpp"
#include <tgmath.h>

Gauss::Gauss(float s){
    error= s;
}

float Gauss::getValue(float x, float mean){
    return exp( -((x-mean)*(x-mean))/(2*error/3*error/3) );
}