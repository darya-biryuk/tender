#ifndef PRODUCT_H
#define PRODUCT_H

#define PRODUCTS_FILEPATH "/home/darya/projects/tender/data/product_list"

struct Product
{
    char type[10];
    char brand[15];
    char model[10];
    char stats[100];
    int count;
};

#endif // PRODUCT_H
