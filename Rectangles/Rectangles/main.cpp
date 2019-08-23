#include <iostream>
#include <string>
#include "RectLoader.h"

int main() {

    std::string inputPath;
    std::cout << "Please enter the input file: ";
    std::getline(std::cin, inputPath);
    RectLoader TRect("rectangles");
 
    VecRect test= TRect.load();
    for (int i = 0; i < test.size(); i++) {

        std::cout << "Index " << test.at(i).m_Index << " Hight: " << test.at(i).m_Hight << " Width: " << test.at(i).m_Width << std::endl;
    }

	return 0;
}