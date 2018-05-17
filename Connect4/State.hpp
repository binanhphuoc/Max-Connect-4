//
//  State.hpp
//  Connect4
//
//  Created by Phuoc Do on 3/1/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

namespace AI {
    
class State{
private:
    string state;
    int player;
    vector<int> player1;
    vector<int> player2;
    
    void countAfterMove(int player, int row, int col);
public:
    State() {state = ""; player = 0;player1.clear(); player2.clear();}
    State(string fileName);
    void getState(string fileName);
    void print();
    void write(string fileName);
    void reset() {State();}
    char& at(int row, int column);
    int chipAt(int column); // return 0 if successful, else return false
    bool isTerminal();
    vector<int> count(int player);
    bool isNull() const {if (player == 0) return true; return false;}
    int nextPlayer() {return player;}
    
};
}
#endif /* State_hpp */
