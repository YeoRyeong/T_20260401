#include<iostream>
#include<SDL.h>

using namespace std;

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int argc, char* argv[])
{
	int X = 100;
	int Y = 100;


	bool bIsRunning = true;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* MyWindow = SDL_CreateWindow("NEMO",100, 100, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	while (bIsRunning)
	{
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent);
		
		SDL_Rect MyRect = { X, Y, 100, 100 };
		SDL_Keycode KeyCode = MyEvent.key.keysym.sym;

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}

		SDL_SetRenderDrawColor(MyRender, 0, 0, 0, 255);
		SDL_RenderClear(MyRender);



		SDL_SetRenderDrawColor(MyRender, 255, 0, 0, 255);
		SDL_RenderDrawRect(MyRender, &MyRect);

		if(MyEvent.type == SDL_KEYDOWN)
		{
			if (KeyCode == SDLK_w) 
			{
				Y--;
			}
		
			if (KeyCode == SDLK_s)
			{
				Y++;
			}
		
			if (KeyCode == SDLK_a)
			{
				X--;
			}
		
			if (KeyCode == SDLK_d)
			{
				X++;
			}

			if (KeyCode == SDLK_ESCAPE)
			{
				bIsRunning = false;
			}
		}
		SDL_RenderPresent(MyRender);
	}

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
	
	return 0;
}