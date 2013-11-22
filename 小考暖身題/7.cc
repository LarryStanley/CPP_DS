#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(void){
                //"0","1","2","3","4","5"
    string s[6] ={"─","│","└","┌","┐","┘"};
    srand( time(NULL) );
    int i = rand()%20 + 1 , j = 1;
    //int p[2][1400];
    /*p[0][0] = i;
    p[1][0] = j;*/
    cout << "\x1b[2J\x1b[" << i << ';' << j << 'H' << s[0];

    while ( j <= 70 ){
        if (rand()%2){
            j++;
            cout << "\x1b[" << i << ';' << j << 'H' << s[0];
        }else if( rand()%2 && i < 20){
            j++;
            cout << "\x1b[" << i << ';' << j << 'H' << s[4];
            i++;
            while ( rand()%2 && i < 20 ){
                cout << "\x1b[" << i << ';' << j << 'H' << s[1];
                i++;
            }
            cout << "\x1b[" << i << ';' << j << 'H' << s[2];
        }else if( rand()%2 && i > 0 ){
            j++;
            cout << "\x1b[" << i << ';' << j << 'H' << s[5];
            i--;
            while ( rand()%2 && i > 0 ){
                cout << "\x1b[" << i << ';' << j << 'H' << s[1];
                i--;
            }
            cout << "\x1b[" << i << ';' << j << 'H' << s[3];
        }
    }   
    return 0;
}
