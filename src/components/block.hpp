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
    void DrawShadow(int rowDrop);

    static int GetCellSize();

    // Block(const Block& block);
    // Block(Block&& block);

    // Block& operator=(const Block&);

private:
    int cellSize;
    int rotationState;

    int rowOffset;
    int columnOffset;

    std::vector<Color> colors;
    std::vector<Color> shadowColors;
};
