#include <stdexcept>
#include "matrix.hpp"
#include "nest.h"
using namespace std;

int main(){

    // Creating Matrix objects
    // one row matrix
    // one column matrix
    // one incorrect size to test the exception handling in nest()
    Matrix test1(1, 3);
    Matrix test2(3, 1);
    Matrix test3(3, 3);

    // Filling the values of the matrices
    for (int i = 0; i < 3; i++){
        test1(0, i) = i + 3;
        test2(i, 0) = i + 3;

        for (int j = 0; j < 3; j++){
            test3(i, j) = i + j + (i * j);
        }
    }

    // Checking values by printing to screen
    cout << "Test1: " << endl;
    test1.Write();
    cout << endl;
    cout << "Test2: " << endl;
    test2.Write();
    cout << endl;
    cout << "Test3: " << endl;
    test3.Write();
    cout << endl;

    // Running test1 and test2, should be the same
    cout << "Running test1 and test2, should be the same" << endl;
    cout << "Test1: " << nest(test1, 5) << endl;
    cout << "Test2: " << nest(test2, 5) << endl;
    cout << "Values should be 148" << endl;

    cout << endl;

    cout << "Running test3: should see error message" << endl;
    try {
        cout << "Test3: " << nest(test3, 5) << endl;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
    }

    return 0;
}
