#include<iostream>
using namespace std;
main()
{
float s,c,a,cpp,cpsf;
cout<<"Enter the size of the fertilizer bag in pounds: ";
cin>> s;
cout<<"Enter the cost the bag: $";
cin>> c;
cout<<"Enter the area in square feet that can be covered by the bag: ";
cin>> a;
cpp = c/s;
cpsf = c/a;
cout<<"Cost of fertilizer per pound: $"<<cpp<<endl;
cout<<"Cost of fertilizing per square foot: $"<<cpsf<<endl;
}