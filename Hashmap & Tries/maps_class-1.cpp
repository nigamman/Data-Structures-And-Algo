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

}