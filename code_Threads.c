#include <stdio.h>
#include <mythreads.h>
#include <stdio.h>
#include <stdio.h>

int max;
volatile int counter = 0; //shared global variable
pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;;

void *
mythread(void *arg)
{
	char *letter =arg;
	int i;
printf("%s: begin [addr of i: %p]\n", letter, &i);
for(i=0; i<max; i++) {
	pthread_mutex_lock(&lock);
	counter = counter + 1;
	pthread_mutex_unlock(&lock);
	}
	printf("%s: done\n", letter);
	return NULL;
}
int main(int argc, char *argv[])
{
	if(argc !=2){
		fprintf(stderr, "usage: main-firdt >loopcount>\n");
		exit(1);
	}
	max = atoi(argv[1]);
	
	
	
	pthread_t p1, p2;
	printf("main: begin [counter = %d] [%x]\n", counter,
			(unsigned int) &counter);
	Pthread_create(&p1, NULL, mythread, "A");
	Pthread_create(&p2, NULL, mythread, "B");
	Pthread_join(p1, NULL);
	Pthread_join(p2, NULL);
	printf("main: done\n [counter: %d]\n [should: %d]\n",
			counter, max*2);
	return 0;
}
	
		