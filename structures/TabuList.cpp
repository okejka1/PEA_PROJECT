//
// Created by User on 10.12.2023.
//

#include <iostream>
#include "TabuList.h"
using namespace std;
TabuList::TabuList(int size) {
    maxSize = size;

}

TabuList::~TabuList() {
    while(!moves.empty()) {
        delete moves.front();
        moves.pop_front();
    }


}
void TabuList::push(int city1, int city2) {
    if(moves.size() == maxSize) {
        delete moves.back();
        moves.pop_back();
    }
    moves.push_front(new Move(city1,city2));
}
void TabuList::printMoves() {
    std::cout << "Currently restricted steps: ";
    for(const auto& move: moves){
        std::cout << "(" << move->firstCity << " <-> " << move->secondCity << ") ";
    }
    std::cout << std::endl;
}
void TabuList::clear() {
    while (!moves.empty()) {
        delete moves.front();
        moves.pop_front();
    }
}
bool TabuList::findMove(int c1, int c2) {
    for(const auto& move:moves) {
        if((move->firstCity == c1 && move->secondCity == c2) || (move->firstCity == c2 && move->secondCity == c1))
            return true;
    }
    return false;
}







