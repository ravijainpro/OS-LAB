#include<iostream>
#include<pthread.h>
#include<semaphore.h>
int MAX=100;
#define ITEMS 5
sem_t full,empty;
pthread_t pro,pro1,con;
int buffer = -1;
int item[ITEMS];
using namespace std;
 
void *producer(void *args)
{ while(MAX>0){
    sem_wait(&empty);
    buffer += 1;
    item[buffer] = buffer;
    cout<<"produced  "<<item[buffer]<<endl;
    sem_post(&full);
    MAX-=1;
  }
}
 
 
void *consumer(void * args)
{
    while(MAX>0){
    sem_wait(&full);
    cout<<"consumed  "<<item[buffer]<<endl;
    buffer -= 1;
    sem_post(&empty);
    MAX-=1;
}
}
 
int main()
{
 
 
    sem_init(&empty,0,ITEMS);
    sem_init(&full,0,0);
    pthread_create(&pro,NULL,producer,NULL);
    pthread_create(&pro1,NULL,producer,NULL);
    pthread_create(&con,NULL,consumer,NULL);
    pthread_join(pro,NULL);
    pthread_join(pro1,NULL);
    pthread_join(con,NULL);
    return(0);
 
}
