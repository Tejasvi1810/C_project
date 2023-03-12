#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include<string.h>
struct ac_dt
{
char accno[10];
char nm[10];
char fnm[10];
char ph[10];
};

struct deposit
{
char accno[10];
long int amt;
char date[15];
char type[5];
};


void main()
{
char un[20];
char pw[20];
char a;
int b;
int c=0;
clrscr();
gotoxy(20,10);
cout<<"UserName : ";
fflush(stdin);
gets(un);
gotoxy(20,14);
cout<<"Password : ";
while(1)
{
fflush(stdin);
a=getch();
b=a;
if(b==13)
break;

pw[c]=a;
c++;
cout<<"*";
}
pw[c]='\0';
gotoxy(20,20);
if(strcmp(un,"admin")==0 && strcmp(pw,"abc123")==0)
{

int choice=100;
while(choice!=0)
{
clrscr();
gotoxy(30,5);
cout<<"Main Menu ";
gotoxy(30,7);
cout<<"1. New Account ";
gotoxy(30,8);
cout<<"2. Deposit ";
gotoxy(30,9);
cout<<"3. Withraw ";
gotoxy(30,10);
cout<<"4. Show Balance ";
gotoxy(30,11);
cout<<"5. All Account ";
gotoxy(30,12);
cout<<"6. All Deposit ";
gotoxy(30,13);
cout<<"7. All Withdraw ";
gotoxy(30,14);
cout<<"8. Statement ";
gotoxy(30,15);
cout<<"0. Exit ";

gotoxy(30,17);
cout<<"enter choice ";
cin>>choice;
if(choice==0)
{
break;
}
else if(choice==1)
{
clrscr();

FILE *fp;
struct ac_dt ac;
char ans;
if((fp=fopen("accounts","a+"))==NULL)
{
cout<<"Error opening file ";
getch();
}
cout<<"Account No : ";
fflush(stdin);
gets(ac.accno);
cout<<"Name : ";
fflush(stdin);
gets(ac.nm);
cout<<"Father Name ";
fflush(stdin);
gets(ac.fnm);
cout<<"Phone : ";
fflush(stdin);
gets(ac.ph);
cout<<"Want to Save ? ";
fflush(stdin);
cin>>ans;
if(ans=='y')
{
fwrite(&ac,sizeof(struct ac_dt),1,fp);
fclose(fp);
}
}
else if(choice==5)
{
FILE *fp;
struct ac_dt ac;
if((fp=fopen("accounts","r"))==NULL)
{
cout<<"Error opening file ";
getch();
}
clrscr();
cout<<"\nAccountno\tName\tFather's Name\tPhone";

while((fread(&ac,sizeof(struct ac_dt),1,fp))==1)
{
cout<<"\n"<<ac.accno;
cout<<"\t\t"<<ac.nm;
cout<<"\t"<<ac.fnm;
cout<<"\t\t"<<ac.ph;
}
getch();
fclose(fp);
}

else if(choice==2)
{
clrscr();
int f=0;
FILE *fp1,*fp2;
struct ac_dt ac;
struct deposit dpt;
if((fp1=fopen("accounts","a+w"))==NULL)
{
cout<<"Error opening file ";
getch();
}
if((fp2=fopen("deposit","a+"))==NULL)
{

cout<<"Error opening file ";
getch();
}

cout<<"Enter account no ";
gets(dpt.accno);


while((fread(&ac,sizeof(struct ac_dt),1,fp1))==1)
{
if(strcmp(ac.accno,dpt.accno)==0)
{
f=1;
cout<<"Name : "<<ac.nm<<endl;
break;
}
}

if(f==0)
{
cout<<"Acc no does not exist ";
getch();
}
else
{
cout<<"Enter date (dd\mm\yyyy): ";
gets(dpt.date);
cout<<"Enter Deposit amount ";
cin>>dpt.amt;
cout<<"Enter Type of Transction (d/w) ? ";
gets(dpt.type);
}
fwrite(&dpt,sizeof(struct deposit),1,fp2);



fclose(fp1);
fclose(fp2);
}

else if(choice==6)
{
FILE *fp;
struct deposit dpt;
struct ac_dt ac;
if((fp=fopen("deposit","r"))==NULL)
{
cout<<"Error opening file ";
getch();
}
clrscr();
cout<<"\nAccountno\tDate\t\tAmount\t\tType";

while((fread(&dpt,sizeof(struct deposit),1,fp))==1)
{
cout<<"\n"<<dpt.accno;
cout<<"\t\t"<<dpt.date;
cout<<"\t"<<dpt.amt;
cout<<"\t\t"<<dpt.type;
}
getch();
fclose(fp);
}

// withdrawl kai liye...


else if(choice==3)
{
clrscr();
int f=0;
FILE *fp1,*fp2;
struct ac_dt ac;
struct deposit dpt;
if((fp1=fopen("accounts","a+w"))==NULL)
{
cout<<"Error opening file ";
getch();
}
if((fp2=fopen("deposit","a+"))==NULL)
{

cout<<"Error opening file ";
getch();
}

cout<<"Enter account no ";
gets(dpt.accno);


while((fread(&ac,sizeof(struct ac_dt),1,fp1))==1)
{
if(strcmp(ac.accno,dpt.accno)==0)
{
f=1;
cout<<"Name : "<<ac.nm<<endl;
break;
}
}

if(f==0)
{
cout<<"Acc no does not exist ";
getch();
}
else
{
cout<<"Enter date (dd\mm\yyyy): ";
gets(dpt.date);
cout<<"Enter Withdrawl amount ";
cin>>dpt.amt;
cout<<"Enter Type of Transction (d/w) ? ";
gets(dpt.type);
}
fwrite(&dpt,sizeof(struct deposit),1,fp2);



fclose(fp1);
fclose(fp2);
}

else if(choice==7)
{
FILE *fp;
struct deposit dpt;
struct ac_dt ac;
if((fp=fopen("deposit","r"))==NULL)
{
cout<<"Error opening file ";
getch();
}
clrscr();

cout<<"\nAccountno\tDate\t\tAmount\t\tType";

while((fread(&dpt,sizeof(struct deposit),1,fp))==1)
{
cout<<"\n"<<dpt.accno;
cout<<"\t\t"<<dpt.date;
cout<<"\t"<<dpt.amt;
cout<<"\t\t"<<dpt.type;
}
getch();
fclose(fp);
}

// balance show kar rahe hai...


else if(choice==4)
{
clrscr();
int f=0;
FILE *fp1,*fp2;
struct ac_dt ac;
struct deposit dpt;
if((fp1=fopen("accounts","r+"))==NULL)
{
cout<<"Error opening file ";
getch();
}
if((fp2=fopen("deposit","r+"))==NULL)
{

cout<<"Error opening file ";
getch();
}

cout<<"Enter account no ";
gets(dpt.accno);


while((fread(&ac,sizeof(struct ac_dt),1,fp1))==1)
{
if(strcmp(ac.accno,dpt.accno)==0)
{
f=1;
cout<<"Name : "<<ac.nm<<endl;
//getch();
break;
}
}

if(f==0)
{
cout<<"Acc no does not exist ";
getch();
}

else
{
long int d=0;
long int w=0;

while((fread(&dpt,sizeof(struct deposit),1,fp2))==1)
{
if(strcmp(ac.accno,dpt.accno)==0 && strcmp(dpt.type,"d")==0)
{

d=d + (dpt.amt);

}
if(strcmp(ac.accno,dpt.accno)==0 && strcmp(dpt.type,"w")==0)
{
w=w + (dpt.amt);
}
}

cout<<"Total deposit till now is : "<<d<<endl;
cout<<"Total Withdrawl till now is : "<<w<<endl;
cout<<"Balance is : "<<d-w<<endl;
getch();
}
}

// statement show kar rahe hai....


else if(choice==8)
{
clrscr();
int f=0;
FILE *fp1,*fp2;
struct ac_dt ac;
struct deposit dpt;
if((fp1=fopen("accounts","r+"))==NULL)
{
cout<<"Error opening file ";
getch();
}
if((fp2=fopen("deposit","r+"))==NULL)
{

cout<<"Error opening file ";
getch();
}

cout<<"Enter account no ";
gets(dpt.accno);


while((fread(&ac,sizeof(struct ac_dt),1,fp1))==1)
{
if(strcmp(ac.accno,dpt.accno)==0)
{
f=1;
cout<<"Name : "<<ac.nm<<endl;
cout<<"Account statement for "<<ac.nm<<" is : "<<endl<<endl;
//getch();
break;
}
}

if(f==0)
{
cout<<"Acc no does not exist ";
getch();
}

else
{

cout<<"\nAccountno\tDate\t\tAmount\t\tType";
long int d=0;
long int w=0;
while((fread(&dpt,sizeof(struct deposit),1,fp2))==1)
{
if(strcmp(ac.accno,dpt.accno)==0 &&    strcmp(dpt.type,"d")==0)
{
d=d+dpt.amt;
}
if(strcmp(ac.accno,dpt.accno)==0 && strcmp(dpt.type,"w")==0)
{
w=w+dpt.amt;
}

if(strcmp(ac.accno,dpt.accno)==0)
{

cout<<"\n"<<dpt.accno;
cout<<"\t\t"<<dpt.date;
cout<<"\t"<<dpt.amt;
cout<<"\t\t"<<dpt.type;
}
}

cout<<endl<<endl;
cout<<"CLOSING BALANCE IS : "<<d-w;

getch();
}
}







else
cout<<"invalid User";
}
}
getch();
}