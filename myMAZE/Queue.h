#pragma once
#include "public.h"

typedef struct {
	point *base;
	int front;
	int rear;
}squeue;

void initqueue(squeue &Q)
{
	Q.base = (point*)malloc(MAXQSIZE * sizeof(point));
	if (!Q.base)
		return;
	Q.front = Q.rear = 0;
}

void qqush(squeue &Q, point e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}
point qfront(squeue Q){
    return Q.base[Q.rear-1];
}
void qpop(squeue &Q)
{
	Q.rear--;
}
int isfull(squeue Q){
    return Q.rear>=MAXQSIZE ;
}
int isempty(squeue Q){
	return Q.front == Q.rear ;
}