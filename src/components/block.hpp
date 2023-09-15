#pragma once
#include <vector>
#include <map>

#include "position.hpp"
#include "colors.hpp"

class Block{
public:
    int id;
    std::map<int, std::vector<Position>> cells;

    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();

private:
    int cellSize;
    int rotationState;

    int rowOffset;
    int columnOffset;

    std::vector<Color> colors;
};
