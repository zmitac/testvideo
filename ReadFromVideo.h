#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // cv::Canny()
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp> 
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/video/video.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class ReadFromVideo
{

public:
	ReadFromVideo(){};
	~ReadFromVideo(){};
	bool setDeviceName(char* videopath);
	bool setDeviceName(int number);

	void ppp(int a){ std::cout << "a = " << a << std::endl;}

	cv::VideoCapture *getCapture(){return &mCapture;}

	int getFrameTotalCount(){ 
		return mFrameTotalCount;
	}

	bool updateFrameFromNumber(int number, cv::Mat &frame);


	cv::VideoCapture mCapture;

private:
	int mFrameTotalCount = 0;
	cv::Mat mSrcFrame;


};




