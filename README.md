#  Rectangles
Amir Shirazi developed this project. In this project, an algorithm was developed to collect several rectangles and place them in a square with a minimum area size.

This program is a console application and receive the input file (*txt) and show the result in the console. In the directory of the project, there is a sample including 10 rectangles. 

The output includes the position of each rectangle based on their origin, the index number of each rectangle, and the size of the area of the optimum square.

#How it works
1. The program collects all input to a vector of a structure called "Rect."

2. All objects in the vector are sorted based on the larger length. In case that the width of a rectangle is larger than the height, it will be rotated 90 degrees.

3. The first rectangles are used as a reference. Then the second one is placed in the next to the reference. The bottom left corner of each rectangle is used as an origin to place them into the square.

4. For the third one, the space on the top of the second one respect to the reference one is checked. It means the difference between the height of the reference and the second rectangle is calculated. Then the program tries to find which rectangle has enough width, which can fit in this space. This rectangle will be rotated 90 degrees again and placed in this empty place. The critical point for this selection is the width of the selected rectangle (after rotation) must not be larger than the width of the second rectangle. Then the space on the top of the third rectangle is checked. This process will continue until the end of the vector.

5. In each step, the coordinate (x,y) of the origin of each rectangle is calculated.

6. Based on the x position of the last rectangle and its width, the length of the width of the optimum square is calculated.
