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
           rectBuffer >> tmpRect.m_Index >> tmpRect.m_Hight >> tmpRect.m_Width;
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
