// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}



 // } Driver Code Ends
//User function template for C++

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution{
  public:
  bool helper(Node* root, int target, vector<int> &ans){
      if(root == nullptr){
          return false;
      }
      
      if(root->data == target){
          //ans.push_back(root->data);
          return true;
      }
      
      bool left = helper(root->left, target, ans);
      
      if(left == true){
          ans.push_back(root->data);
          return true;
      }
      
      // left = false
      bool right = helper(root->right, target, ans);
      if(right == true){
          ans.push_back(root->data);
          return true;
      }
      
      // right = false;
      // therefore na hi left me mila na hi right me
      
      return false;
      
    //   ans.push_back(root->data);
      
    //   bool left = helper(root->left, target, ans);
      
    //   bool right = false;
    //   if(!left){
    //       right = helper(root->right, target, ans);
    //   }
    //   else{
    //       return true;
    //   }
      
    //   if(right == true){
    //       return true;
    //   }
      
    //   // else right me bhi nahi mila mtlb pop kardo 
    //   ans.pop_back();
    //   return false;
  }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code he
         
         vector<int> ans;
         
         helper(root,target, ans);
         return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin, s);
        
        int target;
        cin>>target;
        getchar();
        
        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root,target);
        for(int i = 0;i<nodes.size();i++){
            cout<<nodes[i]<<" ";
        }
        cout<< endl;
    }
    return 1;
}
  // } Driver Code Ends