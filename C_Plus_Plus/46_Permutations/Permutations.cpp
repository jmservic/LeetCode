#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        bool * visited = new bool[nums.size()] {false}; 
        vector<vector<int>> permutations;
        vector<int> store;
        CreatePermutations(nums, visited, permutations, store);
        delete[] visited;
        return permutations;
    }

    void CreatePermutations(vector<int> &nums, bool visited[], vector<vector<int>> &permutations, vector<int> &store){
        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i]) continue;
            visited[i] = true;
            store.push_back(nums[i]);
            if (store.size() == nums.size())
            {
                permutations.push_back(store);
            } else 
            {
                CreatePermutations(nums, visited, permutations, store);
            }
            visited[i] = false;
            store.pop_back();
        }
    }
};