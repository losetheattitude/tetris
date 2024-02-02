#include <raylib.h>
#include <vector>
#include <iostream>

#include "./gamescene.hpp"
#include "../core/game.hpp"
#include "../components/colors.hpp"
#include "../core/terminal/terminal.hpp"
#include "../state/pausestate.hpp"
#include "../state/overstate.hpp"

GameScene::GameScene(Game* game, JoyStick* joystick)
{
    this->game = game;
    this->joystick = joystick;

    font = LoadFontEx("/home/bat/Proyectos/tetris-c++/font/Paul-le1V.ttf", 64, 0, 0);
}

GameScene::~GameScene()
{
    delete this->game;
    delete this->joystick;
}

void GameScene::DrawLevelComponent(){
    sprintf(this->levelText, "%d", game->level->GetLevel());
    Vector2 levelTextSize = MeasureTextEx(font, this->levelText, 38, 2);

    DrawRectangleRounded({320, 480, 170, 130}, 0.3, 6, lightBlue);
    DrawTextEx(font, this->levelText, {320 + (170 - levelTextSize.x) / 2, 525}, 38, 2, WHITE);
    DrawTextEx(font, "Level", {360, 440}, 35, 2, WHITE);

    const char* levelId = this->game->level->GetLevelText().c_str();
    Vector2 levelIdSize = MeasureTextEx(font, levelId, 15, 2);
    DrawTextEx(font, levelId, {480 - levelIdSize.x, 605 - levelIdSize.y}, 15, 2, WHITE);
}

void GameScene::DrawNextBlockComponent(){
    DrawTextEx(font, "Next", {365, 170}, 38, 2, WHITE);             
    DrawRectangleRounded({320, 210, 170, 180}, 0.3, 6, lightBlue);
}

void GameScene::DrawScoreComponent(){
    DrawTextEx(font, "Score", {353, 15}, 38, 2, WHITE);
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
    sprintf(this->scoreText, "%d", game->score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
}    

void GameScene::DrawPause()
{
    DrawRectangleRounded({47, 275, 230, 95}, 0.3, 6, lightBlue);
    DrawTextEx(font, "PAUSED", {90, 297}, 50, 2, WHITE);
}

void GameScene::DrawGameOver()
{
    DrawRectangleRounded({20, 290, 280, 110}, 0.3, 6, lightBlue);
    DrawTextEx(font, "GAME OVER", {61, 305}, 45, 2, WHITE);
    DrawTextEx(font, "PRESS R", {110, 355}, 30, 2, WHITE);
}

void GameScene::Draw()
{
    ClearBackground(darkBlue);
    this->DrawScoreComponent();
    this->DrawNextBlockComponent();
    this->DrawLevelComponent();
    game->Draw();

    if(game->isOverState()){
        this->DrawGameOver();
    }

    if(game->isPauseState()){
        this->DrawPause();
    }
}

void GameScene::Play()
{   
    game->ProcessCommand(this->joystick->ProduceCommand());
}