#ifndef PRODUCT_H
#define PRODUCT_H

#define PRODUCTS_FILEPATH "../tender/data/product_list"
#define PRODUCTS_LIST_SIZE 15

#include <stdbool.h>

struct Product
{
    char type[10];
    char brand[15];
    char model[10];
    char stats[100];    
    char count[100];
};

struct Product products[PRODUCTS_LIST_SIZE];
void printProduct();
void getProducts();
void getField(char* buff, char* result[]);
bool productIsEmpty(struct Product product);

#endif // PRODUCT_H
