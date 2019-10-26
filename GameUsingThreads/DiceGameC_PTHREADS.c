#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#define MAX 500

struct data
{
    //given as arg
    char *filename;
    //returned from thread
    int x;
    int y;
};
   void *getcoords(void *ptr);
   int main(int argc, char** argv) {
        struct data hello; //struct
        pthread_t mythread;  //thread
        void *ret;  //return value from struct
    	int victory;
    	int moveOne = 0, moveTwo = 0;
    	int oneTotal = 0, twoTotal = 0;
    	int overVictory = 0, overVictoryTwo = 0;
    	int i = 0;
		char oneName[MAX];
    	char twoName[MAX];
        printf("                                    Hello! Welcome to the lucky star game!\n");
		printf("                                        Press any key to start the game\n");
    	mygetch();
    	printf("Enter name for player one: ");          //Enter first player
    	scanf("%s", oneName);
    	printf("Enter name for player two: ");
    	scanf("%s", twoName);
    	printf("First to number of stars? ");
    	scanf("%d", &victory);
		//create thread passing in the struct with the filename
	while (oneTotal <= victory && twoTotal <= victory)
    	{
			pthread_create(&mythread,NULL,getcoords,(void*)&hello); //join thread and return value to the variable ret
			pthread_join(mythread,&ret); //a struct of data* now to hold the return info
			struct data *newinfo;
			newinfo = (struct data*) ret;  //this line segfaults
			printf("%s, press any key to roll the dice \n", oneName);
			mygetch();
			int x = newinfo->x; 
            moveOne = x;
            oneTotal += moveOne;
            printf("%s rolled the dice for %d\n", oneName, moveOne);
            if (oneTotal == victory)
            {
                printf("%s: ", oneName);
                for (i = 0; i < oneTotal; ++i)
                {
                    printf("*");
                }
                printf(" Stars(%d)", oneTotal);
                printf("\n");
                printf("--------------------------------------\n");
                break;
            }
            else if (oneTotal > victory)
            {
                overVictory = oneTotal - (victory);
                printf("Oops, you went over the victory by %d\n", overVictory);
                oneTotal = victory - overVictory;
                oneTotal = abs(oneTotal);
            }
            printf("%s: ", oneName);
            for(i = 0; i<oneTotal; ++i)
            {
                printf("*");
            }
            printf(" Stars(%d)", oneTotal);
            printf("\n");
            printf("--------------------------------------\n");
            //Second player
            printf("%s, press any key to roll the dice \n", twoName);
            mygetch();
            int y = newinfo->y;
            moveTwo = y;
            twoTotal += moveTwo;
            printf("%s rolled the dice for %d\n", twoName, moveTwo);
            if (twoTotal == victory)
            {
                printf("%s: ", twoName);
                for (i = 0; i < twoTotal; ++i)
                {
                    printf("*");
                }
                printf(" Stars(%d)", twoTotal);
                printf("\n");
                printf("--------------------------------------\n");
                break;
            }
            else if (twoTotal > victory)
            {
                overVictoryTwo = twoTotal - (victory);
                printf("Oops, you went over the victory by %d\n", overVictoryTwo);
                twoTotal = victory - overVictoryTwo;
                twoTotal = abs(twoTotal);
            }
            printf("%s: ", twoName);
            for(i = 0; i<twoTotal; ++i)
            {
                printf("*");
            }
            printf(" Stars(%d)", twoTotal);
            printf("\n");
            printf("--------------------------------------\n");
    	}
    	if (oneTotal > twoTotal)
    	{
            printf("%s, you won the game!\n", oneName);
            for (i = 0; i < oneTotal; ++i)
                {
                    printf("*");
                }
            printf(" Stars(%d)\n", oneTotal);
    	}
    	else
    	{
            printf("%s, you won the game!\n", twoName);
            for (i = 0; i < twoTotal; ++i)
                {
                    printf("*");
                }
            printf(" Stars(%d)\n", twoTotal);
    	}
       return 0;

}


void *getcoords(void *ptr) {
    struct data *ret = (struct data *) ptr;
    int z = RAND(1,6);
    int w = RAND(1,6);
    ret->x = z;
    ret->y = w;
    return(ptr);

}

int RAND(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) +1);
}


int mygetch ( void ) 
{
  int ch;
  struct termios oldt, newt;
  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}