/*
 * login.c
 *
 *  Created on: 22 mar. 2020
 *      Author: ikergallar, misaga019
 */
#include<stdio.h>
#include <ctype.h>

char username[]={0};
char password[]={0};
int main ()
{  void sign_in();
   void sign_up();
   int selection=0;
   printf("\n\t1>. Sign in\n\t2>. Sign up\n\tPlease make a selection\t");
   scanf("%d",&selection);
   switch(selection)
      {
      case 1:
         sign_in();
         break;
      case 2:
         sign_up();
         break;
      default:
         printf("\n\tinvalid selection,try again\n");
      }


}

void sign_in()
{  char user_name[]={'0'};
   char pass_word[]={'0'};
    int x,y,z,count=0;
    retry:
   printf("\n\tplease enter username:\t");
   scanf("%s",user_name);
   if(strcmp(username,user_name)==0)
    {
     printf("\tnow enter your password\t");
     scanf("%s",pass_word);
     if(strcmp(password,pass_word))
      printf("\n\t\tyou're welcome!!");
   else
      {
      printf("wrong password");
      }

   }

  else
   {
    printf("\tinvalid username");
    main();
   }
}



void sign_up()
{
   char confirmpswrd[10]={0};
   int a=0;
   int b=0;
   int c=0;
   printf("\tenter username\t");
   scanf("%s",username);
   reenterpswrd:
   printf("\tplease enter password\t");
   scanf("%s",password);
    while(password[b]!='\0')
      {
         b++;
      }
   if(b<=7)
   {
      printf("\t\t***password too weak\ntry again\n");
      goto reenterpswrd;
   }
   else if(b>=8&&b<=15)
      printf("\t\t***strong password\n");
   else
      printf("\t\t***very strong password\n");
   printf("\tconfirm password\t");
   scanf("%s",confirmpswrd);
   if(strcmp(password,confirmpswrd)==0)

      printf("\n\tsign up successful!\n");

   else if(c!=b)
      printf("passwords don't match");


}
