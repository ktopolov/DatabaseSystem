#include <iostream>
#include <math.h>

#include "math/Matrix.h"

matrix::Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    std::cout << "Ran it!" << std::endl;
}

matrix::Vector3::~Vector3()
{
    std::cout << "Descructed!" << std::endl;
}

float matrix::Vector3::norm()
{
    float out = std::sqrt(std::pow(this->x, 2.0) + std::pow(this->y, 2.0) + std::pow(this->z, 2.0));
    return out;
}

float matrix::dot(const matrix::Vector3 &v1, const matrix::Vector3 &v2)
{
    float out = v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
    return out;
}

matrix::Vector3 matrix::cross(const matrix::Vector3 &v1, const matrix::Vector3 &v2)
{
    float x = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
    float y = -(v1.getX() * v2.getZ() - v1.getZ() * v2.getX());
    float z = v1.getX() * v2.getY() - v1.getY() * v2.getX();
    // matrix::Vector3 out(x, y, z);
    return matrix::Vector3(x, y, z);
}
