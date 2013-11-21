#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <stdio.h>

using namespace std;

//回傳星期幾的函數
int returnWeekday(int year, int month, int day);
//判斷是否為平年的函數
int isLeapYear(int year);
//印出單一月份結果
void printSingleResult(int year, int month, int day, int column, int stop);

//儲存印到第幾行
int row;

int main(void){
    //宣告各種變數
    int year[2], month[2], day[2];
    int countOfYear, countOfMonth;
    
    //初始化各種變數
    row = 1;
    scanf("%i %i %i %i %i %i", &year[0], &month[0], &day[0], &year[1], &month[1], &day[1]);
    countOfYear = year[1]-year[0]+1;
    
    //計算總共需印出多少個月份
    for (int i = 0; i < countOfYear; i++) {
        if (countOfYear == 1) {
            countOfMonth = month[1] - month[0] + 1;
        }else{
            if (!i)
                countOfMonth = 12 - month[0] + 1;
            else if (i == countOfYear-1)
                countOfMonth = countOfMonth + month[1];
            else
                countOfMonth = 12 + countOfMonth;
        }
    }
    
    //開始印各個月份
    int currentDate[3],previousRow;
    previousRow = row;
    currentDate[0] = year[0];
    currentDate[1] = month[0];
    currentDate[2] = day[0];
    cout << "\x1b[2J" << flush;
    for (int i = 0; i < countOfMonth; i++) {
        int stop;
        if (i == countOfMonth -1)
            stop = day[1];
        else
            stop = 0;
        if (i%2){
            row = previousRow;
            printSingleResult(currentDate[0], currentDate[1], currentDate[2], 32, stop);
            row = row + 2;
        }else{
            previousRow = row;
            printSingleResult(currentDate[0], currentDate[1], currentDate[2], 1 ,stop);
        }

        if (currentDate[1] == 12){
            currentDate[1] = 1;
            currentDate[0]++;
        }else
            currentDate[1]++;
        
        currentDate[2] = 1;
    }
    cout << endl;
    
    return 0;
}

void printSingleResult(int year, int month, int day, int column, int stop)
{
    string monthInChinese[12] = {"ㄧ","二","三","四","五","六","七","八","九","十","十一","十二"};
    string weekDayShort[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    int countOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year))
        countOfMonth[1] = 29;
    
    cout << "\x1b[" << row << ";" << column << "H" << setw(14) << year << " 年 " << monthInChinese[month-1] << " 月 " << flush;
    row++;
    
    cout << "\x1b[" << row << ";" << column << "H" << flush;
    for (int i = 0; i < 7; i++)
        cout << setw(4) << weekDayShort[i];
    row++;
    
    cout << "\x1b[" << row << ";" << column << "H";
    for (int i = day; i <= countOfMonth[month-1]; i++){
        if (i == day)
            cout << setw(4*(returnWeekday(year, month, day)+1)) << i;
        else
            cout << setw(4) << i;
        if (returnWeekday(year, month, i) == 6){
            row++;
            cout << "\x1b[" << row << ";" << column << "H" << flush;
        }
        if (i == stop)
            break;
    }
    
}

int returnWeekday(int year, int month, int day){
    int a = (14-month)/12;
    year = year - a;
    month = month + 12*a -2;
    //萬年曆公式
    return (year + year/4 - year/100 + year/400 + 31*month/12 + day)%7;
}

int isLeapYear(int year){
	return (year%400==0) || ((year%4==0) && (year%100!=0));
}
