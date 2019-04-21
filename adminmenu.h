#ifndef ADMINMENU_H
#define ADMINMENU_H

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

#endif // ADMINMENU_H
