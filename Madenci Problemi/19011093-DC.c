#include <stdio.h>
#include <stdlib.h>

int max_kesintisiz(int elemanlar[], int low,int high,int *bas,int *bitis,int *max_value)
{
  int mid,max_sol,max_sag,max_crs,max_tmp;
	
  if (low == high) 
  {
    return elemanlar[high];
  }

  mid = (high+low)/2;

  max_sol = max_kesintisiz(elemanlar, low, mid,bas,bitis,max_value);
  max_sag = max_kesintisiz(elemanlar, mid+1, high,bas,bitis,max_value);
  max_crs = cross_bul(elemanlar, low, mid, high,bas,bitis,max_value);
  
  max_tmp=max_bul(max_sol, max_sag, max_crs);
  
 if(max_tmp > *max_value){
  	*max_value=max_tmp;
  }
  
  return max_tmp;
}

int cross_bul(int elemanlar[], int low, int mid, int high,int *bas,int *bitis,int *max_value)
{
	
  int i,midtoleft,midtoright,toplam,maximum2,bas_tmp,bitis_tmp,cr_top;
   midtoleft = -9999;
   midtoright = -9999;
   toplam = 0;
  
  for (i=mid; i>=low; i--)
  {
    toplam = toplam+elemanlar[i];
    if (toplam>midtoleft){
    	midtoleft = toplam;
    	bas_tmp=i;
	}        
  }

  toplam = 0;

  for (i=mid+1; i<=high; i++)
  {
    toplam=toplam+elemanlar[i];
    if (toplam>midtoright){
    	midtoright = toplam;
    	bitis_tmp=i;
	}   
  }
  
  cr_top=midtoleft+midtoright;
	if( cr_top> *max_value){
		*bas=bas_tmp;
		*bitis=bitis_tmp;
	}

  return cr_top;
}

int max_bul(int v1, int v2, int v3)
{
  if (v1 >v2 && v1>v3){
  	return v1;
  }   
  else if (v2>v1 && v2>v3){
  	return v2;
  }
  else{
	return v3;
  }
}

int main()
{
  int i,n,bas,bitis,max_value=-10000,max;
   /*int elemanlar[100];
  printf("Lutfen dizinin eleman boyutunu giriniz : ");
  scanf("%d",&n);
  for (i=0;i<n; i++){
  	printf("Lutfen dizinin %d.elemanýný giriniz : \n",i+1);
  	scanf("%d",&elemanlar[i]);
  }*/
  /*int elemanlar[] = {8, 30, 36, -2, -6000, -52, 8,-1,-11,10,4};
  n=11;
   /*int elemanlar[] = {-8, -30, -36, -2, -6, -52, -8,-1,-11,-10,-4}; 
   n=11;
   int elemanlar[] = {-5, 255, 66, -8, 4, -52, 27, 5}; 
   n=8;*/
   int elemanlar[] = {12, -100, 66, -400, -4, 52, 27, 5}; 
   n=8;
  max=max_kesintisiz(elemanlar,0,(n-1),&bas,&bitis,&max_value);
  if(max_value >0){
  	printf("En buyuk kazanci %d olup ", max_value);
  	printf("' %d-%d ' noktalari arasindadir.",bas,bitis);
  }
  else if(max_value < 0){
  	printf("Zararli bir is olup zarari : %d olup ", max_value);
  	printf("' %d-%d ' noktalari arasindadir.",bas,bitis);
  }
  else {
  	printf("Kazanci veya zarari yoktur. 0 degeri ", max_value);
  	printf("' %d-%d ' noktalari arasindadir.",bas,bitis);
  }
  
  return 0;
}
