all: background

background: background.cpp myimage.h 
	g++ background.cpp -Wall -lX11 -lGL -lGLU -lm

clean:
	rm -f background a.out


