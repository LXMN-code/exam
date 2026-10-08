#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
int a[50],b[50],c[50],i,j,k,count,n;
printf("Enter frame size (Example: 8):");
scanf("%d",&n);
printf("Enter the frame in the form of 0 and 1 :");
for(i=0; i<n; i++)
{
scanf("%d",&a[i]);
}
i=0;
b[i++]=0;b[i++]=1;b[i++]=1;b[i++]=1;b[i++]=1;
b[i++]=1;b[i++]=1;b[i]=0;
for(i=8; i<n+8; i++)
{
b[i]=a[i-8];
}
b[i++]=0;b[i++]=1;b[i++]=1;b[i++]=1;b[i++]=1;
b[i++]=1;b[i++]=1;b[i]=0;
printf("Frame is :");
for(i=0; i<n+16; i++)
{
printf("%d",b[i]);
}
i=8;
j=8;
while(i<n+8)
{
count=0;
if(b[i]==0)
{
c[j]=b[i];
for(k=i+1; b[k]==1 && k<n+8 && count<5; k++)
{
j++;
c[j]=b[k];
count++;
if(count==5)
{
j++;

c[j]=0;
}
i=k ;
}
}
else
{
c[j]=b[i];
}
i++;
j++;
}
printf("\nAfter Bit Stuffing :");
for(i=0; i<8; i++)
{
c[i]=b[i];
}
c[j++]=0;c[j++]=1;c[j++]=1;c[j++]=1;c[j++]=1;
c[j++]=1;c[j++]=1;c[j++]=0;
for(i=0; i<j; i++)
{
printf("%d",c[i]);
}
getch();
return 0;
}
