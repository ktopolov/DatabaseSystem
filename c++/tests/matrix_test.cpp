#include <iostream>

#include "math/Matrix.h"

int main()
{
    std::cout << "Hello World" << std::endl;
    matrix::Vector3 vec1(1.0, 2.0, 2.0);
    std::cout << vec1.norm() << std::endl;

    const matrix::Vector3 vec2(2.0, 1.0, 0.0);

    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;

    float dotProd = matrix::dot(vec1, vec2);
    std::cout << "Dot product: " << dotProd << std::endl;

    const matrix::Vector3 vec3 = matrix::cross(vec1, vec2);
    std::cout << "Cross Product: " << vec3 << std::endl;
}
