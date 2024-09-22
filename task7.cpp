#include<iostream>
using namespace std;
main()
{
string name;
float adultprice,childprice,adultsold,childsold,charity,ticketsale,donation,remaining;
cout<<"Enter the movie name: ";
cin>> name;
cout<<"Enter the adult ticket price: $";
cin>> adultprice;
cout<<"Enter the child ticket price: $";
cin>> childprice;
cout<<"Enter the number of adult tickets sold: ";
cin>> adultsold;
cout<<"Enter the number of child ticket sold: ";
cin>> childsold;
cout<<"Enter the percentage of the amount to be donated to charity: ";
cin>> charity;
cout<<endl;
ticketsale = (adultprice*adultsold)+(childprice*childsold);
donation = (charity/100)*ticketsale;
remaining = ticketsale - donation;
cout<<"Movie: "<<name<<endl;
cout<<"Total amount generated from ticket sales: $"<<ticketsale<<endl;
cout<<"Donation to cahrity (10%): $"<<donation<<endl;
cout<<"Remaining amount after donation: $"<<remaining<<endl;
}