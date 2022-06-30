/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == nullptr){
            return s;
        }
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                if(front == nullptr){
                    s+="#,";
                }
                else{
                    s+=(to_string(front->val) +",");
                }
                if(front != nullptr){
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        
        cout << s << endl;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return nullptr;
        }
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        // stoi(str);
        TreeNode *root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                getline(s, str, ',');
                if(str == "#"){
                    front->left = nullptr;
                }
                else{
                    TreeNode *temp = new TreeNode(stoi(str));
                    front->left = temp;
                    q.push(temp);
                }
                
                getline(s, str, ',');
                if(str == "#"){
                    front->right = nullptr;
                }
                else{
                    TreeNode * temp = new TreeNode(stoi(str));
                    front->right = temp;
                    q.push(temp);
                }
            }
        }
        
        return root;
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));