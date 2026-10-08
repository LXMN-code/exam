1. Write a program for a HLDC frame to perform the following.
i) Bit stuffing ii) Character stuffing

i) Bit stuffing

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


------------------------------------------------------------------------------------------------------------------

ii) Character stuffing
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
void main()
{
int i=0,j=0,n,l;
char a[50],b[50],c[50],temp[50];
printf("enter string:");
scanf("%s",&a);
n=strlen(a);
for(i=0;i<n;i++)
{
if(a[i]=='f' && a[i+1]=='l' && a[i+2]=='a' && a[i+3]=='g')
{
temp[j++]='e';
temp[j++]='s';
temp[j++]='c';
temp[j++]='f';
temp[j++]='l';
temp[j++]='a';
temp[j++]='g';
i=i+3;
}
else
{
temp[j++]=a[i];
}
}
l=strlen(temp);
for(i=0;i<l;i++)
{
temp[i]=temp[i];
}
temp[i]='\0';
strcpy(b,"flag");
strcat(b,temp);
strcat(b,"flag");
printf("\n%s",b);

------------------------------------------------------------------------------------------------

Implementation of Stop and Wait Protocol and Sliding Window Protocol. 
STOP & WAIT 
#include<stdio.h> 
#define sleep(x) 
int flag=0;
void sender(int);
void receiver(int);
int main () 
{ 
 int i=0, j=0, n; 
 printf("STOP AND WAIT\n"); 
 printf("------------\n"); 
 printf("Enter the number of frames to transmit:"); 
 scanf("%d",&n); 
 printf("There are %d frames to transmit\n",n); 
 for(i=0;i<n;i++) 
 { 
 printf("\nSENDER SIDE protocol\n"); 
 sender(i); 
 receiver(i); 
 } 
 printf("All frames are transmitted\n"); 
} 
 void sender(int i) 
{ 
 if(flag==0) 
 { 
 printf("\nFrame[%d] is sent\n",i); 
 printf("------------\n"); 
 //receiver(i); // if flag is not 1 receiver cannot receive frames  flag=1; 
 sleep(1000); 
 } 
 else 
 printf("No acknowledgement for previous frames!\n"); 
} 
void receiver(int i) 
{ 
 if (flag==1) 
 { 
 printf("\nRECEIVER SIDE protocol\n"); 
 printf("\nReceiving frame[%d]",i); 
 printf("\nsending acknowledgement\n"); 
 printf("------------\n");
 flag=0; 
 sleep(2000); 
 } 
 else 
 printf("\n no frames to receive"); 
 // exit(0); 
} 
-------------------------------------------------------------------------------------------------------------------------------------------------------------
SLIDING WINDOW 
#include<stdio.h> 
int main() 
{ 
 int w,i,f,frames[50]; 
 printf("Enter window size: "); 
 scanf("%d",&w); 
 printf("\nEnter number of frames to transmit: "); 
 scanf("%d",&f); 
 printf("\nEnter %d frames: ",f); 
 for(i=1;i<=f;i++) 
 scanf("%d",&frames[i]); 
 printf("\nWith sliding window protocol the frames will be sent in the following   manner(assuming no corruption of frames)\n\n"); 
 printf("After sending %d frames at each stage sender waits for  
 acknowledgment sent by the receiver\n\n",w); 
 for(i=1;i<=f;i++) 
 { 
 if(i%w==0) 
 { 
 printf("%d\n",frames[i]); 
 printf("Acknowledgement of above frames sent is received by  sender\n\n"); 
 } 
 else 
 printf("%d ",frames[i]); 
 } 
 if(f%w!=0) 
 printf("\nAcknowledgement of above frames sent is received by sender\n"); 
 return 0; 
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Create an Instance of Simulator class
set ns [new Simulator]
#Open a new file to store animation data
set nf [open prog1.nam w]
$ns namtrace-all $nf
#Open the NS trace file
set tracefile [open prog1.tr w]
$ns trace-all $tracefile
#Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$n0 label "Source1"
$n1 label "Source2"
$n2 label "node"
$n3 label "Destination"
#Give shapes to nodes
$n0 shape square
$n1 shape square
$n2 shape circle
$n3 shape hexagon
#Give colors to nodes
$n0 color green
$n1 color green
$n2 color red
$n3 color blue
$ns color 1 "red"
$ns color 2 "blue"
#Setting up the links // vary the bandwidth for performance analysis
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail
$ns queue-limit $n2 $n3 10 
$ns duplex-link-op $n2 $n3 queuePos 0.5
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
#Create node 3 as a UDP receiver
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
# Color
$udp0 set class_ 1
$udp1 set class_ 2
#Connect UDP with NULL
$ns connect $udp0 $null0
$ns connect $udp1 $null0
set cbr0 [new Application/Traffic/CBR]
set cbr1 [new Application/Traffic/CBR]
#Generate trattic for UDP
$cbr0 set packetSize_ 2500
#$cbro set interval_0.3
$cbr1 set packetSize_ 3000
#$cbr1 set interval_0.3
#Generate traffic
$cbr0 attach-agent $udp0
$cbr1 attach-agent $udp1
$ns at 0.5 "$cbr0 start"
$ns at 9.5 "$cbr0 stop"
$ns at 1.5 "$cbr1 start"
$ns at 9.5 "$cbr1 stop"
#Terminate the simulation
proc finish {} {
global ns nf tracefile
$ns flush-trace
close $tracefile
close $nf
exec nam prog1.nam &
exit 0 -----------------------------------

-----------------------------------------------------------------------------------------

set ns [new Simulator]
set nf [open prog2.nam w]
$ns namtrace-all $nf
set tracefile [open prog2.tr w]
$ns trace-all $tracefile

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$n0 label "TCP Source"
$n1 label "UDP Source"
$n2 label "Router"
$n3 label "TCP_UDP Destination"

$n0 shape square
$n1 shape square
$n2 shape circle
$n3 shape hexagon

$n0 color green
$n1 color green
$n2 color red
$n3 color blue

$ns color 1 red
$ns color 2 blue

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail

$ns queue-limit $n2 $n3 10
$ns duplex-link-op $n2 $n3 queuePos 0.5

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0

set null0 [new Agent/Null]
$ns attach-agent $n3 $null0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0

$udp0 set class_ 1
$tcp0 set class_ 2

$ns connect $tcp0 $sink0
$ns connect $udp0 $null0

set ftp0 [new Application/FTP]
set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.01
$ftp0 set packetSize_ 500
$ftp0 set interval_ 0.01

$ftp0 attach-agent $tcp0
$cbr0 attach-agent $udp0

$ns at 0.5 "$ftp0 start"
$ns at 9.5 "$ftp0 stop"
$ns at 1.0 "$cbr0 start"
$ns at 9.9 "$cbr0 stop"

proc finish {} {
global ns nf tracefile
$ns flush-trace
close $tracefile
close $nf
exec nam prog2.nam &
exec awk -f prog2.awk prog2.tr &
exit 0
}

$ns at 10.0 "finish"

$ns run
```


}
$ns at 10.0 "finish"
$ns run