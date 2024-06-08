#include <iostream>

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
		for (int i = 0; i < image_width; i++)
		{
			double r = double(i) / (image_width - 1);
			double g = double(j) / (image_height - 1);
			double b = 0.0f;

			int ir = (255.999 * r);
			int ig = (255.999 * g);
			int ib = (255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
		}
	}

	std::cin.get();

	return 0;

}