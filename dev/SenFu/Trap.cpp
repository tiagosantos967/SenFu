//
//  Trap.cpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include "Trap.hpp"

Trap::Trap(float Ae, float Be, float Ce, float De){
    A= Ae;
    B= Be;
    C= Ce;
    D= De;
}

float Trap::getValue(float x){
    if( x <= B && x >= A )
        return (x - A)/(B - A);
    else
    if( x <= D && x > C )
        return (x - D)/(C - D);
    else
    if( x <= C && x >= B )
        return 1;
    else
        return 0;
}