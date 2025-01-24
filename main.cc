#include <cstdio>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <fstream>

#include "vector.h"
#include "sphere.h"
#include "lighting.h"

typedef struct 
{
    int width;
    int height;
    double fov;
} Camera;

Vector unproject(int x, int y, Camera camera, Vector cameraPos) 
{
    double scale = tan(camera.fov * 0.5 * M_PI / 180.0);
    double aspectRatio = static_cast<double>(camera.width) / camera.height;

    double xCoord = (2 * (x + 0.5) / camera.width - 1) * aspectRatio * scale;
    double yCoord = (1 - 2 * (y + 0.5) / camera.height) * scale;
    double zCoord = -1;

    Vector direction = {xCoord, yCoord, zCoord};
    return normalize(direction);
}

void display(const std::vector<std::vector<cv::Vec3b>>& image)
{
    cv::Mat img(1000, 1000, CV_8UC3, cv::Scalar(0, 0, 0));

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            img.at<cv::Vec3b>(i, j) = image[i][j];
        }
    }

    cv::imshow("image", img);
    cv::waitKey(0);
}

void saveImgToFile(const std::vector<std::vector<cv::Vec3b>>& image, const std::string& filename)
{
    cv::Mat img(1000, 1000, CV_8UC3, cv::Scalar(0, 0, 0));

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            img.at<cv::Vec3b>(i, j) = image[i][j];
        }
    }

    cv::imwrite(filename, img);
}

int main() 
{
    Vector cameraPos = {0, 0, 0};
    Camera camera = {1000, 1000, 90};
    Sphere sphere = {{0, 0, -3}, 1};
    Vector sphereColor = {1, 0, 0};

    Vector lightPos = {5, 5, 10};

    std::vector<std::vector<cv::Vec3b>> image(camera.height, std::vector<cv::Vec3b>(camera.width, cv::Vec3b(0, 0, 0)));

    for (int i = 0; i < camera.height; i++)
    {
        for (int j = 0; j < camera.width; j++)
        {
            Vector direction = unproject(j, i, camera, cameraPos);
            Vector intersectionPoint;
            if (sphereIntersection(cameraPos, direction, sphere, &intersectionPoint))
            {
                Vector light = getLightVector(intersectionPoint, lightPos);
                Vector normal = sphereNormal(intersectionPoint, sphere);
                Vector observer = getObserverVector(intersectionPoint, cameraPos);
                Vector reflection = getReflectionVector(light, normal);

                Vector color = calculateLighting(light, normal, reflection, observer, sphereColor);

                image[i][j][0] = static_cast<uchar>(std::min(255.0, std::max(0.0, color.x * 255)));
                image[i][j][1] = static_cast<uchar>(std::min(255.0, std::max(0.0, color.y * 255)));
                image[i][j][2] = static_cast<uchar>(std::min(255.0, std::max(0.0, color.z * 255)));
            }
            else
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }
    }

    saveImgToFile(image, "image.png");
    display(image);

    return 0;
}