#ifndef __PAD__
#define __PAD__


#include <string>
#include <vector> 
#include <utility> // pair
#include <iostream>

#include <assert.h>

#include <cmath>

class pad {
   private:
      std::vector<std::string> data;
      std::pair<float,float> xDataRange;
      std::pair<float,float> yDataRange;
    public:

    pad(int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            data.emplace_back(std::string(columns,'.'));
        }
    }

    void SetXRange( float xmin, float xmax)
    {
        assert( xmin <  xmax);
        xDataRange.first = xmin;
        xDataRange.second = xmax;
    }

    void SetYRange( float ymin, float ymax)
    {
        assert( ymin <  ymax);
        yDataRange.first = ymin;
        yDataRange.second = ymax;
    }

    std::pair<int,int> padSize() const
    {
        return { data.at(0).size() , data.size() };
    }
    
    
    void AddPoint( float x, float y)
    {
        assert(!"FIXME");
        
        //Casting a float as an int is dodgy? Perhaps control the rounding process
        int column = round ( (x - xDataRange.first  ) / ( GetXRange() ) );
        std::cout << x << " is column "<< column <<std::endl;
        int row = int (y - yDataRange.first ) / ( GetYRange() );
        std::cout << y << " is column "<< row <<std::endl;
        set(row, column, 'Z');
    }

    float GetXRange() const
    {
        return xDataRange.second - xDataRange.first;
    }

    float GetYRange() const
    {
        return yDataRange.second - yDataRange.first;
    }



    void set(int x, int y, char c)
    {
       data.at(y).at(x)=c;
    }

    void Draw() const
    {
       std::cout<<"draw"<<std::endl;
       for (const std::string& row: data)
          std::cout << row <<"\n";
std::cout<<"end draw"<<std::endl; 
        /*
        for (const std::string& row: data)
          for (int i = 0 ; i < row.size(); i++ )
             std::cout << row.at(i);
           std::cout<<"\n";
        std::cout<<std::endl;
        */
    }
    void DrawRow(int row)
    {
        std::cout<<data.at(row);
    }
};


#endif