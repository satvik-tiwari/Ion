#include <iostream>
#include "Point3.h"
#include "Color.h"
#include "Ray.h"
#include <cassert>

static double HitSphere(const RTM::Vec3& center, double radius, const Ray& r)
{
	//vector from origin of ray to center of sphere
	RTM::Vec3 oc = center - r.GetOrigin();

	// ax^2 + bx + c = 0
	// calcualte a, b, c using quadratic eqation formula
	// if b^2 - 4ac >= 0, it means real roots exist
	// hence intersection has occured
	double a = RTM::Dot(r.GetDirection(), r.GetDirection());
	double b = -2.0 * RTM::Dot(r.GetDirection(), oc);
	double c = RTM::Dot(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	
	// if < 0 return -1
	if (discriminant < 0)
		return -1;
	// return the closest intersection point t, i.e, smallest root
	else
		return (-b - sqrt(discriminant)) / (2.0 * a);
}

static RTM::Color RayColor(const Ray& ray) 
{
	// if ray hits sphere return color based on noraml at the hit point, otherwiese blue gradient
	double t = HitSphere(RTM::Point3(0, 0, -1), 0.5, ray);
	if (t >= 0.0)
	{
		RTM::Vec3 normal = RTM::Normalize(ray.At(t) - RTM::Vec3(0, 0, -1));
		return 0.5 * RTM::Color(normal.X() + 1.0, normal.Y() + 1.0, normal.Z() + 1.0); // maping normal from -1,1 to 0, 1
	}

	RTM::Vec3 directionNorm = RTM::Normalize(ray.GetDirection());
	// assert(directionNorm.Y() >= -1.0 && directionNorm.Y() <= 1.0);
	// std::cout << "Norm Y : " << directionNorm.Y() << std::endl;
	
	double a = 0.5 * (directionNorm.Y() + 1.0); 
	//std::cout << "a : " << a << std::endl;
	
	// Linear interpolation
	// blended value =  (1 - a) * startValue + a * EndValue 
	auto var1 = ((1.0 - a) * RTM::Color(1.0, 1.0, 1.0));
	auto var2 = (a * RTM::Color(0.5, 0.7, 1.0));

	auto var = var1 + var2;
	// std::cout << "Pixel Color : " << var << std::endl;
	assert(var.X() >= 0.0 && var.X() <= 1.0);
	
	return var;
}

int main()
{
	//-------------------------image-----------------------------------------


	// predetermining aspect ratio and image width
	double aspectRatio = 16.0 / 9.0;
	int imageWidth = 400;

	// calulating image height and making sure its atleast 1
	int imageHeight = int(imageWidth / aspectRatio);
	imageHeight = imageHeight < 1 ? 1 : imageHeight;

	//-------------------------Camera--------------------------------------

	struct Viewport
	{
		RTM::Vec3 u, v;
		RTM::Vec3 upperLeft;
		double height, width;
	};

	Viewport viewport;
	double focalLength = 1.0;
    viewport.height = 2.0;
	viewport.width = viewport.height * (double(imageWidth) / imageHeight);
	RTM::Point3 cameraCenter = RTM::Point3(0, 0, 0);

	// calculate vectors across horizontal and vertical edges of the viewport

	
	viewport.u = RTM::Vec3(viewport.width, 0, 0);
	viewport.v = RTM::Vec3(0, -viewport.height, 0);

	struct Pixel
	{
		RTM::Vec3 delta_u, delta_v;
	};
	
	// calculate the horizontal and vertical delta vectors from pixel to pixel
	Pixel pixel;
	pixel.delta_u = viewport.u / imageWidth;
	pixel.delta_v = viewport.v / imageHeight;

	// calculate the location of the upper left pixel

	// subtracting focal length moves us from camera center to viewport center as focal length
	// is pointing to viewport in -z axis
	// subtracting half of viewport width moves us from center of viewport to left edge
	// subtracting half of viewport height moves us from center of viewport to top edge
	viewport.upperLeft = cameraCenter - RTM::Vec3(0, 0, focalLength) - viewport.u/2 - viewport.v/2; //upper left corner of the viewport

	//to ensure the ray is passing thru the center of the pixel, we half delta_u and delat_v
	RTM::Vec3 pixelLoc00 = viewport.upperLeft + 0.5f * (pixel.delta_u + pixel.delta_v);


	//-------------------------render-------------------------------------------

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	// writing pixels in rows from bottom left to top right
	for (int j = 0; j < imageHeight; j++)
	{
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for (int i = 0; i < imageWidth; i++)
		{
		
			RTM::Vec3 pixelCenter = pixelLoc00 + (i * pixel.delta_u) + (j * pixel.delta_v);
			RTM::Vec3 rayDirection = pixelCenter - cameraCenter; // not normailizing direction because we would have to calculate
															     // square root
																 // and use divsion operation every time and that can be
																 // computationally expensive.

			Ray ray(cameraCenter, rayDirection);

			RTM::Color pixelColor = RayColor(ray);
			RTM::Color::WriteColor(std::cout, pixelColor);
		}
	}
	
	std::clog << "\rDone.                 \n";
	std::cin.get();


	return 0;

}