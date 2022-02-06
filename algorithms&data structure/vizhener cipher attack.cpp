// crypt2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <windows.h>
#include <iomanip>
std::string alph = "абвгдежзийклмнопрстуфхцчшщъыьэюя";

char MyToLower(char r)
{
    switch (r)
    {
    case 'А': r = 'а'; break;
    case 'Б': r = 'б'; break;
    case 'В': r = 'в'; break;
    case 'Г': r = 'г'; break;
    case 'Д': r = 'д'; break;
    case 'Е': r = 'е'; break;
    case 'Ж': r = 'ж'; break;
    case 'З': r = 'з'; break;
    case 'И': r = 'и'; break;
    case 'Й': r = 'й'; break;
    case 'К': r = 'к'; break;
    case 'Л': r = 'л'; break;
    case 'М': r = 'м'; break;
    case 'Н': r = 'н'; break;
    case 'О': r = 'о'; break;
    case 'П': r = 'п'; break;
    case 'Р': r = 'р'; break;
    case 'С': r = 'с'; break;
    case 'Т': r = 'т'; break;
    case 'У': r = 'у'; break;
    case 'Ф': r = 'ф'; break;
    case 'Х': r = 'х'; break;
    case 'Ц': r = 'ц'; break;
    case 'Ч': r = 'ч'; break;
    case 'Ш': r = 'ш'; break;
    case 'Щ': r = 'щ'; break;
    case 'Ъ': r = 'ъ'; break;
    case 'Ы': r = 'ы'; break;
    case 'Ь': r = 'ь'; break;
    case 'Э': r = 'э'; break;
    case 'Ю': r = 'ю'; break;
    case 'Я': r = 'я'; break;

    }
    return r;
}


std::string format(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= 'а' && s[i] <= 'я') && s[i] != 'ё') {
            s[i] = ' ';
        }

    }
    return s;
}

std::string probdel(std::string s) {
    int size = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            size++;
        }
    }
    char* ns = new char[size+1];
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            ns[j] = s[i];
            j++;
        }
        if (j == size) {
            break;
        }
    }
    ns[size] = '\0';
    return std::string(ns);
}

std::string encrypt(std::string s, std::string alpha, std::string key) {
    
  
    int j = 0;
    for (int i = 0; i < s.length(); i++) {


        int k = 0;
        
        for (k; k < alpha.length(); k++) {

            if (alpha[k] == key[j%key.length()]) {
                j++;
                break;
            }
        }
        int g = 0;
        for (; g < alpha.length(); g++) {
            if (alpha[g] == s[i]) {
                break;
            }

        }
        s[i] = alpha[(k + g) % alpha.length()];
    }
    
    return s;
}

std::string decrypt(std::string s, std::string alpha, std::string key) {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {


        int k = 0;

        for (k; k < alpha.length(); k++) {

            if (alpha[k] == key[j % key.length()]) {
                j++;
                break;
            }
        }
        int g = 0;
        for (; g < alpha.length(); g++) {
            if (alpha[g] == s[i]) {
                break;
            }

        }
        s[i] = alpha[(g + alpha.length() - k) % alpha.length()];
    }
    return s;
}

std::string* index(std::string s, int n, std::string alpha) {
    
        int count = s.length() / n;
        int k = n;
        double* index = new double[n];
        for (int i = 0; i < n; i++) {
            index[i] = 0;
        }
        int c = count;
        
        std::string* mass = new std::string[n];
        
        
        
        for (int i = 0; i < k; i++) {
            n = 0;
            count = c;
            while (count != 0) {
                mass[i].push_back(s[n+i]);
                n = n + k;
                count--;
              


            }
        }
       

      
        
        for (int ij = 0; ij < k; ij++) {


            
            for (int i = 0; i < alpha.length(); i++) {
                double freq = 0;
                
                for (int j = 0; j < mass[ij].length(); j++) {
                    if (alpha[i] == mass[ij][j]) {
                        freq++;
                    }
                }

                index[ij] = index[ij]+(freq * (freq - 1)) / (mass[ij].length() * (mass[ij].length() - 1));
            }

        }

        for (int z = 0; z < k; z++) {

        std::cout << mass[z] << " " << index[z] << std::endl;
        }
        double sred = 0;
        for (int z = 0; z < k; z++) {
            sred =sred+ index[z];
        }
        std::cout << "SRED:" << sred / k << std::endl;
        
        
            
            for (int f= 0; f < k; f++) {
                int* most = new int[alpha.length()];
                for (int i = 0; i < alpha.length(); i++) {
                    int count = 0;
                    for (int j = 0; j < mass[f].length(); j++) {
                        if (alpha[i] == mass[f][j]) {
                            count++;
                        }
                    }
                   
                        most[i] = count;
                    
                }
            
            int max=most[0];
            int ind=0;
            for (int i = 0; i < alpha.length(); i++) {
                if (most[i] > max) {
                    max = most[i];
                    ind = i;
                }
            }
            if (ind - alpha.find_first_of('о') < 0) {
                std::cout << alpha[(alpha.length()-ind - alpha.find_first_of('о') )% 32];
            }
            else {
                std::cout << alpha[(ind - alpha.find_first_of('о') % alpha.length() )% 32];
            }
           
        }
        return 0;
}
        
        
            
                
         
                
      
    
  
    

    



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string text;
    std::string s;
    std::ifstream in("variant.TXT");
    if (in.is_open()) {
        while (getline(in, s)) {
           text += s;
        }
        in.close();
    }
    else
    {
        std::cout << "Error open" << std::endl;
    }
    for (int i = 0; i < text.length(); i++) {
        text[i] = MyToLower(text[i]);
    }
    
    std::string key;
    std::cout << "Введіть ключ" << std::endl;
    std::cin >> key;
   std::cout <<encrypt(probdel(format(text)), alph, key) << std::endl;
    int len=key.length();
    
    std::cout << "len=" << len << std::endl;

    std::cout << "Encrypted text index" << std::endl;
 // index(encrypt(probdel(format(text)), alph, key) ,len, alph);
    len = 14;
    std::cout << "len=" << len << std::endl;
    index(probdel(format(text)), len, alph);
    

    
    
  
    
  
}


