#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
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
                if (root->children.find(board[i][j]) != root->children.end()) {
                    dfs(i, j, board, root, "", visited);
                }
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
        stack<tuple<int, int, Node*, string>> stk;
        stk.push({i, j, cur, word});

        while (!stk.empty()) {
            auto [x, y, node, currentWord] = stk.top();
            stk.pop();

            if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || node == nullptr) {
                continue;
            }

            char c = board[x][y];
            if (node->children.find(c) == node->children.end()) {
                continue;
            }

            visited[x][y] = true;
            node = node->children[c];
            currentWord += c;
            if (node->terminal) {
                res.insert(currentWord);
            }

            stk.push({x-1, y, node, currentWord});
            stk.push({x+1, y, node, currentWord});
            stk.push({x, y-1, node, currentWord});
            stk.push({x, y+1, node, currentWord});

            visited[x][y] = false;
        }
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