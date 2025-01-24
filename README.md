# Compilation command
```
g++ -Iinclude main.cc src/sphere.c src/lighting.c src/vector.c -o run `pkg-config --cflags --libs opencv4`
```