#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

namespace matrix
{
    class Vector3
    {
    public:
        // /**
        //  * Instantiate vector
        //  *
        //  * @param x X-Component of vector
        //  * @param y Y-Component of vector
        //  * @param z Z-Component of vector
        //  */
        Vector3(float x, float y, float z);

        // /**
        //  * Destruct vector
        //  */
        ~Vector3();

        // the float getX() const tells compiler that Vector3 will not be modified within getX()

        // /**
        //  * Get vector components
        //  */
        float getX() const { return this->x; };
        float getY() const { return this->y; };
        float getZ() const { return this->z; };

        // /**
        //  * L2 norm of a vector
        //  *
        //  * @return L2 norm (length) of the vector
        //  */
        float norm();

        friend std::ostream &operator<<(std::ostream &os, const matrix::Vector3 &vec)
        {
            os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]" << std::endl;
            return os;
        }

    private:
        float x; // x-component
        float y; // y-component
        float z; // z-component
    };

    // /**
    //  * Dot product of two vectors.
    //  *
    //  * @param v1 First vector
    //  * @param v2 Second vector
    //  * @return Dot product of two vectors
    //  */
    float dot(const matrix::Vector3 &v1, const matrix::Vector3 &v2);

    // /**
    //  * Cross product of two vectors.
    //  *
    //  * @param v1 First vector
    //  * @param v2 Second vector
    //  * @return Cross product of two vectors
    //  */
    Vector3 cross(const matrix::Vector3 &v1, const matrix::Vector3 &v2);

}

// Remove this when I have

#endif // MATRIX_H
