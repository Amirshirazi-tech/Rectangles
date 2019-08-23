#pragma once

#include <iostream>
#include <string>
#include <vector>



struct Rect
{
    float m_Hight{};
    float m_Width{};
    int m_Index{};
};

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
};

