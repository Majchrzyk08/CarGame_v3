//
// Created by eys on 20/8/21.
//

#include "ViewController.h"

ViewController::ViewController(Game *_game) {
    game = _game;
    cout << "[DEBUG] frame duration: " << frameDuration() << " ms" << endl;
    initSDL();

    commandFactory = new CommandFactory(game);
    commandFactory->add(new MoveCommand());
    commandFactory->add(new ShootCommand());
    commandFactory->add(new AccCommand());
    commandFactory->add(new DebugCommand());
    commandFactory->add(new HelpCommand());
    commandFactory->add(new StartCommand());
    commandFactory->add(new QuitCommand());
    commandFactory->add(new WaveCommand());
    commandFactory->add(new ClearCommand());
    commandFactory->add(new CheatCommand());
    commandFactory->add(new BlastCommand());

    game->setRenderer(renderer);
    game->loadTextures();

}

void ViewController::run() {
    uint32_t startTime = 0;
    uint32_t frameTime;

    while(!game->doQuit()){
        frameTime = SDL_GetTicks() - startTime;
        handleEvents();
        if (frameTime >= frameDuration()) {
            clearBackground();
            game->update();
            game->draw();
            SDL_RenderPresent(renderer);
            startTime = SDL_GetTicks();
        }
        else{
            SDL_Delay(frameDuration() - frameTime);
        }
    }
}

void ViewController::clearBackground() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ViewController::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) ){
        Command* command = commandFactory->getCommand(event);
        if (command != nullptr)command->execute();
    }
}

uint32_t ViewController::frameDuration() {
    return 1000 / FRAME_RATE;
}

void ViewController::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(game->getGameName().c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              game->getWindowWidth(),
                              game->getWindowHeight(),
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (window == nullptr || renderer == nullptr)
        throw string("Error creating SDL window or renderer");

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, &screenSurface->clip_rect, 0xFF);
    SDL_UpdateWindowSurface(window);
}

ViewController::~ViewController() {
    delete commandFactory;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
