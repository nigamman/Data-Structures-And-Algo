#include<iostream>
#include<unordered_map>

using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val) {
            this->value = val;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};
//insertion
void insertWord(TrieNode* root, string word) {
    // cout << "Receieved Word: " << word << " for insertion " << endl;  //uncommment this line to see how insertion working
    //base case 
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL) {
        //element present
        child = root->children[index];
    }
    else {
        //element is not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    //recursion 
    insertWord(child,word.substr(1));
}

//searching word
bool searchWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        //present
        child = root->children[index];
    }
    else {
        //not found
        return false;
    }
    //bakki recursion sabhal lega
    bool recursionKaAns = searchWord(child,word.substr(1));
    return recursionKaAns;
}
void deleteWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else{
        //not present
        return;
    }
    deleteWord(child, word.substr(1));
}
int main () {
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout << "Insertion Done!" << endl;

    if(searchWord(root, "cat")) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    deleteWord(root, "cat");

    if(searchWord(root, "cat")) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}