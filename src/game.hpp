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

    Grid* grid;
    BaseLevel* level;
    InputTerminal* inputTerminal;

    Game(Grid* grid, BaseLevel* level, InputTerminal* inputTerminal, int saveFlags);
    ~Game();
    void Draw();
    void HandleInput(int keyPressed);
    void MoveBlockDown();
    void UpdateScore(int linesCleared, int moveDownPoints);
    void Save();

private:
    int saveFlags;

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
};