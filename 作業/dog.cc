#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void sp(){
  cout << "\x1b[0m"<<flush;
  usleep(10000);
}
void cc(){
  int f,b;
  f=rand()%8;
  b=rand()%8;
  while(f==b)b=rand()%8;
  cout<<"\x1b[" << 30 + f << ";" << 40 + b << "m"<<flush;
  usleep(10000);
}
int main(){
  int i,j,n;
  srand(time(NULL));
    cin>>n;
    for(i=0;i<n;i++){
      for(j=0;j<(n+1)*5-1;j++){
        sp();
        cout<<" ";
      }
      cc();
      cout<<"|";
      for(j=0;j<i;j++){
        sp();
        cout<<" ";
      }
      for(j=0;j<2;j++){
        cc();
        cout<<"\\";
      }cout<<endl;
    }
    for(i=0;i<(n+1)*2;i++){
      for(j=0;j<(n+1)*2-i-1;j++){
        sp();
        cout<<"  ";
      }
      for(j=0;j<n+2;j++){
        cc();
        cout<<"-";
      }
      if(i==0){
        for(j=0;j<n+2;j++){
          sp();
          cout<<" ";
        }
        for(j=0;j<n+1;j++){
          cc();
          cout<<'-';
        }
        for(j=0;j<n+3;j++){
          cc();
          cout<<'_';
        }
        cout<<endl;
      }
      else if( i>0 && i<n+1 ){
        for(j=0;j<3*n+7+i;j++){
          sp();
          cout<<' ';
        }
        cc();
        cout<<'/'<<endl;
      }
      else if(i==n+1){
        for(j=0;j<3*n+5;j++){
          sp();
          cout<<" ";
        }
        for(j=0;j<n+3;j++){
          cc();
          cout<<"-";
        }
        cc();
        cout<<","<<endl;
      }
      else{
        for(j=0;j<i+2*n+3;j++){
          sp();
          cout<<" ";
        }
        cc();
        cout<<"/"<<endl;
      }
    }
    cout << "\x1b[0m";
    return 0;
}
