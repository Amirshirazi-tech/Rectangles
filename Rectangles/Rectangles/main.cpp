#include <iostream>
#include <string>
#include <algorithm>
#include "RectLoader.h"



int main() {

    std::string inputPath;
    std::cout << "Please enter the input file: ";
    std::getline(std::cin, inputPath);
    RectLoader TRect(inputPath);

    VecRect VecLoadRect = TRect.load();
    TRect.SortHeight(VecLoadRect);
    VecRect squareCollect = TRect.squareFinder(VecLoadRect);

    for (int i = 0; i < squareCollect.size(); i++) {

       std::cout << "Index: " << squareCollect.at(i).m_Index
       <<" Position X: " << squareCollect.at(i).m_bottomLeftX 
       << " Position Y: " << squareCollect.at(i).m_bottomLeftY  << std::endl;
    }

    float widthSquare = squareCollect.back().m_bottomLeftX + squareCollect.back().m_Width;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "The area of the square is " << widthSquare << " x " << widthSquare << std::endl;

	return 0;
}