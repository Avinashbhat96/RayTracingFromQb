#include "CApp.hpp"

CAPP::CAPP(){
    isRunning = true;
    pWindow = nullptr;
    pRenderer = nullptr;
}

bool CAPP::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    pWindow = SDL_CreateWindow("Ray tracer - Dont forget to subscribe!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, SDL_WINDOW_SHOWN);
    if (pWindow != nullptr){
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

        m_image.Initialize(1200,720, pRenderer);

        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderClear(pRenderer);

        m_scene.Render(m_image);

        m_image.Display();

        SDL_RenderPresent(pRenderer);

    }
    else{
        return false;
    }
    return true;
}

int CAPP::OnExecute(){
    SDL_Event event;
    if(OnInit() == false){
        return -1;
    }
    while (isRunning){
        if(stopFlag)
            return -1;
        while(SDL_PollEvent(&event) != 0)
        {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
    return -1;
}

void CAPP::OnEvent(SDL_Event *event){
    if(event->type == SDL_QUIT){
        isRunning = false;
    }
}

void CAPP::OnLoop(){

}

void CAPP::OnRender(){
    // SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    // SDL_RenderClear(pRenderer);

    // m_scene.Render(m_image);

    // m_image.Display();

    // SDL_RenderPresent(pRenderer);
}

void CAPP::OnExit(){
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = nullptr;
    SDL_Quit();
}