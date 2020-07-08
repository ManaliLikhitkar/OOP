#include<iostream>
using namespace std;
class Complex
{
   private:
           float x,y;
   public:
         Complex()
         {
            x=0;
            y=0;
         }
         Complex(float a, float b)
         {
            x=a;
            y=b;
         }
         void Read();
         void Display();
         friend Complex operator+(Complex A, Complex B)
         {
             Complex temp;
             temp.x=A.x+B.x;
             temp.y=A.y+B.y;
             return temp;
         }
         friend Complex operator-(Complex A, Complex B)
         {
             Complex temp;
             temp.x=A.x-B.x;
             temp.y=A.y-B.y;
             return temp;
         }
         Complex operator*(Complex A)
         {
             Complex temp;
             temp.x=(x*A.x)-(y*A.y);
             temp.y=(x*A.y)+(y*A.x);
             return temp;
         }
         Complex operator/(Complex A)
         {
             if(A.x==0 && A.y==0)
                cout<<"Division cannot be performed"<<endl;
             else
             {
               Complex temp;
               temp.x=((x*A.x)+(y*A.y))/((A.x*A.x)-(A.y*A.y));
               temp.y=((y*A.x)-(x*A.y))/((A.x*A.x)-(A.y*A.y));
               return temp;
             }
         }
};
void Complex::Read()
{
     cout<<"Enter the real and imaginary parts of the complex number"<<endl;
     cin>>x>>y;
}
void Complex::Display()
{
     cout<< "(";
     if(y>0)
        cout<<x<<"+"<<y<<"i";
     else
        cout<<x<<y<<"i";
     cout<< ")";
}
int main()
{
  int choice;
  Complex A(2,3),B,C;
  A.Read();
  B.Read();
  do
  {
     cout<<"\n \n1.Read numbers \n2.Add \n3.Subtract \n4.Multiply \n5.Divide \n6.Display \n7.Exit"<<endl;
     cout<<"Enter your choice \n"<<endl;
     cin>>choice;
     switch (choice)
     {
        case 1:
                A.Read();
                B.Read();
                break;
        case 2:
                C=A+B;
                A.Display();
                cout<< " + " ;
                B.Display();
                cout<< " = " ;
                C.Display();
                cout<<endl;
                break;
        case 3:
                C=A-B;
                A.Display();
                cout<< " - " ;
                B.Display();
                cout<< " = " ;
                C.Display();
                cout<<endl;
                break;
        case 4:
                C=A*B;
                A.Display();
                cout<< " * " ;
                B.Display();
                cout<< " = " ;
                C.Display();
                cout<<endl;
                break;
        case 5:
                C=A/B;
                A.Display();
                cout<< " / " ;
                B.Display();
                cout<< " = " ;
                C.Display();
                cout<<endl;
                break;
        case 6:
                A.Display();
                cout<<endl;
                B.Display();
                cout<<endl;
                break;
        case 7:
                cout<<"THANK YOU"<<endl;
     }
   }while(choice!=7);
   return 0;
}
            
