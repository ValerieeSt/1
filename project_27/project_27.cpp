#include <iostream>
#include <vector>


namespace GlobalVars
{
    double a; // Начальное значение t
    double b;  // Конечное значение t
    double h;  // Шаг
    double y0; // Начальное условие y(a)

    double t;
}

void InputVars()
{
    std::cout << "Enter a: ";
    std::cin >> GlobalVars::a;
    std::cout << "Enter b: ";
    std::cin >> GlobalVars::b;
    std::cout << "Enter h: ";
    std::cin >> GlobalVars::h;
    std::cout << "Enter y0: ";
    std::cin >> GlobalVars::y0;
}

// Функция, описывающая правую часть дифференциального уравнения
double f(double t, double y) {
    // Пример: дифференциальное уравнение y' = -2ty
    return -2 * t * y;
}

// Реализация явной схемы Эйлера (явной схемы 1-го порядка) для решения задачи Коши
std::vector<double> EulerMethod(double a, double b, double h, double y0) {
    int n = (b - a) / h; // Количество шагов
    std::vector<double> y(n + 1); // Вектор значений y
    y[0] = y0; // Начальное условие

    double t = a;
    for (int i = 0; i < n; ++i) {
        double dydt = f(t, y[i]);
        y[i + 1] = y[i] + h * dydt;
        t += h;
    }

    return y;
}

void printResult(std::vector<double> sol)
{
    std::cout << "t\ty" << std::endl;
    GlobalVars::t = GlobalVars::a;

    for (int i = 0; i < sol.size(); ++i) {
        std::cout << GlobalVars::t << "\t" << sol[i] << std::endl;
        GlobalVars::t += GlobalVars::h;
    }
}

int main() {

    InputVars();

    printResult(EulerMethod(GlobalVars::a, GlobalVars::b, GlobalVars::h, GlobalVars::y0));

    return 0;
}
