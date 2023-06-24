#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1, k = m-1, l = 0;
        // storing the answer
        vector<int> ans;
        int itr;
        while(i<=k && l<=j){
            for(itr = l; itr<=j; itr++)
                ans.push_back(matrix[i][itr]);
            i++;
            for(itr = i; itr<=k; itr++)
                ans.push_back(matrix[itr][j]);
            --j;
            if(i <= k){
                for(itr = j; itr>=l; itr--)
                    ans.push_back(matrix[k][itr]);
                --k;
            }
            if(l <= j){
                for(itr = k; itr>=i; itr--)
                    ans.push_back(matrix[itr][l]);
                ++l;
            }
        }
        return ans;
    }
