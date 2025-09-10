#include<bits/stdc++.h>
using namespace std;
//path closed?
//out of bound?
// already visited?
bool isSafe(int srcx, int srcy,int newx, int newy,vector<vector<int>> maze,int rows, int col,vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx <rows) && (newy>=0 &&newy< col) && (maze[newx][newy] == 1) && visited[newx][newy] == false)
    {
        return true;
    }
    else{
        return false;
    }
    
}
void rat_in_maze(vector<vector<int>> &maze,int rows, int col, int srcx, int srcy, string ans, vector<vector<bool>> &visited)
{
    if (srcx == rows-1 && srcy == col-1)
    {
            cout<<ans<<endl; 
            return;
    }

    //Move up from current position
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,rows,col,visited))
    {
        //mark visited
        visited[newx][newy] = true;
        //call recursion
        rat_in_maze(maze,rows,col,newx,newy,ans+'U',visited);
        /*Backtracking:-  Mark unvisited after coming back from recursion as there may be
        some other ways using some part of that path*/
        visited[newx][newy] = false;
    }

    //Move down from current position
    newx = srcx+1;
    newy = srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,rows,col,visited))
    {
        //mark visited
        visited[newx][newy] = true;
        //call recursion
        rat_in_maze(maze,rows,col,newx,newy,ans+'D',visited);
        /*Backtracking:-  Mark unvisited after coming back from recursion as there may be
        some other ways using some part of that path*/
        visited[newx][newy] = false;
    }

    //Move Left from current position
    newx = srcx;
    newy = srcy-1;
    if(isSafe(srcx,srcy,newx,newy,maze,rows,col,visited))
    {
        //mark visited
        visited[newx][newy] = true;
        //call recursion
        rat_in_maze(maze,rows,col,newx,newy,ans+'L',visited);
        /*Backtracking:-  Mark unvisited after coming back from recursion as there may be
        some other ways using some part of that path*/
        visited[newx][newy] = false;
    }

    //Move Right from current position
    newx = srcx;
    newy = srcy+1;
    if(isSafe(srcx,srcy,newx,newy,maze,rows,col,visited))
    {
        //mark visited
        visited[newx][newy] = true;
        //call recursion
        rat_in_maze(maze,rows,col,newx,newy,ans+'R',visited);
        /*Backtracking:-  Mark unvisited after coming back from recursion as there may be
        some other ways using some part of that path*/
        visited[newx][newy] = false;
    }
   
  
}
//----------------------------------------------------



int main()
{
    vector<vector<int>> maze{{1,0,0,0},
    {1,1,0,0},
    {1,1,1,0},
    {1,1,1,1}
    };
    int rows = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string ans = "";
    //create a 2D-vector with rows and cols and having all cols filled with false 
    vector<vector<bool>> visited(rows, vector<bool> (col,false));
    if (maze[srcx][srcy] == 0)
    {
        cout<<"No path exists"<<endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        rat_in_maze(maze,rows,col,srcx,srcy,ans,visited);
        
    }
    
    

    return 0;
}