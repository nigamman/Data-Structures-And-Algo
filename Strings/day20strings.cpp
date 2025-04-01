#include <iostream> 
#include <string.h>
using namespace std;

int main () {

    string name = "String"; //initiallize
    //cin >> name; //take input from user
    //getline(cin,name); // Reads a full line of input and print

    cout << "Printing the value of string: " << name << endl; //output
    cout <<"at index: " << name.at(3) << endl;
    cout << "Find Length: " << name.length() << endl;
    cout << "First Char: " << name.front() << endl;
    cout << "Back Char: " << name.back() << endl;


    string str1 = "Love";
    string str2 = "Hate";
    str1.append(str2); // str 1 mein 2 ko add kar diya
    cout << str2 << endl;

    string desc = "hi! how are you ?";
    desc.erase(4,1); // (kahan se, kitna) spaces are not included
    cout << desc << endl;

    string start = "Jai Ram";
    string middle = "Siya";
    start.insert(4, middle);
    cout << start << endl;

    string word = "Clone";
    cout << word << endl;

    word.push_back('d');
    cout << word << endl;

    word.pop_back();
    cout << word << endl;

    string str3 = "Why are you?";
    string str4 = "sorry";
    if (str3.find(str4) == string::npos) { // npos == no position found 
        //not found 
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found" << endl;
    }
 
    string str5 = "Hello";
    string str6 = "Hello";

    if (str5.compare(str6) == 0) {
        cout << "Matching" << endl;
    }
    else { 
        cout << "Not Matching" << endl;
    }

    string desc1 = "My Name Is Khan, What's your name buddy";
    cout << desc1.substr(2,9) << endl; //space included & 2 & 9 are not included

}