#include <vector>
#include <string>
#include <memory>
#include <algorithm>


using namespace std;

class Solution {
private:
    struct TrieNode {
        unique_ptr<TrieNode> nodes[26];
        bool wordEnd = false;
    };

    unique_ptr<TrieNode> root;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> foundWords;
        root = make_unique<TrieNode>();
        int cols = board[0].size(), rows = board.size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        string word;

        for (string word : words) {
            auto currNode = root.get();
            for (char l : word) {
                int index = l - 'a';
                if (currNode->nodes[index].get() == nullptr) {
                    currNode->nodes[index] = make_unique<TrieNode>();
                }
                currNode = currNode->nodes[index].get();
            }
            currNode->wordEnd = true;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                auto startNode = root.get()->nodes[board[i][j] - 'a'].get();
                if(!startNode) continue;
                word.push_back(board[i][j]);
                dfs(visited, board, i, j, foundWords, startNode, word);
            }
        }

        return foundWords;
    }
        
        void dfs(vector<vector<bool>> &visited, vector<vector<char>>& board, int row, int col, vector<string> &foundWords, TrieNode * node, string &word) {
            visited[row][col] = true;
            char letter;
            TrieNode * nextNode;
            
            if (node->wordEnd && find(foundWords.begin(), foundWords.end(), word) == foundWords.end()){
                foundWords.push_back(word);
            }

            //above index
            if (row > 0 && !visited[row - 1][col]) {
                letter = board[row - 1][col];
                nextNode = node->nodes[letter - 'a'].get();
                if (nextNode) {
                    word.push_back(letter);
                    dfs(visited, board, row - 1, col, foundWords, nextNode, word);
                }
            }

            //right index
            if (col < board[0].size() - 1 && !visited[row][col + 1]) {
                letter = board[row][col + 1];
                nextNode = node->nodes[letter - 'a'].get();
                if (nextNode) {
                    word.push_back(letter);
                    dfs(visited, board, row, col + 1, foundWords, nextNode, word);
                }
            }

            //bottom index
            if (row < board.size() - 1 && !visited[row + 1][col]){
                letter = board[row + 1][col];
                nextNode = node->nodes[letter - 'a'].get();
                if (nextNode) {
                    word.push_back(letter);
                    dfs(visited, board, row + 1, col, foundWords, nextNode, word);
                }
            }

            //left index
            if (col > 0 && !visited[row][col - 1]) {
                letter = board[row][col - 1];
                nextNode = node->nodes[letter - 'a'].get();
                if (nextNode) {
                    word.push_back(letter);
                    dfs(visited, board, row, col - 1, foundWords, nextNode, word);
                }
            }

            visited[row][col] = false;
            if (!word.empty()){
                word.pop_back();
            }
        }
};