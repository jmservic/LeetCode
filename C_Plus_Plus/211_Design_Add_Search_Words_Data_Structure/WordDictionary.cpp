#include <string>
#include <unordered_map>
#include <memory>
#include <stack>
using namespace std;

class WordDictionary {
private:
    struct Node {
        unordered_map<char, unique_ptr<Node>> links;
        bool wordEnd;
    };

    unique_ptr<Node> root;

public:
    WordDictionary(): root(make_unique<Node>()) {
        
    }
    
    void addWord(string word) {
        Node * currNode = root.get();

        for (char letter : word) {
            if (!currNode->links.contains(letter)) {
                currNode->links.insert(make_pair(letter, make_unique<Node>()));
            }
            currNode = currNode->links[letter].get();
        }

        currNode->wordEnd = true;
    }
    
    bool search(string word) {
        Node * currNode;
        stack<pair<Node *, int>> visitNodes;
        visitNodes.push(make_pair(root.get(), 0));

        while (!visitNodes.empty()) {
            auto currPair = visitNodes.top();
            visitNodes.pop();
            currNode = currPair.first;
            int index = currPair.second;
            if (index == word.length() && currNode->wordEnd){
                return true;
            }
            
            char letter = word[index];

            if (letter == '.') {
                for (auto it = currNode->links.begin(); it != currNode->links.end(); ++it){
                    visitNodes.push(make_pair(it->second.get(), index + 1));
                }
                continue;
            }

            if (!currNode->links.contains(letter)) {
                continue;
            }

            visitNodes.push(make_pair(currNode->links[letter].get(), index + 1));
        }

        return false;        
    }
};