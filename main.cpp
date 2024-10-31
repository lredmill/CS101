//
//  main.cpp
//

/*
You will not upload this file as part of your project. 
This program will read the filename, start and end positions
then call your function with a stringstream for you to write to.
On return it will print the contents of the string stream and 
the distance returned by your function.
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "wavefront.h"
int main(int argc, const char * argv[]) {
    std::string filename;
    std::cout<<"filename: ";
    std::cin >> filename;
    
    int srow, scol;
    std::cout << "start row: ";
    std::cin >> srow;
    std::cout<<"start col: ";
    std::cin >>scol;
    
    int xrow, xcol;
    std::cout << "goal row: ";
    std::cin >> xrow;
    std::cout<<"goal col: ";
    std::cin >> xcol;
    
    std::stringstream ss;
    int distance;
    distance = wavefront(filename,srow,scol,xrow,xcol,ss);
    std::cout << ss.str() << std::endl;
    std::cout << "Distance = " << distance << std::endl;
    
    return 0;
}
