#include "structs.h"

Employee emp1 = {"Иванов", "Алексей", "Петрович", "Продавец автомобилей", "095-123-4567", "ivanov.alex@gmail.com"};
Employee emp2 = {"Петров", "Сергей", "Александрович", "Менеджер по продажам", "067-987-6543", "petrov.sergey@gmail.com"};

Car car1 = {"Audi", "A4", "F3487", 2023, 45000.0, 48000.0};
Car car2 = {"BMW",  "X5", "A1447", 2022, 60000.0, 65000.0};

Sale sale1 = {
        {"Иванов", "Алексей", "Петрович"}, // Информация о сотруднике
        {"Audi", "A4", "F3487"}, // Информация о машине
        {19, 3, 2024},
        47000.0,
        2000,// Реальная цена продажи
        1
};
Sale sale2 = {
        "Петров", "Сергей", "Александрович", // Информация о сотруднике
        "BMW", "X5", "A1447", // Информация о машине
        {25, 5, 2024},
        62000.0,
        2000,// Реальная цена продажи
        2
};


// собираем в массивы
const int sizeStaticArr = 2;
Employee staticArrEpl[sizeStaticArr] = {
    emp1, emp2
};

Car staticArrCar[sizeStaticArr] = {
        car1, car2
};

Sale staticArrSales[sizeStaticArr] = {
        sale1, sale2
};
