/* Joseph Hilland
 * ECE 231
 * Spring 12
 *
 * maze.cpp
 * 
*/


#include<iostream>
#include "maze.h"

void maze::input(char *argv[])
{
     if (argv[1])  { //  Checks if there is a filename on the command line
        inFile.open(argv[1], ios::in);
        if (!inFile) {
            cout << "Can't open file " << argv[1] << endl;
            exit(1); // Exits program
        } else
        cout << argv[1] << " Opened Successfully" << endl;
    }
    else{
        cout << "No Input File" << endl;
        exit(1);
    }
    if (argv[2])  { //  Checks if there is a filename on the command line
        outFile.open(argv[2]);
        if (!outFile) {
            cout << "Can't create file " << argv[2] << endl;
            exit(1); // Exits program
        } else
        cout << argv[2] << " Created Successfully" << endl;
    }
    else{
        cout << "No Output File Declared" << endl;
        exit(1);
    }

}
//Collects data from input file and puts it into a multidimentional array, and converts the numbers to .pgm format
void maze::build()
{
    inFile>>buffer;
    buffer.clear();
    inFile>>width>>height;

    maze=new string*[width];
    for(i=0; i<width; ++i)
    maze[i]=new string[height];

    getline(inFile, buffer, '\0');
    inFile.close();
    it=buffer.begin();
    for(j=0;j<height;j++)
    {
    for(i=0;i<width;i++,it++)
    {
        if(isspace(*it))
        {
            i--;
        }
        else
        {
            if(*it=='0')
            {
                maze[i][j]='2';
            }
            else
            {
                maze[i][j]='0';
            }
        }

    }
    }
    buffer.clear();

}

void maze::solve()
{
    pad(maze);//covers the maze in 3's
    //Finds an entrance.
    for(i=1,j=1;i<width-1&&j<height-1;i++,j++)
    {
        if(maze[i][1]=="2")
        {
            j=1;
            break;
        }
        else if(maze[i][height-2]=="2")
        {
            j=height-2;
            break;
        }
        else if(maze[1][j]=="2")
        {
            i=1;
            break;
        }
        else if(maze[width-2][j]=="2")
        {
            i=width-2;
            break;
        }
    }
    sw=i;
    sh=j;
    flag=0;
    srand((unsigned)time(0));//seeds the random function
    //Checks for different combinations of situations and solves the maze until
    //no open spaces are left
    while(solved(maze))
    {
        if(UP("2")&&DOWN("2")&&LEFT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 3;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                j--;
                backtrack.push("down");
            }
            else if(choice==2)
            {
                i--;
                backtrack.push("left");
            }
        }
        else if(UP("2")&&DOWN("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 3;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                j--;
                backtrack.push("down");
            }
            else if(choice==2)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(UP("2")&&LEFT("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 3;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                i--;
                backtrack.push("left");
            }
            else if(choice==2)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(DOWN("2")&&LEFT("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 3;
            if(choice==0)
            {
                j--;
                backtrack.push("down");
            }
            else if(choice==1)
            {
                i--;
                backtrack.push("left");
            }
            else if(choice==2)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(UP("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(UP("2")&&LEFT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                i--;
                backtrack.push("left");
            }
        }
        else if(DOWN("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                j--;
                backtrack.push("down");
            }
            else if(choice==1)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(DOWN("2")&&LEFT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                j--;
                backtrack.push("down");
            }
            else if(choice==1)
            {
                i--;
                backtrack.push("left");
            }
        }
        else if(UP("2")&&DOWN("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                j++;
                backtrack.push("up");
            }
            else if(choice==1)
            {
                j--;
                backtrack.push("down");
            }
        }
        else if(LEFT("2")&&RIGHT("2"))
        {
            maze[i][j]='T';
            choice=rand() % 2;
            if(choice==0)
            {
                i--;
                backtrack.push("left");
            }
            else if(choice==1)
            {
                i++;
                backtrack.push("right");
            }
        }
        else if(UP("2"))
        {
            if(flag==1)
            {
            maze[i][j]='T';
            flag=0;
            }
            else
            maze[i][j]='X';
            j++;
            backtrack.push("up");
        }
        else if(DOWN("2"))
        {
            if(flag==1)
            {
            maze[i][j]='T';
            flag=0;
            }
            else
            maze[i][j]='X';
            j--;
            backtrack.push("down");
        }
        else if(LEFT("2"))
        {
            if(flag==1)
            {
            maze[i][j]='T';
            flag=0;
            }
            else
            maze[i][j]='X';
            i--;
            backtrack.push("left");
        }
        else if(RIGHT("2"))
        {
            if(flag==1)
            {
            maze[i][j]='T';
            flag=0;
            }
            else
            maze[i][j]='X';
            i++;
            backtrack.push("right");
        }
        else
        {
            if((UP("3")||DOWN("3")||LEFT("3")||RIGHT("3")))
            {
                maze[i][j]='X';
                break;
            }
            else//backtracks if a dead end is hit
            {
                if(maze[i][j]=="T")
                maze[i][j]="1";
                else
                {
                while(maze[i][j]!="T")
                {
                    if(backtrack.top()=="up")
                    {
                        maze[i][j]='1';
                        j--;
                        backtrack.pop();
                    }
                    else if(backtrack.top()=="down")
                    {
                        maze[i][j]='1';
                        j++;
                        backtrack.pop();
                    }
                    else if(backtrack.top()=="left")
                    {
                        maze[i][j]='1';
                        i++;
                        backtrack.pop();
                    }
                    else if(backtrack.top()=="right")
                    {
                        maze[i][j]='1';
                        i--;
                        backtrack.pop();
                    }

                }
                }
                flag=1;
            }
        }
    }
convert(maze);//converts solution into .pgm format
test(maze);
//outputs solution to .pgm file
    outFile<<"P2"<<endl;
    outFile<<width<<" "<<height<<endl;
    outFile<<"3"<<endl;
    for(j=0;j<height;j++)
    {
        outFile<<endl;
    for(i=0;i<width;i++,it++)
    {
        outFile<<maze[i][j]<<" ";

    }
    }
}
//Covers maze in 3's
void maze::pad(string** &Maze)
{

    for(i=0,j=0;i<width&&j<height;i++,j++)
    {
        Maze[i][0]='3';
        Maze[i][height-1]='3';
        Maze[0][j]='3';
        Maze[width-1][j]='3';
    }

}
//Conerts solution into .pgm format
void maze::convert(string** &Maze)
{

    for(j=0;j<height;j++)
    {
    for(i=0;i<width;i++)
    {
        if((Maze[i][j]=="X")||(Maze[i][j]=="T"))
        Maze[i][j]='3';
        if(Maze[i][j]=="2")
        Maze[i][j]='1';
    }
    }

}
//checks for open spaces
bool maze::solved(string** &Maze)
{
    for(J=0;J<height;J++)
    {
    for(I=0;I<width;I++)
    {
        if(Maze[I][J]=="2")
        return true;
    }
    }
    return false;
}
//Prints maze to screen for testing purposes.
void maze::test(string** &Maze)
{

    for(k=0;k<height;k++)
    {
        cout<<endl;
    for(l=0;l<width;l++)
    {
        cout<<Maze[l][k];
    }
    }
    //exit(1);
}

