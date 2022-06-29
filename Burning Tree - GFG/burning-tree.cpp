// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  unordered_map<Node*, Node*> mp;
  unordered_map<Node*, bool> visited;
  int time ;
  Node* TAR;
  
 void getPar(Node* root, int target){
     if(root == nullptr){
         return ;
     }
     
     queue<Node*> q;
     q.push(root);
     
     while(!q.empty()){
         int sz = q.size();
         while(sz--){
             auto front = q.front();
             q.pop();
             
             int val = front->data;
             if(val == target){
                 TAR = front;
             }
             
             if(front->left){
                 mp[front->left] = front;
                 q.push(front->left);
             }
             if(front->right){
                 mp[front->right] = front;
                 q.push(front->right);
             }
         }
     }
     return;
 }
 
 void solve(int target){
     Node *start = TAR;
     queue<Node*> q;
     
     q.push(start);
     visited[start] = true;
     
     while(!q.empty()){
         int sz = q.size();
         bool burnedSomething = false;
         
         while(sz--){
             auto front = q.front();
             q.pop();
             //cout << front->data << " " ;
             
             // going LEFT (down)
             if(front->left && !visited[front->left] ){ 
                 // unvisited
                visited[front->left] = true;
                q.push(front->left); 
                burnedSomething = true;
             }
             
             if(front->right && !visited[front->right]){
                // unvisited
                 visited[front->right] = true;
                 q.push(front->right);
                 burnedSomething = true;
             }
            //  cout <<"mpfront = " << mp[front]->data << endl;
             if(mp[front] && !visited[mp[front]]){
                 visited[mp[front]] = true;
                 q.push(mp[front]); 
                 burnedSomething = true;
             }
         }
         
         if(burnedSomething){
             time++;
         }
     }
     
     return ;
 }
 
 
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        time = 0;
        // make undirected graph
        
        getPar(root, target);
        //cout << "map size = " << mp.size() << endl;
        solve(target);
        
        return time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends