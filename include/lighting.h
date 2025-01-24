#ifndef LIGHTING_H
#define LIGHTING_H

#include "vector.h"

Vector getLightVector(Vector surface, Vector lightPos);
Vector getReflectionVector(Vector light, Vector normal);
Vector getObserverVector(Vector surface, Vector observer);

Vector calculateLighting(Vector light, Vector normal, Vector relefction, Vector observer, Vector surfaceColor);

#endif