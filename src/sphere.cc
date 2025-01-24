#include <cmath>
#include <stdbool.h>
#include <cstdio>

#include "sphere.h"
#include "vector.h"

Vector sphereNormal(Vector point, Sphere sphere) 
{
    Vector normal = vectorSub(point, sphere.center);
    return normalize(normal);
}

bool sphereIntersection(Vector origin, Vector direction, Sphere sphere, Vector * result) 
{
    // printf("origin: %f %f %f\n", origin.x, origin.y, origin.z);
    // printf("direction: %f %f %f\n", direction.x, direction.y, direction.z);
    // printf("sphere center: %f %f %f\n", sphere.center.x, sphere.center.y, sphere.center.z);
    // printf("sphere radius: %f\n", sphere.r);
    Vector s = vectorSub(origin, sphere.center);
    // printf("s: %f %f %f\n", s.x, s.y, s.z);

    double a = scalarProduct(direction, direction);
    double b = 2 * scalarProduct(direction, s);
    double c = scalarProduct(s, s) - sphere.r * sphere.r;
    // printf("a: %f\n", a);
    // printf("b: %f\n", b);
    // printf("c: %f\n", c);
    // printf("b^2 - 4ac: %f\n", b * b - 4 * a * c);
    // printf("sqrt(b^2 - 4ac): %f\n", sqrt(b * b - 4 * a * c));

    double delta = b * b - 4 * a * c;

    if (delta < 0) 
    {
        return false;
    }

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 < 0 && t2 < 0) 
    {
        return false;
    }
    
    if (t1 < 0) 
    {
        *result = vectorSum(origin, productByScalar(t2, direction));
        // result->x = origin.x + direction.x * t2;
        // result->y = origin.y + direction.y * t2;
        // result->z = origin.z + direction.z * t2;
    } 
    else if (t2 < 0) 
    {
        *result = vectorSum(origin, productByScalar(t1, direction));
        // result->x = origin.x + direction.x * t1;
        // result->y = origin.y + direction.y * t1;
        // result->z = origin.z + direction.z * t1;
    } 
    else 
    {
        if (t1 < t2) 
        {
            *result = vectorSum(origin, productByScalar(t1, direction));
            // result->x = origin.x + direction.x * t1;
            // result->y = origin.y + direction.y * t1;
            // result->z = origin.z + direction.z * t1;
        } 
        else 
        {
            *result = vectorSum(origin, productByScalar(t2, direction));
            // result->x = origin.x + direction.x * t2;
            // result->y = origin.y + direction.y * t2;
            // result->z = origin.z + direction.z * t2;
        }
    }
    return true;
}