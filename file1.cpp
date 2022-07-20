#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
/*
-----ATM Machine System----
--FEATURES:--
--1.Check Balance
--2.Cash Withdraw
--3.User details
--4.Mobile Updation
*/
class atm{                                        //Class Declaration
    private:                                      //Private Data members
     long int account_no;
     string name;
     int PIN;
     double balance;
     string mobile_no;
    public:                                        //Public Data Functions
     void setdata(long int account_no_e,string name_e,int PIN_e,double balance_e,string mobile_no_e){
      account_no=account_no_e;
      name=name_e;
      PIN=PIN_e;
      balance=balance_e;
      mobile_no=mobile_no_e;
     }
     long int getAccountNo(){
         return account_no;
     }
     string getName(){
         return name;
     }
     string getMobileNo(){
         return mobile_no;
     }
     int getPin(){
         return PIN;
     }
     double getBalance(){
         return balance;
     }
     void setMobileNo(string mobile_no_prev,string mobile_no_new){
         if(mobile_no_prev==mobile_no){
             mobile_no=mobile_no_new;
             cout<<"Sucessfully Updated Mobile Number."<<endl;
             getch();
         }
         else{
             cout<<"Incorrect!! Previous Mobile Number"<<endl;
             getch();
         }
     }
     void cashWithdraw(int amount){
         if(amount>0 && amount<balance){
             balance-=amount;
             cout<<"Please! Collect Your Cash"<<endl;
             cout<<"Available Balance in the Account:"<<balance<<endl;
             getch();
         }
         else{
             cout<<"Invaild Amount not supported by your Account"<<endl;
         }
     }

};
int main(){
   int choice=0,enterPin;
   long int enteraccount_no;

   system("cls");
   atm user1;
   user1.setdata(1234567,"Ekta Kosta",3425,670000,"8319553302");

   do{
       system("cls");
       cout<<endl<<"*************W E L C O M E   T O   A T M    M A C H I N E  S Y S T E M**************** ";
       cout<<endl<<"*****************************C R E A T E D   B Y************************************* ";
       cout<<endl<<"****************************E K T A    K O S T A**************************************";
       cout<<endl<<"Please Enter Your Account Number:";
       cin>>enteraccount_no;
       cout<<endl<<"Enter Your PIN:";
       cin>>enterPin;

       if(enteraccount_no==user1.getAccountNo() && enterPin==user1.getPin()){
             do{
                 int amount;
                 string mobile_no_prev,mobile_no_new;

                 system("cls");
                 cout<<endl<<"Here's Features and Functions in the ATM machine:";
                 cout<<endl<<"Select options:";
                 cout<<endl<<"1.Check Balance";
                 cout<<endl<<"2.Cash Withdraw";
                cout<<endl<<"3.User details";
                cout<<endl<<"4.Mobile Updation";
                cout<<endl<<"5.Exit";
                cin>>choice;
                switch (choice)
                {
                case 1:
                    cout<<"Your Current Balance is:"<<user1.getBalance()<<endl;
                    getch();
                    break;
                case 2:
                    cout<<"Enter the amount you want to withdraw:"<<endl;
                    cin>>amount;
                    user1.cashWithdraw(amount);
                    break;
                case 3:
                    cout<<endl<<"**User Details are**";
                    cout<<endl<<"Account Number: "<<user1.getAccountNo();
                    cout<<endl<<"Name: "<<user1.getName();
                    cout<<endl<<"PIN: "<<user1.getPin();
                    cout<<endl<<"Current Balance: "<<user1.getBalance();
                    cout<<endl<<"Mobile Number: "<<user1.getMobileNo();
                    
                    getch();
                    break;

                case 4:
                  cout<<"Enter the old mobile Number:"<<endl;
                  cin>>mobile_no_prev;
                  cout<<"Enter new mobile number you want to replace with old new number:"<<endl;
                  cin>>mobile_no_new;
                  user1.setMobileNo(mobile_no_prev,mobile_no_new);
                  getch();
                  break;

                case 5:
                  exit(0);
                default:
                    cout<<"Enter valid Data:"<<endl;
                    break;
                }

             }while(1);
       }
       else{
          cout<<"Enter correct Account number and PIN:"<<endl;
                }
   }while(1);
}
