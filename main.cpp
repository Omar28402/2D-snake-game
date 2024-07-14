#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define LEFT -2
#define RIGHT 2
#define MINSNAKE 5
#define MAXSNAKE 60
void initGrid(int,int);
void drawGrid();
void drawSnake();
void drawFood();
void drawdamage();

void random(int &,int &);
void randomdamage(int &,int &);

#endif // GAME_H_INCLUDED
