all:
	cc -o main -L/usr/local/lib -I/usr/local/include -lGL -lGLU -lglut -lm *.c
