#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    string name;
    int price;

    Item(const string& name, int price) : name(name), price(price) {}

    int bonus(int n) const {
        return price * n / 100;
    }
};

void printVector(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << item.name << " (" << item.price << " - RUB)\n";
    }
    cout << endl;
}

int main() {
    Item apples("Яблоки", 200);
    Item milk("Молоко", 120);
    Item candy("Конфеты", 300);
    Item butter("Масло", 500);
    Item nuts("Орехи", 1000);
    Item sausage("Колбаса", 350);
    Item mustard("Горчица", 45);
    Item bread("Хлеб", 50);
    Item tea("Чай", 100);
    Item cake("Торт", 650);

    vector<Item> items = {apples, milk, candy, butter, nuts, sausage, mustard, bread, tea, cake};

    cout << "All possible permutations of the vector items:\n";

    int maxBonus = 0;
    vector<Item> bestOrder;

//     sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
//         return a.price > b.price;
//     });

//     do {
//         // cout << "Current permutation:\n";
//         // printVector(items); 
//         int totalBonus = 0;
//         for (const auto& item : items) {
//             totalBonus += item.bonus(3);
//         }
//         if (totalBonus > maxBonus) {
//             maxBonus = totalBonus;
//             bestOrder = items;
//         }
//     } while (next_permutation(items.begin(), items.end(), [](const Item& a, const Item& b) {
//         return a.price > b.price;
//     }));

//     cout << "\nMost profitable order with full use of bonuses:\n";
//     printVector(bestOrder);
//     cout << "Total Bonus: " << maxBonus << " - RUB\n";

//     return 0;
// }
    vector<int> indices(items.size());

    for (int i = 0; i < items.size(); ++i) {
        indices[i] = i;
    }

    while (next_permutation(indices.begin(), indices.end())) {
        // printVector(items);
        int totalBonus = 0;
        vector<Item> currentOrder;
        for (int i = 0; i < items.size(); ++i) {
            totalBonus += items[indices[i]].bonus(3);
            currentOrder.push_back(items[indices[i]]);
        }
        if (totalBonus > maxBonus) {
            maxBonus = totalBonus;
            bestOrder = currentOrder;
        }
    }

    cout << "\nMost profitable order with full use of bonuses:\n";
    printVector(bestOrder);
    cout << "Total Bonus: " << maxBonus << " - RUB\n";

    return 0;
}
