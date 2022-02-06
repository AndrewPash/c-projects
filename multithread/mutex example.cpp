//you need file 'check' with some text

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
pthread_mutex_t mutex;
string s[5];
int arr[5];
int count=0;
void * set(void *arg){
for(int i=0;i<5;i++){
pthread_mutex_lock(&mutex);
arr[i]=i+1;
pthread_mutex_unlock(&mutex);
}
return 0;
}
void *change(void *arg){

for(int i=0;i<5;i++){
pthread_mutex_lock;
cout << arr[i] << endl;
pthread_mutex_unlock(&mutex);
}
return 0;
}
void *read(void *arg){
pthread_mutex_lock(&mutex);
sleep(3);
 ifstream in("check");
 if(in.is_open()){
 for(int i=0;i<*((int*)arg);i++){
    getline(in,s[i]); 
 }
 }
 else{
 cout << "Error opening";
 }
 in.close();
 pthread_mutex_unlock(&mutex);
return 0;
}

void *print(void *arg){
pthread_mutex_lock(&mutex);
 for(int i=0;i<*((int*)arg);i++){
 sleep(5);
 time_t seconds=time(NULL);
 tm* time=localtime(&seconds) ;
cout << s[i] << " " << asctime(time) << endl;
}
pthread_mutex_unlock(&mutex);
return 0;
} 

int main(int argc,char *argv[]){
 int n=atoi(argv[1]);
 int g=atoi(argv[2]);
 pthread_t thread[2*g];
 pthread_t thread1;
 for(int i=0;i<g;i++){
 pthread_create(&thread[i],NULL,read,(void*)&n);
  pthread_join(thread[i],NULL);

 pthread_create(&thread[2*i],NULL,print,(void*)&n);
 pthread_join(thread[2*i],NULL);
 }
  pthread_create(&thread1,NULL,set,NULL);
 pthread_join(thread1,NULL);
  pthread_create(&thread1,NULL,change,NULL);
 pthread_join(thread1,NULL);
 pthread_mutex_destroy(&mutex);
return 0;
}
