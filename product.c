#include "product.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"

void getProducts()
{
    int i = 0;

    FILE* fd = fopen(PRODUCTS_FILEPATH, "r");
    char buff[256];
    while(fgets(buff, 256, fd) != NULL)
    {
        if(strcmp(buff, "[Product]\n") == 0)
        {
            struct Product product;
            while(fgets(buff,256,fd) != NULL)
            {
                char* result[2];
                getField(buff, result);
                if(strcmp(result[0],"type") == 0)
                {
                    strcpy(product.type, result[1]);
                }
                else if(strcmp(result[0],"model") == 0)
                {
                    strcpy(product.model, result[1]);
                }
                else if(strcmp(result[0],"brand") == 0)
                {
                    strcpy(product.brand, result[1]);
                }
                else if(strcmp(result[0],"stats") == 0)
                {
                    strcpy(product.stats, result[1]);
                }
                else if(strcmp(result[0],"count") == 0)
                {
                    strcpy(product.count, result[1]);
                }

                if(strcmp(buff,"[End]\n") == 0)
                    break;
            }
            if (i >= PRODUCTS_LIST_SIZE)
                break;
            products[i++] = product;
        }
    }
    fclose(fd);
}

void printProduct()
{
    int i = 0;
    while(i < PRODUCTS_LIST_SIZE)
    {
        if(productIsEmpty(products[i]))
        {
            i++;
            continue;
        }
        printf("type %s\n", products[i].type);
        printf("brand %s\n", products[i].brand);
        printf("model %s\n", products[i].model);
        printf("stats %s\n", products[i].stats);
        printf("count %s\n", products[i].count);
        i++;
    }
}

bool productIsEmpty(struct Product product)
{
    if(strlen(product.type) == 0)
        return true;
    else
        return false;
}
