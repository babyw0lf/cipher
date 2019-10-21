//This program works for plaintext and keyword entered in Capital Letter only
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char plaintext[20],keyword[20],ciphertext[20];
void encrypt();
void main()
{
	int x,i,j=0,n,k;
	printf("\nEnter the plaintext : ");
	scanf("%s",plaintext);
	n=strlen(plaintext);
	printf("\nEnter the keyword : ");
	scanf("%s",keyword);
	k=strlen(keyword);
	if(n>k)
	{
		for(i=k;i<n;i++)
		{
			keyword[i]=keyword[j];  //fill the keyword till the size of plaintext j++;
		}
	}
	encrypt(n);
	printf("Ciphertext:  %s\n",ciphertext);
}
void encrypt(int count)
{
	int i,x,sum;
	for(i=0;i<count;i++)
	{
		sum=plaintext[i]+keyword[i];
                //printf("sum is %d",sum);
		if(sum<130||sum>180)
		{
			printf("\nEnter input in CAPS only \n");
			exit(0);
		}
		else{
                        x= (sum % 26) ;
printf("%d",x);
			ciphertext[i]= x+65;
}
	}
}

