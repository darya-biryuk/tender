#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "usermenu.h"
#include "applicant.h"
#include "product.h"
#include "user.h"

void adminMenu();
void adminHelp();
void addRecord();
void addApplicant();
void addProduct();
void addUser();
void removeRecord();
void removeApplicant();
void removeProduct();
void removeUser();
void editRecord();
void editApplicant();
void editProduct();
void editUser();
void manageUsers();
void setApplicants(struct Applicant newApplicants[], int size);
void setProducts(struct Product products[], int size);
void removeAllApplicants();
void removeAllProducts();
void setUsers(struct User newUsers[], int size);
void removeUsers();
void removeAllUsers();

#endif // ADMINMENU_H
