#include <math.h>
#include <stdio.h>

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

Vector calculateLighting(Vector light, Vector normal, Vector relefction, Vector observer, Vector surfaceColor)
{
    Vector ambientLightPos = {0, 0, 0};

    double ambientCoff = 0.2;
    double diffuseCoff = 0.7;
    double specularCoff = 0.7;
    double decay = 10;

    Vector Ia = productByScalar(ambientCoff, ambientLightPos);
    Vector Id = productByScalar(diffuseCoff * scalarProduct(light, normal), surfaceColor);
    Vector Is = productByScalar(specularCoff * pow(scalarProduct(relefction, observer), decay), surfaceColor);

    return vectorSum(vectorSum(Ia, Id), Is);
}
