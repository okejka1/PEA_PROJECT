//
// Created by antek on 17.10.2023.
//

#include <fstream>
#include <iostream>
#include <random>
#include "FileRandomizer.h"

void FileRandomizer::randomize(int size) {
    std::ofstream file(R"(..\input\random.atsp)");

    if (!file.is_open()) {
        std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDist(1, 999);

    file << size << std::endl;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            if(i == j)
                file << "  " << 0;
            else
                file << "  " << weightDist(gen);
        }
        file << std::endl;
    }

    file.close();
}