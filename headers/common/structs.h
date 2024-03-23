#ifndef STRUCTS
#define STRUCTS

struct EmployeeData
{
    char lastName[SIZE_STR];
    char firstName[SIZE_STR];
    char patronymic[SIZE_STR];
};

struct Employee
{
    EmployeeData empData;
    char position[SIZE_STR];
    char phoneNumber[SIZE_STR];
    char email[SIZE_STR];
};

struct CarData
{
    char manufacturer[SIZE_STR];
    char model[SIZE_STR];
    char vinCode[SIZE_STR];
};

struct Car
{
    CarData carData;
    int yearGraduation;
    double price;
    double potentialSalePrice;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Sale
{
    EmployeeData empData;
    CarData carData;
    Date data;
    double realSalePrice;
    double margin;
    int id;
};


#endif
