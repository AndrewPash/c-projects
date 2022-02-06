//you need file 'check' for saving data

#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


typedef struct buffer {
         long    mtype;
         string x;
         } msg_t;

 
int main()
 {
key_t key,key1,key2;
key=10;
key1=11;
key2=12;
int msgqid=msgget(key,IPC_CREAT | 0666);
int msgqid1=msgget(key,IPC_CREAT | 0666);
int msgqid2=msgget(key,IPC_CREAT | 0666);
msg_t buf;
msg_t buf1;
msg_t buf2;
int len=sizeof(msg_t)-sizeof(long);

pid_t pID,pID1,pID2;

if (!(pID=fork())) // child
 {
 cout << "Enter 1 column" << endl;
 cin >> buf.x;
 buf.mtype=1;
 msgsnd(msgqid,&buf,len,0);
 return 0;
}
if (!(pID1=fork())) // child
 {
 sleep(3);
 buf1.mtype=1;
 cout << "Enter 2 column" << endl;
 cin >>buf1.x;
 msgsnd(msgqid1,&buf1,len,0);
 return 0;
}
if (!(pID2=fork())) // child
 {
 sleep(7);
 cout << "Enter 3 column" << endl;
 cin >>buf2.x;
 buf2.mtype=1;
 msgsnd(msgqid2,&buf2,len,0);
 return 0;
}

waitpid(pID,NULL,0);
waitpid(pID1,NULL,0);
waitpid(pID2,NULL,0);

msgrcv(msgqid,&buf,len,1,0);
msgrcv(msgqid1,&buf1,len,1,0);
msgrcv(msgqid2,&buf2,len,1,0);
string pr="     ";
string g=buf.x+pr+buf1.x+pr+buf2.x;
msgctl(msgqid,IPC_RMID,0);
msgctl(msgqid1,IPC_RMID,0);
msgctl(msgqid2,IPC_RMID,0);
string s;
bool c=true;
 ifstream in("check");
 if(in.is_open()){
 while(getline(in,s)){
     if(g==s){
     cout << "Not added" << " " << g;
     c=false;
     return 0;
     }
 }
}
if(c){
FILE * file=fopen("check","a");
     if(file){
     fputs(g.c_str(),file);
     fclose(file);
     }
}
return 0;
}
