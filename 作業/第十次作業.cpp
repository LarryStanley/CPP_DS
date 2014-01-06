/*
 學號:101201033
 系級:數學二
 姓名:曾崇軒
 第_次作業:10
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

//將字元轉換成整數
int charToInt(unsigned char intputChar){
    int outputInt = 10*(intputChar/16) + intputChar%16;
    return outputInt;
}

//將整數轉換成字元
unsigned intToChar(int inputInt){
    unsigned char outputChar = inputInt%10 + (inputInt/10)*16;
    return outputChar;
}

//Timer Class實作與宣告
class Timer{
    
private:
    unsigned char min, sec;
public:
    Timer (int m, int s){
        min = intToChar(m);
        sec = intToChar(s);
    }
    
    bool friend operator > (Timer inputTimer, int inputInteger){
        if ( charToInt((inputTimer.min))*60 + charToInt(inputTimer.sec) > inputInteger)
            return true;
        else
            return false;
    }
    
    friend ostream& operator << (ostream& out, Timer& inputTimer){
    	int inputMin = charToInt(inputTimer.min);
    	int inputSec = charToInt(inputTimer.sec);
        if (inputMin < 10) {
            out << "0" << inputMin;
        }else {
        	out << inputMin;
        }
        
        out << ":";
        
        if (inputSec < 10) {
            out << "0" << inputSec;
        }else {
        	out << inputSec;
        }
        
        return out;
    }
    
    friend void operator -- (Timer& inputTimer){
		int inputMin = charToInt(inputTimer.min);
		int inputSec = charToInt(inputTimer.sec);
		
        //分、秒減少
		if (inputSec == 0) {
			inputSec = 59;
			inputMin--;
		}else {
			inputSec--;
		}
		inputTimer = Timer(inputMin, inputSec);
    }
    
    friend Timer operator += (Timer& inputTimer, int inputInteger){
    	int inputMin = charToInt(inputTimer.min);
		int inputSec = charToInt(inputTimer.sec);
		
		inputSec = inputSec + inputInteger;
		
        //若超過六十秒就進位成分
		if (inputSec > 60) {
			inputMin = inputMin + (int)inputSec/60;
			inputSec = inputSec - (int)inputSec/60 * 60;
		}
		
		return Timer(inputMin, inputSec);
    }
};

int main(){
    Timer foo(10,0);
    
    while (foo > 0) {
        cout << foo << endl;
        usleep(1000000);
        --foo;
    }
    
    foo += 30;
    cout << foo << endl;
    
    return 0;
}