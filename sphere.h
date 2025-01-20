#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>
#include "vector.h"

typedef struct
{
    Vector center;
    double r;
} Sphere;

Vector sphereNormal(Vector point, Sphere sphere);
bool sphereIntersection(Vector origin, Vector direction, Sphere sphere, Vector * result);

#endif