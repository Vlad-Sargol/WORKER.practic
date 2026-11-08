#include "Worker.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    const int CURRENT_YEAR = 2026; // условный текущий год
    int n;

    cout << "Введите количество работников: ";
    cin >> n;

    // динамический массив объектов класса
    WORKER* staff = new WORKER[n];

    // ввод данных с клавиатуры
    cin.ignore(); // убирает "хвост" Enter после ввода n
    for (int i = 0; i < n; i++) {
        string fio, post;
        double salary;
        int year;

        cout << "\n--- Работник №" << i + 1 << " ---" << endl;
        cout << "Фамилия и инициалы: ";
        getline(cin, fio);
        cout << "Должность: ";
        getline(cin, post);
        cout << "Зарплата: ";
        cin >> salary;
        cout << "Год поступления на работу: ";
        cin >> year;
        cin.ignore();

        staff[i].set(fio, post, salary, year);
    }

    // вывод всех работников
    cout << "\nСписок работников:" << endl;
    for (int i = 0; i < n; i++) {
        staff[i].show();
    }

    // запрос стажа и поиск
    int stazh;
    cout << "\nВведите значение стажа (лет): ";
    cin >> stazh;

    bool found = false; // флаг: нашли ли хоть кого-то
    cout << "\nРаботники со стажем более " << stazh << " лет:" << endl;
    for (int i = 0; i < n; i++) {
        if (staff[i].experience(CURRENT_YEAR) > stazh) {
            cout << staff[i].getFio() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Таких работников нет." << endl;
    }

    // освобождение памяти динамического массива (вызываются деструкторы)
    delete[] staff;

    return 0;
}