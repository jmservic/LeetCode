#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
using namespace std;

class Solution {
    public:
        bool canFinishSLOW(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, unordered_set<int>> graph;
            unordered_set<int> visited;
            stack<int> toVisit;
            for(auto prereq : prerequisites) {
                graph[prereq[0]].insert(prereq[1]);
                if(graph.contains(prereq[1]))
                {
                    toVisit.push({prereq[1]});
                    while(!toVisit.empty())
                    {
                        int currCourse = toVisit.top();
                        unordered_set<int> currCoursePreq = graph.at(currCourse);
                        toVisit.pop();
                        for(int course : currCoursePreq)
                        {
                            if(course == prereq[0])
                                return false; // cycle detected 
                            if(!visited.contains(course) && graph.contains(course))
                                toVisit.push(course);
                        }

                        visited.insert(currCourse);
                    }
                    visited.clear();
                }
            }
            return true;
        }
        
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            if(prerequisites.size() == 0) return true;
            vector<vector <int>> classConstraints(numCourses);
            vector<bool> visited(numCourses);
            vector<bool> pathVisit(numCourses);

            for(vector<int> & prereq : prerequisites) //push back constraints
            {
                int start = prereq[0];
                int end = prereq[1];
                classConstraints[start].push_back(end);
            }

            for(int i = 0; i < classConstraints.size(); ++i)
            {
                if(visited[i])
                    continue;
                
                if(dfs(i, classConstraints, visited, pathVisit) == false)
                    return false;
            }

            return true;
        }

        bool dfs(int course, vector<vector <int>> &classConstraints, vector<bool> &visited,
            vector<bool> &pathVisit)
        {
            visited[course] = true;
            pathVisit[course] = true;

            for(int prereq : classConstraints[course])
            {
                if(pathVisit[prereq])
                    return false; //cycle
                if(!visited[prereq]){
                    if(dfs(prereq, classConstraints, visited, pathVisit) == false) 
                        return false;
                }
            }
            pathVisit[course] = false;
            return true;
        }

        bool CanTopologicalSort(const vector<vector<vector<int>>> &groupedPreReqs) {
            unordered_set<int> visited;
            unordered_set<int> recursiveVisited;

            for(int i = 0; i < groupedPreReqs.size(); ++i)
            {
                for(vector<int> prereq : groupedPreReqs[i])
                {
                    if(visited.contains(prereq[1]))
                        continue;              
                    if(VisitPrereqs(i, prereq[1], visited, groupedPreReqs, recursiveVisited) == false)
                        return false;
                }
                visited.insert(i);
            }
            return true;
        }

        bool VisitPrereqs(int startCourse, int preReq, unordered_set<int> &visited, const vector<vector<vector<int>>> &groupedPreReqs, unordered_set<int> &recursiveVisited)
        {
            if(preReq == startCourse)
                return false;

            recursiveVisited.insert(preReq);
            for(vector<int> constraint : groupedPreReqs[preReq])
            {
                if(visited.contains(constraint[1]))
                    continue;
                recursiveVisited.clear();  
                if(recursiveVisited.contains(constraint[1]) ||
                    VisitPrereqs(startCourse, constraint[1], visited, groupedPreReqs, recursiveVisited) == false)
                    return false;
                visited.insert(recursiveVisited.begin(), recursiveVisited.end());
            }

            return true;
        }

        bool canFinishBetterButSlow(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<int> connections(numCourses, numCourses - 1); 
            vector<vector<int>> parents(numCourses);
            vector<unordered_set<int>> children(numCourses);
            stack<int> toVisit;
            for (auto &prereq : prerequisites)
            {
                if((connections[prereq[0]] -= 1) < 0) return false;
                
                parents[prereq[0]].push_back(prereq[1]);
                toVisit.push(prereq[1]);
                while(!toVisit.empty())
                {
                    int currCourse = toVisit.top();
                    toVisit.pop();
                    if(!children[currCourse].contains(prereq[0]))
                    {
                        if(currCourse == prereq[0] || (connections[currCourse] -= 1) < 0) 
                            return false;
                        children[currCourse].insert(prereq[0]);
                        for (auto parent : parents[currCourse])
                            toVisit.push(parent);
                    }
                }

            }
            return true;
        }
        bool canFinishStillSLow(int numCourses, vector<vector<int>>& prerequisites)
        {
            unordered_map<int, vector<int>> graph;
            for(auto prereq : prerequisites) {
                graph[prereq[0]].push_back(prereq[1]);
            }

            for(auto node : graph)
            {
                unordered_set<int> visitedSet;
                if(CycleDetected(graph, node.first, visitedSet, numCourses))
                return false;
            }
            return true;
        }

        bool CycleDetected(unordered_map<int, vector<int>> &graph, int course,unordered_set<int> &visitedSet, int numCourses)
        {
            if(visitedSet.contains(course))
                return true;
            visitedSet.insert(course);
            if(graph.contains(course))
            {
                auto preReqs = graph[course];
                for(int preReq : preReqs)
                {
                    if(CycleDetected(graph, preReq, visitedSet, numCourses))
                        return true;
                }
                for(int preReq : preReqs){
                    visitedSet.erase(preReq);
                }
            }

            return false;
        }
};

int main()
{
    vector<vector<int>> prerequisites = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
    Solution sol;
    sol.canFinish(7, prerequisites);
}