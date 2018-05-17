//
//  AlphaBetaPrune.hpp
//  Connect4
//
//  Created by Phuoc Do on 3/2/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#ifndef AlphaBetaPrune_hpp
#define AlphaBetaPrune_hpp

#include <stdio.h>
#include "State.hpp"
#include <vector>

using namespace std;

namespace AI
{
class AlphaBetaPrune
{
    struct optionValue
    {
        int option; //0 mean
        double value;
    };

    static int maxPlayer;
    
    static optionValue maxValue(State& s, double a, double b, int depth, int depthLimit);
    static optionValue minValue(State& s, double a, double b, int depth, int depthLimit);
    static vector<State> successors(State& s);
    static double evaluate(State& s);
    static double max(double a, double b) {return (a>b)?a:b;}
    static double min(double a, double b) {return (a<b)?a:b;}
public:
    // alpha beta decision
    static int abd(State s, int depth = 7);
    
};
}

#endif /* Prune_hpp */
