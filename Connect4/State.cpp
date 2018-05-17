//
//  State.cpp
//  Connect4
//
//  Created by Phuoc Do on 3/1/18.
//  Copyright © 2018 Phuoc Do. All rights reserved.
//

#include "State.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
namespace AI {

State::State(string fileName)
{
    getState(fileName);
}

void State::getState(string fileName)
{
    reset();
    ifstream ifs(fileName.c_str());
    if (!ifs.is_open())
    {
        cout << "Error: Cannot open the input file.\nA new game state is created instead." << endl;
        for (int i = 0; i < 6; i++)
            state += "0000000";
        player1 = count(1);
        player2 = count(2);
        player = 1;
        return;
    }
        
    for (int i = 0; i < 6; i++)
    {
        string s;
        getline(ifs, s);
        state += s;
    }
    player1 = count(1);
    player2 = count(2);
    string s;
    getline(ifs, s);
    player = atoi(s.c_str());
}

void State::print()
{
    for (int i = 6; i >= 1; i--)
    {
        for (int j = 1; j <= 7; j++)
            cout << "[" << ((at(i, j) == '0')?' ':at(i,j)) << "]";
        cout << endl;
    }
}
    
    void State::write(string fileName)
    {
        ofstream ofs(fileName.c_str(), ofstream::out);
        
        for (int i = 6; i >= 1; i--)
        {
            for (int j = 1; j <= 7; j++)
            {
                ofs << at(i, j);
            }
            ofs << endl;
        }
        ofs << player;
        ofs.close();
    }
    
char& State::at(int row, int column)
{
    return state.at((6-row)*7 + column-1);
}

