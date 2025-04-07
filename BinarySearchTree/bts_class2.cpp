#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertBST(Node* &root, int &data) {
    //if the root is null it means the tree is empty so we create the new node of root
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    //now, we call recursion for the right subtree, so we make sure the data is greater than the root node
    if(data > root->data) {
        root->right = insertBST(root->right, data);
    }
    else{
        //in this case the data will be lesser than the root node
        root->left = insertBST(root->left, data);
    }
    return root;
}
void createBST(Node* &root) {
    cout<< "Enter the root: " << endl;
    int data;
    cin >> data;

    while(data != -1) {
        root = insertBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}
void levelOrderBST(Node* root) {
    if(root==NULL) {
        return;
    }
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
}
Node* BSTFromInorder(vector<int> &inorder, int s, int e) {
    if (s > e) return NULL;
    int mid = s + (e-s) / 2;

    //create new node for the mid element
    Node* root = new Node(inorder[mid]);

    //reursive calls for the left and right subtree
    root->left = BSTFromInorder(inorder, s, mid-1);
    root->right = BSTFromInorder(inorder, mid+1, e);

    return root;
}
int main() {
    vector <int> inorder{2,4,6,8,10};
    int start = 0;
    int end = inorder.size()-1;
    Node* root = BSTFromInorder(inorder, start, end);
    levelOrderBST(root);
}