#ifndef __GRAPH__
#define __GRAPH__



#include <string>

#include <pad.h>

class axis {
    private:
    const std::string label;
    public:
    axis(const std::string& _label): label(_label)
    {
    }
    void Print() const
    {
        std::cout<< label <<std::endl;
    }
    char at(size_t i) const
    {
        return label.at(i);
    }
    size_t size() const
    {
        return label.size();
    }
    // TODO: Add function to estimate how many rows text will take
    // EXTRA: possibly count spaces so that we can do something pretty
};

class graph {
private:
    std::string title;
    axis XAxis;
    axis YAxis;
    
    public:
    // TODO: Thank about how to handle the pad... many inherit from it?
    pad* thePad;
public:
    
    graph(const std::string& _title, const std::string& x_label, const std::string& y_label):
        title(_title), XAxis(x_label), YAxis(y_label)
    {
        thePad = NULL;
    }

    void Draw()
    {
       if (!thePad)
       {
           std::cout<<"NO PAD!" <<std::endl;
           return;
       }
       //Ideally I want to know the terminal width...
        for (int i = 0;  i < thePad->padSize().first + 2;  i++)
            std::cout<<"=";
        std::cout << std::endl;
        std::cout << title << std::endl;
        for (int i = 0;  i < thePad->padSize().first + 2;  i++)
            std::cout<<"=";
        std::cout << std::endl;
        
        // Top border

        // TODO: Pad by the number of columns the YAxis label will need

        std::cout<<" *";
        for (int i = 0;  i < thePad->padSize().first;  i++)
           std::cout<<"-";
        std::cout<<"*"<<std::endl;

        // Sides and pad drawing
        for (int i = 0; i < thePad->padSize().second; i++)
        {
            
            // TODO: Centre the YAxis label vertically
            if (i < YAxis.size() )
               std::cout<< YAxis.at(i);
            else
               std::cout<< " ";
            std::cout <<"|";
            thePad->DrawRow(i);
            std::cout <<"|"<<std::endl;
        }

        // Bottom border
        std::cout<<" *";
        for (int i = 0;  i < thePad->padSize().first;  i++)
           std::cout<<"-";
        std::cout<<"*"<<std::endl;
        
        // Centre X label
        std::cout<<" ";
        XAxis.Print();
    }



};

#endif