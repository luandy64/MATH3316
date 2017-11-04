/*
    Andy Lu
    SMU Mathematics
    MATH 3316 Fall 2016
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "matrix.hpp"

using namespace std;

/*
    This main driver computes the forward difference estimates of f(x) = x^-3, at x = 3, using increment h = 2 ^ -n, where n = 1, 2, 3, ..., 52.
    This calculated value is then compared to the actual value of f'(3); then
    the relative error is calculated, along with the upper bound of this error.
*/


int main(){

    // Initializing vectors to store all data
    vector<double> h; // the increment
    vector<double> n; // 1, 2, 3, ... , 52
    vector<double> x; // this is the value of the forward difference estimate
    vector<double> r; // relative error
    vector<double> R; // this is r's upper bound

    // Setting up the h values, h = 2 ^ (-n)
    // for all n = 1, 2, 3, ..., 52
    double temp;
    for(int i = 1; i <= 52; i++){
        temp = double(i);

        n.push_back(temp);
        h.push_back(pow(2,(-temp)));
    }
    // Initializing variables to store values for the upper bound calculation
    double c1 = 0.0;
    double c2 = 0.0;

    // f'(a) = -3 * x ^ -4
    double df = -3.0 * pow(3.0, -4.0);

    // f''(a) = 12 * x ^ -5
    double ddf = 12.0 * pow(3.0, -5.0);

    for(int i = 0; i < 52; i++){

        // approx = (f(a+h) - f(a))(1/h)
        x.push_back( (pow((3.0+h[i]),-3.0) - pow(3.0, -3.0))
                   * (pow(h[i], -1.0)));

        // r = | actual - approx | / |actual|
        r.push_back( fabs((df - x[i]) * pow(df, -1.0)) );
        // r.push_back( fabs((df - x[i]) / df) );
        // r.push_back( fabs(2.0 * pow(3.0, -1.0) * h[i])
        //            + fabs(-1.0 * pow(2.0, -52.0) * pow(h[i], -1.0)));

        // c1 = | f''(a) / 2 * f'(a) |
        //c1 = fabs( ddf * pow( (2.0 * df), -1.0) );

        // c2 = | f(a) * machineEp / f'(a) |
        //c2 = fabs( pow(3.0, -3.0) * pow(10.0, -16.0) * pow(df, -1.0) );

        // R = (h * c1) + (1/h * c2)
        //R.push_back( (h[i] * c1) + (pow(h[i], -1.0) * c2) );
        R.push_back( fabs(-2.0 * pow(3.0, -1.0)) * h[i]
                   + fabs(-1.0 * pow(2.0, -52.0)) * pow(h[i], -1.0));

    }

    // Writing everything to files
    VecWrite(h, "h.txt");
    VecWrite(n, "n.txt");
    VecWrite(r, "r.txt");
    VecWrite(R, "upper.txt");

    return 0;
}
