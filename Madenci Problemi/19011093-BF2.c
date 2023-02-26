#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,n,max,sum,x,y;
  /*int elemanlar[100];
  printf("Lutfen dizinin eleman boyutunu giriniz : ");
  scanf("%d",&n);
  for (i=0;i<n; i++){
  	printf("Lutfen dizinin %d.elemanýný giriniz : \n",i+1);
  	scanf("%d",&elemanlar[i]);
  }*/
  
  /*int elemanlar[] = {8, -30, 36, 2, -6, 52, 8,-1,-11,10,4};
   n=11;
   int elemanlar[] = {-8, -30, -36, -2, -6, -52, -8,-1,-11,-10,-4}; 
   n=11;
   int elemanlar[] = {-5, 255, 66, -8, 4, -52, 27, 5}; 
   n=8;*/
   int elemanlar[] = {12, -100, 66, -400, -4, 52, 27, 5}; 
   n=8;
   max=-100000;
  for(i=0;i<n;i++){
  	sum=0;
  	for(j=i;j<n;j++){
  		sum=sum+elemanlar[j];
  		if(sum > max){
  			max=sum;
  			x=i;
  			y=j;
		  }
	  }
  }
 
  
  if(max >0){
  	printf("En buyuk kazanci %d olup ", max);
  	printf("' %d-%d ' noktalari arasindadir.",x,y);
  }
  else if(max < 0){
  	printf("Zararli bir is olup zarari : %d olup ", max);
  	printf("' %d-%d ' noktalari arasindadir.",x,y);
  }
  else {
  	printf("Kazanci veya zarari yoktur. 0 degeri ", max);
  	printf("' %d-%d ' noktalari arasindadir.",x,y);
  }
  return 0;
}



 
