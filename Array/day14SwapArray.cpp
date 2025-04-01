 #include <iostream>
 #include <vector>
 using namespace std; 

// void printArray(int arr[][4], int row, int col) {
//         for (int i=0; i<row; i++) {
//             for (int j=0; j<col; j++) {     
//                 cout << arr[i][j] << " ";
//             }           
//             cout << endl;
//         }
//     }

// void transpose(int arr[][4], int row, int col) {
//     for(int i=0; i<row; i++) {
//         for(int j=i; j<col; j++) {
//             swap(arr[i][j], arr[j][i]);
//         }
//     }
// }

int main () {
//     int arr[4][4] = {
//         {12,13,33,14},
//         {10,34,25,65}, 
//         {33,65,58,43},
//         {56,67,69,96},
//     };
//     int row = 4;
//     int col = 4;

//     cout << "Print Before Transpose" << endl;
//     printArray(arr, row, col); 
//     cout << "Print After Transpose"<< endl;
//     transpose(arr, row, col);
//     printArray(arr, row, col);

//     return 0;
//  }

    //int arr[5];
    //vector <int> arr;
    //vector <int> v(6,4);

    // arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(5);
    // arr.push_back(38);
    // arr.push_back(31);
    
    //cout << arr.size() << endl;
    // cout << "Sixe of Vector "<< v.size() << endl;

    // cout << "Printing the vector" << endl;

    // for (int i=0; i < v.size(); i++) {
    //     cout << v[i] << " " ;
    // }
    // cout << endl;

    // vector<vector<int>> arr(5, vector <int>(8,0));
    // //row size --> arr.size()
    // for(int i=0; i<arr.size(); i++) {
    //     for(int j=0; j<arr[i].size(); j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }   

    vector<vector<int>> arr;

    vector<int> vec1(8,0);
    vector<int> vec2(7,1);
    vector<int> vec3(6,2);
    vector<int> vec4(5,3);
    vector<int> vec5(4,2);

    arr.push_back(vec1);
    arr.push_back(vec2);
    arr.push_back(vec3);
    arr.push_back(vec4);
    arr.push_back(vec5); 

    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}  
