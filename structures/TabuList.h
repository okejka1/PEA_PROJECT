#ifndef P1_TABULIST_H
#define P1_TABULIST_H

#include "Move.h"
#include <deque>


class TabuList {
private:
    std::deque<Move*> moves;
    int maxSize;

public:
    explicit TabuList(int size);

    ~TabuList();

    void push(int city1, int city2);

    void printMoves();

    void clear();

    bool findMove(int c1, int c2);
};

#endif //P1_TABULIST_H
