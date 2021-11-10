#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <cmath>
using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize; using std::fixed;

int main() {
/*DECIMAL FORMATTING*/
//    cout << "What is the price for a six-pack?: ";
//    double pricePack;
//    cin >> pricePack;
//
//
//    cout << "What is the volume per can (in ounces)?: ";
//    double canVol;
//    cin >> canVol;
//
//    const double CANS_PER_PACK = 6;
//    double packVol = canVol * CANS_PER_PACK;
//    double pricePerOunce = pricePack / packVol;
//
//    cout << "The price per ounce is: "
//                    << fixed << setprecision(2) << pricePerOunce;

/*STRING FORMATTING*/
    string f = "Hello, world!";

    string name, lastName;
    cin >> name >> lastName;
    cout << name << " " << lastName;
    cout << f.substr(7, 2) << f.substr(3, 2) << f.substr(3, 2) << f[0];


}
