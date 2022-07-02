#pragma once



constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char SCREEN_RESIZE = 2;

constexpr unsigned short SCREEN_HEIGHT = 240;
constexpr unsigned short SCREEN_WIDTH = 320;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

enum Cell
{
	Empty,
	Wall
};

typedef std::vector<std::array<Cell, SCREEN_HEIGHT / CELL_SIZE>> Map;
