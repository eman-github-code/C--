#include <iostream>
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h> // for Sleep()

using namespace std;

const int width = 20;
const int height = 10;

char map[height][width + 1] = {
    "###################",
    "#........#........#",
    "#.####.#.#.####.#.#",
    "#.................#",
    "#.####.#.#.####.#.#",
    "#.#....#.#....#.#.#",
    "#.#.####.####.#.#.#",
    "#..................",
    "#.###############.#",
    "###################"
};

int pacmanX = 1, pacmanY = 1;

void drawMap() {
    system("cls"); // clear screen
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == pacmanX && y == pacmanY)
                cout << "P";
            else
                cout << map[y][x];
        }
        cout << endl;
    }
}

void move(char dir) {
    int newX = pacmanX;
    int newY = pacmanY;

    if (dir == 'w') newY--;
    else if (dir == 's') newY++;
    else if (dir == 'a') newX--;
    else if (dir == 'd') newX++;

    if (map[newY][newX] != '#') {
        pacmanX = newX;
        pacmanY = newY;
    }
}

int main() {
    while (true) {
        drawMap();

        if (_kbhit()) {
            char ch = _getch();
            move(tolower(ch));
        }

        Sleep(100); // delay for smoother display
    }

    return 0;
}

