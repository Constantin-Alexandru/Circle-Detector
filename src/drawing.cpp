#include "./includes/drawing.h"

cv::Mat drawing::drawCircle(cv::Vec3i circle, cv::Mat image)
{
    cv::Mat circledImage = image.clone();

    cv::Point center = cv::Point(circle[0], circle[1]);

    int radius = circle[2];

    cv::circle(circledImage, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);

    cv::circle(circledImage, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);

    return circledImage;
}

cv::Mat drawing::drawText(cv::Mat image, std::string text, int x, int y)
{
    cv::Mat textImage = image.clone();
    cv::putText(textImage, text, cv::Point(x, y), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.9, cv::Scalar(118, 185, 0), 2);

    return textImage;
}

cv::Mat drawing::fillImage(cv::Mat image, cv::Scalar colour)
{
    cv::Mat filledImage = image.clone();
    filledImage = colour;
    return filledImage;
}