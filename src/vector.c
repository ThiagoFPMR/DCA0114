#include "vector.h"

Vector productByScalar(double a, Vector v) 
{
    v.x *= a;
    v.y *= a;
    v.z *= a;

    return v;
}

double scalarProduct(Vector a, Vector b) 
{
    double res = 0;
    res += a.x * b.x;
    res += a.y * b.y;
    res += a.z * b.z;

    return res;
}

Vector vectorSum(Vector a, Vector b) 
{
    Vector res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.z = a.z + b.z;

    return res;
}

Vector vectorSub(Vector a, Vector b) 
{
    Vector res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    res.z = a.z - b.z;

    return res;
}

Vector crossProduct(Vector a, Vector b) 
{
    Vector res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;

    return res;
}

Vector productByMatrix(double m[3][3], Vector v) 
{
    Vector res;
    res.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
    res.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
    res.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;

    return res;
}

Vector normalize(Vector v)
{
    return productByScalar(1/scalarProduct(v, v), v);
}

