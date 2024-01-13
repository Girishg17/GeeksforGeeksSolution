//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
public:
    Node* insertionSort(struct Node* head)
    {
        vector<int> v;
        Node *p = head;
        
        while(p) 
        {
            v.push_back(p->data);
            p = p->next;
        }
        
        for(int i = 1; i < v.size(); i++) 
        {
            int temp = v[i], j = i - 1;
            
            while(j >= 0 and v[j] > temp) 
            {
                v[j + 1] = v[j];
                j--;
            }
          
            v[j + 1] = temp;
        }
        
        Node *dummy = new Node(0);
        p = dummy;
        
        for(auto i: v) 
        {
            p->next = new Node(i);
            p = p->next;
        }
        
        return dummy->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends