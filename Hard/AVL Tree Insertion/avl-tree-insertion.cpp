//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
public:
    /*You are required to complete this method */

    Node* insertToAVL(Node* node, int data) {
        // Your code here
        if (node == NULL) return new Node(data); // Create a new node if the current node is NULL

        if (data < node->data) {
            node->left = insertToAVL(node->left, data);
        } else if (data > node->data) {
            node->right = insertToAVL(node->right, data);
        }

        // Update height and perform rotations if needed
        updateHeight(node);
        return balance(node);
    }

    int height(Node* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        if (node == NULL) return;
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* balance(Node* node) {
        if (node == NULL) return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            // Left-Right Case
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            // Left-Left Case
            return rotateRight(node);
        }
        // Right Heavy
        if (balance < -1) {
            // Right-Left Case
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            // Right-Right Case
            return rotateLeft(node);
        }

        return node;
    }
};


//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends