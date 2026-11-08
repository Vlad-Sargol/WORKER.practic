#ifndef WORKER_H
#define WORKER_H

#include <string>
using namespace std;

class WORKER {
private:
    string fio;     // фамилия и инициалы
    string post;    // должность
    double salary;  // зарплата
    int year;       // год поступления на работу

public:
    WORKER();                                     // конструктор по умолчанию
    WORKER(string f, string p, double s, int y);  // конструктор с параметрами
    WORKER(string f);                             // конструктор с одним параметром
    ~WORKER();                                    // деструктор

    void set(string f, string p, double s, int y); // изменить все поля
    void show();                                   // вывести данные на экран
    int experience(int currentYear);               // посчитать стаж
    string getFio();                               // вернуть фамилию
    int getYear();                                 // вернуть год приёма
};

#endif