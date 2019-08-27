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

VecRect RectLoader::squareFinder(VecRect & VecLoadRect)
{

    Rect square(VecLoadRect.at(0).m_Height, VecLoadRect.at(0).m_Width, VecLoadRect.at(0).m_Index, 0, 0);
    VecRect VecCollect;
    VecCollect.push_back(square);

    for (int i = 1; i < VecLoadRect.size(); i++) {

        if (VecLoadRect.at(i).m_unUsedFlag == true) {
            VecLoadRect.at(i).m_bottomLeftX = VecLoadRect.at(i - 1).m_bottomLeftX + VecLoadRect.at(i - 1).m_Width;
            VecLoadRect.at(i).m_bottomLeftY = 0;
            float gapHeight = VecLoadRect.at(0).m_Height - VecLoadRect.at(i).m_Height;
            VecCollect.push_back(VecLoadRect.at(i));
            float gapWidth = gapHeight;
            float height{};
            for (int j = 0; j < VecLoadRect.size(); j++) {
                if (VecLoadRect.at(j).m_Width < gapHeight and VecLoadRect.at(j).m_Height <= VecLoadRect.at(i).m_Width and VecLoadRect.at(j).m_unUsedFlag == true) {

                    if (VecLoadRect.at(j).m_Width < gapWidth) {

                        rotateRect(VecLoadRect.at(j));

                        VecLoadRect.at(j).m_bottomLeftX = VecLoadRect.at(i).m_bottomLeftX;
                        VecLoadRect.at(j).m_bottomLeftY = height + VecLoadRect.at(i).m_Height;
                        VecLoadRect.at(j).m_unUsedFlag = false;
                        VecCollect.push_back(VecLoadRect.at(j));
                        gapWidth -= VecLoadRect.at(j).m_Height;
                        height += VecLoadRect.at(j).m_Height;
                    }
                }
            }

            VecLoadRect.at(i).m_unUsedFlag = false;
        }
    }

    return VecCollect;
}


void RectLoader::SortHeight(VecRect & inputVecRect)
{
    // Comparing height and width of each rectangle. If width is bigger than heidth, the recatngle will be rotated.
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

//Rect gapFinder(const Rect obj)
//{
//    const float gapHeight{};
//    if (obj.m_Width < gapHeight) {
//        return  obj;
//    }
//}

void rotateRect(Rect& rectangle)
{
    float temp = rectangle.m_Width;
    rectangle.m_Width = rectangle.m_Height;
    rectangle.m_Height = temp;
}
