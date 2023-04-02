#define SC_W 500
#define SC_H 500

#define FPS 24

#define PI 3.14

//---App logic
void start(int argc, char **const argv);
void render(void);

//---Userspace 
//Draw functions
void drawRectangle(
	unsigned short x1,
	unsigned short y1,
	unsigned short x2,
	unsigned short y2
);

//Events
void eventInit(void);
void eventLoop(void);
