#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int val) {
        this -> data = val;
        Node* left;
        Node* right;
    }
};
Node* insertIntoBST(Node* root, int data) {
	if(root == NULL) {
		root = new Node(data);
		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}
Node* createTree() {
    cout << "Enter the value of the node: " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    } 
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

     Node* front = q.front();
     q.pop();

        if(front!= NULL) {
            cout << front->data << " ";
        
            if(front->left != NULL) {
                q.push(front->left);
            }
            if(front->right != NULL) {
                q.push(front->right);
            }
        }
        else {
            //front == NULL
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        if (root == NULL) {
            return;
        }
    }
}
void convertBSTtoDLL(Node* root, Node* &head) {
    if(root == NULL) {
        return;
    }
    //recursive call for right subtree
    convertBSTtoDLL(root->right, head);

    // MANNUL TASK FOR ROOT NODE
    //attaching next pointer of current node to head of LL
    root->right = head;
    //attaching prev pointer of head of LL to current node
    if(head!=NULL) {
        head ->left =root;
    }
    //head update
    head = root;

    //recursive call for left subtree
    convertBSTtoDLL(root->left, head);

}
Node* convertDLLtoBST(Node* &head, int n) {
    if (head == NULL || n <= 0) {
        return NULL;
    }
    //LNR
    Node* leftSubtree = convertDLLtoBST(head, n/2);

    //N
    Node* root = head;
    root->left = leftSubtree;
    //head update
    head = head->right;

    //R
    Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
    root->right = rightSubtree;
    return root;
}
void printLinkedList(Node* head) {
	Node* temp = head;
	cout << "printing the entire list: " << endl;
	while(temp != NULL) {
		cout << temp->data <<"->";
		temp = temp->right;
	}
	cout << endl;
}

int main () {

    int inorder[] = {10,20,30,40,50,60};
    int size = 6;
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;
    //10<->20<->30

    Node* root = convertDLLtoBST(head, 3);
    levelOrder(root);
	

}