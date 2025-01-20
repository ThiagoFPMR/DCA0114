#ifndef VECTOR_H
#define VECTOR_H

typedef struct 
{
    double x;
    double y;
    double z;
} Vector;

Vector productByScalar(double a, Vector v);
double scalarProduct(Vector a, Vector b);
Vector vectorSum(Vector a, Vector b);
Vector vectorSub(Vector a, Vector b);
Vector crossProduct(Vector a, Vector b);
Vector productByMatrix(double m[3][3], Vector v);
Vector normalize(Vector v);

#endif