#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> constraints = vector<vector<int>>(numCourses);
        vector<int> courseOrdering;
        vector<bool> visited = vector<bool>(numCourses);
        //Add in one to check which we've added to the courseOrdering already. Another vector<bool> or just an array...
        for (auto &prerequisite : prerequisites)
        {
            constraints[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if(!dfs(i, constraints, visited, courseOrdering))
            {
                return vector<int>();
            }
        }

        return courseOrdering;
    }

    bool dfs(int course, const vector<vector<int>> &constraints, vector<bool> &visited, vector<int> courseOrdering)
    {

    }
};

int main()
{

}