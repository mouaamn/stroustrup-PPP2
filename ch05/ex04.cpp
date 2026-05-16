#include "std_lib_facilities.h"

double ctok(double c)
// converts Celsius to Kelvin;
// pre-condition: c >= absolute zero.
{
    constexpr double C_ABS_ZERO{ -273.15 };

    if (c < C_ABS_ZERO)
        error("Absolute zero");

    double k = c + 273.15;
    return k;
}

int main()

try {
    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable
    if (!cin)
        error("Bad input");

    double k = ctok(c);     // convert temperature
    cout << k << '/n';      // print out temperature
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception" << '\n';
    return 1;
}