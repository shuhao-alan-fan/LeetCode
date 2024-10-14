struct Node{
    char val;
    bool terminal;
    vector<Node*> children = {};
    Node(char value){
        this->val = value;
        this->terminal = false;
    }
};


class WordDictionary {
private:
    Node* root;
public:
    

    WordDictionary() {
        this->root = new Node(' ');
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c : word){
            bool found = false;
            for(Node* p : cur->children){
                if(c == p->val){
                    found = true;
                    cur = p;
                    break;
                }
            }
            if (!found){
                Node* n = new Node(c);
                cur->children.push_back(n);
                cur = n;
            }
        }
        cur->terminal = true;
        return ;
    }
    
    bool search(string word) {
        
        return search_helper(word,root);
 
    }

    bool search_helper(string word, Node* cur){
        for(int i = 0; i<word.size(); i++){
            bool found = false;
            if(word[i] == '.'){
                
                for(Node* p : cur->children){
                    // return search_helper(word.substr(i+1),p);
                    if(search_helper(word.substr(i+1),p)){
                        return true;
                    }
                }
                return false;
            }
            else{
                for(Node* p : cur->children){
                    if(word[i] == p->val){
                        found = true;
                        cur = p;
                        break;
                    }
                }
                if(!found){
                    return false;
                }
            }
        }
        cout<<cur->val<<endl;
        return cur->terminal;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */