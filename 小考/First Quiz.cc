#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int intputInteger;
  cin >> intputInteger;
  for(int i = 1; i<=9; i++){
    cout << setw(4)  << intputInteger << endl;
    cout << " X " << i << setw(6);
    for(int j = 1; j<=i; j++){
      if(j == 1)
	cout << intputInteger;
      else
	cout << " + "  << intputInteger;
    }
    if(i != 1)
      cout << " = " << intputInteger*i;
    cout << endl  <<  "----" << endl << setw(4)  << intputInteger*i << endl << endl;
  }
  return 0;
}
