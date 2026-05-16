/*

Given the anti-clockwise points of a properly formed, non-self-intersecting, not-necessarily-convex polygon, render it as a filled ASCII art polygon.

Input
A series of at least 3 (x,y) pairs representing the points. It's up to you whether the first point is repeated as the last point to close the loop. x coordinates are integers in the range 1-78. coordinates are integers in the range 1-38.

Output
An 80x40 text field representing the range 0-79 x 0-39 (0,0 at the top left), consisting of space characters (outside the polygon) and * for characters within the polygon. It's acceptable (but optional) to avoid printing whitespace to the right/below the polygon.

The exact algorithm for exactly how a diagonal line is converted to a text staircase is somewhat flexible, within reason.

Scoring
Code golf.

Test cases
[[1,1], [1,3], [2,3], [2,1]]:

    
 **
 **
 **
(77 blank columns and 36 blank rows not included).

[[1,1], [1,3], [3,3]]:

    
 *
 **
 ***
(The following test cases were made with the help of AI-generated code; they may not be right.)

[
        [9, 1],
        [1, 15],
        [24, 30],
        [50, 20],
        [30, 20],
        [50, 10],
]
         **                                                                     
        ********                                                                
        ************                                                            
       ******************                                                       
      ***********************                                                   
      ****************************                                              
     **********************************                                         
     **************************************                                     
    ********************************************                                
    *********************************************                               
   ********************************************                                 
  *******************************************                                   
  *****************************************                                     
 ****************************************                                       
  *************************************                                         
   **********************************                                           
     ******************************                                             
      ***************************                                               
        ***********************                                                 
         ****************************************                               
           ***********************************                                  
            *******************************                                     
              ***************************                                       
                **********************                                          
                 *******************                                            
                   **************                                               
                    **********                                                  
                      ******                                                    
                       **                                                       
[
        [40, 5],
        [50, 9],
        [46, 14],
        [34, 14],
        [30, 9],
]





                                       **                                       
                                    ********                                    
                                  ************                                  
                               ******************                               
                              ********************                              
                               ******************                               
                                ****************                                
                                 **************                                 
                                  ************                                  
```

*/

#include <cstdio>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

enum
{
	WIDTH = 80,
	HEIGHT = 40,
};

struct Display
{
	char pixels[HEIGHT][WIDTH];

	void render(const vector<Point2f> &polygon);
	void draw();
};

void Display::render(const vector<Point2f> &polygon)
{
	for (auto y = 0; y < HEIGHT; y++)
	{
		for (auto x = 0; x < WIDTH; x++)
		{
			auto point = Point2f{ x + 1, y + 1 };
			if (pointPolygonTest(polygon, point, false) >= 0)
				pixels[y][x] = '*';
			else
				pixels[y][x] = ' ';
		}
	}
}

void Display::draw()
{
	for (auto y = 0; y < HEIGHT; y++)
	{
		for (auto x = 0; x < WIDTH; x++)
			printf("%c", pixels[y][x]);
		printf("\n");
	}
	printf("\n");
}

void test(const vector<Point2f> &polygon)
{
	Display display;
	display.render(polygon);
	display.draw();
}

int main()
{
	vector<Point2f> polygon_1 = {
		{ 1, 1 },
		{ 1, 3 },
		{ 2, 3 },
		{ 2, 1 },
	};

	vector<Point2f> polygon_2 = {
		{ 1, 1 },
		{ 1, 3 },
		{ 3, 3 },
	};

	vector<Point2f> polygon_3 = {
		{ 9, 1 },
		{ 1, 15 },
		{ 24, 30 },
		{ 50, 20 },
		{ 30, 20 },
		{ 50, 10 },
	};

	vector<Point2f> polygon_4 = {
		{ 40, 5 },
		{ 50, 9 },
		{ 46, 14 },
		{ 34, 14 },
		{ 30, 9 },
	};

	test(polygon_1);
	test(polygon_2);
	test(polygon_3);
	test(polygon_4);

	return 0;
}
