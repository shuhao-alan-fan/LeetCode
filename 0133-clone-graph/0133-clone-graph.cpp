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
    unordered_map<int,Node*> map;
    Node* cloneGraph(Node* node){
        if(!node) return nullptr;
        if(map.find(node->val) != map.end()) return map[node->val];

        Node* copy_node = new Node(node->val);
        map[node->val] = copy_node;
        for(Node* n : node->neighbors){
            
            copy_node->neighbors.push_back(cloneGraph(n));
        
        }
        return copy_node;
    }
    
};