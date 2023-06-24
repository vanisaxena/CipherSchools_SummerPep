#include <bits/stdc++.h>
using namespace std;
bool findElement(vector<int> nums, int k){
  int a=0;
  int b=matrix[0].length-1;
                
  while(a<matrix.length && b>=0)
    if(matrix[a][b]==target)
        return true;
    else if(matrix[a][b]>target)
        b--;
    else
        a++;
    return false;
}
