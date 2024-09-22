#include<iostream>
using namespace std;
main()
{
float i,p;
float chance;
cout<<"Enter Imposter Count: ";
cin>> i;
cout<<"Enter Player Count: ";
cin>> p;
chance = (i/p)*100;
cout<<"Chance of being an imposter: "<<chance<<"%"<<endl;
}
