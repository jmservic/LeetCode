#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {

    typedef
    struct mult_var
    {
        double multiplier;
        string variable;
    } mult_var;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, mult_var> varMap = unordered_map<string, mult_var>();
        defineEqualities(varMap, equations, values);

        vector<double> results = vector<double>();

        for(auto &query : queries)
        {
            //calculate the query
            results.push_back(calcQuery(varMap, query));
        }

        return results;
    }

    void defineEqualities(unordered_map<string, mult_var> &varMap, vector<vector<string>>& equations, vector<double>& values)
    {
        //Loop through the equations
        //If both operands are defined, continue
        //If both operands are not defined, define the second as itself, and continue
        //to the case where only the first 1 isn't define.
        //If only the second isn't defined, define it in terms of the first.

    }

    double calcQuery(const unordered_map<string, mult_var> &varMap, const vector<string> &query)
    {

    }

    bool validQuery(const unordered_map<string, mult_var> &varMap, const vector<string> &query) 
    {

    }
};