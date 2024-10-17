struct Node {
    char val;
    vector<Node*> children;
    Node* parent;
    bool terminal = false;
    Node(char value){
        val = value;
    }
};



class Solution {
public:
    Node* root = new Node(' ');
    unordered_set<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        res.clear();
        build_tree(words);
        Node* cur = root;
        for(int i = 0; i<board.size(); i ++){
            for(int j = 0; j<board[i].size(); j++){

                dfs(i,j,board, cur, "");
            
            }
        }
        for(string i : res){
            sol.push_back(i);
        }
        return sol;
    }

    void dfs(int i, int j, vector<vector<char>>& board, Node* & p, string word){
        int row = board.size(), col = board[0].size();
        Node* cur = p;
        if(i < 0 || j < 0 || i >= row || j >= col || cur == nullptr){
            return ;
        }
        bool found = false;
        for(Node* child : cur->children){
            if(board[i][j] == child->val){
                cur = child;
                word = word + child->val;
                found = true;
                if(child->terminal){
                    res.insert(word);
                }
                
            }
        }
        if(!found){
            return;
        }
        char c = board[i][j];
        board[i][j] = '*';
        dfs(i-1,j,board,cur,word);
        dfs(i+1,j,board,cur,word);
        dfs(i,j-1,board,cur,word);
        dfs(i,j+1,board,cur,word);
        board[i][j] = c;
    }


    void build_tree(vector<string>& words){
        for(string s : words){
            Node* cur = root;
            for(int i = 0; i<s.size(); i++){
                bool found = false;
                for(Node* p : cur->children){
                    if(p->val == s[i]){
                        found = true;
                        cur = p;
                        break;
                    }
                }
                if(!found){
                    
                    Node* n = new Node(s[i]);
                    n-> parent = cur;
                    cur->children.push_back(n);
                    cur = n;
                    
                }
                if(i == s.size()-1){
                    cur->terminal = true;
                }
                
            }
        }
        
        return;
    }
    
};