#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"bus_reservation.h""
char ch[10][130]={"Bus No. 1  [8:00 A.M ] Kannur-> Kasaragod","Bus No. 2  [8:30 A.M ] Kannur-> Kozhikode","Bus No. 3  [9:00 A.M ] Kannur-> Kochi","Bus No. 4  [1:30 P.M ] Kannur-> Chennai","Bus No. 5  [6:00 P.M ] Kannur-> Bangalore","bus 6"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int busno;

int main()
{
    char username[]="user", password[]="pass", id[8], p[6];
    int n=1, x, y;
    printf("\n========================================== BUS RESERVATION SYSTEM ======================================================");
    do{

    	 printf("\n\n---------------------------------------------- LOGIN -------------------------------------------------------------------\n\n\n");
         printf("\nEnter Username:");
         scanf("%s", &id);

         printf("\nEnter Password:");
         scanf("%s", &p);

         x=strcmp(id, "user");
         y=strcmp(p, "pass");
        printf("\n\n************************************************************************************************************************");
    if(x==0 && y==0)
    {
     int num,i;
     do{
         printf("\nSucessfully Logged In");
         system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancel Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
             bus();//for list of bus
             break;
        case 2:
        	 system("cls");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bus number
            bus();//for seeing bus list
            printf("Enter the Bus number:--->");
            scanf("%d",&busno);
             booking(busno);//for booking tickets
             break;
        case 3:
        	printf("Enter the bus number:---->");
            scanf("%d",&busno);
             cancel(busno);
             break;
        case 4:
        	system("cls");
            printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");

            printf("Enter the number of bus:---->");
            scanf("%d",&busno);
            status(busno);
            break;
        }
  getch();
    }while(num != 5);
         system("CLS");
         printf("\t----------------------------------------------------------------------------------------------------------\n");
         printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
         printf("\t----------------------------------------------------------------------------------------------------------\n");

  getch();
  return 0;
  }

  else
  {

      printf("\n\t\t\t\t\t WRONG LOGIN CREDENTIALS!!! \n\t\t\t\t\tPlease Verify Your Password!", 5-n);
      getch();
      n++;}

      if(n>5)
      {
         printf("\n\n\n---------------------------------------------- ACCESS DENIED!!! --------------------------------------------------------\n\n");
         printf("---------------------------------------- You've Entered Wrong Password 5 times' ----------------------------------------\n\n\n");
        getch();
      }

       }while (n<=5);

}
