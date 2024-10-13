
struct Node{
        char val;
        vector<Node*> children = {};
        bool terminal;

        //constructor
        Node(char value){
            val = value;
            terminal = false;
        }
};

class Trie {
public:
    Node* root;
    Trie() {
        this->root = new Node(' ');
        this->root->terminal = false;
        
    }
    
    void insert(string word) {
        Node* cur = root;

        for(char c:word){
            bool found = false;
            for(Node* a : cur->children){
                if(c == a->val){
                    cur = a;
                    found = true;
                    break;
                }
            }
            if(!found){
                Node* n = new Node(c);
                cur->children.push_back(n);
                cur = n;
            }
            
        }
        cur->terminal = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char c:word){
            bool found = false;
            for(Node* a : cur->children){
                if(c == a->val){
                    cur = a;
                    found = true;
                    break;
                } 
            }
            if(!found) return false;
        }
    
        return cur->terminal;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i = 0; i<prefix.size(); i++){
            bool found = false;
            for(Node* a : cur->children){
                if(prefix[i] == a->val){
                    found = true;
                    if(i == prefix.size()-1) {
                        return true;
                    }
                    cur = a;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */