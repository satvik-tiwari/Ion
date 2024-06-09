#include "Vec3.h"

//Vec3(vector) class utility functions
//seperate file for inline functions
namespace RTM
{

	inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
	{
		return out << v.m_E[0] << ' ' << v.m_E[1] << ' ' << v.m_E[2];
	}

	inline Vec3 operator+(const Vec3& u, const Vec3& v)
	{
		return Vec3(u.m_E[0] + v.m_E[0], u.m_E[1] + v.m_E[1],
			u.m_E[2] + v.m_E[2]);
	}

	inline Vec3 operator-(const Vec3& u, const Vec3& v)
	{
		return Vec3(u.m_E[0] - v.m_E[0], u.m_E[1] - v.m_E[1],
			u.m_E[2] - v.m_E[2]);
	}

	inline Vec3 operator*(const Vec3& u, const Vec3& v)
	{
		return Vec3(u.m_E[0] * v.m_E[0], u.m_E[1] * v.m_E[1],
			u.m_E[2] * v.m_E[2]);
	}

	inline Vec3 operator*(double t, const Vec3& u)
	{
		return Vec3(t * u.m_E[0], t * u.m_E[1],
			t * u.m_E[2]);
	}

	inline Vec3 operator*(const Vec3& u, double t)
	{
		return t * u;
	}

	inline Vec3 operator/(const Vec3& u, double t)
	{
		return (1 / t) * u;
	}

	//dot product between 2 vectors
	inline double Dot(const Vec3& u, const Vec3& v)
	{
		return (u.m_E[0] * v.m_E[0] +
			u.m_E[1] * v.m_E[1] +
			u.m_E[2] * v.m_E[2]);
	}

	//cross product b/t 2 vectors
	inline Vec3 Cross(const Vec3& u, Vec3& v)
	{
		//u1v2 -v1u2, -(u0v2 - v0u2), u0v1 - vou1
		return Vec3(u.m_E[1] * v.m_E[2] - v.m_E[1] * u.m_E[2],
			u.m_E[2] * v.m_E[0] - v.m_E[2] * u.m_E[0],
			u.m_E[0] * v.m_E[1] - v.m_E[0] * u.m_E[1]);
	}

	//getting a unit vector
	inline Vec3 Normalize(const Vec3& v)
	{
		return v / v.Length();
	}
}