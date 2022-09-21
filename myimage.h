//Author: Jason Rodriguez
//Date:   Sep 21 2022
//Header file for myimage.cpp and background.cpp

#ifndef MYIMAGE_H_
#define MYIMAGE_H_

class MyImage {
public:
	int width, height;
	unsigned char *data;
	~MyImage(); 
	MyImage(const char *fname);
};
#endif
