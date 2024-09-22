#include<iostream>
using namespace std;
main()
{
int number;
int a,b,c,d;
int sum;
cout<<"Enter a 4-digit number: ";
cin>> number;
a =  number%10;
b = (number/100)%10;
c = (number/1000)%10;
d = (number/10000)%10;
sum = a+b+c+d;
cout<<"Sum of the indiviual digits: "<<sum<<endl;
}

