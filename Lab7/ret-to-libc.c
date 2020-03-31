#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_ebp();

void ret2libc(int dummy){
	unsigned long * curr_ebp  = get_ebp();
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = (unsigned long)&system;
	char *str = "/bin/bash";
	curr_ebp[3] = (unsigned long)str;
}

void ret2libc_generic(char *cmd){
	unsigned long * curr_ebp  = get_ebp();
	char *str = cmd;
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = (unsigned long)&system;
	curr_ebp[3] = (unsigned long)str;
}

int main(int argc, char *argv[]) {
	ret2libc(0);
	ret2libc_generic(argv[1]);
	printf("Done!\n");
	return 0;
}
