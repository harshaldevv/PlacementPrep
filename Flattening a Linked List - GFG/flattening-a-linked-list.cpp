// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root == nullptr || root->next == nullptr){
       return root;
   }
   
   
   Node *nxt = flatten(root->next);
   
   
   // now my root and root->next are to be merged
   
   Node *p = root;
   Node *q = nxt;
   
   Node *newhead, *newtail;
   
   if(p->data <= q->data){
       newhead = p;
       newtail = p;
       p = p->bottom;
   }
   else{
       newhead = q;
       newtail = q;
       q = q->bottom;
   }
   
   while( p!= nullptr && q != nullptr){
       
       if(p->data <= q->data){
           newtail->bottom = p;
           newtail = newtail->bottom;
           p = p->bottom;
       }
       else{
           newtail -> bottom = q;
           newtail = newtail->bottom;
           q = q->bottom;
       }
   }
   
   if(q == nullptr){
       newtail->bottom = p;
   }
   if(p == nullptr){
       newtail->bottom = q;
   }
   
   newhead->next = nullptr; // this is important, warna we can access the other
   // nodes using the next pointer
   // but jab merge ho jayega ek list me toh head ka next should not give 
   // access to other nodes na.. head ka next toh null hona chahiye
   // cuz sare nodes ab head ke neeche aake lag gaye hai
   
   return newhead;
}

