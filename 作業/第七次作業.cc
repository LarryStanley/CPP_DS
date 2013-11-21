/*
 學號:101201033
 系級:數學二
 姓名:曾崇軒
 第_次作業:7
 編譯環境:xcode
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void printObstacle(void);
void printCar(int startColumn);

int CarMap[6][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                     {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                     {1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
                     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                     {1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
                     {0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0}};

int main(void){
    
    int StartColumn = 0;
    printObstacle();
    while (1 == 1) {
        cout << "\x1b[2J" << flush;
        printCar(StartColumn);
        printObstacle();
        usleep(50000);
        if (StartColumn -16 == 60)
            StartColumn = 0;
        else
            StartColumn ++;
    }
    return 0;
}

void printObstacle(void){
    cout << "\x1b[1;1H" << flush;
    for (int i = 1; i <= 7; i++) {
        if (i == 7) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= 9; k++)
                    cout << k;
                cout << "0";
            }
        }else{
            for (int j = 0; j < 7; j++)
                cout << "\x1b[0;30m" <<"\x1b[" << i << ";" << 6 + j * 8 << "H" << "III" << flush;
        }
        cout << endl;
    }
}

void printCar(int startColumn){
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            if (CarMap[i][j]){
                if (j + startColumn - 16 > 0 && j + startColumn - 16 <= 60)
                    cout << "\x1b[0;31m" <<"\x1b[" << i + 1 << ";" << j + startColumn - 16 << "H" << "*" << flush;
            }
        }
    }
}
