#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>

/*const int X = 24;
const int Y = 30;*/

using namespace std;

class Toy_Car {
	public :
        int currentX, currentY, nextX, nextY;
        int const sleepTime;
        string carName;
        Toy_Car(string name, int x, int y, int time)
            :carName(name), currentX(x), currentY(y), sleepTime(time){
			cout << "\x1b[" << x << ";" << y << "H" << carName << flush;
		}

		void drive_to(int x, int y) {
			nextX = x;
			nextY = y;
		}
		friend ostream& operator<< ( ostream& out, const Toy_Car& currentCar){
			while (currentCar.currentX != currentCar.nextX){
				out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H";
				if(currentCar.currentX - currentCar.nextX > 0){
					out << "\x1b[" << currentCar.currentX - 1 << ";" << currentCar.currentY << "H" << currentCar.carName;
					currentCar.currentX--;
				}else{	
					out << "\x1b[" << currentCar.currentX + 1 << ";" << currentCar.currentY << "H" << currentCar.carName;
					currentCar.currentX++;
				}
                usleep(currentCar.sleepTime);
			}
			while (currentCar.currentY != currentCar.nextY){
				out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY << "H";
				if(currentY - nextY > 0){
					out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY - 1 << "H" << currentCar.carName;
					currentCar.currentY--;
				}else{
					out << "\x1b[" << currentCar.currentX << ";" << currentCar.currentY - 1 << "H" << currentCar.carName;
					currentCar.currentY++;
				}
                usleep(currentCar.sleepTime);
			}
            return out;
		}
};

int main(){

	cout << "\x1b[2J\x1b[1;1H";

	srand(time(NULL));

	Toy_Car car("車",1,1,500000);

	while (1 == 1){
        int x = rand()%24+1;
		int y = rand()%30+1;

		car.drive_to(x,y);
		cout << car << flush;
	}
    return 0;
}
