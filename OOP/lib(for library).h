#include <iostream>
#include <ctime>
using namespace std;
class library{ // класс бібліотека
protected:
    int x;
    int c; // змінні для сортування книжок
    int z;
public:
    string link;  // створення характеристик книжни
    string name;   // назва
    string author; // автор
    string title; // жанр
};
class department:virtual public library{
public:
    void choosaut(); //функція  для вибору автора
    void choosedep(); // функція вибору жанру
};
void department::choosedep() {
    cout << "In this library are 4 departments:1-detectives,2-dramas,3-horrors,4-fantasy,choose by picking number" << endl;
    cin >> x; // змінна х відповідає за жанр
}
void department::choosaut() {
    if(x==1)
    {
        cout << "You`re in department of detectives"<< endl;
        title="detectives";
        cout << "In this department are two authors:1-Agatha Christie,2-Arthur Ignatius Conan Doyle,choose a author by picking a number" << endl;
        cin >> z; //змінна z відповідає за автора
    }
    else if (x==2){
        cout << "You`re in department of dramas" << endl ;
        title="dramas";
        cout << "In this department are two authors:1-William Shakespeare,2-Anton Chekhov,choose a author by picking a number" << endl ;
        cin >> z;
    }
    else if (x==3){
        cout << "You`re in department of horrors" << endl ;
        title="horrors";
        cout << "In this department are two authors:1-Stephen Edwin King,2- Howard Phillips Lovecraft,choose a author by picking a number" << endl ;
        cin >> z;
    }
    else if (x==4){
        cout << "You`re in department of fantasy" << endl ;
        title="fantasy";
        cout << "In this department are two authors:1-George Raymond Richard Martin,2-John Ronald Reuel Tolkien,choose a author by picking a number" << endl ;
        cin >> z;
    }

}
class book: virtual public department{ // класс книга
public :
    void choosebook() ; // функція сортування по авторам
    void choosbook1() ; // функція присвоєння характеристик вибраної книжки

    void showinfo(); // функція виводу інформації


};








void book::choosebook() {
    if (x == 1 && z == 1) {
        cout << "Two books of this author:1-Murder on the Orient Express,2-The Murder of Roger Ackroyd" << endl;
        cin >> c; // змінна с відповідає за певну книжку певного автора
    } else if (x == 1 && z == 2) {
        cout << "Two books of this author:1-Sherlock Holmes:The Hound of the Baskervilles,2-A Study in Scarlet" << endl;
        cin >> c;

    } else if (x == 2 && z == 1) {
        cout << "Two books of this author:1-Hamlet,2-Romeo and Juliet" << endl;
        cin >> c;
    } else if (x == 2 && z == 2) {
        cout << "Two books of this author:1-The Lade with the Dog,2-Man in a Shell" << endl;
        cin >> c;
    } else if (x == 3 && z == 1) {
        cout << "Two books of this author:1-The Stand,2-The Shining" << endl;
        cin >> c;
    } else if (x == 3 && z == 2) {
        cout << "Two books of this author:1-Call of Cthulhu,2-At the Mountains of Madness" << endl;
        cin >> c;
    } else if (x == 4 && z == 1) {
        cout << "Two books of this author:1-A Song of Ice and Fire,2-Blood of the Dragon" << endl;
        cin >> c;
    } else if (x == 4 && z == 2) {
        cout << "Two books of this author:1-Hobbit,2-The Lord of the Rings" << endl;
        cin >> c;
    }
}

void book::choosbook1() { // присвоєння характеристик книжки вибраної користувачем
    if (x == 1 && z == 1 && c == 1) {
        author = "Agatha Christie";
        name = "Murder on the Orient Express";
        link = "http://www.etextlib.mobi/Book/Details/37893";
    } else if (x == 1 && z == 1 && c == 2) {
        author = "Agatha Christie";
        name = "The Murder of Roger Ackroyd";
        link = "https://litlife.club/books/90759";
    } else if (x == 1 && z == 2 && c == 2) {
        author = "Arthur Ignatius Conan Doyle";
        name = "A Study in Scarlet";
        link = "https://royallib.com/book/Doyle_Arthur/A_Study_in_Scarlet.html";
    } else if (x == 1 && z == 2 && c == 1) {
        author = "Arthur Ignatius Conan Doyle";
        name = "Sherlock Holmes:The Hound of the Baskervilles";
        link = "https://librebook.me/the_hound_of_the_baskervilles";
    } else if (x == 2 && z == 1 && c == 1) {
        author = "William Shakespeare";
        name = "Hamlet";
        link = "https://librebook.me/the_tragical_historie_of_hamlet__prince_of_denmarke";
    } else if (x == 2 && z == 2 && c == 1) {
        author = "Anton Chekhov";
        name = "The Lade with the Dog";
        link = "https://ilibrary.ru/text/976/p.1/index.html";
    } else if (x == 2 && z == 1 && c == 2) {
        author = "William Shakespeare";
        name = "Romeo and Juliet";
        link = "https://librebook.me/romeo_and_juliet";
    } else if (x == 2 && z == 2 && c == 2) {
        author = "Anton Chekhov";
        name = "Man in a Shell";
        link = "https://ilibrary.ru/text/438/p.1/index.html";
    } else if (x == 3 && z == 1 && c == 2) {
        author = "Stephen Edwin King";
        name = "The Shining";
        link = "https://litlife.club/books/126791";
    } else if (x == 3 && z == 2 && c == 2) {
        author = "Howard Phillips Lovecraft";
        name = "At the Mountains of Madness";
        link = "https://litlife.club/books/245783";
    } else if (x == 3 && z == 1 && c == 1) {
        author = "Stephen Edwin King";
        name = "The Stand";
        link = "https://librebook.me/the_stand_king_stiven_edvin";
    } else if (x == 3 && z == 2 && c == 1) {
        author = "Howard Phillips Lovecraft";
        name = "Call of Cthulhu";
        link = "https://librebook.me/the_call_of_cthulhu";
    } else if (x == 4 && z == 1 && c == 1) {
        author = "George Raymond Richard Martin";
        name = "A Song of Ice and Fire";
        link = "http://loveread.me/series-books.php?id=1017";
    } else if (x == 4 && z == 2 && c == 1) {
        author = "John Ronald Reuel Tolkien";
        name = "Hobbit";
        link = "https://librebook.me/the_hobbit_or_there_and_back_again";
    } else if (x == 4 && z == 1 && c == 2) {
        author = "George Raymond Richard Martin";
        name = "Blood of the Dragon";
        link = "https://www.rulit.me/books/the-blood-of-a-dragon-download-free-237852.html";
    } else if (x == 4 && z == 2 && c == 2) {
        author = "John Ronald Reuel Tolkien";
        name = "The Lord of the Rings";
        link = "https://librebook.me/the_lord_of_the_rings";
    } else {
        cout << "You`re enter wrong number";
        exit;
    }
}

void book::showinfo() { // функція виводу інформації про замовлення пвної книжки та дата її взяття
    time_t seconds = time(NULL);
    tm *timeinfo = localtime(&seconds);
    cout << "You`re offer is:" << name << " by " << author << "." << "Department:" << title << " Date of offer:"
         << asctime(timeinfo) << link << endl;

}




