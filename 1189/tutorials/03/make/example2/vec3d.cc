#include "vec3d.h"

// Math operators
Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs){
	Vec3d ret{lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z};
	return ret;
}

Vec3d operator*(const Vec3d& lhs, const Vec3d& rhs){
	Vec3d ret{lhs.y*rhs.z-lhs.z*rhs.y,
		lhs.z*rhs.x-lhs.x*rhs.z,
		lhs.x*rhs.y-lhs.y*rhs.x};
	return ret;
}

// io operators
std::ostream& operator<<(std::ostream& out, const Vec3d& rhs){
	out << "[ " << rhs.x << ", " << rhs.y << ", " << rhs.z << " ]";
	return out;
}

std::istream& operator>>(std::istream& in, Vec3d& rhs){
	std::cout << "Please enter three numbers:" << std::endl;
	in >> rhs.x >> rhs.y >> rhs.z;
	return in;
}
