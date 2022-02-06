#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
void CreateCatalog() {
    if (CreateDirectory("c:\\FILE11", NULL)) {
        cout << "FILE11 created" << endl;
        if (CreateDirectory("c:\\FILE11\\FILE12", NULL)) {
            cout << "FILE12 created" << endl;
            if (CreateDirectory("c:\\FILE11\\FILE12\\FILE13", NULL)) {
                cout << "FILE13 created" << endl;

            } else {
                cout << "Error,directory already exists";
            };

        } else {
            cout << "Error,directory already exists";
        };
    } else {
        cout << "Error,directory already exists";
    };
    if (CreateDirectory("c:\\FILE21", NULL)) {
        cout << "FILE21 created" << endl;
        if (CreateDirectory("c:\\FILE21\\FILE22", NULL)) {
            cout << "FILE22 created" << endl;
            if (CreateDirectory("c:\\FILE21\\FILE22\\FILE23", NULL)) {
                cout << "FILE23 created" << endl;

            } else {
                cout << "Error,directory already exists";
            };

        } else {
            cout << "Error,directory already exists";
        };
    } else {
        cout << "Error,directory already exists";
    };
}

void hod(string dir)
{
    string dot="*";
    string dir1=dir+dot;
    const char  srv='.';
    LPCSTR ptr=dir1.c_str();
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(ptr, &FindFileData);
    if (hFind!=INVALID_HANDLE_VALUE){

        while (FindNextFile(hFind, &FindFileData)) {

            if(FindFileData.dwFileAttributes==FILE_ATTRIBUTE_DIRECTORY && FindFileData.cFileName[0]!=srv)
            {
                cout << "Folder:" << FindFileData.cFileName << endl;
                string nwdir= dir + FindFileData.cFileName;
                SetCurrentDirectoryA(nwdir.c_str());
                cout << "Current directory now is:" << nwdir << endl;
                hod(dir+FindFileData.cFileName+"\\");
            }
            else{
                cout << "File:" <<FindFileData.cFileName << endl;
            }
        }


    }
    FindClose(hFind);
}

void copy(string from,string to)
{
    string dot="*";
    string dir1=from+dot;
    const char  srv='.';
    LPCSTR ptr=dir1.c_str();
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(ptr, &FindFileData);
    if (hFind!=INVALID_HANDLE_VALUE){

        while (FindNextFile(hFind, &FindFileData)) {

            if(FindFileData.dwFileAttributes!=FILE_ATTRIBUTE_DIRECTORY && FindFileData.cFileName[0]!=srv)
            {
                string old=from+FindFileData.cFileName;
                string nwfile=to+FindFileData.cFileName;
                if(CopyFile(old.c_str(),nwfile.c_str(),FALSE)){
                    cout << "Successfully copied file:" << FindFileData.cFileName << endl;
                }
            }

        }
    }

    FindClose(hFind);
}

void filecreate(const string& name){

    if(CreateFile(name.c_str(),GENERIC_WRITE,7,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr)){
        cout<< "File created";
    }
    else {
        cout << "Error:" << GetLastError();
    }

}

void search(string dir,const char n)
{
    string dot="\\*";
    string dir1=dir+dot;
    LPCSTR ptr=dir1.c_str();
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(ptr, &FindFileData);
    if (hFind!=INVALID_HANDLE_VALUE){

        while (FindNextFile(hFind, &FindFileData)) {

            if(FindFileData.dwFileAttributes!=FILE_ATTRIBUTE_DIRECTORY && FindFileData.cFileName[1]==n )
            {
                cout << FindFileData.cFileName << endl;
            }
        }

    }


    FindClose(hFind);
}

