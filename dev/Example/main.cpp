//
//  main.cpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SenFu.hpp"

int main(int argc, const char * argv[]) {
    /*
     *  This is an example of how to use the Sensor Fusion object.
     */
    
    // Sensor fusion object will fuse 3 sensors using the CENTROID deffuzification method. 500 precision points.
    SenFu sf(500,MAX);

    //Adding sensors (READ documentation for further details)
    
    //GPS: Values come with an error of 2.5m
    sf.addSensor(new float[4]{4.0f,10.0f,1000.0f,1000.0f}, 2.5f);
    //LASER: Values come with an error of 10cm
    sf.addSensor(new float[4]{-1000.0f,-1000.0f,3.0f,6.0f}, .1f);
    //IMAGE:
    sf.addSensor(new float[4]{-1000.0f,-1000.0f,5.0f,10.0f}, .5f);
    
    // Iteration example. This should be cyclic.
    float *f= new float[3]{4.8f,5.1f,5.2f,};
    printf("%f",sf.evaluate(f));
    
    return 0;
}
