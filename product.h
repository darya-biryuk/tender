#ifndef PRODUCT_H
#define PRODUCT_H

#define PRODUCTS_FILEPATH "../tender/data/product_list"
#define PRODUCTS_LIST_SIZE 15
#define PRODUCT_BUF_SIZE 64

#include <stdbool.h>

struct Product
{
    char type[PRODUCT_BUF_SIZE];
    char brand[PRODUCT_BUF_SIZE];
    char model[PRODUCT_BUF_SIZE];
    char stats[PRODUCT_BUF_SIZE];
    char count[PRODUCT_BUF_SIZE];
};

struct Product products[PRODUCTS_LIST_SIZE];
void printProduct();
void getProducts();
void setProducts(struct Product products[], int size);
void getField(char* buff, char* result[]);
bool productIsEmpty(struct Product product);

#endif // PRODUCT_H
