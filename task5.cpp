#include<iostream>
using namespace std;
main()
{
string name;
float w,d;
cout<<"Enter the name of person: ";
cin>> name;
cout<<"Enter the target weight loss in kilograms: ";
cin>> w;
d = w*15;
cout<<name<<" will need "<<d<<" days to lose "<<w<<" kg of weight by following the doctor's suggestions"<<endl;
cin>> d;
}