#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

class Trie {
private:
    struct Node
    {
        unordered_map<char, unique_ptr<Node>> links;
        bool wordEnd = false;
    };

    unique_ptr<Node> root;
    
public:
    Trie(): root(make_unique<Node>()) {
        
    }
    
    void insert(string word) {
        Node * current = root.get();
        for (char l : word)
        {
            if (!current->links.contains(l))
            {
                current->links.insert(make_pair(l, make_unique<Node>()));
            }
            current = current->links[l].get();
        }
        current->wordEnd = true;
    }
    
    bool search(string word) {
        Node * current = root.get();
        for (char l : word)
        {
            if(!current->links.contains(l))
            {
                return false;
            }
            current = current->links[l].get();
        }

        return current->wordEnd;
    }
    
    bool startsWith(string prefix) {
        Node * current = root.get();

        for (char l : prefix)
            {
                if(!current->links.contains(l))
                {
                    return false;
                }
                current = current->links[l].get();
            }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main() 
 {
    Trie trie;
    trie.insert("apple");
    trie.startsWith("app");
 }