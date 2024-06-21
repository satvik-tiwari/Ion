#include "Vec3.h"

namespace RTM
{

	Vec3::Vec3()
		: m_E{ 0.0f, 0.0f, 0.0f }
	{
	}

	Vec3::Vec3(double e0, double e1, double e2)
		: m_E{ e0, e1, e2 }
	{
	}

	double Vec3::X() const
	{
		return m_E[0];
	}

	double Vec3::Y() const
	{
		return m_E[1];
	}

	double Vec3::Z() const
	{
		return m_E[2];
	}

	Vec3 Vec3::operator-() const
	{
		return Vec3(-m_E[0], -m_E[1], -m_E[2]);
	}

	double Vec3::operator[](int i) const
	{
		return m_E[i];
	}

	double& Vec3::operator[](int i)
	{
		// TODO: insert return statement here
		return m_E[i];
	}

	Vec3& Vec3::operator+=(const Vec3& v)
	{
		// TODO: insert return statement here
		m_E[0] += v.m_E[0];
		m_E[1] += v.m_E[1];
		m_E[2] += v.m_E[2];

		return *this;
	}

	Vec3& Vec3::operator*=(double t)
	{
		// TODO: insert return statement here

		m_E[0] *= t;
		m_E[1] *= t;
		m_E[2] *= t;

		return *this;

	}

	Vec3& Vec3::operator/=(double t)
	{
		// TODO: insert return statement here

		return *this *= (1 / t);
	}

	double Vec3::Length() const
	{
		return std::sqrt(LengthSquared());
	}

	double Vec3::LengthSquared() const
	{
		return m_E[0] * m_E[0] +
			m_E[1] * m_E[1] +
			m_E[2] * m_E[2];
	}

}
