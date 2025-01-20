#ifndef LIGHTING_H
#define LIGHTING_H

Vector getLightVector(Vector surface, Vector lightPos);
Vector getReflectionVector(Vector light, Vector normal);
Vector getObserverVector(Vector surface, Vector observer);

#endif