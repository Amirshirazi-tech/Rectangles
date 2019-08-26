#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 



struct Rect
{
    float m_Height{};
    float m_Width{};
    float m_bottomLeftX{};
    float m_bottomLeftY{};
    bool m_unUsedFlag = true;
    //float m_upeerRigth{};
    //float m_lowerRight{};
    int m_Index{};
    Rect() = default;
    Rect(float height, float width, int index, float upperX, float upperY) : m_Height(height), m_Width(width), m_Index(index), m_bottomLeftX(upperX), m_bottomLeftY(upperY) {};
};

//Rect gapFinder(const Rect obj);
void rotateRect(Rect& rectangle);

typedef std::vector<Rect> VecRect;

class RectLoader
{
private:
   const std::string* m_Path = nullptr;

public:
    RectLoader(const std::string& filePath) ;
    virtual ~RectLoader() ;
    std::string getPath() const { return *m_Path; }
    VecRect load();
    
    void SortHeight(VecRect& inputVecRect);
};

