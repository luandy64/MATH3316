/*
    Andy Lu
    SMU Mathematics
    MATH 3316 Fall 2016

    This file defines the function 'nest()' that takes two arguments:
    - a Matrix object defined in 'matrix.h'
    - a double

    The function implements a nested multiplication algorithm in order to
    minimize the number of floating point operations carried out when evaluating
    polynomials
*/

#ifndef NEST_H
#define NEST_H

double nest(Matrix&, double);

#endif
