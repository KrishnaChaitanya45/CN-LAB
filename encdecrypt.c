#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
void main()
{
int a,b,i,j,t,x,n,k=0,flag=0,prime[100];
char m[20],pp[20];
float p[20],c[20];
double e,d;
clrscr();
for(i=0;i<50;i++)
{
flag=0;
for(j=2;j<i/2;j++)
if(i%j==0)
{
flag=1;
break;
}
if(flag==0)
prime[k++]=i;
}
a=prime[k-1];
b=prime[k-2];
n=a*b;
t=(a-1)*(b-1);
e=(double)prime[2];
d=1/(float)e;
printf("\nKey of encryption is:%lf\n",d);
printf("\nEnter plain the text:");
scanf("%s",&m);
x=strlen(m);
printf("\nDecryption status From Source to Destination:\n");
printf("\nSource\t->----------------------------------<-destination\n");
printf("\nChar\tnumeric\tcipher\t\tnumeric\t\tchar \n");
printf("\n***********************************************************
\n");
printf("\n");
for(i=0;i<x;i++)
{
printf("%c",m[i]);
printf("\t%d",m[i]-97);
c[i]=pow(m[i]-97,(float)e);
c[i]=fmod(c[i],(float)n);
printf("\t%f",c[i]);
p[i]=pow(c[i],(float)d);
p[i]=fmod(p[i],(float)n);
printf("\t%f",p[i]);
pp[i]=p[i]+97;
printf("\t%c\n",pp[i]);
printf("\n***********************************************************
\n");
printf("\n");
}
getch();
}