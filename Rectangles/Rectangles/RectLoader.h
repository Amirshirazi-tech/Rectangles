#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 



struct Rect
{
    float m_Height{};
    float m_Width{};
    int m_Index{};
};

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

