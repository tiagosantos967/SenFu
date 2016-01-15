//
//  Sensor.hpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#ifndef Sensor_hpp
#define Sensor_hpp

#include <stdio.h>
#include "Gauss.hpp"
#include "Trap.hpp"

class Sensor
{
public:
    Sensor(float sig[4], float prob);
    //Evaluate input x. The sensor estimated that it was at point "est".
    float evaluate(float x, float est);
    //Get Significance.
    float getSig(float x);
    
private:
    Gauss* prob;
    Trap* sig;
    
};

#endif /* Sensor_hpp */
