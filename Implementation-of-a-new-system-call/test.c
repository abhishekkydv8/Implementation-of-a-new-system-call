#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>

int main(){
	
	printf(" Invoking system call \n");
	long ans=syscall(326);
	if(ans==0)
		printf("system call is executed check the kernel log \n");
	else
		printf("system call fail \n");	
	return 0;
}
