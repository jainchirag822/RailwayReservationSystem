#include<stdio.h>
#include<conio.h>
#include<string.h>
struct air
{
  char name[20];
  int phno;
  char address[50];
  int ticketno;
  char uname[10],pass[13];
  }s;
void login();
void view();
void reserve();
void cancel();
void form();

void menu()
{
int ch;
clrscr();
printf("\n\n*****RAILWAY RESERVATION SYSTEM*****");
printf("\n\n\t1.VIEW ALL TRAINS");
printf("\n\n\t2.RESERVE A TICKET");
printf("\n\n\t3.CANCEL A TICKET");
printf("\n\n\t4.EXIT ");
printf("\n\n\n\n---Enter Your Choice(1,2,3,4)---");
scanf("%d",&ch);
switch(ch)
{
 case 1: view();
    getch();
    menu();
    break;
 case 2: reserve();
    getch();
    menu();
    break;
  case 3: cancel();
   getch();
   menu();
   break;
   case 4:exit();
   break;
  default:printf("\nEnter a valid choice");
   getch();
   menu();
}
}
void view()
{
  int c;
  FILE *file;
  clrscr();
  file = fopen("trains.txt","r");
  if(file)
  {
  while ((c=getc(file)) != EOF)
  putchar(c);
  fclose(file);
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n---Press Double Enter Go to Menu---");
  getch();
}
void form()
{
 printf("\n\nEnter Your Name:");
 scanf("%s",&s.name);
 printf("\n\nEnter Your Contact No.:");
 scanf("%d",&s.phno);
 printf("\n\nEnter Your Address:");
 scanf("%s",&s.address);
 printf("\n\nEnter Your Seat No.:");
 scanf("%d",&s.ticketno);
 printf("\n\n\n*Your Ticket is Confirmed*");
 getch();
}

void reserve()
{
  int code,total_seats=100,reserved=0,class;
  clrscr();
  if(reserved<total_seats)
  {
   reserved++;
   printf("\n\nEnter Your Train code:");
   scanf("%d",&code);
   if(code==1024||code==1045||code==1069||code==1132||code==1198||code==1187||code==1218||code==1250||code==1276)
     {
     clrscr();
     printf("\n\n 1.First Class(Fare 1500 Rs.)");
     printf("\n\n 2.Second Class(Fare 800 Rs.)");
     printf("\n\n 3.Sleeper Class(Fare 500 Rs.)");
     printf("\n\n\n\n\n---Enter Your Choice(1,2,3)---");
     scanf("%d",&class);
       if(class==1)
       {
  clrscr();
  printf("\n\n*Your Fare is 1500 Rs.*");
  form();
  menu();
       }
       else if(class==2)
       {
  clrscr();
  printf("\n\n*Your Fare is 800 Rs.*");
  form();
  menu();
       }
       else if(class==3)
       {
  clrscr();
  printf("\n\n*Your Fare is 500 Rs.*");
  form();
  menu();
       }
       else
       {
  clrscr();
  menu();
       }
 getch();
}
else
printf("\n\nWarning!You Have Entered The Wrong Code");
}
}
void cancel()
{
 int ticket;
 char ch;
 clrscr();
 printf("\n\nEnter Your Seat No.:");
 scanf("%d",&ticket);
 if(ticket==s.ticketno)
  {
   printf("\n\n*Your Seat is Cancelled*");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n---Press Double Enter Go to Menu---");

   getch();
   }
 else
 {
 printf("\n\nSeat No. is Invalid");
 getch();
 menu();
}
}
void login()
{       int i;
char ch;
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t*************");
	printf("\n\t\t\t\t**  Login  **");
	printf("\n\t\t\t\t*************");
	printf("\n\t\t\tUsername:");
	scanf("%s",&s.uname);
	printf("\t\t\tPassword:");
	for(i=0;i<5;i++)
	{
	ch=getch();
	s.pass[i]=ch;
	ch='*';
	printf("%c",ch);
	}
	if(strcmp(s.uname,"admin") == 0 && strcmp(s.pass,"admin") == 0)
	{
		printf("\n\t\t\tAccess Granted.");
		getch();
		menu();
	}
	else
	{
		printf("\n\t\t\tAccess Denied. Try Again..");
		getch();
		login();
	}
}
void main()
{
	clrscr();
	printf("*******************************************************************************\n");
	printf("**                 WELCOME TO RAILWAY RESERVATION SYSTEM                     **\n");
	printf("*******************************************************************************\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n---Press Enter to Continue---");
	getch();
	login();
}



