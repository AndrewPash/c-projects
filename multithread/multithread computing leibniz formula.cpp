#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
pthread_mutex_t mutex;
double sign=1;
double pi = 0;
void * count(void *arg){
double p = 0;
pthread_mutex_lock;
    for (int i = 0; i < *((int*)arg); i++)
    {
    
    p += sign/ (2 * i + 1);
    sign=-sign;
    
    }
   pi=p*4;
    pthread_mutex_unlock(&mutex);
    return 0;
}


void *print(void *arg){

 pthread_mutex_lock(&mutex);
cout << pi << endl;
pthread_mutex_unlock(&mutex);

return 0;
} 

int main(int argc,char *argv[]){
 int n=atoi(argv[1]);
 int g=atoi(argv[2]);
 pthread_t thread[n];
 pthread_t thread1;
 for(int i=0;i<n;i++){
 pthread_create(&thread[i],NULL,count,(void*)&g);

  pthread_join(thread[i],NULL);
  
 }
  pthread_create(&thread1,NULL,print,NULL);
  pthread_join(thread1,NULL);
 pthread_mutex_destroy(&mutex);
return 0;
}
