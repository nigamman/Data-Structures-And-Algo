#include <iostream>
using namespace std;

// int increamentBy1 (int  &n) {
//     n += 1;
//     return n;  
// }

// int main () {
//     int n = 5;
//     increamentBy1(n);
//     cout << n << endl;

//     return 0;

// }

// int passByValue (int a) {
//     a--;
//     a/=7;
//     cout << a << endl;
// }
// int main () {
//     int a = 9;
//     a++;
//     a*=5;
//     passByValue(a);
//     cout << a << endl;
// }

int passByValue (int m) {
    m--;
    m *= 10;
    
    cout << m << endl;
}
int main () {
    int m = 90;
    m++;

    passByValue(m);

    cout << m << endl;                                            
}