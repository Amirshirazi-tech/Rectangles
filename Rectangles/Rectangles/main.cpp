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
    Rect square(VecLoadRect.at(0).m_Height, VecLoadRect.at(0).m_Width, VecLoadRect.at(0).m_Index, 0, 0);
    VecRect VecCollect;
    VecCollect.push_back(square);

    for (int i = 1; i < VecLoadRect.size(); i++) {
        VecLoadRect.at(i).m_bottomLeftX = VecLoadRect.at(i - 1).m_bottomLeftX + VecLoadRect.at(i - 1).m_Width;
        VecLoadRect.at(i).m_bottomLeftY = 0;
         
        if ( VecLoadRect.at(i).m_unUsedFlag == true) {
            float gapHeight = VecLoadRect.at(i-1).m_Height - VecLoadRect.at(i).m_Height;
            VecCollect.push_back(VecLoadRect.at(i));

            for (int j = 0; j < VecLoadRect.size(); j++) {
                float gapWidth = VecLoadRect.at(i - 1).m_Height - VecLoadRect.at(i).m_Width;
                if (VecLoadRect.at(j).m_Width < gapHeight and VecLoadRect.at(j).m_Width < gapWidth and VecLoadRect.at(j).m_unUsedFlag == true) {
                
                    rotateRect(VecLoadRect.at(j));

                    VecLoadRect.at(j).m_bottomLeftX = VecLoadRect.at(i).m_bottomLeftX;
                      
                    VecLoadRect.at(j).m_bottomLeftY = VecLoadRect.at(i-1).m_bottomLeftY + VecLoadRect.at(j - 1).m_Height + VecLoadRect.at(i).m_Height;
                    VecLoadRect.at(j).m_unUsedFlag = false;
                    VecCollect.push_back(VecLoadRect.at(j));

                }
            }

            VecLoadRect.at(i).m_unUsedFlag = false;
        }
    }

    for (int i = 0; i < VecCollect.size(); i++) {

        std::cout << "Index: " << VecCollect.at(i).m_Index
            <<" Position X: " << VecCollect.at(i).m_bottomLeftX << " Position Y: " << VecCollect.at(i).m_bottomLeftY  << std::endl;

    }

 
    float widthSquare = VecCollect.back().m_bottomLeftX + VecCollect.back().m_Width;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "The area of the square is " << widthSquare << " x " << widthSquare << std::endl;


   

	return 0;
}