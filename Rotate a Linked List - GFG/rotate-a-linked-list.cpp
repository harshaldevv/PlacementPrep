// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // Your code here
        int l =1;
        Node* curr = head;
        while(curr->next != nullptr ){
            l++;
            curr=curr->next;
        }
        
        k = k%l;
        // cout << " k = " << k << endl;
        if(k == 0){
            return head;
        }
        
        // now move tempNode by k times
        Node *temp = head;
        for(int i = 0 ; i < k-1 ; i++){
            temp= temp->next;
        }
        
        Node *nxt = temp->next;
        
        //break link
        temp->next = nullptr;
        
        Node *temp2 = nxt;
        
        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }
        
        temp2->next = head;
        
        return nxt;
        
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends