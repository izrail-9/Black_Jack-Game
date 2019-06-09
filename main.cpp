#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
void calc_func();
using namespace std;
int main();
void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nWELCOME"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\n";
                cin.get();
               // cin.get();
                calc_func();return;
               // main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();return;
        }
}
void registr()
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();return;


}

void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();return;
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();return ;
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();return ;
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                //cin.get();
                                main();return;
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                        main();return;
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();return;
        }
}
bool check(int p,int d,int k,int & m,int mny,int ins)
{
    if(k==0 && p==21)
    {   //system("cls");
        cout<<"congratulation you r a blackJack"<<endl;
        m=m+1.5*mny;
          cout<<"you have total money: "<<m<<endl;
        return 1;
    }
    else if(k==1 && p>21)
    {   //system("cls");
        cout<<"you have been bust\n";
        if(ins!=1)
            m-=mny;
              cout<<"you have total money: "<<m<<endl;
        return 1;
    }
    else if(k==4 &&  d==21)
    {  //system("cls");
        cout<<"you have been bust\n";
        if(ins!=1)
            m-=mny;
              cout<<"you have total money: "<<m<<endl;
            return 1;
    }
    else if(k==2 && d==p)
    {
        cout<<"draw\n"; return 1;
    }
    else if(k==2 && d>21)
    {   //system("cls");
        cout<<"you have win\n";
        m+=mny;
          cout<<"you have total money: "<<m<<endl;
        return 1;
    }
    else if(k==2 && d>p && d<=21)
    {   //system("cls");
        cout<<"you have lost\n";
        if(ins!=1)
            m-=mny;
        cout<<"you have total money: "<<m<<endl;
        return 1;
    }
    return 0;
}
int main()
{
cout<<"*****************************************************"<<endl;
cout<<"          *WELCOME TO BLACKJACK GAME*                "<<endl;
cout<<"*****************************************************"<<endl;
/*cout<<"Plese Enter your Name: ";
string c;cin>>c;*/
   int choice;
   cout<<"1.LOGIN\n";
        cout<<"2.REGISTER\n";
        cout<<"3.FORGOT PASSWORD (or) USERNAME\n";
        cout<<"4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this program\nThis program is created by @Thestral9\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"Wrong Choice Intered\n"<<endl;
                        main();break;
        }
}
void calc_func()
{
cout<<"*****************************************************"<<endl;
cout<<"          *WELCOME TO BLACKJACK GAME*                "<<endl;
cout<<"*****************************************************"<<endl;
int total;char f;
cout<<"Enter the total Money you want to play: ";
while(1)
{
cin>>total;
//total=(int)f-'0';
if(total<=0)
    cout<<"sorry you can't play without money\nPlease enter valid money: ";
    else
        break;
}
system("cls");
//cout<<"********"<<" Welcome "<<c<<"********"<<endl;
cin.get();
while(1)
{
  cout<<"Enter Money Amount to play: ";
  int mny;char mn;
 while(1)
 {
  cin>>mny;
  //mny=(int)mn-'0';
  if(mny>total||mny<=0)
  {
    cout<<"You can't play with more then your total Money to play or Please enter  valid money: ";
  }
  else
    break;
 }
 cin.get();
 cout<<endl;
cout<<"Press Enter to Generate your 1st 2 cards"<<endl;
cin.get();
int p_sum=0,d_sum=0;
srand(time(NULL));
int p_card1=rand()%11+1;
int p_card2=rand()%11+1;
//int card3,card4,card5;
p_sum=p_card1+p_card2;
cout<<"Your 1st card is "<<p_card1<<endl<<"Your 2nd card is "<<p_card2<<endl;
cout<<"You Have total value of cards is: "<<p_sum<<endl<<endl;
cout<<"*********Now it's dealer turns***********"<<endl<<endl;
int d_card1=rand()%11+1;//rand()%11+1;
int d_card2=rand()%11+1;
d_sum+=d_card1;
cout<<"dealer's 1st card is "<<d_card1<<endl;//<<" Dealer's 2nd card is "<<d_card2<<endl;
cout<<"dealer's Have total value of cards is: "<<d_sum<<endl;
cout<<"(note that dealer have also a 2nd card which is not seen now)\n\n";
int ins=0;
if(d_sum==11)
{
    cout<<"would you like to take insurance\n1.yes\n2.No"<<endl;
    int a;cin>>a;
    if(a==1)
    {
       ins=1;
    }
}
bool j= check(p_sum,d_sum,0,total,mny,ins);
bool k=0;
if(j!=1)
{
int s=0;
while(s!=2 && k!=1)
{
cout<<"1.Hit\n2.stay"<<endl;
cout<<"select your choice :";
cin>>s;
 if(s==1)
 {   system("cls");
    int p_card3=rand()%11+1;
      p_sum+=p_card3;
      cout<<"your total card value is: "<<p_sum<<endl;
      cout<<"dealer's total card value is: "<<d_sum<<endl;
     k=check(p_sum,d_sum,1,total,mny,ins);
 }
 else if(s!=2)
    cout<<"invalid selection"<<endl;
}
if(k!=1)
{
cout<<"***************NOW DEALER'S TURN**************"<<endl;
d_sum+=d_card2;
cout<<"DEALER HAVE TOTAL CARD VALUE IS :"<<d_sum<<endl;
k=check(p_sum,d_sum,4,total,mny,ins);
while(k!=1)
{
    int d_card3=rand()%11+1;
    cout<<"DEALER TAKE "<<d_card3<<" CARD VALUE"<<endl;
    d_sum+=d_card3;
    cout<<"NOW DEALER HAVE TOTAL CARD VALUE IS: "<<d_sum<<endl;
    k=check(p_sum,d_sum,2,total,mny,ins);
    if(k==1) break;
}
}
}
if(total<=0)
{
    cout<<"YOU HAVE LOST YOUR ALL MONEY\n\n";
    cout<<"THANKS FOR PLAYING THE GAME SEE YOU SOON"<<endl;
    return;
}
cout<<"1.PRESS ANY KEY TO PLAY AGAIN\n2.PRESS 2 TO EXIT"<<endl;
int x;cin>>x;
if(x==2)
{
    cout<<"THANKS FOR PLAYING THE GAME SEE YOU SOON"<<endl;
    return ;
}
cin.get();
}
}
