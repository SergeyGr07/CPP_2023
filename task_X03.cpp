#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    Item(const string& name, int price) : name(name), price(price) {}
    string getName() const { return name; }
    int getPrice() const { return price; }
    int bonus(int n) const { return price * n / 100; }

private:
    string name;
    int price;
};

int main() {
    vector<Item> items = {
        Item("яблоки", 200),
        Item("молоко", 120),
        Item("конфеты", 300),
        Item("масло", 500),
        Item("орехи", 1000),
        Item("колбаса", 350),
        Item("горчица", 45),
        Item("хлеб", 50),
        Item("чай", 100),
        Item("торт", 650)
    };

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.bonus(3) > b.bonus(3);
    });

    int totalBonus = 0;
    int remainingBonus = 0;
    vector<Item> bestOrder;

    for (const Item& item : items) {
        int itemPrice = item.getPrice();

        if (remainingBonus >= itemPrice) {
            remainingBonus -= itemPrice;
        } else {
            totalBonus += item.bonus(3);
            remainingBonus = item.bonus(3) - itemPrice;
        }

        bestOrder.push_back(item);
    }

    cout << "Самый выгодный порядок покупки (с остатком бонусов):" << endl;
    for (const Item& item : bestOrder) {
        cout << item.getName() << " - " << item.getPrice() << " рублей" << endl;
    }
    cout << "Итого начислено бонусов: " << totalBonus << " рублей" << endl;

    totalBonus = 0;
    remainingBonus = 0;
    bestOrder.clear();

    for (const Item& item : items) {
        int itemPrice = item.getPrice();
        totalBonus += itemPrice;
        bestOrder.push_back(item);
    }

    cout << "\nСамый выгодный порядок покупки (с полным использованием бонусов):" << endl;
    for (const Item& item : bestOrder) {
        cout << item.getName() << " - " << item.getPrice() << " рублей" << endl;
    }
    cout << "Итого начислено бонусов: " << totalBonus * 0.03 << " рублей" << endl;

    return 0;
}
