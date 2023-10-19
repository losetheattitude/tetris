#include <random>

#include "game.hpp"

Game::Game(Grid* grid, Level* level, int saveFlags)
{
    this->saveFlags = saveFlags;

    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();

    score = 0;

    this->state = makeStateSingleton(GameState::PLAY);

    this->grid = grid;
    //Strategy pattern
    this->level = level;
    this->level->Configure();
    this->level->SetScore(&this->score);

    InitAudioDevice();
    rotateSound = LoadSound("/home/bat/Proyectos/tetris-c++/sounds/rotate.mp3");
    clearSound = LoadSound("/home/bat/Proyectos/tetris-c++/sounds/clear.mp3");
}

Game::~Game()
{
    CloseAudioDevice();
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    delete this->level;
    delete this->grid;
    delete this->state;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};    
}

void Game::Draw()
{
    grid->Draw();
    currentBlock.Draw(11, 11);
    this->DrawBlockShadow(currentBlock);

    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255, 283);
            break;
        case 4:
            nextBlock.Draw(255, 269);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }
}

void Game::ProcessCommand(Command* command)
{
    this->state->ProcessCommand(*this, command);
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.UndoRotation();
    }
    else
    {
        PlaySound(rotateSound);
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        if(grid->IsCellOutsize(item.row, item.column)){
            return true;
        }
    }

    return false;
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        grid->grid[item.row][item.column] = currentBlock.id;
    }

    currentBlock = nextBlock;
    if(BlockFits() == false)
    {
        this->state = makeStateSingleton(GameState::OVER);
        return;
    }

    nextBlock = GetRandomBlock();
    int rowsCleared = grid->ClearFullRows();
    if(rowsCleared > 0){
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid->IsCellEmpty(item.row, item.column) == false){
            return false;
        }
    }

    return true;
}

void Game::Reset()
{
    grid->Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    level->Configure();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{   
    score += this->level->GetLineScore(linesCleared) + moveDownPoints;
}

int Game::ClosestDistance(Block& block)
{
    int distance = 20;
    for(Position cellPosition : block.GetCellPositions()){
        int temp = 0;
        while(!this->grid->IsCellOutsize(cellPosition.row + temp + 1, cellPosition.column) && 
               this->grid->IsCellEmpty(cellPosition.row + temp + 1, cellPosition.column))
        {
            temp++;
        }

        if(temp < distance){
            distance = temp;
        }
    }

    return distance;
}

void Game::DrawBlockShadow(Block& block)
{   
    int distance = this->ClosestDistance(block);
    block.DrawShadow(distance);
}

void Game::Save()
{
    // ExchangerBuilder builder = ExchangerBuilder();
    // Exchanger* b = builder.Build(123);

    // b->ExchangeToStorage(this);
    // delete b;
}