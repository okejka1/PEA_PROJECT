#include <iostream>
#include "Menu.h"
#include "structures/Graph.h"

using namespace std;

int main() {
    cout << "Hello, Klapson!" << endl;
    Graph siema(403);
    siema.readGraphDirected("rbg403.atsp", 403);
    siema.display();
//    Menu::show();
    return 0;
}
