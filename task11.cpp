#include<iostream>
using namespace std;
main()
{
int age,moves;
int avg;
cout<<"Enter the person's age: ";
cin>> age;
cout<<"Enter the number of times they've moved: ";
cin>> moves;
avg = age/(moves+1);
cout<<"Average number of years lived in the same house: "<<avg<<endl;

}
