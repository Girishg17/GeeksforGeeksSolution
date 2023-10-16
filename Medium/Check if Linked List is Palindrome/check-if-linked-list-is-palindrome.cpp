//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL)return true;
        Node * slow=head;
        Node * fast=head;
        Node * prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        if(fast==NULL){
            prev->next=NULL;
            Node * prev1=NULL;
            Node * curr=slow;
            Node * follow=slow;
            while(curr){
                follow=follow->next;
                curr->next=prev1;
                prev1=curr;
                curr=follow;
            }
           
            while(prev1 && head){
                if(prev1->data !=head->data)return false;
                prev1=prev1->next;
                head=head->next;
            }
            if(prev1||head)return false;
            return true;
            
        }
        else{
            prev->next=NULL;
            slow=slow->next;
             Node * prev1=NULL;
            Node * curr=slow;
            Node * follow=slow;
            while(curr){
                follow=follow->next;
                curr->next=prev1;
                prev1=curr;
                curr=follow;
            }
           
            while(prev1 && head){
                if(prev1->data !=head->data)return false;
                prev1=prev1->next;
                head=head->next;
            }
            if(prev1||head)return false;
            return true;
        }
            
        
        return false;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends