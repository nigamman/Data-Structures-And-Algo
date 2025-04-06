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
Node* minValue(Node* root) {
    if(root == NULL) {
        return NULL;
    }
    Node* temp = root;

    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root) {
    if(root == NULL) {
        return NULL;
    }
    Node* temp = root;

    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}
void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}
bool searchInBST(Node* root, int target) {
    if(root == NULL) {
        return false;
    }
    if(root->data == target) {
        return true;
    }
    //else cases recursion will handle
    //if the target is less than root so we will search in left subtree
    bool rightAns = false;
    bool leftAns = false;
    if(target < root->data) {
        leftAns = searchInBST(root->left, target);
    }
    else{
        rightAns = searchInBST(root->right, target);
    }
    //so we use OR operator because either of left or right is true it's return true
    return leftAns || rightAns;
}
Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node to delete found
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* mini = minValue(root->right);
        root->data = mini->data;
        root->right = deleteNode(root->right, mini->data);
    }
    return root;
}
int main() {

    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Traversal" << endl;
    levelOrderBST(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    Node* minNode = minValue(root);

    if(minNode == NULL) {
        cout << "NOT VALID" << endl; 
    }
    else{
        cout << "MIN Element in the tree: " << minNode->data << endl;
    }

    Node* maxNode = maxValue(root);

    if(maxNode == NULL) {
        cout << "NOT VALID" << endl; 
    }
    else{
        cout << "MAX Element in the tree: " << maxNode->data << endl;
    }

    // int tar;
    // cout << "Enter the target: " << endl;
    // cin >> tar;

    // while(tar != -1) {
    //     bool ans = searchInBST(root, tar);
    //     if(ans == true) {
    //         cout << "Found" << endl;
    //     }
    //     else {
    //         cout << "Not Found" << endl;
    //     }
    //     cout << "Enter the targett: " << endl;
    //     cin >> tar;
    // } 

    int target;
    cout << "Enter the value of target: " << endl;
    cin >> target;
    
    while(target != -1) {
        root = deleteNode(root, target);
        cout << endl << "Printing Level Order Traversal: " << endl;
        levelOrderBST(root);

        cout << "Enter the target: " << endl;
        cin >> target;
    }


}