//Author: Jason Rodriguez
//Date:   Sep 21 2022
//Source file for myimage.h class definition

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include "myimage.h"

extern class MyImage myimage;

MyImage::~MyImage() { delete [] data; }

MyImage::MyImage(const char *fname) {
//		if (fname[0] == '\0')
		if (fname[0] == 0)
			return;
		char name[40];
//		char name[FILENAME_MAX];
		strcpy(name, fname);
		int slen = strlen(name);
		name[slen-4] = '\0';
		char ppmname[80];
		sprintf(ppmname,"%s.ppm", name);
		char ts[100];
		sprintf(ts, "convert %s %s", fname, ppmname);
		system(ts);
		FILE *fpi = fopen(ppmname, "r");
		if (fpi) {
			char line[200];
			fgets(line, 200, fpi);
			fgets(line, 200, fpi);
			//skip comments and blank lines
			while (line[0] == '#' || strlen(line) < 2)
				fgets(line, 200, fpi);
			sscanf(line, "%i %i", &width, &height);
			fgets(line, 200, fpi);
			//get pixel data
			int n = width * height * 3;			
			data = new unsigned char[n];			
			for (int i=0; i<n; i++)
				data[i] = fgetc(fpi);
			fclose(fpi);
		} else {
			printf("ERROR opening image: %s\n", ppmname);
			exit(0);
		}
		unlink(ppmname);
	}

