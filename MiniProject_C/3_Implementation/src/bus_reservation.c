#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bus_reservation.h"

char ch[10][130]={"Bus No. 1  [8:00 A.M ] Kannur-> Kasaragod","Bus No. 2  [8:30 A.M ] Kannur-> Kozhikode","Bus No. 3  [9:00 A.M ] Kannur-> Kochi","Bus No. 4  [1:30 P.M ] Kannur-> Chennai","Bus No. 5  [6:00 P.M ] Kannur-> Bangalore","bus 6"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};

int bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);

	return 1;
}

int booking(int busno)
{
	if(busno<6&&busno>0)
	{
	   int i=0;
	    char numstr[100];

	system("cls");
	printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
	printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
	status_1(busno);
	 FILE *f1, *fopen();//for reading the seats from the user.
	 char str1[80]="32",str2[4],str3[4];
	 int seat1,seat2,booking=0;

	if(busno == 1)
	{
	 f1 = fopen("bus1.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);

	}else if(busno == 2)
	{
	 f1 = fopen("bus2.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);

	}else if(busno == 3)
	{
	 f1 = fopen("bus3.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);

	}
	else if(busno == 4)
	{
	 f1 = fopen("bus4.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);

	}
	else if(busno == 5)
	{
	 f1 = fopen("bus5.txt","r+");
	 fgets(str1,80,f1);
	 fclose(f1);

	}
	seat1=atoi(str1);//covert the string into number
	if(seat1 <= 0)
	{
	 printf("There is no blank seat in this bus ");
	}else
	{
	printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
	printf("\n\t\t\t\tNumber of Tickets:----->");
	scanf("%d",&booking);
	printf("\n");
	//itoa(busno,numstr,10);
	sprintf(numstr,"%d",busno);
	int number;
	char *names;

	if(booking<=32&&booking>0){

		for(i=0; i<booking; i++)//for entering the person name and seat number in the file
		{
		    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
			printf("\t\t\t\tEnter the seat number:--->");
			scanf("%d",&number);
			printf("\t\t\t\tEnter the name of person:--->");
			scanf("%s",names);
			printf("\n======================================================================================================\n\n");
			printf("\n");
			book(numstr,number,names);

		}

		seat1=seat1-booking;

		//itoa(seat1, str1, 10);
		sprintf(str1,"%d",seat1);
		//for reading the seats from the user.
		if(busno == 1)
		{
		 f1 = fopen("bus1.txt","w");
		 fputs(str1,f1);
		 fclose(f1);
		}
		else if(busno == 2)
		{
		 f1 = fopen("bus2.txt","w");
		 fputs(str1,f1);
		  fclose(f1);
		}
		else if(busno == 3)
		{
		 f1 = fopen("bus3.txt","w");
		 fputs(str1,f1);
		  fclose(f1);
		}
		else if(busno == 4)
		{
		 f1 = fopen("bus4.txt","w");
		 fputs(str1,f1);
		  fclose(f1);
		}
		else if(busno == 5)
		{
		 f1 = fopen("bus5.txt","w");
		 fputs(str1,f1);
		 fclose(f1);
		}
		printf("-----------------TICKET-------------------------------TICKET-------------------------------TICKET-------------------\n");
	printf("\n   Note-->: A snapshot of this page with valid ID proof will serve as TICKET!!! No Hardcopy Required\n");
	printf("\n\n\t\t\t\tNo Of Seats Reserved : %d",booking);
	printf("\n\t\t\t\tThe Total booking amount is %d Rs",200*booking);
	printf("\n\t\t\t\tBooking Success!!!\n\n");
	printf("\n-----------------TICKET-------------------------------TICKET-------------------------------TICKET-------------------\n");

	}
	else{
		printf("\n\n\n\n\n\t\t\t\t\t Only 32 Seats Available!!!\n\n");
	}
	}




	return 1;
	}
	else{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\tINVALID BUS SELECTION!!!");
	}
	return 0;
}



int book(char *numstr,int number,char *names)
{

	char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";

	FILE *a,*b;
	int i=0;
	strcat(numstr,".txt");
	strcat(tempstr1,numstr);
	strcat(tempstr2,numstr);
	a = fopen(tempstr1,"a");//for open the file to write the name in the file
	b = fopen(tempstr2,"a");//for open the file for writing the number in the file
	//itoa(number, tempstr, 10);
	sprintf(tempstr,"%d",number);
	fprintf(a,"%s ",names);
	fprintf(b,"%s ",tempstr);
	fclose(a);
	fclose(b);


	return 1;

}



int read_number(int busno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
//itoa(busno,numstr,10);
sprintf(numstr,"%d",busno);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


int read_name(int busno)//for putting the numeric value in the array
{
	if(busno>0&&busno<6)
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
//itoa(busno,numstr,10);
sprintf(numstr,"%d",busno);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
   return 1;}

return 0;
}

int status(int busno)
{

   if(busno>0&&busno<6){

   int i,index=0,j;
    j=read_number(busno);
    read_name(busno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                       %s                                                            \n",ch[busno-1]);
    printf("                                               RESERVATION STATUS                                               \n ");
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }

return 1;
}
else{printf("The Bus No. Is Not Valid");
}

return 0;
}

int status_1(int busno)
{
if(busno>0&&busno<6)
{
      printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(busno);
    read_name(busno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
return 1;
}
return 0;
}


int cancel(int busno)
{

 if(busno>0&&busno<6)
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";

 //itoa(busno,numstr,10);
 sprintf(numstr,"%d",busno);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(busno);
 read_name(busno);
 status_1(busno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");

 printf("\t\t\t\tYour Refund Has been Issued\t\t\t\n" );
    printf("======================================================================================================\n");

return 1;
}
return 0;
}


