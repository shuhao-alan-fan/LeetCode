#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    char val;
    unordered_map<char, Node*> children;
    bool terminal = false;
    Node(char value) : val(value) {}
};

class Solution {
public:
    Node* root = new Node(' ');
    unordered_set<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        res.clear();
        build_tree(words);
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dfs(i, j, board, root, "", visited);
            }
        }
        for(const string& word : res) {
            sol.push_back(word);
        }
        return sol;
    }

private:
    void dfs(int i, int j, vector<vector<char>>& board, Node* cur, string word, vector<vector<bool>>& visited) {
        int row = board.size(), col = board[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col || visited[i][j] || cur == nullptr) {
            return;
        }

        char c = board[i][j];
        if(cur->children.find(c) == cur->children.end()) {
            return;
        }

        visited[i][j] = true;
        cur = cur->children[c];
        word += c;
        if(cur->terminal) {
            res.insert(word);
        }

        dfs(i-1, j, board, cur, word, visited);
        dfs(i+1, j, board, cur, word, visited);
        dfs(i, j-1, board, cur, word, visited);
        dfs(i, j+1, board, cur, word, visited);

        visited[i][j] = false;
    }

    void build_tree(const vector<string>& words) {
        for(const string& word : words) {
            Node* cur = root;
            for(char c : word) {
                if(cur->children.find(c) == cur->children.end()) {
                    cur->children[c] = new Node(c);
                }
                cur = cur->children[c];
            }
            cur->terminal = true;
        }
    }
};