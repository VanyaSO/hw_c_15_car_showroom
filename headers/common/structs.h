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

struct Car
{
    char manufacturer[SIZE_STR];
    int yearGraduation;
    char model[SIZE_STR];
    double price;
    double potentialSalePrice;
    char vinCode[SIZE_STR];
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
    Car car;
    Date data;
    double realSalePrice;
};


#endif
