#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "sphere.h"
#include "vector.h"

Vector sphereNormal(Vector point, Sphere sphere) 
{
    Vector normal = vectorSub(point, sphere.center);
    return normalize(normal);
}

bool sphereIntersection(Vector origin, Vector direction, Sphere sphere, Vector * result) 
{
    Vector s = vectorSub(origin, sphere.center);

    double a = scalarProduct(direction, direction);
    double b = 2 * scalarProduct(direction, s);
    double c = scalarProduct(s, s) - sphere.r * sphere.r;

    double delta = b * b - 4 * a * c;

    if (delta < 0) 
        return false;

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 < 0 && t2 < 0) 
        return false;
    
    if (t1 < 0) 
        *result = vectorSum(origin, productByScalar(t2, direction));
    else if (t2 < 0) 
        *result = vectorSum(origin, productByScalar(t1, direction));
    else 
    {
        if (t1 < t2) 
            *result = vectorSum(origin, productByScalar(t1, direction));
        else 
            *result = vectorSum(origin, productByScalar(t2, direction));
    }
    return true;
}
