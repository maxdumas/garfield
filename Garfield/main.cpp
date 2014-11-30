#include <SDL2/SDL.h>
#include "FlurryApplication.h"
#include "RunnerApplication.h"

int main(int argc, char* argv[])
{
    RunnerApplication app;
	return app.run(640, 640, "Garfield Tests");
}