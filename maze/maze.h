/*  Joseph Hilland
 *  ECE 231
 *  Spring 12
 *
 *  Maze.h
 *  	
*	Original Source code:
*		Julian Lucero
*		ECE231 - Spring 2011
*		Date: 5/01/2011
*
*/


#ifndef MAZEh
#define MAZEh
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<stack>
#include <queue>
#include<ctime>
#define UP(x) (maze[i][j+1]==x ? true : false)
#define DOWN(x) (maze[i][j-1]==x ? true : false)
#define LEFT(x) (maze[i-1][j]==x ? true : false)
#define RIGHT(x) (maze[i+1][j]==x ? true : false)

using namespace std;

class maze
{
public:
    
    void input(char *argv[]);
    void build();
    void solve();
    void output();
private:
    
    ifstream inFile;
    ofstream outFile;
    string** maze;
    string::iterator it;
    string buffer;
    queue<string> solutions;
    stack<string> backtrack;
    int i, j, width, height, sw, sh, choice, I, J,k,l, flag;
    //Functions
    void pad(string** &Maze);
    void convert(string** &Maze);
    bool solved(string** &Maze);
    void test(string** &Maze);
};

#endif
