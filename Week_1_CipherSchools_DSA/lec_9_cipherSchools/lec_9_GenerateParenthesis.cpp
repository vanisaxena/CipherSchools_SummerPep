#include <iostream>
using namespace std;
void generate(string curr, vector<string>& result, int o, int c, int n){
        if(c == n){ 
            result.push_back(curr);
            return;
        }
        if(o<n)
            generate(curr+"(", result, o+1, c, n);
        if(c<o)
            generate(curr+")", result, o, c+1, n);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string curr = "";
        generate(curr, result, 0, 0, n);
        
        return result;
    }
