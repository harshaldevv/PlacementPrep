class TrieNode {
public:
    bool is_word;
    unordered_map<char, TrieNode*> children;
    TrieNode(): is_word(false) {}
};

class Solution {
public:
    // HCI RESEARCH
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (const char& c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
        vector<string> ans;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, "", ans);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string word, vector<string>& ans) {
        if (node->is_word) {
            ans.push_back(word);
            node->is_word = false;  // avoid duplicates
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || !node->children.count(board[i][j])) {
            return;
        }
        char c = board[i][j];
        board[i][j] = '#';  // mark cell as visited
        dfs(board, i+1, j, node->children[c], word+c, ans);
        dfs(board, i-1, j, node->children[c], word+c, ans);
        dfs(board, i, j+1, node->children[c], word+c, ans);
        dfs(board, i, j-1, node->children[c], word+c, ans);
        board[i][j] = c;  // unmark cell
    }
};
