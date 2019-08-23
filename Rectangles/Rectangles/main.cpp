#include <iostream>
#include <string>
#include "RectLoader.h"

int main() {

    std::string inputPath;
    std::cout << "Please enter the input file: ";
    std::getline(std::cin, inputPath);
    RectLoader Rect(inputPath);
    Rect.load();

	//std::cout << "Hello" << std::endl;

	return 0;
}