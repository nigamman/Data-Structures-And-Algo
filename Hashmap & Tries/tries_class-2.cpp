#include <iostream>
#include <vector>
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
    }
};
void insertWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    
    if(root->children[index] != NULL) {
        //present
        child = root->children[index];
    }
    else {
        //absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    //recursion
    insertWord(child, word.substr(1));
}
void storeString(TrieNode* root, vector<string>& ans, string &input, string &prefix) {
    //base case
    if(root->isTerminal == true) {
        //ans store
        ans.push_back(prefix + input);
        //return
    }

    for(char ch = 'a'; ch <= 'z'; ch++) {
        int index = ch - 'a';
        TrieNode* next = root->children[index];
        if(next != NULL) {
            //child exist
            input.push_back(ch);
            //baaki recursion
            storeString(next, ans, input, prefix);
            //backtrack
            input.pop_back();
        }
    }
}
void findPrefixString(TrieNode* root, string input, vector<string>& ans, string & prefix) {
    //base case
    if(input.length() == 0) {
        TrieNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL) {
        //child present
        child = root->children[index];
    }
    else {
        return;
    }
    //recursion
    findPrefixString(child, input.substr(1), ans, prefix);
}
vector<vector<string> > getSuggestions(TrieNode* root, string input) {

    vector<vector<string> > output;
    TrieNode* prev = root;
    string inputhelper = "";
  
    for(int i=0; i<input.length(); i++) {
      char lastchar = input[i];
      int index = lastchar - 'a';
      TrieNode* curr = prev->children[index];
  
      if(curr == NULL) {
        break;
      }
      else {
        vector<string> nicheKaAns;
        inputhelper.push_back(lastchar);
        string dummy = "";
        storeString(curr, nicheKaAns, inputhelper, dummy);
        output.push_back(nicheKaAns);
        //important
        prev = curr;
      }
  
    }
    return output;
  }

int main() {
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
  
    string input = "l";
    string prefix = input;
    vector<string> ans;

    findPrefixString(root, input, ans, prefix);

    for(auto i: ans) {
        cout << i << " " << endl;
    }
    cout << endl;

    // vector<vector<string>> ans = getSuggestions(root,"loa");
    // //printing ans
    // for(int i=0; i<ans.size(); i++) {
    //     cout << i << "-> ";
    //     for(auto str: ans[i]) {
    //         cout << str << ", ";
    //     } 
    //     cout << endl;
    // }
}