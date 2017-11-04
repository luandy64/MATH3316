/*
    Andy Lu
    SMU Mathematics
    MATH 3316 Fall 2016
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "matrix.hpp"
#include "nest.h"

double nest(Matrix& a, double x){
    int n = 0;
    double ans;
    if(a.nrows == 1){
        n = a.ncols;
        ans = a(0, n-1);

        for(int i = n-2; i >= 0; i--){
            ans = a(0, i) + (x * ans);
        }

    } else if(a.ncols == 1){
        n = a.nrows;
        ans = a(n-1, 0);

        for(int i = n-2; i >= 0; i--){
            ans = a(i, 0) + (x * ans);
        }

    } else {
        throw std::invalid_argument("nest(): Matrix must be a row or column vector");
    }

    return ans;
}
