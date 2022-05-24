// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *rev(Node *head){
        Node *curr = head;
        Node *prev = nullptr;
        Node *nxt;
        
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first == nullptr){
            return second;
        }
        else if(second == nullptr){
            return first;
        }
        
        Node *p1 = rev(first);
        Node *p2 = rev(second);
        
        int carry = 0;
        int sum;
        
        Node *dummy = new Node (-1);
        Node *cursor = dummy;
        
        while(p1 || p2 || carry > 0){
            sum = 0;
            if(p1 != nullptr){
                sum += p1->data;
            }
            if(p2 != nullptr){
                sum += p2->data;
            }
            
            if(carry > 0 ){
                sum += carry;
                carry = 0;
            }
            
            carry = sum/10;
            sum %= 10;
            
            Node *temp = new Node(sum);
            cursor->next = temp;
            cursor = cursor->next;
            
            if(p1 != nullptr){
                p1 = p1->next;
            }
            
            if(p2 != nullptr){
                p2 = p2->next;
            }
        }
        
        
        Node *ans = rev(dummy->next);
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends