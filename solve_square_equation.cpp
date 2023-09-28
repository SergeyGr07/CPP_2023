#include <iostream>
#include <cmath>

using namespace std;

void solve_square_equation(float a, float b, float c) {
    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {

        float root_1 = (-b + sqrt(discriminant)) / (2 * a);
        float root_2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Два корня: x1 = " << root_1 << ", x2 = " << root_2 << endl;
    } else if (discriminant == 0) {

        float root = -b / (2 * a);
        cout << "Один корень: x = " << root << endl;
    } else {

        cout << "Нет корней" << endl;
    }
}

int main() {
    float a, b, c;
    cout << "Введите коэффициенты a, b и c: ";
    cin >> a >> b >> c;

    solve_square_equation(a, b, c);

    return 0;
}
