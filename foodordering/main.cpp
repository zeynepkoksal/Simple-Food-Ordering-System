// main.cpp
// ZEYNEP KÖKSAL
// 22244710063

#include "food_ordering.h"

int main() {
    Category appetizers("Appetizers");
    Category mainCourse("Main Course");
    Category desserts("Desserts");
    
    ifstream file("menu.txt");
    if (!file) {
        cerr << "Error: Could not open menu.txt" << endl;
        return 1;
    }
    
    string category, name;
    double price;
    int available;
    
    while (file >> category >> name >> price >> available) {
        if (category == "Appetizers") {
            appetizers.addFoodItem(name, price, available);
        } else if (category == "MainCourse") {
            mainCourse.addFoodItem(name, price, available);
        } else if (category == "Dessert") {
            desserts.addFoodItem(name, price, available);
        }
    }
    file.close();
    
    appetizers.displayMenu();
    mainCourse.displayMenu();
    desserts.displayMenu();
    
    return 0;
}

