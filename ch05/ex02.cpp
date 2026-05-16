/*
    List of errors:
    1. The type of variable k should been double
    2. The result should been k, and not int (the type)
    3. There was a missing semicolon when k was returned
    4. There was a reading into an non-existing variable d
    5. Argument of type string was given instead of type double
    6. There was a misspell of cout as Cout
*/

#include "std_lib_facilities.h"

double ctok(double c)    // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable
    double k = ctok(c);     // convert temperature
    cout << k << '/n';      // print out temperature
}