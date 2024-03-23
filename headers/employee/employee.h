#ifndef EMPL
#define EMPL
#include "cstring"

Employee createEmployee()
{
    cin.ignore(INT_MAX, '\n');
    cout << endl;
    Employee empl;
    cout << "Для добавления сотрудника необходимо ввести" << endl;

    cout << "Фамилия: ";
    setString(empl, ptrSetEmplLastName);

    cout << "Имя: ";
    setString(empl, ptrSetEmplFirstName);

    cout << "Отчество: ";
    setString(empl, ptrSetEmplPatronymic);

    cout << "Должность: ";
    setString(empl, ptrSetEmplPosition);

    cout << "Номер телефона (000-000-0000): ";
    setString(empl, ptrSetEmplPhone, ptrValidEpmlPhone);

    cout << "Email: ";
    setString(empl, ptrSetEmplEmail, ptrValidEpmlEmail);

    return empl;
}

void printEmployee(Employee empl)
{
    cout << "Ф.И.О: " << empl.empData.lastName << " " <<  empl.empData.firstName << " " << empl.empData.patronymic << endl;
    cout << "Должность: " << empl.position << endl;
    cout << "Номер телефона: " << empl.phoneNumber << endl;
    cout << "Email: " << empl.email << endl;
    cout << endl;
}
void (*ptrPrintEmployee)(Employee) = printEmployee;
#endif
