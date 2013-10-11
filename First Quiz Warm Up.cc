#include <iostream>

using namespace std;

int main()
{
  int inputInteger;

  cin >> inputInteger;

	//乘法表開始
  for(int i = 1; i<=9; i++){
    cout << inputInteger << " X " << i << " = "  << inputInteger*i << " ";
    for(int j = 1; j<=i; j++){
      if(j == 1)
	      cout <<inputInteger;
      else
	      cout << " + " << inputInteger;
    }
    if(i != 1)
      cout << " = " << inputInteger*i;
    cout << endl;
  }
  
}
