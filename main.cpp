#include<iostream>
#include <cmath>
#include <string>       
#include <windows.h>
#include <winuser.h>                                                     
#include <conio.h>  
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

#define ABC     27
//#define ABC     26

string abeceda = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

class TText {
public:
    int pocet = 0;
};

class TPismeno : public TText{
public:
    double pocetProcent;
    char znak;
};

TText text;
TPismeno pismeno[ABC];

void Prirazeni() {
    for (int i = 0; i < ABC; i++) {
        pismeno[i].znak = abeceda.at(i);
    }
    
}

int main()
{
    Prirazeni();
    string mujText;
    double jednoPR;

    getline(cin, mujText);
    cout << "\n\n";
    transform(mujText.begin(), mujText.end(), mujText.begin(), ::toupper);

    for (int k = 0; k < ABC; k++) {
        for (int i = 0; i < mujText.length(); i++) {
            if (mujText.at(i) == abeceda.at(k)) {
                if (pismeno[k].znak == abeceda.at(k)) {
                    pismeno[k].pocet++;
                }
            }
            
        }
    }
    
    text.pocet = mujText.length();

    jednoPR = 100.0 / text.pocet;

    for (int i = 0; i < ABC; i++) {
        pismeno[i].pocetProcent = jednoPR * (double)pismeno[i].pocet;
    }
    

    double sum = 0;
    for (int i = 0; i < ABC; i++) {
        sum += pismeno[i].pocetProcent;
    }


    cout << endl;
    for (int i = 0; i < ABC; i++) {
        cout << pismeno[i].znak << "   " << pismeno[i].pocetProcent << " %" << endl;
    }

    return 0;
}