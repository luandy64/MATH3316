#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "matrix.hpp"
#ifndef MATRIX
#define MATRIX

using namespace std;

int main(){
    vector<double> h; // the increment
    vector<double> n; // 1, 2, 3, ... , 52
    vector<double> x; // this is the value of the forward difference estimate
    vector<double> r; // relative error
    vector<double> R; // this is r's upper bound
    
    Matrix co(1,4);
    co(0,0) = 27.0;
    co(0,1) = 27.0;
    co(0,2) = 9.0;
    co(0,3) = 1.0;
    
    double temp1;
    for(int i = 0; i < 52; i++){
        temp1 = i + 1.0;
        n.push_back(temp1);
        h.push_back(pow(2,(-temp1)));
    }

    double temp2;

    for(int i = 0; i < 52; i++){
        
        x.push_back( (pow(3.0+h[i],-3.0) - pow(3.0, -3.0)) * (pow(h[i], -1.0)));
        
        r.push_back(fabs( -h[i]*12.0*pow(3.0, -5.0)*pow(-6.0,-1.0)*pow(3,-4.0) + pow(h[i],-1.0)*pow(2.0,-52.0)*pow(3.0,-3.0)+pow(2.0,-52.0)*pow(3.0,-3.0)*pow(-3.0, -1.0)*pow(3.0,-4.0) ));

        R.push_back((2.0 * pow(3.0, -1.0) *h[i] + pow(2.0, -52.0) * pow(h[i], -1.0)));

    }

    
    VecWrite(h, "h.txt");
    VecWrite(n, "n.txt");
    VecWrite(r, "r.txt");
    VecWrite(R, "upper.txt");
}

#endif // end matrix