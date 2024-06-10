#include <iostream>
#include "Point3.h"
#include "Color.h"

int main()
{
	//image

	int image_width = 256;
	int image_height = 256;

	//render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	//writing pixels in rows from bottom left to top right
	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			RTM::Color pixelColor = RTM::Color(double(i) / (image_width - 1),
				double(j) / (image_height), 0);

			pixelColor.WriteColor(std::cout, pixelColor);
		}
	}
	
	std::clog << "\rDone.                 \n";
	std::cin.get();

	RTM::Point3 p(2.0f, 2.0f, 2.0f);

	return 0;

}