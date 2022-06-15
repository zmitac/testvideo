#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> 
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utility.hpp>
//add detection
#include <opencv2/objdetect.hpp>

#include <opencv2/video/video.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ReadFromVideo.h"


using namespace cv;
using namespace std;


int main(int argc, char*argv[])
{
	
	ReadFromVideo mCap;

	CommandLineParser parser(argc, argv,
							"{help h||}"
							"{video|. |path/video.mp4.}"
							);
	parser.printMessage();
	

	//VideoCapture cap;
	//cap.open(&videoin[0]);
	//cap.open(argv[1]);
	char *arr = argv[1];
	mCap.ppp(3);
	//bool capflag = mCap.setDeviceName(0);
	bool capflag = mCap.setDeviceName(arr);
	char tmp;
	double ticks = 0;
	bool stopflag = false;
	//if(!cap.isOpened())
	if(!capflag)
	{
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}
	//int total_frame = int(cap.get(CAP_PROP_FRAME_COUNT));
	//int total_frame = int(mCap.getCapture()->get(CAP_PROP_FRAME_COUNT));
	int total_frame = mCap.getFrameTotalCount();
	printf("total_frame = %d \n", total_frame);


	cv::Mat frame;
	int framecount = 0;
	bool frameflag = false;
	while( framecount <= total_frame){

		frameflag = mCap.updateFrameFromNumber(framecount, frame);
		if( frameflag){
		namedWindow("Live", WINDOW_KEEPRATIO);
		imshow("Live", frame);
		if(stopflag)
			tmp = waitKey(0) & 0xff;
		else
			tmp = waitKey(5) & 0xff;

		if( tmp == 0 || tmp == 27 || tmp == 'q' )
			break;
		}
		if( tmp =='s' || tmp == 'S')
		{
			stopflag = true;
		}
		if( tmp =='r' || tmp == 'R')
		{
			stopflag = false;
		}

		printf("frame no = %d/ %d\n", framecount, total_frame);
		if( framecount >= total_frame)
			break;//framecount==0;
		else 
			framecount+=1;
	
	}
	destroyAllWindows();
	return 0;

}


#if 0

/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
    Mat frame;
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
#endif
