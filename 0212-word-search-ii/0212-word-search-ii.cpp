struct Node {
    char val;
    unordered_map<char, Node*> children;
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
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] == '*' || cur == nullptr){
            return ;
        }
        
        
        if(cur->children.find(board[i][j]) != cur->children.end()){
            word = word + board[i][j];
            
            cur = cur->children[board[i][j]];
            if(cur->terminal){
                res.insert(word);
            }
            
        }
        else{
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
            for(char c : s){
                if(cur->children.find(c) == cur->children.end()){
                    cur->children[c] = new Node(c);
                }
                cur = cur->children[c];
            }
            cur->terminal = true;
        }
        
        return;
    }
    
};