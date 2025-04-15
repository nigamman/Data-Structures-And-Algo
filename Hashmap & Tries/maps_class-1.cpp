#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    //creation
    unordered_map<string,int> mapping;

    //insertion
    pair<string, int> p = make_pair("hashmap", 23);

    pair<string,int> q("pointers", 21);

    pair<string,int> r;
    r.first = "arun";
    r.second = 22;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["babbar"] = 51;

    cout << "Size of the map: " << mapping.size() << endl;

    //access
    cout << mapping.at("arun") << endl;
    cout << mapping["pointers"] << endl;

    //searching
    cout << mapping.count("hashmap") << endl;

    if(mapping.find("pointrs") != mapping.end()) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    cout << "Size of map: " << mapping.size() << endl;
    cout << mapping["kumar"] << endl;
    cout << "Size of map: " << mapping.size() << endl;
    
    return 0;
}