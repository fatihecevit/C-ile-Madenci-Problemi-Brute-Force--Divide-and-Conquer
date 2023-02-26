#include <stdio.h>
#include <stdlib.h>

int main()
{
  int maxlar[100];
  int konum[2];
  int i,j,k,n,max,max_reel,sum,x,y;
 
  
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
  
  max_reel=-100000;
  for (i=0;i<n; i++){
  	max=-100000;
  	for(j=0; j<n-i ;j++){
  		sum=0;
  		for(k=j;k<=j+i;k++){
  			sum=sum+elemanlar[k];
		  }
		  if(sum>max){
		  	max=sum;
		  	x=j;
		  	y=k-1;
		  }
	}
	maxlar[i]=max;
	if(max > max_reel){
		max_reel=max;		
		konum[0]=x;
	 	konum[1]=y;
	}
  }
  
  for(i=0;i<n;i++){
  	if(i != n-1){
  		printf("%d - ",maxlar[i]);
	  }else{
	  	printf("%d  ",maxlar[i]);
	  }
  	
  }
  
  if(max_reel >0){
  	printf("\nEn buyuk kazanci %d olup ", max_reel);
  	printf("' %d-%d ' noktalari arasindadir.",konum[0],konum[1]);
  }
  else if(max_reel < 0){
  	printf("\nZararli bir is olup zarari : %d olup ", max_reel);
  	printf("' %d-%d ' noktalari arasindadir.",konum[0],konum[1]);
  }
  else {
  	printf("\nKazanci veya zarari yoktur. 0 degeri ", max_reel);
  	printf("' %d-%d ' noktalari arasindadir.",konum[0],konum[1]);
  }
  return 0;
}



 
