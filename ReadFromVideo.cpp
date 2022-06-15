#include "ReadFromVideo.h"


bool ReadFromVideo::setDeviceName(char* videopath){
	std::cout << "[" << __func__ << "]" << "videopath:" << videopath << std::endl; 
	printf("[%s] videopath = %s \n", __func__, videopath);
	mCapture.open(videopath);
	if(!mCapture.isOpened())
	{
		std::cout<<  "ERROR: Can't initialize camera capture." << std::endl;
		return false;
	}
	mFrameTotalCount = mCapture.get(cv::CAP_PROP_FRAME_COUNT);
	return true;
}

bool ReadFromVideo::setDeviceName(int number)
{
	std::cout << "[" << __func__ << "]" << "number:" << number << std::endl; 
	mCapture.open(number);
	if(!mCapture.isOpened())
	{
		std::cout <<"ERROR: Can't initialize camera capture." << std::endl;
		return false;
	}
	mFrameTotalCount = mCapture.get(cv::CAP_PROP_FRAME_COUNT);
	return true;
}

bool ReadFromVideo::updateFrameFromNumber(int number, cv::Mat &frame){

		if( number > mFrameTotalCount)
		{
			std::cerr << "ERROR blank frame grabbed \n";
			return false;
		}

		mCapture.set(cv::CAP_PROP_POS_FRAMES, number);
		mCapture.read(frame);
		if( frame.empty())
		{
				std::cerr << "ERROR blank frame grabbed \n";
				return false;
		}
		return true;
}
	



