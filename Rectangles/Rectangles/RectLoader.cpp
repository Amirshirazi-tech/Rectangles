#include "RectLoader.h"
#include <sstream>
#include <fstream>


RectLoader::RectLoader(const std::string & filePath)
{
    m_Path = new std::string(filePath);
}

RectLoader::~RectLoader()
{
    delete m_Path;
}

VecRect RectLoader::load()
{
  std::ifstream rectFile;
  VecRect vCollecRect;
 
   rectFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

   try {
       rectFile.open(this->getPath());
       rectFile.ignore(255, '\n');       //Ignoring the first line
       std::string line;
       while (!rectFile.eof()) {
 
           getline(rectFile, line);     
           std::stringstream rectBuffer (line);
           Rect tmpRect;
           rectBuffer >> tmpRect.m_Index >> tmpRect.m_Height >> tmpRect.m_Width;
           vCollecRect.push_back(tmpRect);
        }
     rectFile.close();
    }

   catch (std::ifstream::failure e) {
       std::cout << "Error opening file: please check the existing your input file." << std::endl;
       //return -1;
   }
     
   return vCollecRect;
}

void RectLoader::SortHeight(VecRect & inputVecRect)
{
    // Comparing height and width of each rectangle. If width is bigger than heidth, the recatngle will be rotated.

    //test
    for (int i = 0; i < inputVecRect.size(); i++) {            

        float Controler = std::max(inputVecRect.at(i).m_Height, inputVecRect.at(i).m_Width);
        if (Controler == inputVecRect.at(i).m_Width) {
            rotateRect(inputVecRect.at(i));
        }
    }
    std::sort(inputVecRect.begin(), inputVecRect.end(), [](const Rect & lhs, const Rect& rhs) {
        return lhs.m_Height > rhs.m_Height;
    });
}

void rotateRect(Rect& rectangle)
{
    float temp = rectangle.m_Width;
    rectangle.m_Width = rectangle.m_Height;
    rectangle.m_Height = temp;
}
