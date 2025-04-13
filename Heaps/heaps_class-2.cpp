#include <iostream>
#include <queue>
#include <vector>
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

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    }
    else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node*& root) {
    cout << "Enter data (-1 to stop): " << endl;
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data (-1 to stop): " << endl;
        cin >> data;
    }
}

void levelOrderBST(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        }
        else {
            cout << front->data << " ";
            if (front->left != NULL) q.push(front->left);
            if (front->right != NULL) q.push(front->right);
        }
    }
}

void findInOrder(Node* root, vector<int>& inorder) {
    if (root == NULL) return;

    findInOrder(root->left, inorder);
    inorder.push_back(root->data);
    findInOrder(root->right, inorder);
}

void replaceUsingPostorder(Node* root, vector<int>& inorder, int& index) {
    if (root == NULL) return;

    replaceUsingPostorder(root->left, inorder, index);
    replaceUsingPostorder(root->right, inorder, index);
    root->data = inorder[inorder.size() - 1 - index];
    index++;
}

void convertBSTToMaxHeap(Node* root) {
    vector<int> inorder;
    findInOrder(root, inorder);
    int index = 0;
    replaceUsingPostorder(root, inorder, index);
}
int kthSmallest (int arr[], int n, int k) {

    priority_queue<int>maxHeap;

    //step1- first push k elements in the maxHeap
    for(int i=0; i<k; i++) {
        maxHeap.push(arr[i]);
    }

    //step2- after pushing k elements, comparing the values of max heap top element and arr[i] element and push the smallest element
    for(int i=k; i<n; i++) {
        if(maxHeap.top() > arr[i]) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}
int findKthLargest(int nums[], int n, int k) {
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(int i =0; i < k; i++) {
        minHeap.push(nums[i]);
    }
    for(int i=k; i<n; i++) {
        if(minHeap.top() < nums[i]) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}

int main() {
    Node* root = NULL;
    createBST(root);

    cout << "\nBST (Level Order):" << endl;
    levelOrderBST(root);

    convertBSTToMaxHeap(root);

    cout << "\nMax Heap (Level Order):" << endl;
    levelOrderBST(root);

    return 0;


//    int arr[] = {12,34,5,2,12,43,1};
//    //int ans = kthSmallest(arr, 7, 5);
//    int ans = findKthLargest(arr,7,2);
//    cout << "Answer is: " << ans << endl;
//    return 0;

}