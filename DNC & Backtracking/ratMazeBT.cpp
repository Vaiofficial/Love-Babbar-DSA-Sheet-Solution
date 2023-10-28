#include <bits/stdc++.h>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>> &visited)
{
    if (
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy] == 1 &&
        visited[newx][newy] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printallMaze(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    // destination coordinates are arr[row-1][col-1]
    if (srcx == row - 1 && srcy == col - 1)
    {
        // reached destination
        cout << output << endl;
        return;
    }

    // ak case solve karo baki recursion ko de do solve karne

    // UP
    int newx = srcx - 1;
    int newy = srcy;

    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('U');
        printallMaze(maze, row, col, newx, newy, output, visited);
        // call backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
    // RIGHT

    newx = srcx;
    newy = srcy+1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('R');
        printallMaze(maze, row, col, newx, newy, output, visited);
        // call backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('D');
        printallMaze(maze, row, col, newx, newy, output, visited);
        // call backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
    // LEFT
    newx = srcx;
    newy = srcy -1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('L');
        printallMaze(maze, row, col, newx, newy, output, visited);
        // call backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
    };
    int row = 4;
    int col = 4;

    // created visited array to check whether element is already visited or not to the position we want to go next.
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int srcx = 0; // source positions , start.
    int srcy = 0;
    string output = ""; // to store output.


    if (maze[0][0] == 0)
    {
        cout << "No path exist" << endl;
    }
    else
    {
        visited[srcx][srcy] = true; // src = source
        printallMaze(maze, row, col, srcx, srcy, output, visited);
    }

    return 0;
}