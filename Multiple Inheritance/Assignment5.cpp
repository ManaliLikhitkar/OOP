#include<iostream>
#include<string.h>
using namespace std;
class Date
{
    public:
	int day, month, year;
};
class personal
{
  protected:
   	char name[20];
    Date dob;
   	char adhar[13];
  public:
        personal() {}
        personal(char n[], int day,int month, int year, char a[])
        {
           strcpy(name,n);
           dob.day=day;
           dob.month=month;
           dob.year=year;
           strcpy(adhar,a);
        }
};
class proffesional
{
  protected:
         int yrs_of_exp;
         char dept[10];
         float salary;
         char post[10];
  public:
         proffesional() {}
         proffesional(int y,char dep[],float sal, char p[])
         {
            yrs_of_exp=y;
            strcpy(dept,dep);
            salary=sal;
            strcpy(post,p);
         }
};
class academic
{
  protected:
         char qual[10];
         int year;
         float per;
         char university[20];
  public:
        academic() {}
        academic(char q[],int y,float p,char u[])
        {
           strcpy(qual,q);
           year=y;
           per=p;
           strcpy(university,u);
        }
};
class biodata:public personal,public proffesional,public academic
{
  public:
        char *skill_set[20];
        biodata() {}
        biodata(char n[],int day,int month,int year)
        {
           strcpy(name,n);
           dob.day=day;
           dob.month=month;
           dob.year=year;
        }
        int read(int n, biodata b[]);
        void display(int n);
};
int biodata::read(int n,biodata b[])
{
   int skill,i;
   do
   {
       cout<<"Enter the name:"; cin>>name; cout<<"\n";
       for(i=0; name[i]!='\0';i++)
       {
           if(!isalpha(name[i]))
           {
              cout<<"Please enter correct name\n";
              break;
           }
       }
	   if(name[i]=='\0')
	      break;
   }while(1);
   do
   {
	   cout<<"Enter the date of birth:"; cin>>dob.day>>dob.month>>dob.year; cout<<"\n";
	   if(dob.day<1 || dob.day>31 || dob.month<1 || dob.month>12)
	   {
	      cout<<"Please enter correct date"<<endl;
	      continue;
	   }
	   else
	     break;
   }while(1);
   do
   {
      cout<<"Enter adhar card number:"; cin>>adhar; cout<<endl;
      for(i=0; i<n; i++)
      {
          if(strcmp(adhar,b[i].adhar)==0)
          {
              cout<<"Please enter unique number\n";
              break;
          }
      }
      if(i==n)
        break;
   }while(true);
   cout<<"Enter years of experience:"; cin>>yrs_of_exp; cout<<endl;
   cout<<"Enter department:"; cin>>dept; cout<<endl;
   cout<<"Enter salary:"; cin>>salary; cout<<endl;
   cout<<"Enter post:"; cin>>post; cout<<endl;
   cout<<"Enter your qualification:"; cin>>qual; cout<<endl;
   cout<<"Enter year of passing:"; cin>>year; cout<<endl;
   cout<<"Enter percentage:"; cin>>per; cout<<endl;
   cout<<"Enter university:"; cin>>university; cout<<endl;
   cout<<"Enter the number of skills:"; cin>>skill; cout<<endl;
   cout<<"Enter the skills\n";
   for(i=0; i<skill; i++)
   {
      skill_set[i]=new char[15];
      cin>>skill_set[i];
   }
   return skill;
}
void biodata::display(int n)
{
   int i; cout<<name<<"\t"<<dob.day<<"/"<<dob.month<<"/"<<dob.year<<"\t"<<adhar<<"\t"<<yrs_of_exp<<"\t"<<dept<<"\t"<<salary<<"\t"<<post<<"\t"<<qual<<"\t"<<year<<"\t"<<per<<"%\t"<<university<<"\t";
    for(i=0; i<n; i++)
    {
       cout<<(skill_set[i]);
       if(i<n-1)
       cout<<",";
    }
    cout<<endl;
}
int main()
{
   int choice,n,skill;
   biodata b[10];
   do
   {
	   cout<<"\n\n1.Read data\n2.Display data\n3.Exit\n\n";
	   cin>>choice; cout<<"\n";
	   switch(choice)
	   {
	     case 1:
		    cout<<"Enter the number of records\n";
		    cin>>n;
		    for(int i=0; i<n; i++)
		    {
                cout<<"\nRECORD NUMBER:"<<i+1<<endl;
		        skill=b[i].read(i,b);
		    }
		    break;
	     case 2:
		    for(int i=0; i<n; i++)
		    {
		       b[i].display(skill);
		    }
		    break;
	     case 3:
		    cout<<"THANK YOU!!\n";
		    break;
	     default:
		    cout<<"Enter correct choice\n";
	   }
   }while(choice!=3);
}
