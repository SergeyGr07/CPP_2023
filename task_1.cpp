#include <iostream>
#include <cmath> // Включаем библиотеку для математических функций

double calculatePolygonArea(double sideLength, int numberOfSides) {
    if (numberOfSides < 3) {
        std::cout << "Ошибка: N-угольник должен иметь минимум 3 стороны." << std::endl;
        return 0.0;
    }

    double apothem = sideLength / (2 * tan(M_PI / numberOfSides));
    double area = (numberOfSides * sideLength * apothem) / 2;
    return area;
}

int main() {
    double sideLength;
    int numberOfSides;

    std::cout << "Введите длину стороны (A): ";
    std::cin >> sideLength;

    std::cout << "Введите количество сторон (N): ";
    std::cin >> numberOfSides;

    double polygonArea = calculatePolygonArea(sideLength, numberOfSides);

    std::cout << "Площадь N-угольника: " << polygonArea << std::endl;

    return 0;
}

