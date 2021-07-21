#ifndef __PAD__
#define __PAD__


#include <string>
#include <vector> 
#include <utility> // pair
#include <iostream>

#include <assert.h>

#include <cmath>

#include <array>

static std::array<char,10> char_list{' ','.',':','-','=','+','*','#','%','@'};

static char GetNextShade( const char c)
{
    for ( size_t i = 0; i < char_list.size() - 1 ; i++ )
    {
        if (c == char_list[i])
        {
            return char_list[i+1];
        }
    }
    return c;
}

template <typename T>
class range {
public:
   T min;
   T max;
   range(int minimum, int maximum): min(minimum), max(maximum)
   {

   }
   range()
   {
       min = 0.0;
       max = 0.0;
   }
};


class pad {
   private:
      std::vector<std::string> data;
      range<float> xDataRange;
      range<float> yDataRange;
      float xBinSize;
      float yBinSize;

      const size_t fXBins; 
      const size_t fYBins;
    public:

    pad(size_t XSize, size_t  YSize): fXBins(XSize), fYBins(YSize)
    {
        for (size_t i = 0; i < fYBins; i++)
        {
            data.emplace_back(std::string(fXBins,' '));
        }
    }

    void SetXRange( float xmin, float xmax)
    {
        assert( xmin <  xmax );
        xDataRange.min = xmin;
        xDataRange.max = xmax;
        xBinSize = (xmax - xmin) / ( fXBins - 1 );
    }

    void SetYRange( float ymin, float ymax)
    {
        assert( ymin <  ymax );
        yDataRange.min = ymin;
        yDataRange.max = ymax;
        yBinSize = (ymax - ymin) / ( fYBins - 1 );
    }

    std::pair<size_t,size_t> padSize() const
    {
        assert(fXBins == data.at(0).size());
        assert(fYBins == data.size());
        
        return { data.at(0).size() , data.size() };
    }
    
    float BinToX(size_t xbin) const 
    {
        assert(xbin > 0);
        assert(xbin < fXBins );
        return xDataRange.min + xbin *  xBinSize;
    }

    float BinToY(size_t ybin) const 
    {
        assert(ybin > 0);
        assert(ybin < fYBins );
        return xDataRange.min + ybin *  yBinSize;
    }

    int XToBin(float x) const 
    {
        // I can return values beyond valid range...
        return round((x -xDataRange.min) / xBinSize );
    }

    int YToBin(float y) const 
    {
        // I can return values beyond valid range...
        return round((y - yDataRange.min ) / yBinSize );
    }

    void SetPoint( float x, float y, char c)
    {
        //Casting a float as an int is dodgy? Perhaps control the rounding process
        int column = XToBin( x );
        std::cout << x << " is column "<< column <<std::endl;
        int row =   YToBin( y );
        std::cout << y << " is row "<< row <<std::endl;
        SetBin(column, row, c);
    }

    float GetXRange() const
    {
        return xDataRange.max - xDataRange.min;
    }

    float GetYRange() const
    {
        return yDataRange.max - yDataRange.min;
    }

    void SetBin(const int x, const int y, const char c)
    {
       //The y coordinates need flipping
       data.at(y).at(x)=c;
    }

    void Draw() const
    {
       for (const std::string& row: data)
          std::cout << row <<"\n";
    }
    void DrawRow(const size_t row)
    {
        std::cout<<data.at((fYBins - 1) - row);
    }
    
    char GetBin( size_t x, size_t y)
    {
        return data.at(y).at(x);
    }
    
    std::pair<size_t, size_t> XYToBin( const float x, const float y)
    {
        return {XToBin(x), YToBin(y)};
    }

    char GetPoint(const float x, const float y)
    {
        size_t xbin = XToBin( x );
        size_t ybin = YToBin( y );
        return GetBin(xbin, ybin);
    }
    void AddPoint(float x, float y)
    {
        std::pair<size_t, size_t> xy = XYToBin(x,y);
        
        char c = GetBin(xy.first, xy.second);
        std::cout<< "Adding data to point ("<< xy.first <<"," << xy.second <<") was "<< c;
        c = GetNextShade(c);
        std::cout << " is " << c <<std::endl;
        SetBin(xy.first, xy.second,c);
    }

};


#endif