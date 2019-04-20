#include "adminmenu.h"
#include <stdio.h>
#include "applicant.h"
#include "product.h"

void adminMenu()
{
    int er;
    getProducts();
    getApplicants();
    while(1)
    {
        adminHelp();
        scanf("%d", &er);
        switch(er)
        {
        case 1:
            addRecord();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printApplicant(applicants, APPLICANTS_LIST_SIZE);
            break;
        case 5:
            printProduct();
            break;
        case 6:
            search();
            break;
        case 7:
            sort();
            break;
        case 8:
            break;
        case 9:
            getProducts();
            getApplicants();
            break;
        case 10:
            fflush(stdin);
            getchar();
            return;
        default:
            printf("Wrong choice/n");
        }
    }
}

void adminHelp()
{
    printf("1.Enter new record\n");
    printf("2.Edit record\n");
    printf("3.Delete record\n");
    printf("4.Print applicants\n");
    printf("5.Print products\n");
    printf("6.Search\n");
    printf("7.Sort\n");
    printf("8.User managment\n");
    printf("9.Обновить списки данных\n");
    printf("10.Exit\n");
}

void addProduct()
{
    struct Product newProduct;
    printf("Введите название организации\n");
    fgets(newProduct.type, sizeof(newProduct.type), stdin);
    printf("Введите электронную почту\n");
    fgets(newProduct.brand, sizeof(newProduct.brand), stdin);
    printf("Введите телефон\n");
    fgets(newProduct.model, sizeof(newProduct.model), stdin);
    printf("Введите предлагаемую стоимость\n");
    fgets(newProduct.stats, sizeof(newProduct.stats), stdin);
    printf("Введите дату доставки\n");
    fgets(newProduct.count, sizeof(newProduct.count), stdin);

    FILE* f = fopen(APPLICANT_FILEPATH, "at");
    fprintf(f, "\n[Applicant]\n");
    fprintf(f, "name=%s", newApplicant.name);
    fprintf(f, "email=%s", newApplicant.email);
    fprintf(f, "phone=%s", newApplicant.phone);
    fprintf(f, "price=%s", newApplicant.price);
    fprintf(f, "date=%s", newApplicant.delivery_date);
    fprintf(f, "remark=%s", newApplicant.remark);
    fprintf(f, "country=%s", newApplicant.addr.country);
    fprintf(f, "city=%s", newApplicant.addr.city);
    fprintf(f, "street=%s", newApplicant.addr.street);
    fprintf(f, "[End]\n");
    fclose(f);
    getApplicants();
    return;
}

void addApplicant()
{
    struct Applicant newApplicant;
    printf("Введите название организации\n");
    fgets(newApplicant.name, 20, stdin);
    printf("Введите электронную почту\n");
    fgets(newApplicant.email, 20, stdin);
    printf("Введите телефон\n");
    fgets(newApplicant.phone, 20, stdin);
    printf("Введите предлагаемую стоимость\n");
    fgets(newApplicant.price, 20, stdin);
    printf("Введите дату доставки\n");
    fgets(newApplicant.delivery_date, 20, stdin);
    printf("Введите страну\n");
    fgets(newApplicant.addr.country, 15, stdin);
    printf("Введите город\n");
    fgets(newApplicant.addr.city, 15, stdin);
    printf("Введите улицу\n");
    fgets(newApplicant.addr.street, 15, stdin);
    printf("Введите дополнительные сведения\n");
    fgets(newApplicant.remark, 100, stdin);

    FILE* f = fopen(APPLICANT_FILEPATH, "at");
    fprintf(f, "\n[Applicant]\n");
    fprintf(f, "name=%s", newApplicant.name);
    fprintf(f, "email=%s", newApplicant.email);
    fprintf(f, "phone=%s", newApplicant.phone);
    fprintf(f, "price=%s", newApplicant.price);
    fprintf(f, "date=%s", newApplicant.delivery_date);
    fprintf(f, "remark=%s", newApplicant.remark);
    fprintf(f, "country=%s", newApplicant.addr.country);
    fprintf(f, "city=%s", newApplicant.addr.city);
    fprintf(f, "street=%s", newApplicant.addr.street);
    fprintf(f, "[End]\n");
    fclose(f);
    getApplicants();
    return;
}

void addRecord()
{
    int ch;
    while(1)
    {
        printf("Выберите параметр для добавления\n");
        printf("1.Добавить участника тендера\n");
        printf("2.Добавить продукт\n");
        printf("3.Прекратить добавление\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            fflush(stdin);
            getchar();
            addApplicant();
            break;
        case 2:
            //addProduct();
            break;
        case 3:
            return;
        default:
            printf("Неверный выбор\n");
        }
    }
}
