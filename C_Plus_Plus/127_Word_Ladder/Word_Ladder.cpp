#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.end() == find(wordList.begin(), wordList.end(), endWord))
        {
            return 0;
        }
        int transforms = 1;
        vector<bool> visited(wordList.size(), false);
        queue<string> transformQueue({beginWord});
        
        while(!transformQueue.empty())
        {
            int loopCount = transformQueue.size();
            for(size_t _ = 0; _ < loopCount; ++_)
            {
                string currWord = transformQueue.front();
                transformQueue.pop();
                if (currWord == endWord)
                {
                    return transforms;
                }

                for(size_t j = 0; j < wordList.size(); ++j)
                {
                    if(visited[j])
                        continue;
                    string word = wordList[j];
                    int diffChar = 0;
                    
                    for(size_t i = 0; i < currWord.size(); ++i)
                    {
                        diffChar += (currWord[i] != word[i]) ? 1 : 0;
                        if(diffChar > 1) break;
                    }
                    
                    if(diffChar == 1)
                    {
                        transformQueue.push(word);
                        visited[j] = true;
                    }    
                }
            }            

            transforms++;
        }

        return 0;
    }
};