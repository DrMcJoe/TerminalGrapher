#include <iostream>

#include "pad.h"
#include "graph.h"

int main()
{
    std::cout << "Demo!" << std::endl;

    pad myPad(10,10);
    myPad.SetXRange(-10,10);
    myPad.SetYRange(0, 10);
    
    myPad.set(4,4,'#');
    //myPad.AddPoint(0., 9.);

    myPad.Draw();

    graph myGraph("test 1","x","y");
    myGraph.thePad = &myPad;

    myGraph.Draw();

    return EXIT_SUCCESS;
}