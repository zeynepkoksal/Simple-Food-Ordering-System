// food_ordering.h
// ZEYNEP KÖKSAL
// 22244710063

#ifndef FOOD_ORDERING_H
#define FOOD_ORDERING_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct FoodItem {
    string name;
    double price;
    bool available;
    FoodItem* next;
    
    FoodItem(string n, double p, bool a) {
        name = n;
        price = p;
        available = a;
        next = nullptr;
    }
};

struct Category {
    string name;
    FoodItem* head;
    
    Category(string n) {
        name = n;
        head = nullptr;
    }
    
    void addFoodItem(string itemName, double itemPrice, bool itemAvailable) {
        FoodItem* newItem = new FoodItem(itemName, itemPrice, itemAvailable);
        if (head == nullptr) {
            head = newItem;
        } else {
            FoodItem* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
    }
    
    void displayMenu() {
        cout << "Category: " << name << endl;
        FoodItem* temp = head;
        while (temp != nullptr) {
            cout << "- " << temp->name << " ($" << temp->price << ") [";
            cout << (temp->available ? "Available" : "Not Available") << "]" << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif

