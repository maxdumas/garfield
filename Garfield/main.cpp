#include <SDL2/SDL.h>
#include "FlurryApplication.h"

int main(int argc, char* argv[])
{
    FlurryApplication app;
	return app.run(640, 480, "Garfield Tests");
}