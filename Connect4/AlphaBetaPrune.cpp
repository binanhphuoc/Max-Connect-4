//
//  AlphaBetaPrune.cpp
//  Connect4
//
//  Created by Phuoc Do on 3/2/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#include "AlphaBetaPrune.hpp"
#include "State.hpp"

namespace AI
{
    int AlphaBetaPrune::maxPlayer;
    
    AlphaBetaPrune::optionValue AlphaBetaPrune::maxValue(State& s, double a, double b, int depth, int depthLimit)
    {
        optionValue ov;
        if (s.isTerminal() || depth == depthLimit)
        {
            ov.option = 0;
            ov.value = evaluate(s);
            return ov;
        }
        
        ov.value = -1000;
        //vector<State> states = successors(s);
        for (int i = 0; i< 7; i++)
        {
            State state = s;
            if (state.chipAt(i+1) == 1)
                continue;
            double val = minValue(state, a, b, depth+1, depthLimit).value;
            if (ov.value < val)
            {
                ov.value = val;
                ov.option = i+1;
            }
            if (ov.value >= b)
            {
                return ov;
            }
            a = max(a, ov.value);
        }
        return ov;
    }
    
    AlphaBetaPrune::optionValue AlphaBetaPrune::minValue(State& s, double a, double b, int depth, int depthLimit)
    {
        optionValue ov;
        if (s.isTerminal() || depth == depthLimit)
        {
            ov.option = 0;
            ov.value = evaluate(s);
            return ov;
        }
        
        ov.value = 1000;
        //vector<State> states = successors(s);
        for (int i = 0; i< 7; i++)
        {
            State state = s;
            if (state.chipAt(i+1) == 1)
                continue;
            double val = maxValue(state, a, b, depth+1, depthLimit).value;
            if (ov.value > val)
            {
                ov.value = val;
                ov.option = i+1;
            }
            if (ov.value <= a)
            {
                return ov;
            }
            b = min(b, ov.value);
        }
        return ov;
    }
    
    vector<State> AlphaBetaPrune::successors(State& state)
    {
        vector<State> states;
        State s;
        states.assign(7, s);
        for (int i = 1; i <= 7; i++)
        {
            s = state;
            if (s.chipAt(i) == 1)
                continue;
            states.at(i-1) = s;
        }
        return states;
    }
    
    double AlphaBetaPrune::evaluate(State& s)
    {
        vector<int> connectMax = s.count(maxPlayer);
        vector<int> connectMin = s.count((maxPlayer==1)?2:1);
        if (s.isTerminal())
        {
            if (connectMax.at(3) > connectMin.at(3))
                return 20;
            if (connectMax.at(3) == connectMin.at(3))
                return 0;
            if (connectMax.at(3) < connectMin.at(3))
                return -20;
        }
        
        return
        0.7*(connectMax.at(3)-connectMin.at(3)) +
        0.5*(connectMax.at(2)-connectMin.at(2)) +
        0.3*(connectMax.at(1)-connectMin.at(1))+
        0.1*(connectMax.at(0)-connectMin.at(0));
    }
    
    int AlphaBetaPrune::abd(State s, int depth)
    {
        maxPlayer = s.nextPlayer();
        return maxValue(s, -1000, 1000, 0, depth).option;
    }
}
