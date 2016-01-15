//
//  gauss.hpp
//  SenFu
//
//  Created by Tiago Santos on 07/01/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#ifndef gauss_hpp
#define gauss_hpp

#include <stdio.h>

class Gauss{
public:
    Gauss(float std);
    //Evaluate input x. The sensor estimated that it was at point "est".
    float getValue(float x, float est);
private:
    float error;
};

#endif /* gauss_hpp */
