#pragma once

#include <opencv2/opencv.hpp>

namespace filters
{

    /**
     * @brief Applies a greyscale version of itself in it
     * 
     * @param image The image to apply the filter on
     * @return cv::Mat The image with the filter on
     */
    cv::Mat greyScale(cv::Mat image);

    /**
     * @brief Blurs the image by using a Gaussian function
     * 
     * @param image The image to apply the blur on
     * @return cv::Mat The image with the blur on
     */
    cv::Mat blur(cv::Mat image);

    /**
     * @brief Finds the edges from an image and displays them
     * 
     * @param image The image to find the edges in
     * @return cv::Mat The image showing only the edges
     */
    cv::Mat edgeDetection(cv::Mat image);

    /**
     * @brief Finds all the circles in an image using the Circle Hough Transform
     * 
     * @param image The image to find the circles in
     * @return std::vector<cv::Vec3f> The list of circles found in the image
     */
    std::vector<cv::Vec3f> circlesDetection(cv::Mat image);
}