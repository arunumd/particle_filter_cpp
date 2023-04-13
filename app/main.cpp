#include <iostream>
#include <bee-map.h>
// OPENCV Headers
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
	
using namespace cv;

int main(int argc, char *argv[]) {
    std::cout << "BEEMAP " << std::endl;
	
	char mapName[100];  // Name of the map file
	strncpy(mapName,"wean.dat",100);
    map_type* map = (map_type*) malloc(sizeof(map_type)); // Dynamic Memory Location
	
	read_beesoft_map(mapName,map);	

	// Create Mat object
	Mat image_map = Mat::zeros(map->size_x, map->size_y, CV_32FC1);
	
	for(int i = 0;i < image_map.rows;i++)
	{
		for(int j = 0;j < image_map.cols;j++)
		{
			if(map->prob[i][j] > 0.0)
				image_map.at<float>(i,j) = map->prob[i][j];
		}
	}

	namedWindow("mapImage",WINDOW_AUTOSIZE);
	imshow("mapImage",image_map);

	waitKey(0);
	return 0;
}
