#include "./includes/main.h"

#define FPS 60

/**
 * @brief The core of the program, contains the initializers and the main loop
 * 
 * @return int The status of the program at the end
 */
int main()
{

    std::string activeFilters = "FPS: " + FPS + '\n';

    cv::Mat capturedFrame, modifiedFrame;

    cv::VideoCapture vid(0);

    if (!vid.isOpened())
    {
        exit(-1);
    }

    bool greyFilter = false;
    bool edgeFilter = false;
    bool circleFilter = false;
    bool circlesFilter = false;

    while (vid.read(capturedFrame))
    {
        activeFilters += "Active Filters: ";

        modifiedFrame = capturedFrame.clone();

        if (greyFilter)
        {
            activeFilters += "Grey Filter ";
            modifiedFrame = filters::greyScale(capturedFrame);
        }
        if (edgeFilter)
        {
            activeFilters += "Edge Filter ";
            cv::Mat filter = filters::greyScale(capturedFrame);
            filter = filters::blur(filter);
            if (greyFilter)
                modifiedFrame += filters::edgeDetection(filter);
            else
                modifiedFrame = filters::edgeDetection(filter);
        }
        if (circleFilter || circlesFilter)
        {
            if (circleFilter)
            {
                activeFilters += "Circle Filter ";
            }
            else
            {
                activeFilters += "Circles Filter ";
            }

            cv::Mat filter = filters::greyScale(capturedFrame);
            filter = filters::blur(filter);
            filter = filters::edgeDetection(filter);
            std::vector<cv::Vec3f> circles = filters::circlesDetection(filter);
            if (circles.size() > 0)
            {
                if (circleFilter)
                {
                    int maxRadius = 0;
                    cv::Vec3i biggestCircle;
                    for (int i = 0; i < circles.size(); i++)
                    {
                        if (circles[i][2] > maxRadius)
                        {
                            biggestCircle = circles[i];
                            maxRadius = biggestCircle[2];
                        }
                    }

                    modifiedFrame = drawing::drawCircle(biggestCircle, modifiedFrame);
                }
                else
                {
                    for (int i = 0; i < circles.size(); i++)
                    {
                        modifiedFrame = drawing::drawCircle(circles[i], modifiedFrame);
                    }
                }
            }
        }

        // Creates the material for the info window
        cv::Mat activeFiltersMat = capturedFrame.clone();
        activeFiltersMat = drawing::fillImage(activeFiltersMat, cv::Scalar(0, 0, 0));
        activeFiltersMat = drawing::drawText(activeFiltersMat, activeFilters, 10, activeFiltersMat.rows / 2);

        // Creates the 2 windows
        cv::imshow("Active Filters", activeFiltersMat);
        cv::imshow("Circle Detection Webcam", modifiedFrame);

        int pressedKey = cv::waitKey(1000 / FPS);

        // `Esc` Key - Exits the program
        if (pressedKey == 27)
            exit(0);

        // `G` Key - Toggles the grey filter
        if (pressedKey == 103 || pressedKey == 71)
        {
            greyFilter = !greyFilter;
        }

        // `E` Key - Toggles the edge detection filter
        if (pressedKey == 101 || pressedKey == 69)
        {
            edgeFilter = !edgeFilter;
        }

        // `C` Key - Toggles the single circle detection filter
        if (pressedKey == 99 || pressedKey == 67)
        {
            circleFilter = !circleFilter;
            circlesFilter = false;
        }

        // `A` Key - Toggles the multiple circles filter
        if (pressedKey == 97 || pressedKey == 65)
        {
            circlesFilter = !circlesFilter;
            circleFilter = false;
        }
    }

    exit(0);
}