#include <bits/stdc++.h>
using namespace std;

    public boolean isSafe(int row, int col, char[][] ch, int n){
        // condition checking the row 
        for(int i=0; i<n; i++)
            if(ch[row][i] == 'Q')
                return false;
        // condition checking the column
        for(int i=0; i<n; i++)
            if(ch[i][col] == 'Q')
                return false;
        // checking for upper left diagonal, upper right diagonal
        int it = row;
        for(int i = col; i>=0 && it>=0; it--, i--)
            if(ch[it][i] == 'Q')
                return false;
        it = row;
        for(int i=col; i<n && it>=0; i++, it--)
            if(ch[it][i] == 'Q')
                return false;
        // checking for lower left diagonal, lower right diagonal
        it = row;
        for(int i=col; i>=0 && it<n; i--, it++)
            if(ch[it][i] == 'Q')
                return false;
        for(int i=col; i<n && it<n; i++, it++)
            if(ch[it][i] == 'Q')
                return false;
        return true;
    }
    public void fill_ans(List<List<String>> ans, char[][] ch, int n){
        List<String> l = new ArrayList<>();
        for(int i=0; i<n; i++){
            String val = "";
            for(int j=0; j<n; j++){
                if(ch[i][j] == 'Q')
                    val += "Q";
                else
                    val += ".";
            }
            l.add(val);
        }
        ans.add(l);
    }
    public void find(List<List<String>> ans, char[][] ch, int row, int n){
        if(row == n){
            fill_ans(ans, ch, n);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(row, col, ch, n)){
                ch[row][col] = 'Q';
                find(ans, ch, row+1, n);
                ch[row][col] = '.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] ch = new char[n][n];
        
        // find the solution
        find(ans, ch, 0, n);
        
        return ans;
    }
