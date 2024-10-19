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