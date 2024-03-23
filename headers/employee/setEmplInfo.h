#ifndef SETEMPLINFO_H
#define SETEMPLINFO_H

typedef void (*ptrSetEmpl)(Employee&, char*);

void setFirstName(Employee& empl, char* value) {
    strcpy(empl.empData.firstName, value);
}
ptrSetEmpl ptrSetEmplFirstName = setFirstName;

void setLastName(Employee& empl, char* value) {
    strcpy(empl.empData.lastName, value);
}
ptrSetEmpl ptrSetEmplLastName = setLastName;

void setPatronymic(Employee& empl, char* value) {
    strcpy(empl.empData.patronymic, value);
}
ptrSetEmpl ptrSetEmplPatronymic = setPatronymic;

void setPosition(Employee& empl, char* value) {
    strcpy(empl.position, value);
}
ptrSetEmpl ptrSetEmplPosition = setPosition;

void setPhoneNumber(Employee& empl, char* value) {
    strcpy(empl.phoneNumber, value);
}
ptrSetEmpl ptrSetEmplPhone = setPhoneNumber;

void setEmail(Employee& empl, char* value) {
    strcpy(empl.email, value);
}
ptrSetEmpl ptrSetEmplEmail = setEmail;
#endif
