#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
int main()
{
 uint SHA256_signing[11], SHA256_verifying[11], Average_SHA256_sign[11] ,
Average_SHA256_verif[11];
 struct timeval timer1, timer2, timer3;
 char sign[2000] , verify[2000];
 for(int k = 0;k<10;k++)
 {
 SHA256_signing[k] =0;
 SHA256_verifying[k] = 0;
 }


//SHA256 signing
for (int k = 0; k < 5; k++)
 {
 for(int m = 1; m<=10;m++)
 {
 sprintf(sign, "openssl SHA256 -sign /home/sachin/compsec/keys/rsaprivatekey2048.pem -out
/home/sachin/compsec/output/cipher%d /home/sachin/compsec/messgaes/msg.%d.eml",m,m);
 gettimeofday(&timer1,NULL);
 system(sign);
 gettimeofday(&timer2, NULL);

 //printf("timer2.sec = %d, timer2.usec= %d, timer1.sec = %d, timer1.usec
= %d\n",timer2.tv_sec,timer2.tv_usec,timer1.tv_sec,timer1.tv_usec);
 SHA256_signing[m]= SHA256_signing[m]+((timer2.tv_sec*1000000+timer2.tv_usec) -
(timer1.tv_sec*1000000+timer1.tv_usec))/1000;
 //printf("timer = %d\n",SHA256_signing[m])
 }
 
 }

//SHA256 verfied
 for (int k = 0; k < 5; k++) {
 for (int i = 1; i <=10; i++)
 {

 sprintf(verify, "openssl SHA256 -verify
/home/sachin/compsec/keys/rsapublickey2048.pem -signature /home/sachin/compsec/output/cipher%d
/home/sachin/compsec/messgaes/msg.%d.eml",i,i);
 gettimeofday(&timer1,NULL);
 system(verify);
 gettimeofday(&timer2, NULL);
 SHA256_verifying[i]= SHA256_verifying[i]+((timer2.tv_sec*1000000+timer2.tv_usec) -
(timer1.tv_sec*1000000+timer1.tv_usec))/1000;

 }

 }
//printf("%u , %u\n",SHA256_signing[i],SHA256_verifying[i]);
 for (int i = 1; i <= 10; i++)
 {
 Average_SHA256_sign[i] = (SHA256_signing[i])/5;
 Average_SHA256_verif[i] = (SHA256_verifying[i])/5;
 printf("SHA256 signing = %d SHA256
verifiying %d\n",Average_SHA256_sign[i],Average_SHA256_verif[i]);
 }
return 0;
} 