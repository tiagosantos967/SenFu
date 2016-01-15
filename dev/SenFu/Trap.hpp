//
//  Trap.hpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#ifndef Trap_hpp
#define Trap_hpp

#include <stdio.h>

class Trap{
public:
    Trap(float A, float B, float C, float D);
    //Get significance for value x.
    float getValue(float x);
private:
    float A,B,C,D;
    
};

#endif /* Trap_hpp */
