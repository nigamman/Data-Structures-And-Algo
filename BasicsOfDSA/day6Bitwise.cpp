#include <iostream>
using namespace std;

int main () {
    int a = 5;
    int b = 5;

    //AND operator
    cout << (a & b) << endl;
    
    //OR operator
    cout << (a | b) << endl;

    // XOR operator
    cout << (a ^ b) << endl;

    //left & right operator
    cout << (a << b) << endl;
    cout << (a >> b) << endl;

    //NOT operator
    int c = 1;
    cout << ~c << endl; 

 //PRE / POST INCREAMENT DECREAMENT
 int x = 10;
 cout << (++x)*(x++) << endl;

 //BREAK 
  for (int i=0; i<10; i++) {
     if(i==4) {
         break; 
        }
     cout << i << endl;
    }

 //CONTINUE
   for(int j=0; j<= 8; j++) {
       if(j==4) {
         continue;
        } 
      cout << j << endl;
    }
}                           
