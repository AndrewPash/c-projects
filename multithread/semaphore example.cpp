//you need file 'check' with some text

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
sem_t semaphore;
sem_t semaphore1;
string s[5];
int arr[5];
int count=0;
void * set(void *arg){
for(int i=0;i<5;i++){
sem_wait(&semaphore1);
arr[i]=i+1;
sem_post(&semaphore1);
}
return 0;
}
void *change(void *arg){

for(int i=0;i<5;i++){
sem_wait(&semaphore1);
cout << arr[i] << endl;
sem_post(&semaphore1);
}
return 0;
}
void *read(void *arg){
sleep(3);
 ifstream in("check");
 if(in.is_open()){
 for(int i=0;i<*((int*)arg);i++){
    getline(in,s[i]);
    sem_post(&semaphore);
 }
 }
 else{
 cout << "Error opening";
 }
 in.close();

return 0;
}

void *print(void *arg){
 for(int i=0;i<*((int*)arg);i++){
 sem_wait(&semaphore);
 sleep(5);
 time_t seconds=time(NULL);
 tm* time=localtime(&seconds) ;
cout << s[i] << " " << asctime(time) << endl;
 sem_post(&semaphore);
 
}

return 0;
} 
