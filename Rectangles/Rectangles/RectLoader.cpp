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

std::vector<Rect> RectLoader::load()
{
   std::ifstream gradeFile;
   std::stringstream grades;
   int grade;
   int total = 0;
   gradeFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

   try {
       gradeFile.open(this->getPath());
       std::string line;
       getline(gradeFile, line);
       grades << line;
       gradeFile.close();

       for (int i = 0; i < 5; ++i) {

           grades >> grade;
           total += grade;
       }
       double average = total / 5;
       std::cout << "average: " << average << std::endl;
   }

   catch (std::ifstream::failure e) {
       //cout << e.what() << endl;
       std::cout << "Error opening file: please check the existing your input file and use *.txt." << std::endl;
       //return -1;
   }
    
    
    
    return std::vector<Rect>();
}
