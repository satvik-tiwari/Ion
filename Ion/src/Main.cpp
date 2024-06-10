#include <iostream>
#include "Point3.h"
#include "Color.h"
#include "Ray.h"

RTM::Color RayColor(const Ray& ray) 
{
	return RTM::Color(0, 0, 0);
}

int main()
{
	//image


	//predetermining aspect ratio and image width
	double aspectRatio = 16.0 / 9.0;
	int imageWidth = 400;

	//calulating image height and making sure its atleast 1
	int imageHeight = int(imageWidth / aspectRatio);
	imageHeight = imageHeight < 1 ? 1 : imageHeight;

	//camera

	struct Viewport
	{
		RTM::Vec3 u, v;
		RTM::Vec3 upperLeft;
		double height, width;
	};

	Viewport viewport;
	double focalLength = 1.0;
    viewport.height = 2.0;
	viewport.height * (double(imageWidth) / imageHeight);
	RTM::Point3 cameraCenter = RTM::Point3(0, 0, 0);

	//calculate vectors across horizontal and vertical edges of the viewport

	
	viewport.u = RTM::Vec3(viewport.width, 0, 0);
	viewport.v = RTM::Vec3(0, -viewport.height, 0);

	struct Pixel
	{
		RTM::Vec3 delta_u, delta_v;
	};

	Pixel pixel;
	pixel.delta_u = viewport.u / imageWidth;
	pixel.delta_v = viewport.v / imageHeight;

	//calculate the location of the upper left pixel

	viewport.upperLeft = cameraCenter - RTM::Vec3(0, 0, focalLength) - viewport.u/2 - viewport.v/2;
	auto pixelLoc00 = viewport.upperLeft + 0.5f * (pixel.delta_u + pixel.delta_v);
	//render

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	//writing pixels in rows from bottom left to top right
	for (int j = 0; j < imageHeight; j++)
	{
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for (int i = 0; i < imageWidth; i++)
		{
			RTM::Color pixelColor = RTM::Color(double(i) / (imageWidth - 1),
				double(j) / (imageHeight), 0);

			pixelColor.WriteColor(std::cout, pixelColor);
		}
	}
	
	std::clog << "\rDone.                 \n";
	std::cin.get();

	RTM::Point3 p(2.0f, 2.0f, 2.0f);

	return 0;

}