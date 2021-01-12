// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>;
#include <iomanip>;

using namespace std;

template <class T> //объявление шаблона

class Equation {

public:
    T a, b, c; //объявление переменных с обобщенным типом данных

    Equation(T _a, T _b, T _c) { //конструктор с параметрами

        a = _a; //инициализация начальных значений объекта класса
        b = _b;
        c = _c;
    }
    void print() {
        cout << a << "x^2";
        if (b < 0) {
            cout << b << "x";

        }
        else {
            cout << "+" << b << "x";

        }

        if (c < 0) {

            cout << c;

        }
        else {

            cout << "+" << c;

        }
        cout << endl;
    }
    void operator*=(T x) {
        a *= x;
        b *= x;
        c *= x;
    }
    Equation<T> operator-(T x) {
        Equation<T> result(a - x, b - x, c - x);
        return result;
    }
    T Disc() {


        return (b * b - 4 * a * c);
    }

    T* getX() {
        T d = Disc();
        if (d < 0) {
            return NULL;
        }
        if (a != 0) {
            if (d == 0) {
                return ValueToMass(-b / (2 * a));
            }
            else {
                T x1 = ((-b + sqrt(d)) / (2 * a));
                T x2 = ((-b - sqrt(d)) / (2 * a));

                T* result = new T[2];
                result[0] = x1;
                result[1] = x2;
                return result;
            }
        }
        else if (b != 0) {
           return ValueToMass(-c / b); //вспомогательная ф-ция для создания массива из 1-го элемента
        }
        else {
            return NULL;
        }
    }
    int getResultCount() { //получение количества ответов
        T d = Disc();
        if (d == 0) {
            return 1;
        }
        else if (d > 0) {
            return 2;
        }
        else {
            return 0;
        }
    }
    void printResult() { //вывод на экран решений
        T* result = getX();
        int size = getResultCount();
        if (size == 0) {
            cout << "NO RESULT!" << endl;
        }
        else if (size == 1) {
            cout << "x = " << result[0];
        }
        else if (size == 2) {
            cout << "x1 = " << result[0] << endl;
            cout << "x2 = " << result[1] << endl;
        }
    }
private:
    T* ValueToMass(T v) {
        T* result = new T[1];
        result[0] = v;
        return result;
    }
};

int main()
{
    Equation<int> equation(-1, 2, 5); //объявление уравнения

    equation.print(); //вывод на экран уравнения

    equation.printResult(); //вывод решения

    equation *= 5;
    equation.print();
    equation = equation - 3;
    equation.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
