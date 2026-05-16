#include "std_lib_facilities.h"

constexpr char KELVIN{ 'K' };
constexpr char CELSIUS{ 'C' };

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

double ktoc(double k) 
// converts Kelbin to Celsius;
// pre-condition: k >= absolute zero.
{
    constexpr double K_ABS_ZERO{ 0 };

    if (k < K_ABS_ZERO)
        error("Absolute zero");

    double c = k - 273.15;
    return c;
}

int main()

try {
    cout << "Enter a temperature (K, C): ";
    double t{};
    char c{};

    cin >> t >> c;
    if (!cin)
        error("Bad input");

    cout << '\n';

    switch (toupper(c)) {
    case KELVIN:
        cout << ktoc(c) << CELSIUS << '\n';
        break;
    case CELSIUS:
        cout << ctok(c) << KELVIN << '\n';
        break;
    default:
        error("Invalid unit");
    }
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception" << '\n';
    return 1;
}