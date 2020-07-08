#include<iostream>
using namespace std;
class shape
{
    protected:
      double a;
      double b;
    public:
       void getdata();
       virtual float compute_area()=0;
};
class triangle:public shape
{
      public:
         float compute_area();
};
class rectangle:public shape
{
      public:
         float compute_area();
};
void shape::getdata()
{
     cout<<"\nEnter 1st value:";
     cin>>a;
     cout<<"Enter 2nd value:";
     cin>>b;
}
float triangle::compute_area()
{
      return(0.5*a*b);
}
float rectangle::compute_area()
{
     return(a*b);
}
int main()
{
      int ch;
      shape *ptr;
      triangle T;
      rectangle R;
      do
      {
          cout<<"\n\nMENU\n1.Area of triangle\n2.Area of rectangle\n3.Exit\n\nEnter your choice:";
          cin>>ch;
          switch(ch)
          {
              case 1:
                     ptr=&T;
                     ptr->getdata();
                     cout<<"\nArea of triangle is "<<ptr->compute_area()<<" square unit"<<endl;
                     break;
              case 2:
                     ptr=&R;
                     ptr->getdata();
                     cout<<"\nArea of rectangle is "<<ptr->compute_area()<<" square unit"<<endl;
                     break;
              case 3:
                     cout<<"\n\nTHANK YOU\n";
                     break;
              default:
                     cout<<"Please enter correct choice!!\n";
          }
      }while(ch!=3);
     return 0;
}
