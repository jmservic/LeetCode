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
        mult_var(double multiplier, string variable) : multiplier(multiplier), variable(variable) {}
        mult_var(mult_var& obj)
        {
            multiplier = obj.multiplier;
            variable = obj.variable;
        }
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

    void defineEqualities(unordered_map<string, mult_var> &varMap, const vector<vector<string>>& equations, const vector<double>& values)
    {
        //Loop through the equations
        for(int i = 0; i < equations.size(); ++i)
        {
            string op1 = equations[i][0], op2 = equations[i][0];
            bool containsOp1 = varMap.contains(op1), containsOp2 = varMap.contains(op2);
            //If both operands are defined, continue
            if(containsOp1 && containsOp2) continue;
            //If both operands are not defined, define the second as itself, and continue
            //to the case where only the first 1 isn't define.
            if(!containsOp1 && !containsOp2)
            {
                varMap.emplace(op2, mult_var(1, op2));
                containsOp2 = true;
            }
            //If only the first isn't defined, define it in terms of the second
            if(!containsOp1 && containsOp2)
                varMap.emplace(op1, mult_var(values[i], op2));                
            else if (containsOp1 && !containsOp2) //If only the second isn't defined, define it in terms of the first.
                varMap.emplace(op2, mult_var(1 / values[i], op1));
        }   
    }

    double calcQuery(const unordered_map<string, mult_var> &varMap, const vector<string> &query)
    {
        if (!validQuery(varMap, query))
            return -1.0;
        
        string op1 = query[0], op2 = query[1];
    
        double result = varMap.at(op1).multiplier / varMap.at(op2).multiplier;
        return result;
    }

    bool validQuery(const unordered_map<string, mult_var> &varMap, const vector<string> &query) 
    {
        string op1 = query[0], op2 = query[1];
        
        return varMap.at(op1).variable == varMap.at(op2).variable;
    }
};