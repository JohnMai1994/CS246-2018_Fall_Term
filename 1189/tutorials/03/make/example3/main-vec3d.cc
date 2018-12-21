#include "vec3d.h"
#include <iostream>
using namespace std;

int main(){
	Vec3d v1 {1,2,3};
	cout << v1 << endl;

	Vec3d v2;
	cin >> v1 >> v2;
	Vec3d sum = v1 + v2;
	Vec3d crossProd = v1 * v2;
	cout << "Sum is " << sum << " and the cross product is " << crossProd << endl;
}
