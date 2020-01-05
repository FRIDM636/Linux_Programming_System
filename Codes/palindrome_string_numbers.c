#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
void pal_numb(int x)
{
	int rev=0, tmp=x;
	printf("[*] Number %d check...\n",x);
	sleep(1);
	while(tmp != 0)
	{
		rev = rev*10 +tmp%10;
		tmp = tmp/10;
	}
	if(rev == x)
		printf("\033[0;32m[*]Your number \033[0;33m\"%d\"\033[0;32m is a palindrome\n",x);
	else
		printf("\033[0;31m[*]Your number \033[0;33m\"%d\"\033[0;31m is not a palindrome\n",x);

}

void pal_str(char c[]) {
	printf("[*] String %s check...\n",c);
	sleep(1);
	int i;
	unsigned int len = strlen(c);
	bool b = true;
	for(i = 0; i<len/2; i++)
		if(c[i] != c[len -i - 1])
			{ b = false; break;}
	
	if(b)
		printf("\033[0;32m[*]Your string \033[0;33m\"%s\"\033[0;32m is a palindrome\n",c);
	else
		printf("\033[0;31m[*]Your string \033[0;33m\"%s\"\033[0;31m is not a palindrome\n",c);
				
}

int main() {
	int n, choice;
	char str[20];
	printf("Please make a choice:\n1- Number palindrome check\n2- String palindrome check\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: printf("Enter a number:\n"); scanf("%d",&n); pal_numb(n);
			break;
		case 2: printf("Enter a string:\n");scanf("%s",str); pal_str(str);
			break;
		default : printf("Bad choice !\n");
			  break;

	}

	return 0;
}
