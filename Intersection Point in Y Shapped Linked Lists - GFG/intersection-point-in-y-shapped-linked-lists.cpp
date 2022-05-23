// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int length(Node * t){
    int l = 0;
    while(t->next != nullptr){
        l++;
        t = t->next;
    }
    
    return l;
}
int inter(Node *big, Node*small, int bigLength, int smallLength){
    int x = bigLength- smallLength;
    
    Node *temp = big;
    
    for(int i = 0 ; i < x ; i++){
        temp = temp->next;
    }
    
    while(temp != nullptr && small != nullptr){
        if(temp == small){
            return temp->data;
        }
        temp = temp->next;
        small = small->next;
    }
    
    return -1;
    
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1 == nullptr || head2 == nullptr){
        return -1;
    }
    
    int l1 = length(head1);
    int l2 = length(head2);
    
    if(l1 >l2){
        return inter(head1, head2, l1, l2);
    }
    else{
        return inter(head2, head1, l2, l1);
    }
    
    
}

