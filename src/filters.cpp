#include "./includes/filters.h"

cv::Mat filters::greyScale(cv::Mat image)
{
    cv::Mat greyImage;

    cv::cvtColor(image, greyImage, cv::COLOR_BGR2GRAY);

    return greyImage;
}

cv::Mat filters::blur(cv::Mat image)
{
    cv::Mat blurredImage;

    cv::GaussianBlur(image, blurredImage, cv::Size(7, 7), 1.5, 1.5);

    return blurredImage;
}

cv::Mat filters::edgeDetection(cv::Mat image)
{
    cv::Mat edgeImage = image.clone();
    cv::Canny(edgeImage, edgeImage, 0, 30, 3);

    return edgeImage;
}

std::vector<cv::Vec3f> filters::circlesDetection(cv::Mat image)
{
    std::vector<cv::Vec3f> circles;

    cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1, image.rows / 16, 100, 30, 1, 30);

    return circles;
}
