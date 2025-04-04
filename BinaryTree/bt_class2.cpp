#include <iostream>
#include <queue>
#include <map>
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
void printTopView(Node* root) {
    map<int,int> hdToNodeMap;
    queue <pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //if there is no entry for horizontal distance(hd) in map, then create a new story
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()) {
            hdToNodeMap[hd] = frontNode->data;
        }
        //checking the child node
        if(frontNode->left != NULL) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "Printing Top View: " << endl;
    for(auto i: hdToNodeMap) {
        cout << i.second << " ";
    }
}
void printBottomView(Node* root) {
    map<int,int> hdToNodeMap;
    queue <pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //overwrite answer so that the deeper nodes can be stored
        hdToNodeMap[hd] = frontNode->data;

        //checking the child node
        if(frontNode->left != NULL) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "Printing Bottom View: " << endl;
    for(auto i: hdToNodeMap) {
        cout << i.second << " ";
    }
}
void printLeftBoundary(Node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }
    cout << root->data << " ";

    if(root->left != NULL) {
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}
void printRightBoundary(Node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }
    if(root->right!= NULL) {
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}
void printLeafBoundary(Node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}
void boundaryTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
    printRightBoundary(root->right);

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
    cout << endl;    
    printTopView(root);
    cout << endl;
    printBottomView(root);
    cout << endl;
    cout << "Printing Boundary Elements: " << endl;
    boundaryTraversal(root);
}