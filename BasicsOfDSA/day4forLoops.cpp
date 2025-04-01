#include <iostream>

using namespace std;

 int main () {

    // for (i=1; i < 5; i++) {
    //     cout << "Print";
    // }

    // for (int i=0; i < 2; i++) {
    //     cout << "Outer loop" << i << endl << endl;
         
    //     for (int j=0; j < 2; j++) { 
    //         cout << "Inner Loop" << j << endl;
    //     }
    // }

    //PATTERN BASED QUESTION!

    // //outer loop --> rows
    // for (int i=0; i<3; i++) {
    
    // //inner loop --> column
    //     for (int j=0; j<5; j++) {
    //         cout << "* ";
        
    //     }
    //         cout << endl;
    // }

//    outer loop 
//     for(int i=0; i<5; i++) {

//      inner loop
//         for(int j=0; j<5; j++) {
    
//             if (i==0 || i==4) {
//              cout << "* ";
//             }
//             else {
//                 if(j==0 || j==4) {
//                  cout << "* ";
//                 }
//                 else {
//                  cout << "  ";
//                 }
//             }
//         }
//         cout <<endl;
//  }
    int n;
    cin >> n;

    // for(int i=0; i<n; i++) {

    //     for(int j=0; j < i+1; j++) {
    //       cout << "* ";
    //     }
    //    cout << endl;
    // }
    
    // for(int i=0; i< n; i++) {

    //     for(int j=0; j < i+1; j++) {
    //         cout << j + 1 << " ";
    //     }
    //   cout << endl;
    // }

    for(int i=0; i<n; i++) {
        
        for(int j=0; j<n-i; j++) {
            cout << j+1 << " ";
        } 
      cout << endl;
    }
    

}  