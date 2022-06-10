#include<stdio.h>
#include<unistd.h>

void main()
{
	int pd[2];
	int i=0;
	pipe(pd);
	i = fork();
	if (i==0)
	{
		close(pd[0]);
		printf("child (%d) writes\n", getpid());
		write(pd[1], "have a good morning", 19);
		printf("child has written\n");
	}
	else
	{
		static char buf[20];
		close(pd[1]);
		printf("parent (%d) reads\n", getpid());
		read(pd[0], buf, 6);
		printf("read data is %s\n", buf);
		sleep(10);
		printf("parent (%d) reads\n", getpid());
		read(pd[0], buf, 6);
		printf("read data is %s\n", buf);
	}
	return;
}
