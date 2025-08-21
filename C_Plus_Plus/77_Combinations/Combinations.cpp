#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> store;
        store.reserve(k);
        CreateCombinations(combinations, store, n, k, 1);
        return combinations;
    }

    void CreateCombinations(vector<vector<int>> &combinations, vector<int> &store, const int &n, const int &k, int start) {
        for (int i = start; i <= n - k + store.size() + 1; ++i) {
            store.push_back(i);
            if (store.size() == k) {
                combinations.push_back(store);
            } else {
                CreateCombinations(combinations, store, n, k, i + 1);
            }
            store.pop_back();
        }
    }
};