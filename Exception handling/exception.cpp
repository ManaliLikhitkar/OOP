#include<iostream>
using namespace std;
class Exception
{
  double c;
  public :
         void divide(double a, double b)
         {
            try
            {
              if(b!=0)
              {
                c=a/b;
                cout<<"Division:"<<c<<endl;
              }
              else
                throw b;
            }
            catch(double b)
            {
              cout<<"Divide by zero exception\n";
            }                      
         }
};
int main()
{
  double a,b;
  Exception E;
  cout<<"\nEnter two numbers: ";
  cin>>a>>b;
  E.divide(a,b);
  return 0;
}
