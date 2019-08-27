#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

/**
* Rect structure is used for collecting rectangles
* It  consists of the height, width, coordinate of the origin (bottom left of the rectangle)
* the index number, and boolean to control whether it is used or not.
**/

struct Rect
{
    float m_Height{};           //Height of the rectangle
    float m_Width{};            // Widht of the rectangle
    float m_bottomLeftX{};      // The X position of the origin
    float m_bottomLeftY{};      // The Y position of the origin
    bool m_unUsedFlag = true;   // Used or Unused controler
    int m_Index{};              //Index of the rectangle
    Rect() {};                  // Constructor without parameters
    Rect(float height, float width, int index, float upperX, float upperY) : 
   m_Height(height), m_Width(width), m_Index(index), m_bottomLeftX(upperX), m_bottomLeftY(upperY) {};    //Constructor with parameters
    ~Rect() {};                 //Destructor
};

// Function for rotating a rectangle. 
void rotateRect(Rect& rectangle);

// typedef of the vector of the Rect objects
typedef std::vector<Rect> VecRect;


/**
* This class supports to collect all rectangles in the input file.
* The object of this class used for sorting and also finding the optimum square.
* It has only one member variable. It is a string type.
**/

class RectLoader
{
private:
   const std::string* m_Path = nullptr;                        // String pointer for the path of the input file

public:

    RectLoader(const std::string& filePath) ;                   // Constructor of the RectLoader class
    virtual ~RectLoader() ;                                     // Destructor of the REctLoader class
    std::string getPath() const { return *m_Path; }             // Get function to return the member variable
    VecRect load();                                             // The function to load and read data from the input file
    VecRect squareFinder(VecRect& VecLoadRect);                 // The function to find the optimum square 
    void SortHeight(VecRect& inputVecRect);                     // The function to sort all rectangles based on their larger lenght
};

