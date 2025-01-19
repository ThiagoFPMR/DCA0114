#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    double x;
    double y;
    double z;
} Vector;

typedef struct
{
    double xo;
    double yo;
    double zo;
    double r;
} Sphere;

bool sphereIntersection(Vector origin, Vector direction, Sphere sphere, Vector * result) 
{
    double a = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
    double b = 2 * (direction.x * (origin.x - sphere.xo) + direction.y * (origin.y - sphere.yo) + direction.z * (origin.z - sphere.zo));
    double c = (origin.x - sphere.xo) * (origin.x - sphere.xo) + (origin.y - sphere.yo) * (origin.y - sphere.yo) + (origin.z - sphere.zo) * (origin.z - sphere.zo) - sphere.r * sphere.r;
    
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

Vector productByScalar(double a, Vector v) 
{
    v.x *= a;
    v.y *= a;
    v.z *= a;

    return v;
}

int scalarProduct(Vector a, Vector b) 
{
    int res = 0;
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

int main() 
{
    int a = 2;
    Vector v = {1, 2, 3};
    Vector r1 =  productByScalar(a, v);
    printf("Scalar product\n");
    printf("a = %d\n", a);
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("a * v = (%f, %f, %f)\n", r1.x, r1.y, r1.z);

    Vector u = {4, 5, 6};
    int r2 = scalarProduct(v, u);
    printf("\nScalar product\n");
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    printf("v . u = %d\n", r2);

    Vector r3 = vectorSum(v, u);
    printf("\nVector sum\n");
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    printf("v + u = (%f, %f, %f)\n", r3.x, r3.y, r3.z);

    Vector r4 = vectorSub(v, u);
    printf("\nVector subtraction\n");
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    printf("v - u = (%f, %f, %f)\n", r4.x, r4.y, r4.z);

    Vector r5 = crossProduct(v, u);
    printf("\nCross product\n");
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("u = (%f, %f, %f)\n", u.x, u.y, u.z);
    printf("v x u = (%f, %f, %f)\n", r5.x, r5.y, r5.z);

    double m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Vector r6 = productByMatrix(m, v);
    printf("\nProduct by matrix\n");
    printf("v = (%f, %f, %f)\n", v.x, v.y, v.z);
    printf("m = |%f, %f, %f|\n", m[0][0], m[0][1], m[0][2]);
    printf("    |%f, %f, %f|\n", m[1][0], m[1][1], m[1][2]);
    printf("    |%f, %f, %f|\n", m[2][0], m[2][1], m[2][2]);
    printf("m * v = (%f, %f, %f)\n", r6.x, r6.y, r6.z);

    return 0;
}

