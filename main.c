#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "vector.h"
#include "sphere.h"
#include "lighting.h"

typedef struct 
{
    int width;
    int height;
    double fov;
    int centerX;
    int centerY;
} Camera;

Vector unproject(int x, int y, Camera camera) 
{
    double aspectRatio = camera.width / camera.height;
    double hFOV = atan(aspectRatio * (camera.fov / 2));
    double hFocalDistance = camera.width / (2 * tan(hFOV / 2));
    double vFocalDistance = camera.height / (2 * tan(camera.fov / 2));

    Vector direction = {(x - camera.centerX) / hFocalDistance, (y - camera.centerY) / vFocalDistance, 1};
    return normalize(direction);
}

int main() 
{
    // Intersection test
    Vector origin = {-1, 0, 0};
    Vector direction = {1, 0, 0};
    Vector center = {5, 0, 0};
    Sphere sphere = {center, 1};
    Vector result;
    bool res = sphereIntersection(origin, direction, sphere, &result);
    printf("Intersection test\n");
    printf("origin = (%f, %f, %f)\n", origin.x, origin.y, origin.z);
    printf("direction = (%f, %f, %f)\n", direction.x, direction.y, direction.z);
    printf("sphere = (%f, %f, %f, %f)\n", center.x, center.y, center.z, sphere.r);
    if (res) 
    {
        printf("intersection point = (%f, %f, %f)\n", result.x, result.y, result.z);
    } 
    else 
    {
        printf("no intersection\n");
    }

    // Lighting test
    Vector lightPos = {0, 0, 0};
    Vector normal = sphereNormal(result, sphere);
    Vector light = getLightVector(result, lightPos);
    Vector reflection = getReflectionVector(light, normal);
    Vector observer = getObserverVector(result, origin);

    printf("\nLighting test\n");
    printf("lightPos = (%f, %f, %f)\n", lightPos.x, lightPos.y, lightPos.z);
    printf("normal = (%f, %f, %f)\n", normal.x, normal.y, normal.z);
    printf("light = (%f, %f, %f)\n", light.x, light.y, light.z);
    printf("reflection = (%f, %f, %f)\n", reflection.x, reflection.y, reflection.z);
    printf("observer = (%f, %f, %f)\n", observer.x, observer.y, observer.z);

    // int a = 2;
    // Vector v = {1, 2, 3};
    // Vector r1 =  productByScalar(a, v);
    // printf("Scalar product\n");
    // printf("a = %d\n", a);
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("a * v = (%f, %f, %f)\n", r1.x, r1.y, r1.z);

    // Vector u = {4, 5, 6};
    // int r2 = scalarProduct(v, u);
    // printf("\nScalar product\n");
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    // printf("v . u = %d\n", r2);

    // Vector r3 = vectorSum(v, u);
    // printf("\nVector sum\n");
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    // printf("v + u = (%f, %f, %f)\n", r3.x, r3.y, r3.z);

    // Vector r4 = vectorSub(v, u);
    // printf("\nVector subtraction\n");
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    // printf("v - u = (%f, %f, %f)\n", r4.x, r4.y, r4.z);

    // Vector r5 = crossProduct(v, u);
    // printf("\nCross product\n");
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    // printf("v x u = (%f, %f, %f)\n", r5.x, r5.y, r5.z);

    // double m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Vector r6 = productByMatrix(m, v);
    // printf("\nProduct by matrix\n");
    // printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    // printf("m = |%f, %f, %f|\n", m[0][0], m[0][1], m[0][2]);
    // printf("    |%f, %f, %f|\n", m[1][0], m[1][1], m[1][2]);
    // printf("    |%f, %f, %f|\n", m[2][0], m[2][1], m[2][2]);
    // printf("m * v = (%f, %f, %f)\n", r6.x, r6.y, r6.z);

    return 0;
}

