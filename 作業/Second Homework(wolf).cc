#include <iostream>

#include <iomanip>

#include <cstdlib>

#include <ctime>

using namespace std;

void cc(){

  int f,b;

  f=rand()%7;

  b=rand()%8;

  while(f==b)b=rand()%8;

  cout<<"\x1b[" << 30 + f + 1 << ";" << 40 << "m"<<flush;

  usleep(200000);

}

int main(){

  int i,j,n;

  srand(time(NULL));

    cin>>n;

    for(i=0;i<n;i++){

      cc();

      cout<<setw((n+1)*5)<<"|";

      cc();

      cout<<setw((i+2))<<"\\\\"<<endl;

    }

    for(i=0;i<(n+1)*2;i++){

      for(j=0;j<(n+1)*2-i-1;j++){

        cc();

        cout<<"  ";

      }

      cc();

      cout<<setfill('-')<<setw(n+2)<<'-';

      if(i==0){

        cc();

        cout<<setfill(' ')<<setw(n+2)<<" ";

        cc();

        cout<<setfill('-')<<setw(n+1)<<'-';

        cc();

        cout<<setfill('_')<<setw(n+3)<<'_'<<endl;

      }

      else if( i>0 && i<n+1 ){

        cc();

        cout<<setfill(' ')<<setw(3*n+8+i)<<'/'<<endl;

      }

      else if(i==n+1){

        cc();

        cout<<setfill(' ')<<setw(3*n+5)<<" ";

        cc();

        cout<<setfill('-')<<setw(n+4)<<','<<endl;

      }

      else{

        cc();

        cout<<setfill(' ')<<setw(i+2*n+4)<<"/"<<endl;

      }

    }

    cout << "\x1b[0m";

    return 0;
}
