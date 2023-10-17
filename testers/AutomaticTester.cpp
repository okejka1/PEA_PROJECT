
#include <random>
#include <iostream>
#include <fstream>
#include "AutomaticTester.h"
#include "../utils/Timer.h"
#include "../utils/FileRandomizer.h"
#include "../structures/Graph.h"
#include "../algorithm/BruteForce.h"

void AutomaticTester::testBruteForce() {

    std::ofstream file(R"(C:\Users\antek\Desktop\studia\5.sem\PEA_PROJECT\input\results.csv)");
    if(!file.is_open()){
        std::cout << "Couldn't open the file, ending test" << std::endl;
        return;
    }

    long long result = 0;
    Timer timer;

    for(int j = 3; j < 11; j++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, j - 1);
        for (int i = 0; i < 100; i++) {
            cout << "Test " << j - 2 << "." << i << " rozpoczety" << endl;
            Graph graph(j);
            FileRandomizer::randomize(j);
            int start = dist(gen), min_cost;
            graph.readGraphDirected("random.atsp");
            BruteForce solver(graph);

            timer.start();
            min_cost = solver.ATSPBruteForce(graph, start);
            timer.stop();

            result += timer.micro();
            cout << "Test " << j - 2 << "." << i << " wykonany" << endl;
            file << "rozmiar" << ";" << j << ";" << "koszt" << ";" << min_cost << ";" "czas wykonania" << ";" << timer.micro() << endl;
        }

        file << "rozmiar" << ";" << j << ";" << "sredni czas wykonania" << ";" << result / 100 << endl;
        result = 0;
    }
}
