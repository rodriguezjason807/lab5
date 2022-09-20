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
