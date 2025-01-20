#include "vector.h"
#include "lighting.h"

Vector getLightVector(Vector surface, Vector lightPos) 
{
    return normalize(vectorSub(lightPos, surface));
}

Vector getReflectionVector(Vector light, Vector normal) 
{
    return normalize(vectorSub(productByScalar(2 * scalarProduct(light, normal), normal), light));
}

Vector getObserverVector(Vector surface, Vector observer) 
{
    return normalize(vectorSub(observer, surface));
}