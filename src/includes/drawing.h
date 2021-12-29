#pragma once

#include <string>

#include <opencv2/opencv.hpp>

namespace drawing
{
    /**
     * @brief Draws a circle at a location on an image
     * 
     * @param circle The location where to draw the circle
     * @param image The image to draw the circle on
     * @return cv::Mat The image with the circle drawn on it
     */
    cv::Mat drawCircle(cv::Vec3i circle, cv::Mat image);

    /**
     * @brief Draws text to the top-left corner of an image
     * 
     * @param image The image to draw the text on
     * @param text The text to draw on an image
     * @param x The x coordinate of the text
     * @param y The y coordinate of the text
     * @return cv::Mat The image with the text drawn
     */
    cv::Mat drawText(cv::Mat image, std::string text, int x, int y);

    /**
     * @brief Fills an image with a given colour
     * 
     * @param image The image to fill
     * @param colour The colour to fill it with
     * @return cv::Mat The filled image
     */
    cv::Mat fillImage(cv::Mat image, cv::Scalar colour);
}