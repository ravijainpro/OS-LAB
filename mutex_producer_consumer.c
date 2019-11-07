/*
https://www.chegg.com/homework-help/questions-and-answers/implement-multi-threaded-producer-consumer-problem-pthreads-library-c-producer-consumer-co-q8539965
The above link have got the same code with explanation (via comments)



The pthread_cond_wait() function blocks the calling thread, waiting for the condition specified by cond to be signaled or broadcast to.

When pthread_cond_wait() is called, the calling thread must have mutex locked. 
The pthread_cond_wait() function atomically unlocks mutex and performs the wait for the condition. 
In this case, atomically means with respect to the mutex and the condition variable and another threads access to those objects through the pthread condition variable interfaces.
*/

# include <stdio.h>
# include <pthread.h>
# define BufferSize 10
# define MAX 10

void *Producer();
void *Consumer();

int BufferIndex=0;
char *BUFFER;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{    
    pthread_t ptid,ctid;
    
    BUFFER=(char *) malloc(sizeof(char) * BufferSize);            
    
    pthread_create(&ptid,NULL,Producer,NULL);
    pthread_create(&ctid,NULL,Consumer,NULL);
    
    pthread_join(ptid,NULL);
    pthread_join(ctid,NULL);
        
    
    return 0;
}

void *Producer()
{    
    for(int i=1; i<=MAX; i++)
    {
        pthread_mutex_lock(&mVar);
        if(BufferIndex==BufferSize)
        {                        
            pthread_cond_wait(&Buffer_Not_Full,&mVar);
        }                        
        BUFFER[BufferIndex++]='@';
        printf("Produce : %d \n",BufferIndex);
        pthread_mutex_unlock(&mVar);
        pthread_cond_signal(&Buffer_Not_Empty);        
    }    
    
}

void *Consumer()
{
    for(int i=1; i<=MAX; i++)
    {
        pthread_mutex_lock(&mVar);
        if(BufferIndex==-1)
        {            
            pthread_cond_wait(&Buffer_Not_Empty,&mVar);
        }                
        printf("Consume : %d \n",BufferIndex--);        
        pthread_mutex_unlock(&mVar);        
        pthread_cond_signal(&Buffer_Not_Full);                
    }    
}
