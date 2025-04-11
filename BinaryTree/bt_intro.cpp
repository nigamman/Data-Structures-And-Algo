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
    cout << "Enter the value: " << endl;
    int data;
    cin >> data;
    
    if(data == -1) {
        return NULL;
    }
    //Step1: create node
    Node* root = new Node(data);
    //Step2: create left subtree
    cout<<"Left of node: "  << root->data << endl;
    root->left = createTree();
    //Step3: create right subtree
    cout <<"right of node: " << root->data << endl;
    root->right = createTree();
}

//preorder
void preOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    //N L R
    //Node
    cout << root->data << " ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

//inorder
void inOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    //L N R
    //L
    inOrderTraversal(root->left);
    //N
    cout << root->data << " ";
    //R
    inOrderTraversal(root->right);
}

//postorder 
void postOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    //L R N
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->data << " ";
}

//Level Order
void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //asli traversal start hoga
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front != NULL) {
            cout << front->data << " ";

            if(front->left != NULL) {
                q.push(front->left);
            }
            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    
        //jahan pr front null nhi hoga
        else{
            cout << endl;
            if(!q.empty()) {
               q.push(NULL); 
            }     
        }
    }

    if(root == NULL) {
        return;
    }

}
int main() {

    Node* root = createTree();
    
    cout << "Printing Inorder: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Printing Preorder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing Postorder: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Printing Level-wise: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}