    void State::countAfterMove(int p, int row, int col)
    {
        vector<int> result;
        result.assign(4, 0);
        for (int c = (col-3 < 1)?1:(col-3); c <= ((col+3 > 7)?7:(col+3))-3; c++)
        {
            
                int count = 0;
                if (at(row, c+0) == '0'+p)
                    count++;
                else if (at(row, c+0) != '0')
                    continue;
                if (at(row, c+1) == '0'+p)
                    count++;
                else if (at(row, c+1) != '0')
                    continue;
                if (at(row, c+2) == '0'+p)
                    count++;
                else if (at(row, c+2) != '0')
                    continue;
                if (at(row, c+3) == '0'+p)
                    count++;
                else if (at(row, c+3) != '0')
                    continue;
                if (count > 0)
                    result.at(count-1)++;
        }
        
        for (int r = (row-3 < 1)?1:(row-3); r <= ((row+3 > 6)?6:(row+3))-3; r++)
        {
            
            int count = 0;
            if (at(r+0, col) == '0'+p)
                count++;
            else if (at(r+0, col) != '0')
                continue;
            if (at(r+1, col) == '0'+p)
                count++;
            else if (at(r+1, col) != '0')
                continue;
            if (at(r+2, col) == '0'+p)
                count++;
            else if (at(r+2, col) != '0')
                continue;
            if (at(r+3, col) == '0'+p)
                count++;
            else if (at(r+3, col) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
        
        int rLow = row-3;
        int rHigh = row+3;
        int cLow = col-3;
        int cHigh = col+3;
        
        while (rLow < 1 || cLow < 1)
        {
            rLow++;
            cLow++;
        }
        
        while (rHigh > 6 || cHigh > 7)
        {
            rHigh--;
            cHigh--;
        }
        
        int r = rLow;
        int c = cLow;
        for (; r <= rHigh-3; r++,c++)
        {
            int count = 0;
            if (at(r, c) == '0'+p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c+1) == '0'+p)
                count++;
            else if (at(r+1, c+1) != '0')
                continue;
            if (at(r+2, c+2) == '0'+p)
                count++;
            else if (at(r+2, c+2) != '0')
                continue;
            if (at(r+3, c+3) == '0'+p)
                count++;
            else if (at(r+3, c+3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
        
        rLow = row-3;
        rHigh = row+3;
        cLow = col+3;
        cHigh = col-3;
        
        while (rLow < 1 || cLow > 7)
        {
            rLow++;
            cLow--;
        }
        
        while (rHigh > 6 || cHigh < 1)
        {
            rHigh--;
            cHigh++;
        }
        
        r = rLow;
        c = cLow;
        for (; r <= rHigh-3; r++,c--)
        {
            int count = 0;
            if (at(r, c) == '0'+p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c-1) == '0'+p)
                count++;
            else if (at(r+1, c-1) != '0')
                continue;
            if (at(r+2, c-2) == '0'+p)
                count++;
            else if (at(r+2, c-2) != '0')
                continue;
            if (at(r+3, c-3) == '0'+p)
                count++;
            else if (at(r+3, c-3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (p == 1)
                player1.at(i) += result.at(i);
            else if (p == 2)
                player2.at(i) += result.at(i);
        }
        
    }
    
int State::chipAt(int column)
{
    if (column < 1 || column > 7)
        return 1;
    for (int row = 1; row <= 6; row++)
    {
        if (at(row, column) == '0')
        {
            at(row, column) = '0' + player;
            countAfterMove(player, row, column);
            player = (player==2)?1:2;
            return 0;
        }
    }
    return 1;
}

bool State::isTerminal()
{
    for (int r = 1; r <= 6; r++)
        for (int c = 1; c <= 7; c++)
            if (at(r, c) == '0')
                return false;
    return true;
}

vector<int> State::count(int player)
{
    if (!isNull())
    {
        if (player == 1)
            return player1;
        if (player == 2)
            return player2;
    }
    
    vector<int> result;
    result.assign (4,0);
    char p = '0' + player;
    for (int row = 1; row <= 6; row++)
    {
        for (int i = 1; i <= 4; i++)
        {
            int count = 0;
            if (at(row, i+0) == p)
                count++;
            else if (at(row, i+0) != '0')
                continue;
            if (at(row, i+1) == p)
                count++;
            else if (at(row, i+1) != '0')
                continue;
            if (at(row, i+2) == p)
                count++;
            else if (at(row, i+2) != '0')
                continue;
            if (at(row, i+3) == p)
                count++;
            else if (at(row, i+3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
    }
    
    for (int col = 1; col <= 7; col++)
    {
        for (int i = 1; i <= 3; i++)
        {
            int count = 0;
            if (at(i+0, col) == p)
                count++;
            else if (at(i+0, col) != '0')
                continue;
            if (at(i+1, col) == p)
                count++;
            else if (at(i+1, col) != '0')
                continue;
            if (at(i+2, col) == p)
                count++;
            else if (at(i+2, col) != '0')
                continue;
            if (at(i+3, col) == p)
                count++;
            else if (at(i+3, col) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
    }
    
    for (int row = 1; row <= 3; row++)
    {
        int r = row;
        int c = 1;
        for (;r + 3 <= 6; r++, c++)
        {
            int count = 0;
            if (at(r, c) == p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c+1) == p)
                count++;
            else if (at(r+1, c+1) != '0')
                continue;
            if (at(r+2,c+2) == p)
                count++;
            else if (at(r+2, c+2) != '0')
                continue;
            if (at(r+3, c+3) == p)
                count++;
            else if (at(r+3, c+3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
    }
    
    for (int col = 2; col <= 4; col++)
    {
        int r = 1;
        int c = col;
        for (;c + 3 <= 7; r++, c++)
        {
            int count = 0;
            if (at(r, c) == p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c+1) == p)
                count++;
            else if (at(r+1, c+1) != '0')
                continue;
            if (at(r+2,c+2) == p)
                count++;
            else if (at(r+2, c+2) != '0')
                continue;
            if (at(r+3, c+3) == p)
                count++;
            else if (at(r+3, c+3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
            
        }
    }
    
    for (int row = 1; row <= 3; row++)
    {
        int r = row;
        int c = 7;
        for (;r + 3 <= 6; r++, c--)
        {
            int count = 0;
            if (at(r, c) == p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c-1) == p)
                count++;
            else if (at(r+1, c-1) != '0')
                continue;
            if (at(r+2,c-2) == p)
                count++;
            else if (at(r+2, c-2) != '0')
                continue;
            if (at(r+3, c-3) == p)
                count++;
            else if (at(r+3, c-3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
    }
    
    for (int col = 6; col >= 3; col--)
    {
        int r = 1;
        int c = col;
        for (;c - 3 >= 1; r++, c--)
        {
            int count = 0;
            if (at(r, c) == p)
                count++;
            else if (at(r, c) != '0')
                continue;
            if (at(r+1, c-1) == p)
                count++;
            else if (at(r+1, c-1) != '0')
                continue;
            if (at(r+2,c-2) == p)
                count++;
            else if (at(r+2, c-2) != '0')
                continue;
            if (at(r+3, c-3) == p)
                count++;
            else if (at(r+3, c-3) != '0')
                continue;
            if (count > 0)
                result.at(count-1)++;
        }
    }
    
    return result;
    
}
}
