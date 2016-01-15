//
//  SenFu.hpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#ifndef SenFu_hpp
#define SenFu_hpp

#include <stdio.h>
#include "Sensor.hpp"
#include <vector>

enum CTYPE {MAX , CENTROID };

//
float find_max_x(float *agg, int x, float min, float step);
float defuzzcentroid(float* data, int nrpoints, float min, float step);

class SenFu
{
public:
    SenFu(int resolution, CTYPE t);
    // ADD one sensor.  sig is the trapezoidal membership function parameters, error is the std for the gaussian membership function.
    void addSensor(float sig[4], float error);
    //Evaluate inputs. x must have the same length as numsensors!
    float evaluate(float *x);
    
private:
    std::vector<Sensor> sensors;
    int sensor_length;
    int resolution;
    void find_min_max(float *x, int size_x, float* min, float*max);
    
    float (*compute_x)(float* data, int nrpoints, float min, float step);
};

#endif /* SenFu_hpp */
