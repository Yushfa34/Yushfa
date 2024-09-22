#include<iostream>
using namespace std;
main()
{
float vp,fp;
int v,f;
float e;
cout<<"Enter vegetable price per kilogram (in coins): ";
cin>> vp;
cout<<"Enter fruit price per kilogram (in coins): ";
cin>> fp;
cout<<"Enter total kilograms of vegetables: ";
cin>> v;
cout<<"Enter total kilograms of fruits: ";
cin>> f;
e = ((vp*v)+(fp*f))/1.94;
cout<<"Total earnings in Rupees (Rps): "<<e<<endl;
}