#pragma once

#include "./components/grid.hpp"
#include "./components/blocks.cpp"
#include "./levels/baselevel.hpp"
#include "./inputterminal.hpp"

class Game{
public:
    int score;
    bool gameOver;
    bool isPaused;
    BaseLevel* level;
    InputTerminal* inputTerminal;

    Game(BaseLevel* level, InputTerminal* inputTerminal);
    ~Game();
    void Draw();
    void HandleInput(int keyPressed);
    void MoveBlockDown();

private:
    double lastUpdateTime;

    Grid grid;
    std::vector<Block> blocks;
    Block nextBlock;
    Block currentBlock;
    Sound rotateSound;
    Sound clearSound;

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    void RotateBlock();
    bool IsBlockOutside();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void DrawBlockShadow(Block block);
    void UpdateScore(int linesCleared, int moveDownPoints);
};