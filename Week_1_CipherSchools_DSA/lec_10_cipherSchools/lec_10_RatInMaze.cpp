#include <bits/stdc++.h>
using namespace std;

public static ArrayList<String> findPath(int[][] maze, int n) {

	int path[][] = new int[n][n];
	 ArrayList < String > ans = new ArrayList < > ();
	printMULTIPLEmazePATHS(maze, 0, 0, path,"",ans);
	return ans;
}

public static void printMULTIPLEmazePATHS(int [][] maze,int i,int j,int[][] path,String move,ArrayList < String > ans) {
	// if 'i' and 'j' are valid or not
	int n=maze.length;
	if(i<0 || i>=n|| j<0 || j>=n) {
		return ;
	}
	if(maze[i][j]==0) {
		return ;
		
	}
	if(path[i][j]!=0) {
		return ;
	}
	
	//its a valid cell include in path
	path[i][j]=1;
			
			
	//destination cell
	if(i==n-1 && j==n-1) {
		ans.add(move);
		
		path[i][j]=0;
		return;
	}
	//explore further directions
	
	//down
	 printMULTIPLEmazePATHS(maze,i+1,j,path,move+"D",ans);
	//left
	 printMULTIPLEmazePATHS(maze,i,j-1,path,move+"L",ans);
	//right
	 printMULTIPLEmazePATHS(maze,i,j+1,path,move+"R",ans);
	//UP
	printMULTIPLEmazePATHS(maze,i-1,j,path,move+"U",ans);
	 path[i][j]=0;
	
}
