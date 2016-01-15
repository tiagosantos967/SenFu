//
//  SenFu.cpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include "SenFu.hpp"
#include <stdio.h>

SenFu::SenFu(int r, CTYPE t){
    sensor_length = 0;
    resolution= r;
    
    switch (t) {
        case CENTROID:
            compute_x= defuzzcentroid;
            break;
        case MAX:
        default:
            compute_x= find_max_x;
            break;
    }
}

void SenFu::addSensor(float *sig, float error){
    Sensor *s= new Sensor(sig,error);
    sensors.push_back(*s);
    sensor_length++;
}

void SenFu::find_min_max(float *x, int size_x, float* min, float*max){
    int i;
    
    *min = *max= x[0];
    for( i=1; i< size_x; i++){
        *min= *min > x[i] || *min == -1? x[i] : *min;
        *max= *max < x[i] || *max == -1? x[i] : *max;
    }
}

float find_max_x(float *agg, int s, float min, float step){
    int i,max_x=0;
    float max;
    
    max= -1;
    for( i=1; i< s; i++){
        if(max < agg[i]){
            max= agg[i];
            max_x= i;
        }
    }
    return min +(step*max_x);
}

float defuzzcentroid(float* data, int nrpoints, float min, float step){
    float dx= step;
    float x,y=0;
    float area=0, xcentroid=0;
    int i;
    
    area=0; xcentroid=0;
    for(i= 0; i< nrpoints; i++){
        x= min +(i + 0.5)*dx;
            
        y= data[i];
            
        xcentroid+= y*x;
        area+= y;
    }
    xcentroid /= area;
        
    return xcentroid;
}

float SenFu::evaluate(float *x){
    float min,max,val,step;
    float agg_result[resolution]; std::fill_n(agg_result, resolution, 0);
    float sig=0;
    int i,j;
    
    find_min_max(x, sensor_length, &min, &max);
    
    for(j=0;j<sensor_length;j++)
        sig += sensors[j].getSig(x[j]);
    
    //If all inputs should be ignored, return -1
    if (max == -1)
        return -1;
    //If inputs are the same, then the final result is obvious... no need for computation.
    if( max == min)
        return max;
    
    val= min;
    step= (max- min)/(float)resolution;
    for(i=0; i<resolution; i++, val+= step){
        for(j=0;j<sensor_length;j++)
            if(x[j] != -1){
                //Sum all the probabilities for that point.
                agg_result[i] += sensors[j].evaluate(val,x[j]) * sensors[j].getSig(x[j]);
                
                
            }
        // Normalize with significance.
        agg_result[i] /= sig;
    }
    
    return compute_x(agg_result,resolution,min,step);
}

