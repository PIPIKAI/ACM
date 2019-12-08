#pragma once
#include "Queue.h"
void qqush(squeue &Q, point e);
void initqueue(squeue &Q);
point qfront(squeue Q);
void qpop(squeue &Q);
void showBlock();
#define hight 20
#define wight 20
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define WALL 4
#define ROAD 5
#define WORKED 6
