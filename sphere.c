#include <math.h>
#include <stdbool.h>

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
    
    double t1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    double t2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);

    if (t1 < 0 && t2 < 0) 
    {
        return false;
    }
    
    if (t1 < 0) 
    {
        result->x = origin.x + direction.x * t2;
        result->y = origin.y + direction.y * t2;
        result->z = origin.z + direction.z * t2;
    } 
    else if (t2 < 0) 
    {
        result->x = origin.x + direction.x * t1;
        result->y = origin.y + direction.y * t1;
        result->z = origin.z + direction.z * t1;
    } 
    else 
    {
        if (t1 < t2) 
        {
            result->x = origin.x + direction.x * t1;
            result->y = origin.y + direction.y * t1;
            result->z = origin.z + direction.z * t1;
        } 
        else 
        {
            result->x = origin.x + direction.x * t2;
            result->y = origin.y + direction.y * t2;
            result->z = origin.z + direction.z * t2;
        }
    }
    return true;
}