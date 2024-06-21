#pragma once

#ifndef RTCore_H
#define RTCore_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// constants

const double RT_INFINITY = std::numeric_limits<double>::infinity();
const double RT_PI = 3.1415926535897932385;

// utility functions

inline double DegreesToRadians(double degrees)
{
	return degrees * RT_PI / 180.0;
}

// common headers

#include "Vec3.h"
#include "Color.h"
#include "Point3.h"
#include "Ray.h"

#endif // !RTCore_H
