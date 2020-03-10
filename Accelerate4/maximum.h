//
// Created by moon misty on 2019-08-26.
//
template < typename T >
T maximum( T value1, T value2, T value3 )
{
    T maximumValue = value1;
    if (value2 > maximumValue)
        maximumValue = value2;
    if (value3 > maximumValue)
        maximumValue = value3;

    return maximumValue;
}

#ifndef ACCELERATE4_MAXIMUM_H
#define ACCELERATE4_MAXIMUM_H


class maximum {

};


#endif //ACCELERATE4_MAXIMUM_H
