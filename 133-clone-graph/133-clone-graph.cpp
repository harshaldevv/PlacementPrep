/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    
    Node *clonee(Node *node){
    
        vector<Node*> neigh;
        
        Node *clone = new Node(node->val);
        
        mp[node] = clone;
        
        for(auto nextvertex : node->neighbors){
            if(mp.find(nextvertex) != mp.end()){
                // we have created a copy of this neighbour
                neigh.push_back(mp[nextvertex]);
            }
            else{
                neigh.push_back(clonee(nextvertex));
            }
        }
        
    
        clone->neighbors = neigh;
        
        return clone;
            
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        
        if(node->neighbors.size() == 0){
            Node *temp = new Node(node->val);
            return temp;
        }
        
        
        return clonee(node);
        
    }
};