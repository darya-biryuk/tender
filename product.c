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

void setProducts(struct Product newProducts[], int size)
{
    int i = 0;
    FILE* f = fopen(PRODUCTS_FILEPATH, "w");
    while(i < size)
    {
        if(productIsEmpty(newProducts[i]))
        {
            i++;
            continue;
        }
        else
        {
            fprintf(f, "\n[Product]\n");
            fprintf(f, "type=%s\n", newProducts[i].type);
            fprintf(f, "brand=%s\n", newProducts[i].brand);
            fprintf(f, "model=%s\n", newProducts[i].model);
            fprintf(f, "stats=%s\n", newProducts[i].stats);
            fprintf(f, "count=%s\n", newProducts[i].count);
            fprintf(f, "[End]\n");
        }
        i++;
    }
    fclose(f);
    getProducts();
}

void printProduct()
{
    int i = 0;
    int isEmpty = 1;
    while(i < PRODUCTS_LIST_SIZE)
    {
        if(productIsEmpty(products[i]))
        {
            i++;
            continue;
        }
        isEmpty = 0;
        printf("[Товар]\n");
        printf("Название: %s\n", products[i].type);
        printf("Бренд: %s\n", products[i].brand);
        printf("Модель: %s\n", products[i].model);
        printf("Характеристики: %s\n", products[i].stats);
        printf("Количество: %s\n", products[i].count);
        printf("\n");
        i++;
    }

    if (isEmpty)
        printf("Список пуст.\n");
}

bool productIsEmpty(struct Product product)
{
    if(strlen(product.type) == 0)
        return true;
    else
        return false;
}
