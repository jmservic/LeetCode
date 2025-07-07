#include <vector>
#include <string>
#include <queue>
#include <memory>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(bank.size() == 0)
        {
            return (startGene == endGene) ? 0 : -1;
        }
        queue<string> que({startGene});
        //bool * visited = new bool[bank.size()]{false};
        unique_ptr<bool[]> visited(new bool[10]{false});
        int steps = 0;

        while(!que.empty())
        {
            size_t pops = que.size();

            for(size_t i = 0; i < pops; ++i)
            {
                string currGene = que.front();
                que.pop();
                if(currGene == endGene)
                {
                    return steps;
                }

                for(size_t index = 0; index < bank.size(); ++index)
                {
                    if(visited[index]){
                        continue;
                    }
                    int numDiff = 0;
                    size_t diffIndex = -1;
                    for(size_t j = 0; j < currGene.size(); ++j)
                    {
                        if(currGene[j] != bank[index][j])
                        {
                            ++numDiff;
                        }
                    }
                    if(numDiff == 1)
                    {
                        que.push(bank[index]);
                        visited[index] = true;
                    }
                }
            }
            ++steps;
        }
        
        //delete[] visited;
        return -1;
    }
};