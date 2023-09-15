#include <raylib.h>
#include <vector>
#include <iostream>

#include "gamescene.hpp"
#include "../game.hpp"
#include "../components/colors.hpp"
#include "../inputterminal.hpp"

GameScene::GameScene(Game* game)
{
    this->game = game;

    font = LoadFontEx("/home/bat/Proyectos/tetris-c++/font/Paul-le1V.ttf", 64, 0, 0);
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
    DrawTextEx(font, "PAUSED", {85, 300}, 50, 2, WHITE);
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

    if(game->gameOver){
        this->DrawGameOver();
    }

    if(game->isPaused && !game->gameOver){
        this->DrawPause();
    }
}

void GameScene::Play()
{      
    int keyPressed = this->game->inputTerminal->GetActiveKey();
    if(keyPressed == KEY_SPACE && !game->gameOver){
        game->isPaused = !game->isPaused;
    }

    if(game->isPaused) return;

    game->HandleInput(keyPressed);
    if(game->level->ShouldLevelUp()){
        game->level->AdjustLevel();
    }

    if(game->level->ShouldTick()){
        game->MoveBlockDown();
    }
}