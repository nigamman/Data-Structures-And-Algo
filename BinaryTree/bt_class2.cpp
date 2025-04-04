#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        Node* left;
        Node* right;
    }
};
Node* createTree() {
    cout << "Enter the value of the data" << endl;
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }
     //Step1: create node
     Node* root = new Node(data);
     //Step2: create left subtree
     //cout<<"Left of node: "  << root->data << endl;
     root->left = createTree();
     //Step3: create right subtree
     //cout <<"right of node: " << root->data << endl;
     root->right = createTree();
}

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    //N L R
    cout << root->data << " ";
    root->left = createTree();
    root->right = createTree();
}
void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    //L N R
    root->left = createTree();
    cout << root->data << " ";
    root->right = createTree();
}
void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    //L R N
    root->left = createTree();
    root->right = createTree();
    cout << root->data << " ";
}
void levelOrder(Node* root) {
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
               q.push(NULL); 
            }     
        }
        //jahan pr front null nhi hoga
        else{
            cout << front->data << " ";

            if(front->left != NULL) {
                q.push(front->left);
            }
            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    }
     if(root == NULL) {
        return;
    }
}
void printleftView(Node* root, int level, vector<int> &leftView) {
    if (root == NULL) {
        return;
    }
    if(level == leftView.size()) {
        leftView.push_back(root->data);
    }
    printleftView(root->left, level+1, leftView);
    printleftView(root->right, level+1, leftView);

}
void printRightView(Node* root, int level, vector<int> &rightView) {
    if(root == NULL) {
        return;
    }
    if(level == rightView.size()) {
        rightView.push_back(root->data);
    }
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}
int main () {
    Node* root = createTree();

    cout << "Printing Tree" << endl; ;
    levelOrder(root);
    cout << endl;

    vector <int> leftView;
    printleftView(root, 0, leftView);

    cout << "Printing Left View: " << endl;
    for(int i=0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }
    cout << endl;
    
    vector <int> rightView;
    printRightView(root, 0, rightView);
    cout << "Printing Right View: " << endl;
    for(int i=0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }

    

}