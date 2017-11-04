/*
    Andy Lu
    SMU Mathematics
    MATH 3316 Fall 2016
*/

// Inclusions
#include <math.h>
#include <fstream>
#include "matrix.hpp"
#include "nest.h"
using namespace std;

// fact() calculates the factorial of the argument
double fact(double x){
    if(x != 1 && x != 0){
        return x * fact(x-1);
    }else
        return 1;
}

/*
    This main driver creates various Taylor Polynomials for f(x) = e^x about the
    origin. Then the actual function of e^x is created and the absolute error of
    each Taylor Polynomial is evaluated. Lastly, the values of all of
    polynomials and their errors are written to files to be plotted in Python.
*/

int main(){
    // Creating the vector z to hold the values
    // 1,  0.99,  0.98, ...,  0.01, 0, 0.01, ..., 0.98, 0.99, 1.0
    vector<double> z = Linspace(-1, 1, 201);

    // p4, p8, and p12 are used to store the values of each Taylor polynomial
    // evaluated at all elements of z
    vector<double> p4;
    vector<double> p8;
    vector<double> p12;

    // f is used to store the values of f(x) = e^x
    vector<double> f;

    // err4, err8, and err12 are used to store the values of the absolute error
    // of the taylor polynomial approximations
    vector<double> err4;
    vector<double> err8;
    vector<double> err12;

    // The matrix objects tay4, tay8, and tay12 are going to store the
    // coefficients of the taylor polynomials, to be used by nest()
    Matrix tay4(1,5);
    tay4(0 , 0) = 1.0;
    for(double a = 1.0; a < 5; a++){
        tay4(0, a) = 1.0 / fact(a);
    }

    Matrix tay8(1,9);
    tay8(0 , 0) = 1.0;
    for(double a = 1.0; a < 9; a++){
        tay8(0, a) = 1.0 / fact(a);
    }

    Matrix tay12(1,13);
    tay12(0 , 0) = 1.0;
    for(double a = 1.0; a < 13; a++){
        tay12(0, a) = 1.0 / fact(a);
    }

    //Creating p4 with Nest
    for(int b = 0; b < z.size(); b++){
        p4.push_back(nest(tay4,z[b]));
    }

    //Creating p8 with Nest
    for(int c = 0; c < z.size(); c++){
        p8.push_back(nest(tay8,z[c]));
    }

    //Creating p12 with Nest
    for(int d = 0; d < z.size(); d++){
        p12.push_back(nest(tay12,z[d]));
    }

    //Creating f (e^x)
    for(int e = 0; e < z.size(); e++){
        f.push_back(exp(z[e]));
    }

    //Calculating error for p4
    for(int i = 0; i < z.size(); i++){
        err4.push_back(fabs(f[i] - p4[i]));
    }

    //Calculating error for p8
    for(int g = 0; g < z.size(); g++){
        err8.push_back(fabs(f[g] - p8[g]));
    }

    //Calculating error for p12
    for(int h = 0; h < z.size(); h++){
        err12.push_back(fabs(f[h] - p12[h]));
    }

    // Writing everything to files
    VecWrite(z, "z.txt");
    VecWrite(p4, "p4.txt");
    VecWrite(p8, "p8.txt");
    VecWrite(p12, "p12.txt");
    VecWrite(f, "f.txt");
    VecWrite(err4, "err4.txt");
    VecWrite(err8, "err8.txt");
    VecWrite(err12, "err12.txt");

    return 0;
}
