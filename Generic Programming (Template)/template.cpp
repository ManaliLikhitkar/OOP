#include<iostream>
using namespace std;

class TEMPLATES
{
  int i,j;
  public:
  template <class T>
  void add(T a[][10], T Addn[10][10], int r, int c)
  {
     for(i=0; i<r; i++)
     {
        for(j=0; j<c; j++)
           Addn[i][j]=a[i][j]+a[i][j];
     } 
  }
  
  template <class T>
  void input(T a[][10],  int r,  int c)
  {
     cout<<"Enter the elements of matrix:\n";
     for(i=0; i<r; i++)
     {
       for(j=0; j<c; j++)
       {
         cin>>a[i][j];
       }
     }
  }
  
  
  template <class T>
  void display(T a[][10], int r, int c)
  {	   
    for(i=0; i<r; i++)
    {
       for(j=0; j<c; j++)
          cout<<a[i][j]<<"\t";
       cout<<"\n";	    
    }
   } 
};


int main()
{
   int ch,r,c;
   TEMPLATES Te;
   cout<<"Enter your choice\n1.Integer matrix\n2.Float matrix\n";
   cin>>ch;
   switch(ch)
   {
     case 1:
           cout<<"Number of rows:"; cin>>r; cout<<"\n";
   	   cout<<"Number of columns:"; cin>>c; cout<<"\n";
   	   int a[10][10],addn[10][10];
   	   Te.input(a,r,c);
   	   Te.add(a,addn,r,c);
   	   cout<<"Addition is:\n";
   	   Te.display(addn,r,c);
           break;
     case 2:
           cout<<"Number of rows:"; cin>>r; cout<<"\n";
   	   cout<<"Number of columns:"; cin>>c; cout<<"\n";
   	   float b[10][10],addnn[10][10];
   	   Te.input(b,r,c);
   	   Te.add(b,addnn,r,c);
   	   cout<<"Addition is:\n";
   	   Te.display(addnn,r,c);
           break;
   }
   return 0;
}	
	


