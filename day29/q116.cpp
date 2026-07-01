//wap to create inventory management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Item {
private:
    int id;
    std::string name;
    int quantity;
    double price;

public:
    Item(int item_id, std::string item_name, int qty, double prc) 
        : id(item_id), name(item_name), quantity(qty), price(prc) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Setters
    void setQuantity(int qty) { quantity = qty; }
    void setPrice(double prc) { price = prc; }

    // Display formatted item details
    void display() const {
        std::cout << std::setw(10) << id 
                  << std::setw(20) << name 
                  << std::setw(15) << quantity 
                  << std::setw(12) << std::fixed << std::setprecision(2) << price << "\n";
    }
};

class Inventory {
private:
    std::vector<Item> items;

public:
    // Add item to inventory
    void addItem() {
        int id, qty;
        std::string name;
        double price;

        std::cout << "\nEnter Product ID: ";
        std::cin >> id;
        
        // Check if ID already exists
        for (const auto& item : items) {
            if (item.getId() == id) {
                std::cout << "Error: Product ID already exists!\n";
                return;
            }
        }

        std::cout << "Enter Product Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Quantity: ";
        std::cin >> qty;
        std::cout << "Enter Price: ";
        std::cin >> price;

        items.push_back(Item(id, name, qty, price));
        std::cout << "Product added successfully!\n";
    }

    // View all inventory items
    void viewInventory() const {
        if (items.empty()) {
            std::cout << "\nInventory is empty.\n";
            return;
        }

        std::cout << "\n------------------------------------------------------------\n";
        std::cout << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(15) << "Quantity" << std::setw(12) << "Price ($)" << "\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& item : items) {
            item.display();
        }
        std::cout << "------------------------------------------------------------\n";
    }

    // Search item by ID
    void searchItem() const {
        int id;
        std::cout << "\nEnter Product ID to search: ";
        std::cin >> id;

        for (const auto& item : items) {
            if (item.getId() == id) {
                std::cout << "\nProduct Found:\n";
                item.display();
                return;
            }
        }
        std::cout << "Product not found.\n";
    }

    // Update quantity and price
    void updateItem() {
        int id;
        std::cout << "\nEnter Product ID to update: ";
        std::cin >> id;

        for (auto& item : items) {
            if (item.getId() == id) {
                int new_qty;
                double new_price;
                std::cout << "Current Quantity: " << item.getQuantity() << " | Enter New Quantity: ";
                std::cin >> new_qty;
                std::cout << "Current Price: " << item.getPrice() << " | Enter New Price: ";
                std::cin >> new_price;

                item.setQuantity(new_qty);
                item.setPrice(new_price);
                std::cout << "Product updated successfully!\n";
                return;
            }
        }
        std::cout << "Product not found.\n";
    }

    // Delete item from inventory
    void deleteItem() {
        int id;
        std::cout << "\nEnter Product ID to delete: ";
        std::cin >> id;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                items.erase(it);
                std::cout << "Product deleted successfully!\n";
                return;
            }
        }
        std::cout << "Product not found.\n";
    }
};

int main() {
    Inventory inv;
    int choice;

    do {
        std::cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Add New Item\n";
        std::cout << "2. View All Items\n";
        std::cout << "3. Search Item by ID\n";
        std::cout << "4. Update Item Stock/Price\n";
        std::cout << "5. Delete Item\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1: inv.addItem(); break;
            case 2: inv.viewInventory(); break;
            case 3: inv.searchItem(); break;
            case 4: inv.updateItem(); break;
            case 5: inv.deleteItem(); break;
            case 6: std::cout << "\nExiting system. Goodbye!\n"; break;
            default: std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
