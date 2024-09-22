#include<iostream>
using namespace std;
main()
{
float vi,vf,t,a;
cout<<"Enter Initial velocity (m/s): ";
cin>> vi;
cout<<"Enter Accerelation (m/s^2): ";
cin>> a;
cout<<"Enter Time (s):  ";
cin>> t;
vf = a*t + vi;
cout<<"Final Velocity (m/s): "<<vf<<endl;
}