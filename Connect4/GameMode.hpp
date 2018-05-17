//
//  GameMode.hpp
//  Connect4
//
//  Created by Phuoc Do on 3/3/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#ifndef GameMode_hpp
#define GameMode_hpp

#include <stdio.h>
#include <string>
#include "AlphaBetaPrune.hpp"
#include "State.hpp"

namespace AI
{
    class GameMode{
        State s;
    public:
        void play(string arg1, string arg2, string arg3, string arg4);
        void reset() {s.reset();}
        void interactive(int maxPlayer, int depth);
        void oneMove(string inputFile, int depth, string outputFile);
        void printScore(State& s);
    };
}

#endif /* GameMode_hpp */
