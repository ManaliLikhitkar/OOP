#include<iostream>
using namespace std;
float avgh=0,avgl=0,avgs=0,avgr=0;
int num=0;
class WeatherReport
{
    private: float hightemp, lowtemp, rain, snow;
             int day;
    public: int n;
    void getdata()
    {
       cout<<"Enter the day,high temperature,low temperature,amount of rainfall,amount of snow for the day."<<endl;
       cin>>day>>hightemp>>lowtemp>>rain>>snow;
        if(day<1 || day>31 || hightemp<lowtemp)
        {
          cout<<"Please enter correct data"<<endl;
          getdata();
        }
     }
    void showdata()
    {
     cout<<" "<<day<<"			"<<hightemp<<" 				"<<lowtemp<<"			"<<rain<<"			"<<snow<<endl;	         
    }
    WeatherReport()
    {
       day=99;
       hightemp=999;
       lowtemp=-999;
       rain=0;
       snow=0;
    }
    void average()
    {
       if(day!=99)
       {
         avgh=avgh+hightemp;
         avgl=avgl+lowtemp;
         avgr=avgr+rain;
         avgs=avgs+snow;
         num++;
       }
    }
       
};
int main()
{
  int n,i,d,choice;
  WeatherReport r[31];
  cout<<"Enter the number of days"<<endl;
  cin>>n;
  for(i=0; i<n; i++)
  {
     r[i].getdata();
  }
  
   do
    {
          cout<<"1.View\n2.Update\n3.Average\n4.Exit"<<endl<<endl<<"Enter your choice"<<"\t";     
          cin>>choice;
          cout<<endl;
          switch(choice)
          {
                case 1: 
                           cout<<"Day		"<<"HIGH TEMPERATURE		"<<"LOW TEMPERATURE		"<<"AMOUNT OF RAIN		"<<"AMOUNT OF SNOW   		"<<endl;
                             for(i=0; i<n; i++)
                             {
                                 r[i].showdata();
                             }
                             break;
                case 2: 
                        avgh=0; avgl=0; avgr=0; avgs=0;
                        cout<<"Enter the day to update"<<"\t";
                        cin>>d;
                        r[d-1].getdata();
                        break;
                case 3:  
                         float ah,al,ar,as;
                         for(i=0;i<n;i++)
                         {
                              r[i].average();
  
                         }
                          ah=avgh/n;
                          al=avgl/n; 
                          ar=avgr/n;
                          as=avgs/n; 
                          cout<<"Average high temperature : "<<ah<<endl;
                          cout<<"Average low temperature : "<<al<<endl;
                          cout<<"Average rainfall :  "<<ar<<endl;
                          cout<<"Average snowfall :  "<<as<<endl;
                          break;
                 case 4: 
                         cout<<"THANK YOU"<<endl;
                         choice=0;
                         break;
                 default:
                          cout<<"Please enter valid choice"<<endl;
                          break;    
             }  
             cout<<endl;
     }
     while(choice);
 return 0;
}
