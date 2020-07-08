#include<iostream>
#include<string.h>
using namespace std;
class Date
{
    public:
	int day, month, year;
};
class Address
{
   public:
	 char city[20],state[20],country[20];
	 int pin;
};
class personal
{
   protected:
           char name[20],bg[4];
           Date dob;
};
class physical
{
   protected:
            int ht, wt;
};
class residential
{
   protected:
           int policy;
           Address A;
};
class person: public personal, public physical, public residential
{
   private:
           long ph;
           char dl[20];
   public:
           void read(person p[],int n);
           void display();
           int search(person p[], int total, int n);
           void edit(person p[], int s);
           void del(person p[],int total,int s);
};
void person::read(person p[],int n)
{
   int i;
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
   cout<<"Enter the blood group:"; cin>>bg; cout<<"\n";
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
   cout<<"Enter the height:"; cin>>ht; cout<<"\n";
   cout<<"Enter the weight:"; cin>>wt; cout<<"\n";
    do
    {
        cout<<"Enter the policy number:"; cin>>policy; cout<<"\n";
        for(i=0; i<n; i++)
        {
            if(policy==p[i].policy)
            {
               cout<<"Please enter unique number\n";
               break;
            }
        }
        if(i==n)
            break;
    }while(1);

   cout<<"Enter the address:"; cin>>A.city>>A.state>>A.country>>A.pin; cout<<"\n";
   int c;
   do
   {
       cout<<"Enter the phone number:"; cin>>ph; cout<<"\n";
       long temp;
       temp=ph;
       c=0;
       while(temp>0)
       {
          c++;
          temp=temp/10;
       }
       if(c!=10)
       {
           cout<<"Please enter correct phone number\n";
            continue;
       }
   }while(c!=10);
    do
    {
        cout<<"Enter the driving license number:"; cin>>dl; cout<<"\n";
        for(i=0; i<n; i++)
        {
            if(strcmp(dl,p[i].dl)==0)
            {
               cout<<"Please enter unique number\n";
               break;
            }
        }
        if(i==n)
            break;
    }while(1);
}
void person::display()
{
   cout<<"  "<<name<<"\t   "<<bg<<"\t\t "<<dob.day<<"/"<<dob.month<<"/"<<dob.year<<"\t\t  "<<ht<<"\t   "<<wt<<"\t"<<policy<<"\t"<<A.city<<","<<A.state<<","<<A.country<<","<<A.pin<<"\t\t"<<ph<<"\t    "<<dl<<endl;
}
int person::search(person p[], int total, int n)
{
    int i;
    for(i=0; i<total; i++)
    {
       if(p[i].policy==n)
          return i;
    }
    return -1;
}
void person::edit(person p[], int s)
{
    int ch;

    do
    {
        cout<<"1.Height\n2.Weight\n3.Address\n4.Phone number\n5.Finish"<<endl;
        cout<<"Enter your choice\n";
        cin>>ch;
    switch(ch)
    {
        case 1:
               cout<<"Enter the new height of person"<<endl;
               cin>>p[s].ht;
               break;
        case 2:
               cout<<"Enter the new weight of person"<<endl;
               cin>>p[s].wt;
               break;
        case 3:
               cout<<"Enter the new address of person"<<endl;
               cin>>p[s].A.city>>p[s].A.state>>p[s].A.country>>p[s].A.pin;
               break;
        case 4:
               cout<<"Enter the new phone number of person"<<endl;
               cin>>p[s].ph;
               break;
    }
    }while(ch!=5);
}
void person::del(person p[],int total,int s)
{
    int i;
    for(i=s; i<total; i++)
    {
        p[i]=p[i+1];
    }
}
int main()
{
  	int total,choice,i,m,s,n;
  	person p[50],d;
  	cout<<"Enter the total number of records"<<endl;
  	cin>>total;
  	for(i=0; i<total; i++)
  	{
  	   cout<<"Record number:"<<i+1<<"\n";
     	   p[i].read(p,i);
  	}
  	do
  	{
  	  cout<<"1.Add record \n2.Search record\n3.Edit record\n4.Delete record\n5.Display records\n6.Exit"<<endl;
  	  cin>>choice;
  	  switch(choice)
  	  {
  	       case 1:
  	              cout<<"Enter the numbers of records to be added"<<endl;
  	              cin>>m;
  	              for(i=total;i<total+m; i++)
  	              {
  	                 p[i].read(p,i);
  	              }
  	              total+=m;
  	              break;
  	       case 2:
  	              cout<<"Enter the policy number whose record is to be searched"<<endl;
  	              cin>>n;
  	              s=d.search(p,total,n);
  	              if(s==-1)
  	                 cout<<"Record not found"<<endl;
  	              else
  	              {
  	                 cout<<"Record found"<<endl;
  	                 p[s].display();
  	              }
  	              break;
  	       case 3:
  	              cout<<"Enter the policy number whose record is to be edited"<<endl;
  	              cin>>n;
  	              s=d.search(p,total,n);
  	              if(s==-1)
  	                 cout<<"Record not found"<<endl;
  	              else
                     d.edit(p,s);
                     cout<<"Edited successfully"<<endl;
  	              break;
  	       case 4:
  	              cout<<"Enter the policy number whose record is to be deleted"<<endl;
  	              cin>>n;
  	              s=d.search(p,total,n);
  	              if(s==-1)
  	                 cout<<"Record not found"<<endl;
                  else
                     {
                         d.del(p,total,s);
                         total--;
                         cout<<"Deleted successfully\n";
                     }
  	              break;
  	       case 5:
  	              //cout<<"NAME\t BLOOD GROUP\t BIRTH DATE\t HEIGHT\t WEIGHT\t POLICY\t ADDRESS\tPHONE\t LICENSE"<<endl;
  	              for(i=0; i<total; i++)
  	              {
  	                 p[i].display();
  	              }
  	              break;
  	       case 6:
  	              cout<<"Thank You"<<endl;
  	              break;
  	       default:
  	              cout<<"Please enter correct choice"<<endl;
  	  }
    }while(choice!=6);
}