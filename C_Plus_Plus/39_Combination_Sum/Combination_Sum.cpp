#include <vector>

using namespace std;
class Solution {
    int target;
    int sum ;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> store;
        this->target = target;
        sum = 0;
        CreateCombinations(candidates, combinations, store, 0);
        return combinations;
    }

    void CreateCombinations(vector<int> &candidates, vector<vector<int>> &combinations, vector<int> &store, int startIndex)
    {
        for (int i = startIndex; i < candidates.size(); ++i)
        {
            int candidate = candidates [i];
            if (sum + candidate > target) continue;
            sum += candidate;
            store.push_back(candidate);
            if (sum == target)
            {
                combinations.push_back(store);
            } else 
            {
                CreateCombinations(candidates, combinations, store, i);
            }
            sum -= candidate;
            store.pop_back();    
        }

    }
};