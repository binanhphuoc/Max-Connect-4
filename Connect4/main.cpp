//
//  main.cpp
//  Connect4
//
//  Created by Phuoc Do on 2/28/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#include <iostream>
#include "State.hpp"
#include "AlphaBetaPrune.hpp"
#include "GameMode.hpp"

using namespace std;
using namespace AI;

int main(int argc, const char * argv[]) {
    if (argc != 5)
    {
        cout << "Error: Too few arguments." << endl;
        return 0;
    }
    GameMode game;
    game.play(argv[1], argv[2], argv[3], argv[4]);
    return 0;
}
