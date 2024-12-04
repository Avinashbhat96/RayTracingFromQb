#include <CApp.hpp>

int main(int argc, char* argv[]){
    CAPP theApp;

    // Register the signal handler
    std::signal(SIGINT, CAPP::signalHandler);

    return theApp.OnExecute();
}