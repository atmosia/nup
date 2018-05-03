#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int init();
int load_media();
void free_sdl();

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

int
init()
{
        int success = 1;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                success = 0;
        } else {
                gWindow = SDL_CreateWindow("SDL Tutorial",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
                if (gWindow == NULL) {
                        printf("Window could not be created! SDL_Error: %s\n",
                                        SDL_GetError());
                        success = 0;
                } else {
                        gScreenSurface = SDL_GetWindowSurface(gWindow);
                }
        }

        return success;
}

int
load_media()
{
        int success = 1;
        const char *path = "hello_world.bmp";
        gHelloWorld = SDL_LoadBMP(path);
        if (gHelloWorld == NULL) {
                printf("Unable to load image %s! SDL Error: %s\n",
                                path,
                                SDL_GetError());
                success = 0;
        }

        return success;
}

void
free_sdl()
{
        SDL_FreeSurface(gHelloWorld);
        gHelloWorld = NULL;
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;
	SDL_DestroyWindow(gWindow);
        gWindow = NULL;
        SDL_Quit();
}

int
main(int argc, char *argv[])
{
        if (!init()) {
                printf("Failed to initialize!\n");
        } else {
                if (!load_media()) {
                        printf("Failed to load media\n");
                } else {
                        SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface,
                                        NULL);
                        SDL_UpdateWindowSurface(gWindow);
                        SDL_Delay(2000);
                }
        }
        free_sdl();

        return 0;
}
