//
//  Sensor.cpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include "Sensor.hpp"

Sensor::Sensor(float s[4], float p){
    prob= new Gauss(p);
    sig= new Trap(s[0],s[1],s[2],s[3]);
}

float Sensor::evaluate(float x, float est){
    return prob->getValue(x,est);
}

float Sensor::getSig(float x){
    return sig->getValue(x);
}