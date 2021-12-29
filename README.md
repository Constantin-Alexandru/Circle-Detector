CIRCLE DETECTION IN C++ WITH OPENCV
===================================

## PREREQUISITES 

- [OpenCV](https://opencv.org/)
- [CMake](https://cmake.org/)

## HOW TO RUN THE PROJECT

#### WINDOWS

 **FOR COMPILATION ONLY:** Run the `compile.cmd` file
 **FOR EXECUTION OF PROGRAM:** Run the `run.cmd` file
 **FOR COMPILATION AND EXECUTION:** Run the `cmpNrun.cmd` file

<br /> 
<br /> 

 #### LINUX

Run the `linuxScript` file


## HOW TO USE THE PROJECT

By pressing `G`, the *GreyScale filter* will be applied to the webcam.
<br />
By pressing `E`, the *Edge Detection filter* will be applied to the webcam.
<br />
By pressing `C`, the ***Circle** Detection filter* will be applied to the webcam.
<br />
By pressing `A`, the ***Circles** Detection filter* will be applied to the webcam.

**NOTE 1:** In order for one filter to work, you don't need to activate the others. The filters work independently of each other.

**NOTE 2:** The `Circle` and `Circles` filter are the same filter, the *Circle* filter **only** showing the biggest circle.

**NOTE 3:** The filters can be stacked on top of one another, with the exception of the `Circle` and `Circles` filters, which cannot be active simultaneously.