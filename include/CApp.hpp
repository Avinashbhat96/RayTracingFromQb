#ifndef CAPP_HPP
#define CAPP_HPP

#include <SDL2/SDL.h>
#include <csignal>
#include <iostream>
#include "Image.hpp"
#include "Scene.hpp"

class CAPP
{
    public:
    CAPP();

    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender();
    void OnExit();
    inline static void signalHandler(int signal) {
        if (signal == SIGINT) {
            std::cout << "\nCtrl+C detected!\n";
            stopFlag = true;
        }
    }

    private:
    Image m_image;
    RT::Scene m_scene;
    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    static inline bool stopFlag = false;
};

#endif // CAPP_HPP