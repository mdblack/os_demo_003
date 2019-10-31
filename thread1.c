#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void delay(float s)
{
	usleep(rand()%((int)(s*1000000)));
}

void slowprint(char* message)
{
	int i;
	for(i=0; message[i]!='\0'; i++)
	{
		putchar(message[i]);
		delay(.1);
	}
}

void* func(void* message)
{
	char* msg=(char*)message;
	while(1)
	{
//		printf("%s\n",msg);
		slowprint(msg);
		delay(1.5);
	}
}

int main()
{
	pthread_t thread1, thread2;

	srand(time(0));

	char* message1="hi from thread 1\n";
	char* message2="HI FROM THREAD 2\n";

	pthread_create(&thread1, NULL, func, message1);
	pthread_create(&thread2, NULL, func, message2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
