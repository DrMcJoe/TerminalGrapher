#include <iostream>

#include "pad.h"
#include "graph.h"

int main()
{
    std::cout << "Demo!" << std::endl;

    pad myPad(100,15);
    myPad.SetXRange(0,100);
    myPad.SetYRange(0, 15);
    
  //  myPad.SetBin(0,14,'#');
//    myPad.SetPoint(10., 9, 'O');

    //myPad.AddPoint(1,1);
    int triangle_size = 15;
    for ( int i = 0;  i< triangle_size; i++)
    {
        //myPad.SetBin(i,0,'#');
        for (int j = i; j < triangle_size; j++ )
        {
            for (int k =0; k < i; k++)
            {
                myPad.AddPoint(i,j);
            }
        }
    }
    //myPad.AddPoint(1,0);
    //myPad.AddPoint(1,0);
    //myPad.AddPoint(1,0);
    //myPad.Draw();

    graph myGraph("test 1","  x label"," y label");
    myGraph.thePad = &myPad;

    myGraph.Draw();

    return EXIT_SUCCESS;
}