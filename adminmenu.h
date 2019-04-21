#ifndef ADMINMENU_H
#define ADMINMENU_H

#define NO_LETTERS 0x1
#define NO_SYMBOLS 0x2
#define NO_NUMBERS 0x4
#define DATE 0x8

#include "usermenu.h"
#include "applicant.h"
#include "product.h"
#include "user.h"

void adminMenu();
void adminHelp();

void addRecord();
void editRecord();
void removeRecord();

void manageUsers();
void addUser();
void editUser();
void removeUser();

void addApplicant();
void editApplicant();
void removeApplicant();
void removeAllApplicants();

void addProduct();
void editProduct();
void removeProduct();
void removeAllProducts();

void enterField(const char* message, char* field, int size, int flags);
int checkNoLetters(char str1[]);
int checkNoNumbers(char str1[]);

#endif // ADMINMENU_H
