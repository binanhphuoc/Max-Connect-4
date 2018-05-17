//
//  GameMode.cpp
//  Connect4
//
//  Created by Phuoc Do on 3/3/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#include "GameMode.hpp"
#include "State.hpp"
#include "AlphaBetaPrune.hpp"
#include <iostream>

using namespace std;

namespace AI
{
    void GameMode::play(string arg1, string arg2, string arg3, string arg4)
    {
        if (arg1 == "interactive")
        {
            s.getState(arg2);
            int com = (arg3 == "computer-next")?s.nextPlayer():(3-s.nextPlayer());
            int depth = atoi(arg4.c_str());
            interactive(com, depth);
        }
        
        else
        {
            oneMove(arg2, atoi(arg4.c_str()), arg3);
        }
    }
    
    void GameMode::interactive(int maxPlayer, int depth)
    {
        if (maxPlayer != s.nextPlayer())
        {
            cout << string( 100, '\n' );
            s.print();
            vector<int> p1 = s.count(1);
            vector<int> p2 = s.count(2);
            cout << "(Player1) " << p1.at(3) << "-" << p2.at(3) << " (Player2)" << endl;
            if (s.isTerminal())
                return;
            while(true)
            {
                cout << "Please make a move: ";
                int choice;
                cin >> choice;
                if (s.chipAt(choice) == 0)
                    break;
                cout << "Invalid move. ";
            }
            s.write("human.txt");
        }
            
        while (true)
        {
            cout << string( 100, '\n' );
            s.print();
            vector<int> p1 = s.count(1);
            vector<int> p2 = s.count(2);
            cout << "(Player1) " << p1.at(3) << "-" << p2.at(3) << " (Player2)" << endl;
            if (s.isTerminal())
                return;
            cout << "Computer is making a choice. Please wait..." << endl;
            int choice = AlphaBetaPrune::abd(s, depth);
            
            s.chipAt(choice);
            s.write("computer.txt");
        
            cout << string( 100, '\n' );
            cout << "COM CHOICE: " << choice << endl;
            s.print();
            p1 = s.count(1);
            p2 = s.count(2);
            cout << "(Player1) " << p1.at(3) << "-" << p2.at(3) << " (Player2)" << endl;
            if (s.isTerminal())
                return;
            while(true)
            {
                cout << "Please make a move: ";
                int choice;
                cin >> choice;
                if (s.chipAt(choice) == 0)
                    break;
                cout << "Invalid move. ";
            }
            s.write("human.txt");
            
        }
        
    }
    
    void GameMode::printScore(State& s)
    {
        vector<int> p1 = s.count(1);
        vector<int> p2 = s.count(2);
        cout << "(Player1) " << p1.at(3) << "-" << p2.at(3) << " (Player2)" << endl;
    }
    
    void GameMode::oneMove(string inputFile,int depth,string outputFile)
    {
        s.getState(inputFile);
        cout << string( 100, '\n' );
        s.print();
        vector<int> p1 = s.count(1);
        vector<int> p2 = s.count(2);
        cout << "(Player1) " << p1.at(3) << "-" << p2.at(3) << " (Player2)" << endl;
        if (s.isTerminal())
            return;
        cout << "Computer is making a choice. Please wait..." << endl;
        int choice = AlphaBetaPrune::abd(s, depth);
        s.chipAt(choice);
        cout << string( 100, '\n' );
        cout << "COM CHOICE: " << choice << endl;
        s.print();
        printScore(s);
        s.write(outputFile);
    }
}
