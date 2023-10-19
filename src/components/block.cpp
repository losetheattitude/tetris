#include <random>
#include <iostream>

#include "colors.hpp"
#include "block.hpp"

Block::Block()
{
    cellSize = Block::GetCellSize();
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;

    colors = GetCellColors();
    shadowColors = GetShadowColors();
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position item: tiles){
        movedTiles.emplace_back(
            item.row + rowOffset, 
            item.column +columnOffset
        );   
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState ++;
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
}

void Block::DrawShadow(int rowDrop)
{
    for(Position cellPosition : this->GetCellPositions()){
        DrawRectangle(
            (cellPosition.column * cellSize) + 11, 
            (cellPosition.row * cellSize) + (rowDrop * cellSize) + 11, 
            cellSize - 1, 
            cellSize - 1, 
            shadowColors[id]
        );
    }
}

int Block::GetCellSize()
{
    return 30;
}