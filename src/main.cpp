#include <iostream>
#include <cstdlib>
#include "main.h"


int main() {
    srand(time(NULL));
    Maze m{150, (1.0/101), "erdos", 200, 10};
    //m.printGraph();
    m.getMaxConnectedComponentSize();
    return 0;
}
