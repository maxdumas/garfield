#include <SDL2/SDL.h>
#include "MyApplication.h"

int main(int argc, char* argv[])
{
    MyApplication app;
	return app.run(640, 480, "Garfield Tests");
}