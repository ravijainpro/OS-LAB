//using c:
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex; //for handeling both reader and writer count values ...
sem_t db; //for wrtiter lock/unlock to db
int readercount=0;
pthread_t reader1,reader2,writer1,writer2;
void *reader(void *);
void *writer(void *);
main()
{
sem_init(&mutex,0,1);
sem_init(&db,0,1);
while(1)
{
pthread_create(&reader1,NULL,reader,"1");
pthread_create(&reader2,NULL,reader,"2");
pthread_create(&writer1,NULL,writer,"1");
pthread_create(&writer2,NULL,writer,"2");
}
}
void *reader(void *p)
{
printf("prevoius value %d\n",mutex);
sem_wait(&mutex);
printf("Mutex acquired by reader %d\n",mutex);
readercount++;
if(readercount==1) sem_wait(&db);
sem_post(&mutex);
printf("Mutex returned by reader %d\n",mutex);
printf("Reader %s is Readingn\n",p);
//sleep(3);
sem_wait(&mutex);
printf("Reader %s Completed Reading\n",p);
readercount--;
if(readercount==0) sem_post(&db);
sem_post(&mutex);
}

void *writer(void *p)
{
printf("Writer is Waiting \n");
sem_wait(&db);
printf("Writer %s is writing\n ",p);
sem_post(&db);
//sleep(2);
}

/*

//////=========================================OLD ONE=================================================
#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
# include<bits/stdc++.h>
using namespace std;

void *reader(void *);
void *writer(void *);

int readcount=0,writecount=0,sh_var=5,bsize[5];
sem_t x,y,z,rsem,wsem;
pthread_t r[3],w[2];

void *reader(void *i)
{
        cout << "\n-------------------------";
        cout << "\n\n reader-" << i << " is reading";

        sem_wait(&z);
        sem_wait(&rsem);
        sem_wait(&x);
        readcount++;
        if(readcount==1)
            sem_wait(&wsem);
        sem_post(&x);
        sem_post(&rsem);
        sem_post(&z);
        cout << "\nupdated value :" << sh_var;
        sem_wait(&x);
        readcount--;
        if(readcount==0)
            sem_post(&wsem);
        sem_post(&x);
}

void *writer(void *i)
{
        cout << "\n\n writer-" << i << "is writing";
        sem_wait(&y);
        writecount++;
        if(writecount==1)
        sem_wait(&rsem);
        sem_post(&y);
        sem_wait(&wsem);

        sh_var=sh_var+5;
        sem_post(&wsem);
        sem_wait(&y);
        writecount--;
        if(writecount==0)
        sem_post(&rsem);
        sem_post(&y);
}

int main()
{
        sem_init(&x,0,1);
        sem_init(&wsem,0,1);
        sem_init(&y,0,1);
        sem_init(&z,0,1);
        sem_init(&rsem,0,1);
        
        pthread_create(&r[0],NULL,(void *)reader,(void *)0);
        pthread_create(&w[0],NULL,(void *)writer,(void *)0);
        pthread_create(&r[1],NULL,(void *)reader,(void *)1);
        pthread_create(&r[2],NULL,(void *)reader,(void *)2);
        pthread_create(&r[3],NULL,(void *)reader,(void *)3);
        pthread_create(&w[1],NULL,(void *)writer,(void *)3);
        pthread_create(&r[4],NULL,(void *)reader,(void *)4);

        pthread_join(r[0],NULL);
        pthread_join(w[0],NULL);
        pthread_join(r[1],NULL);
        pthread_join(r[2],NULL);
        pthread_join(r[3],NULL);
        pthread_join(w[1],NULL);
        pthread_join(r[4],NULL);

        return(0);
}    
*/
