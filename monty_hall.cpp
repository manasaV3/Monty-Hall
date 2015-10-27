//
//  monty_hall.cpp
//  Algorithms
//
//  Created by Manasa on 9/24/15.
//  Copyright (c) 2015 Manasa. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <random>

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    int win = 0;
    int* hats = new int[3];
    for(int i=0; i<n; i++) {
        for(int j=0; j<3;j++)
            hats[j] = 0;
        int prize = rand()%3;
        hats[prize] = 1;
        
        int selected = rand()%3;
        std::cout << "Player has initially selected hat: " << selected <<"\n";
        int temp = rand()%3;
        int no_prize = -1;
        while(no_prize == -1) {
            if(temp != selected) {
                if(temp != prize) {
                    no_prize = temp;
                }
            }
            temp++;
            temp%=3;
        }
        std::cout << "   Hat without a prize: " << no_prize <<"\n";
        for(int j=0; j<3; j++)
            if(j != selected && j != no_prize) {
                selected = j;
                break;
            }
        std::cout << "   Player swaps to hat: " << selected <<"\n";
        std::cout << "   Hat with prize: " << prize <<"\n";
        if (selected == prize) {
            std::cout << "-- Player wins! :) \n";
            win++;
        } else {
            std::cout << "-- Player looses! :( \n";
        }
        std::cout << " \n";
    }
    
    std::cout << " \n" << "Total wins: " << win
    << "\nWin Percentage: " << win * 100 / n;
    
    return 0;
}