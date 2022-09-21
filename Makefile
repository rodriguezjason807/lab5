all: background

background: background.cpp myimage.h myimage.cpp
	g++ background.cpp myimage.cpp myimage.h -Wall -lX11 -lGL -lGLU -lm -obackground
clean:
	rm -f background


