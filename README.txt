This project is supposet to work like a tkinter like C library. 

The "user space" is in event.c where events like inputs, init are located.
You call draw functions here to draw what you want.

The render.c contains the draw functions and the display function.

The init.c contains the timer which rerenders every 1s/FPS seconds.
