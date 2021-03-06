#include "../Logic/Game.h"

void Infobar::drawInfo() {
    int x = game->font->getSize() / 2;
    int y = game->font->getSize() / 2;

    SDL_Rect rect = { 0, 0, game->getWindowWidth(),
                     int(game->font->getSize() * 1.8) };
    Box(rect, BLACK).render(game->renderer);

    string aux;
    aux.append(to_string(game->time_), 0, 5);
    string s1 = "Pos: " + to_string(int(game->car->getX())) + " "
        + to_string(int(game->car->getY())) + "  " +
        "Distance: " + to_string(game->distance_) + "  " +
        "Speed: " + to_string((int)game->car->getVel()) + "  " +
        "Power: " + to_string(game->car->getPower()) + "  " +
        "Coins: " + to_string(game->car->getCoinsNumber()) + " " +
        "Time: " + aux + "  " +
        "Objs: " + " [" + to_string(GoodObject::instances) + ", " + to_string(BadObject::instances) + "]";
    string s2 = "State: Playing"; // esto deberia pillar el nombre de la variable directamente?

    game->renderText(s1, x, y);
    game->renderText(s2, x, game->height - game->font->getSize());

    if (game->debug_) {
        SDL_SetRenderDrawColor(game->renderer, 255, 255, 0, 255);
        SDL_RenderDrawLine(game->renderer, game->width / 2, 0, game->width / 2, game->height);
        SDL_RenderDrawLine(game->renderer, 0, game->height / 2, game->width, game->height / 2);
        SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    }
}

void Infobar::drawHelp() {
    if (game->currentState_ == MENU) {
        if (game->help_) {
            string s1 = "[SPACE] to start";
            string s2 = "[h] for help";

            int yh = game->font->getSize();

            game->renderText(s1, yh / 2, yh * 2);
            game->renderText(s2, yh / 2, yh * 3);
        }

    }
    else if (game->currentState_ == RUNNING) {
        if (game->help_) {
            int yh = game->font->getSize();
            int i = 0;
            for (auto s : game->help) {
                game->renderText(s, yh / 2, yh * (2 + i));
                i++;
            }
        }
    }
   
}

void Infobar::drawState() {
    if (game->currentState_ == MENU) {
        string s1 = "Welcome to Super Cars";
        string s2 = "Level: " + to_string(game->level_);
        string s3 = "Press space to start";
        string s4 = "Press [h] for help";

        string s5 = "State: Menu";

        int x = game->width / 2 - (s1.length() / 2) * game->font->getSize();
        int y = game->height / 2 - game->font->getSize() * 2;

        game->renderText(s1, x, y);
        game->renderText(s2, x, y + game->font->getSize());
        game->renderText(s3, x, y + game->font->getSize() * 2);
        game->renderText(s4, x, y + game->font->getSize() * 3);

        game->renderText(s5, game->font->getSize() / 2, game->height - game->font->getSize());
    }
    else if (game->currentState_ == GAMEOVER) {
        if (game->record_ == 0 && game->victory_ == true)game->record_ = game->time_;
        else if (game->time_ < game->record_&& game->victory_ == true)game->record_ = game->time_;

        string s1 = " ";
        string s2 = " ";
        string s3 = " ";

        if (!game->victory_) {
            s1 = "Game Over!";
        }
        else {
            string timeToPrint;
            timeToPrint.append(to_string(game->time_), 0, 5);
            string recordToPrint;
            recordToPrint.append(to_string(game->record_), 0, 5);
            s1 = "Congratulations!";
            s2 = "User wins";
            s3 = "Time: " + timeToPrint + " Record: " + recordToPrint;
        }

        string s5 = "State: GameOver";

        int x = game->width / 2 - (s1.length() / 2) * game->font->getSize();
        int y = game->height / 2 - game->font->getSize() * 2;

        game->renderText(s1, x, y);
        game->renderText(s2, x, y + game->font->getSize());
        game->renderText(s3, x, y + game->font->getSize() * 2);

        game->renderText(s5, game->font->getSize() / 2, game->height - game->font->getSize());
    }
}