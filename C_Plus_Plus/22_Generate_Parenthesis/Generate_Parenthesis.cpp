#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        worker(result, temp, n, 1);
        return result;
    }

    void worker(vector<string> &result, string &store, int n, int depth) {
        if (depth > n) return;
        size_t storeLen = store.size();

        store.push_back('(');
        worker(result, store, n, depth + 1);

        while(store.size() < depth * 2) {
            store.push_back(')');
            worker(result, store, n, depth + 1);
        }

        if (depth == n) {
            result.push_back(store);
        }

        store.erase(storeLen);
    }
};