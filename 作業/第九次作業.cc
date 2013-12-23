/*
 
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>

const int X = 24;
const int Y = 30;

using namespace std;

class Toy_Car {
	public :
        int currentX, currentY, nextX, nextY, colorCode;
        int const sleepTime;
        string carName;
        Toy_Car(string name, int x, int y, int time)
            :carName(name), currentX(x), currentY(y), sleepTime(time){
            colorCode = 30;
            cout << "\x1b[2J\x1b[1;1H";
            for (int i = 0; i < 31; i++)
                cout << i%5 ;
            for (int i = 0; i < 25; i++)
                cout << i%5 << endl;
			cout << "\x1b[" << x << ";" << y << "H" << carName << flush;
		}

		void drive_to(int x, int y) {
			nextX = x;
			nextY = y;
            cout << "\x1b[26;5H" << "\x1b[" << colorCode << "m" << "[" << currentX << "," << currentY << "] --> [" << nextX << "," << nextY << "] " << flush;
		}
		friend ostream& operator<< ( ostream& out, Toy_Car& currentCar){
        do{
				out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H" << " " << flush;
				if(currentCar.currentX - currentCar.nextX > 0){
                    currentCar.currentX--;
					out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H" << currentCar.carName << flush;
				}else{
                    currentCar.currentX++;
					out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H" << currentCar.carName << flush;
				}
                usleep(currentCar.sleepTime);
        }while (currentCar.currentX != currentCar.nextX);
        do{
				out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H" << " " << flush;
				if(currentCar.currentY - currentCar.nextY > 0){
                    currentCar.currentY--;
					out << "\x1b[" << currentCar.nextX << ";" << currentCar.currentY << "H" << currentCar.carName << flush;
				}else{
                    currentCar.currentY++;
					out << "\x1b[" << currentCar.nextX << ";" << currentCar.currentY << "H" << currentCar.carName << flush;
				}
                usleep(currentCar.sleepTime);
			}while (currentCar.currentY != currentCar.nextY);
            currentCar.colorCode++;
            return out;
		}
};

int main(){
	srand(time(NULL));

	Toy_Car car("車",2,2,500000);

	while (1 == 1){
        int x = rand()%X+3;
		int y = rand()%Y+3;

		car.drive_to(x,y);
		cout << car << flush;
	}
    return 0;
}
