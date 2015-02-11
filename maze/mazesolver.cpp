/* Joseph Hilland
 * ECE 231
 * Spring 12
 *
 * mazesolver.cpp
*/


#include"maze.h"


int main(int argc, char *argv[])
{
	maze solveIt;
	solveIt.input(argv);
	solveIt.build();
	solveIt.solve();
    return(0);
}
