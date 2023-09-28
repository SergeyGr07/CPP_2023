#include <iostream>
#include <cmath> 

using namespace std;

float calculate_polygon_square(float side_len, int sides_number) {
    if (sides_number < 3) {
        cout << "Ошибка: N-угольник должен иметь минимум 3 стороны." << endl;
        return 0.0;
    }

    float apothem = side_len / (2 * tan(M_PI / sides_number));
    float square = (sides_number * side_len * apothem) / 2;
    return square;
}

int main() {
    setlocale(LC_ALL, "RU");
    float side_len;
    int sides_number;

    cout << "Введите длину стороны (A): ";
    cin >> side_len;

    cout << "Введите количество сторон (N): ";
    cin >> sides_number;

    float polygon_square = calculate_polygon_square(side_len, sides_number);

    cout << "Площадь N-угольника: " << polygon_square << endl;

    return 0;
}

