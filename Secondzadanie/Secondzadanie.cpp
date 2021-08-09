
# include <iostream>
# include <windows.h>
# include <cmath>
# include <iomanip>
using namespace std;

// Определяем число PI в виде константы

const double PI = 3.141592653589793238463;

// Фукнция вычисления факториала. Рекурсивный метод

int factorial(int n) {
    if (n < 0) return -1;
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

// Функция D(X,A) построенная по условию задачи.

double D(double x, double a, int K) {

    //double PI = atan(1) * 4;
    double sum = 0;

    for (int n = 1; n <= K; n++) {
        sum += pow(x, n) * sin(a + PI * n / 2.0) / factorial(n);
    }
    return sin(a) + sum;
}

int main()
{
    //настройки консоли для работы с кириллицей

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Условие задания

    cout << "Функция sin(x+a) может быть разложена в ряд\n\n        D(x,a) = sin(a) + Сумма sin(a + PI * n / 2)/n!\n\nгде:\n n меняется от 1 до K.\n K - конечное целое число\n a = 3*PI/7\n\nПостроить таблицу этой функции для x принадлежит отрезку [2*PI/3, PI] с шагом PI/10\nпо точной формуле и по разложению в ряд для K>10.\n\n";

    // Определяем число K
    
    int K;
    
    // Определяем число a по условию задачи

    double a = 3.0 * PI / 7.0;


    /*ввод числа K по условию. В цикле do while проводится проверка введённого значения на соответствие условиям.
    пока K меньше 10-ти программа говорит нам что мы ошиблись и цикл снова просит ввести новое значение для K
    условием выхода из цикла является правильно введённая переменная.
    */

    do {
        cout << "Введите число K>10: "; cin >> K;
        if (K < 10) cout << "\nЧисло меньше 10, попробуйте снова\n";
    } while (K < 10);

    // Построение первой строки таблицы с заданной шириной строк через setw.

    cout << left
        << setw(15) << "x"
        << left
        << setw(15) << "sin(x + a)"
        << left
        << setw(15) << "D(x, a, K)"
        << endl;

    // Построение через цикл всех остальных строк таблицы.

    for (double x = 2.0 * PI / 3.0; x <= PI; x += PI / 10.0) {
        cout << left
            << setw(15) << x
            << left
            << setw(15) << sin(x + a)
            << left
            << setw(15) << D(x, a, K)
            << endl;
    }

    system("pause");
    return 0;
}