void time(string n){
    HANDLE fH;
    FILETIME fileTime;
    SYSTEMTIME sysTime;
    cout << "Enter year,month,day,hours,minutes,seconds" << endl;
    cin >> sysTime.wYear >> sysTime.wMonth >> sysTime.wDay >> sysTime.wHour >> sysTime.wMinute >> sysTime.wSecond;

    fH = CreateFile(n.c_str(), GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_WRITE_ATTRIBUTES, 0);
    if(fH != INVALID_HANDLE_VALUE)
    {
        if(SystemTimeToFileTime(&sysTime,&fileTime)) {
            if(SetFileTime(fH, &fileTime, NULL, NULL)){
                cout << "Successfully changed" << endl;
            }
            else{
                cout << "Error" << endl;
            }

        }
        else{
            cout << GetLastError();
        }
        CloseHandle(fH);
    }
}
void archive(string n){

    if(SetFileAttributes(n.c_str(),FILE_ATTRIBUTE_ARCHIVE)){
        cout << "File is archive" << endl;
    }
    else{
        cout << GetLastError() << endl;
    };

}

void read(string n){
    HANDLE Fileh=CreateFile(n.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    char buff[100];
    int size=GetFileSize(Fileh,NULL);
    if(Fileh==INVALID_HANDLE_VALUE){
        cout << "Failed to open file";
        CloseHandle(Fileh);
        exit(0);
    }

    if(ReadFile(Fileh, buff,sizeof(buff)-2, reinterpret_cast<LPDWORD>(&size), NULL)){
        cout << "File content:" << endl;
        cout << buff << endl;

    }
    CloseHandle(Fileh);

}
void write(string n){
    HANDLE Fileh=CreateFile(n.c_str(),GENERIC_WRITE,FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(Fileh==INVALID_HANDLE_VALUE){
        cout << "Failed to open file";
        CloseHandle(Fileh);
        exit(0);
    }

    char dop[]=",Pashinskiy FB-91";
    int size =GetFileSize(Fileh,NULL);
    SetFilePointer(Fileh, 0, NULL, FILE_END);
    if(WriteFile(Fileh,dop,sizeof(dop),reinterpret_cast<LPDWORD>(&size),NULL)){
        cout << "Successfully writen" << endl;
    }
    else{
        cout << "Failed to write";
    }


    CloseHandle(Fileh);

}


void block(string n) {
    HANDLE fH = CreateFile(n.c_str(), GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_WRITE_ATTRIBUTES,
                           0);
    if (fH != INVALID_HANDLE_VALUE) {
        if (LockFile(fH, 0, 0, 255, 255)) {
            cout << "Successfully locked" << endl;
            Sleep(10000);
        } else {
            cout << "Error:" << GetLastError() << endl;
        }

    }

}


int main(){
     int k;
     char j;
    string n;
    string g="Enter name of file";
    string from,to;
    cout << "Choose function:1-create catalogs,2-directory bypass,3-copy files,4-create file,5-search file,6-change time,7-add archive attribute,8-read file,9-write surname,10-block first string."<< endl;
    cin >> k;
    switch (k){
        case 1:
            CreateCatalog();
            break;
        case 2:
            cout << "Enter path to dir" << endl;
            cin >> n;
            hod(n);
            break;
        case 3:
            cout << "Enter source" << endl;
            cin >> from;
            cout << "Enter to" << endl;
            cin >> to;
            copy(from,to);
            break;
        case 4:
            cout << g << endl;
            cin >> n;
            filecreate(n);
            break;
        case 5 :
            cout << "Enter symbol" << endl;
            cin >> j;
            search(n,j);
        case 6:
            cout << g << endl;
            cin >> n;
            time(n);
            break;
        case 7:
            cout << g << endl;
            cin >> n;
            archive(n);
            break;
        case 8:
            cout << g << endl;
            cin >> n;
            read(n);
            break;
        case 9:
            cout << g << endl;
            cin >> n;
            write(n);
            break;
        case 10:
            cout << g << endl;
            cin >> n;
            block(n);
            break;
        default:
            cout << "Invalid value";
    }
    return 0;
}
