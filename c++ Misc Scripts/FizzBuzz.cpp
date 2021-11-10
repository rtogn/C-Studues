// ask for a person's name, and greet the person
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <cmath>
using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

string fb(int i, int mod, string toPrint) {
    if ( i % mod == 0 )
        return toPrint;
    return "";
}
int main()
{
    string str;
    for(int i = 1; i <= 100; i++) {
        str = "";
        str += fb(i, 3, "fizz");
        str += fb(i, 5, "buzz");

        if(str.empty()) cout<<i<<endl;
        else cout<<str<<endl;




    }
        double p = 4.33;
        int cents = 100 * p +0.0;
        cout << cents;
}
