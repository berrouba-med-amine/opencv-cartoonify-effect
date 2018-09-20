#include <QtCore/QCoreApplication>
#include <iostream>

#include "cartoon.h"


int evilMode_flag = true;
int sketchMode_flag = true;

int evilMode = 1;
int sketchMode = 1;

void evilMode_callback(int, void* )
{
    if(!evilMode)
        evilMode_flag=false;
    else
        evilMode_flag=true;
}

void sketchMode_callback(int, void* )
{
    if(!sketchMode)
        sketchMode_flag=false;
    else
        sketchMode_flag=true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const string win1 = "org_frame";
    const string win2 = "result_frame";
    int cameraNumber = 0;

    if (argc > 1)
        cameraNumber = atoi(argv[1]);
    // Get access to the camera.
    VideoCapture camera;
    camera.open(cameraNumber);
    if (!camera.isOpened())
    {
        cerr << "ERROR: Could not access the camera or video!" << endl;
        exit(1);
    }
    // Try to set the camera resolution.
    camera.set(CV_CAP_PROP_FRAME_WIDTH, 400);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 400);

    //org and result windows
    namedWindow(win1);
    namedWindow(win2);

    createTrackbar("Evil mode",win1, &evilMode, 1, evilMode_callback);
    createTrackbar("Sketch mode",win1, &sketchMode, 1, sketchMode_callback);

    while (true)
    {
        // Grab the next camera frame.
        Mat cameraFrame;
        camera >> cameraFrame;
        if (cameraFrame.empty())
        {
            cerr << "ERROR: Couldn't grab a camera frame." <<   endl;
            exit(1);
        }
        // Create a blank output image, that we will draw onto.
        Mat displayedFrame(cameraFrame.size(), CV_8UC3);

        cartoonifyImage(cameraFrame, displayedFrame,evilMode_flag, sketchMode_flag);

        // Display the processed image onto the screen.
        imshow(win1, cameraFrame);
        imshow(win2, displayedFrame);
        // Wait for at least 20 milliseconds, so that the image can be displayed on the screen!
        // Also checks if a key was pressed in the GUI window.
        if (waitKey(20) == 27)  // Escape Key
            break;
    }
    camera.release();
    destroyWindow(win1);
    destroyWindow(win2);
    return a.exec();
}

