#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
int main()
{
 struct timeval timer1, timer2, timer3;
 char sign[2000] , verify[2000];
 uint SHA1_signing[11], SHA1_verifying[11], Average_SHA1_sign[11] , Average_SHA1_verif[11];
 for(int k = 0;k<12;k++)
 {
 SHA1_signing[k] =0;
 SHA1_verifying[k] = 0;
 }


//SHA1 signing
 for (int k = 0; k < 5; k++)
 {
 for(int m = 1; m<=10;m++)
 {
 sprintf(sign, "openssl SHA1 -sign /home/sachin/compsec/keys/rsaprivatekey1024.pem -out
/home/sachin/compsec/output/cipher%d /home/sachin/compsec/messgaes/msg.%d.eml",m,m);
 gettimeofday(&timer1,NULL);
 system(sign);
 gettimeofday(&timer2, NULL);

 //printf("timer2.sec = %d, timer2.usec= %d, timer1.sec = %d, timer1.usec= %d\n",timer2.tv_sec,timer2.tv_usec,timer1.tv_sec,timer1.tv_usec);
 SHA1_signing[m]= SHA1_signing[m]+((timer2.tv_sec*1000000+timer2.tv_usec) -
(timer1.tv_sec*1000000+timer1.tv_usec))/1000;
 //printf("timer = %d\n",SHA1_signing[m]);

 }

 }

//SHA1 verfied
 for (int k = 0; k < 5; k++) {
 for (int i = 1; i <=10; i++)
 {

 sprintf(verify, "openssl SHA1 -verify /home/sachin/compsec/keys/rsapublickey1024.pem-signature /home/sachin/compsec/output/cipher%d /home/sachin/compsec/messgaes/msg.%d.eml",i,i);
 gettimeofday(&timer1,NULL);
 system(verify);
 gettimeofday(&timer2, NULL);
 SHA1_verifying[i]= SHA1_verifying[i]+((timer2.tv_sec*1000000+timer2.tv_usec) -
(timer1.tv_sec*1000000+timer1.tv_usec))/1000;

 }

 }
 for (int i = 1; i <= 10; i++)
 {
 Average_SHA1_sign[i] = (SHA1_signing[i])/5;
 Average_SHA1_verif[i] = (SHA1_verifying[i])/5;
 printf("SHA1 signing = %d SHA1
verifiying %d\n",Average_SHA1_sign[i],Average_SHA1_verif[i]);
 }
return 0;
} 