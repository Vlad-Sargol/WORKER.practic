#include "Worker.h"
#include <iostream>
using namespace std;

// конструктор по умолчанию: заполняет поля заглушками
WORKER::WORKER() {
    fio = "Не указано";
    post = "Не указана";
    salary = 0;
    year = 2026;
}

// конструктор с параметрами (принимает все данные сразу)
WORKER::WORKER(string f, string p, double s, int y) {
    fio = f;
    post = p;
    salary = s;
    year = y;
}

// конструктор с одним параметром (остальные поля берёт по умолчанию)
WORKER::WORKER(string f) {
    fio = f;
    post = "Преподаватель";
    salary = 50000;
    year = 2020;
}

// деструктор
WORKER::~WORKER() {
}

// метод изменения полей
void WORKER::set(string f, string p, double s, int y) {
    fio = f;
    post = p;
    salary = s;
    year = y;
}

// метод вывода данных на экран
void WORKER::show() {
    cout << fio << "  |  " << post << "  |  " << salary << " руб.  |  " << year << endl;
}

// стаж = текущий год минус год приёма
int WORKER::experience(int currentYear) {
    return currentYear - year;
}

string WORKER::getFio() {
    return fio;
}

int WORKER::getYear() {
    return year;
}