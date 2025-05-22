#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> constraints = vector<vector<int>>(numCourses);
        vector<int> courseOrdering;
        vector<bool> visited = vector<bool>(numCourses);
        vector<bool> coursesAddedToList = vector<bool>(numCourses);

        for (auto &prerequisite : prerequisites)
        {
            constraints[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if(coursesAddedToList[i])
                continue;

            if(!dfs(i, constraints, visited, courseOrdering, coursesAddedToList))
            {
                return vector<int>();
            }
        }

        return courseOrdering;
    }

    bool dfs(int course, const vector<vector<int>> &constraints, vector<bool> &visited, vector<int> &courseOrdering, vector<bool>  &coursesAddedToList)
    {
        if(visited[course])
            return false;
        
        if(coursesAddedToList[course])
            return true;

        visited[course] = true;

        for(int constraint : constraints[course])
        {
            if(!dfs(constraint, constraints, visited, courseOrdering, coursesAddedToList))
                return false;
        }

        courseOrdering.push_back(course);
        coursesAddedToList[course] = true;
        visited[course] = false;
        return true;
    }
};

int main()
{

}