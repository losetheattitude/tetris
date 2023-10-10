#pragma once

class State;
class Command;

#include "../commands/command.hpp"
#include "../state/state.hpp"
#include "../state/factory.hpp"
#include "../components/grid.hpp"
#include "../components/blocks.cpp"
#include "../levels/level.hpp"
#include "../exchanger/builder/exchangerbuilder.hpp"


class Game{
public:
    int score;

    Grid* grid;
    Level* level;
    State* state;

    Game(Grid* grid, Level* level, int saveFlags);
    ~Game();
    void Draw();
    void ProcessCommand(Command* command);
    void Save();

friend class PlayState;
friend class OverState;
friend class Command;

private:
    int saveFlags;

    std::vector<Block> blocks;
    Block nextBlock;
    Block currentBlock;
    Sound rotateSound;
    Sound clearSound;

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void UpdateScore(int linesCleared, int moveDownPoints);
    void MoveBlockDown();
    void MoveBlockLeft();
    void MoveBlockRight();
    void RotateBlock();
    bool IsBlockOutside();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void DrawBlockShadow(Block& block);
    int ClosestDistance(Block& block);
};