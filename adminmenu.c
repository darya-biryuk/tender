#include "adminmenu.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "product.h"
#include "user.h"

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
            editRecord();
            break;
        case 3:
            removeRecord();
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
            manageUsers();
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

void addUser()
{
    struct User newUser;
    printf("Введите имя пользователя\n");
    fgets(newUser.login, sizeof(newUser.login), stdin);
    printf("Введите пароль пользователя\n");
    fgets(newUser.password, sizeof(newUser.password), stdin);

    FILE* f = fopen(SHADOW_FILEPATH, "at");
    fprintf(f, "\n[User]\n");
    fprintf(f, "name=%s", newUser.login);
    fprintf(f, "password=%s", newUser.password);
    fprintf(f, "[End]\n");
    fclose(f);
    getUsers();
    return;
}

void manageUsers()
{
    int ch;
    while(1)
    {
        printf("Выберите операцию\n");
        printf("1.Добавление пользователя\n");
        printf("2.Редактирование данных пользователя\n");
        printf("3.Удаление пользователя\n");
        printf("4.Назад\n");
        scanf("%d", &ch);
        fflush(stdin);
        getchar();
        switch(ch)
        {
        case 1:
            addUser();
            break;
        case 2:
            editUser();
            break;
        case 3:
            removeUser();
            break;
        case 4:
            return;
        default:
            printf("Неверный выбор\n");
        }
    }
}

void adminHelp()
{
    printf("1.Добавить новую запись\n");
    printf("2.Изменить запись\n");
    printf("3.Удалить запись\n");
    printf("4.Вывести участников\n");
    printf("5.Вывести список товаров\n");
    printf("6.Поик\n");
    printf("7.Сортировать\n");
    printf("8.Управление пользователями\n");
    printf("9.Обновить списки данных\n");
    printf("10.Выход\n");
}

void addProduct()
{
    struct Product newProduct;
    printf("Введите вид товара\n");
    fgets(newProduct.type, sizeof(newProduct.type), stdin);
    printf("Введите марку товара\n");
    fgets(newProduct.brand, sizeof(newProduct.brand), stdin);
    printf("Введите модель товара\n");
    fgets(newProduct.model, sizeof(newProduct.model), stdin);
    printf("Введите характеристики товара\n");
    fgets(newProduct.stats, sizeof(newProduct.stats), stdin);
    printf("Введите количество единиц товара\n");
    fgets(newProduct.count, sizeof(newProduct.count), stdin);

    FILE* f = fopen(PRODUCTS_FILEPATH, "at");
    fprintf(f, "\n[Product]\n");
    fprintf(f, "type=%s", newProduct.type);
    fprintf(f, "brand=%s", newProduct.brand);
    fprintf(f, "model=%s", newProduct.model);
    fprintf(f, "stats=%s", newProduct.stats);
    fprintf(f, "count=%s", newProduct.count);
    fprintf(f, "[End]\n");
    fclose(f);
    getProducts();
    return;
}

void addApplicant()
{
    struct Applicant newApplicant;
    printf("Введите название организации\n");
    fgets(newApplicant.name, sizeof(newApplicant.name), stdin);
    printf("Введите электронную почту\n");
    fgets(newApplicant.email, sizeof(newApplicant.email), stdin);
    printf("Введите телефон\n");
    fgets(newApplicant.phone, sizeof(newApplicant.phone), stdin);
    printf("Введите предлагаемую стоимость\n");
    fgets(newApplicant.price, sizeof(newApplicant.price), stdin);
    printf("Введите дату доставки\n");
    fgets(newApplicant.delivery_date, sizeof(newApplicant.delivery_date), stdin);
    printf("Введите страну\n");
    fgets(newApplicant.addr.country, sizeof(newApplicant.addr.country), stdin);
    printf("Введите город\n");
    fgets(newApplicant.addr.city, sizeof(newApplicant.addr.city), stdin);
    printf("Введите улицу\n");
    fgets(newApplicant.addr.street, sizeof(newApplicant.addr.street), stdin);
    printf("Введите дополнительные сведения\n");
    fgets(newApplicant.remark, sizeof(newApplicant.remark), stdin);

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
        printf("2.Добавить товар\n");
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
            fflush(stdin);
            getchar();
            addProduct();
            break;
        case 3:
            return;
        default:
            printf("Неверный выбор\n");
        }
    }
}

void removeApplicant()
{
    int i = 0;
    char company[30];
    printf("Введите компанию, которую хотите удалить :\n");
    fgets(company,sizeof(company),stdin);
    company[strcspn(company, "\n")] = 0;
    while(i < APPLICANTS_LIST_SIZE)
    {
        if(applicantIsEmpty(applicants[i]))
        {
            i++;
            continue;
        }
        if(strcmp(company, applicants[i].name) == 0)
        {
            memset(&applicants[i], 0, sizeof(applicants[i]));
        }
        i++;
    }
    setApplicants(applicants, APPLICANTS_LIST_SIZE);
}

void removeProduct()
{
    int i = 0;
    char typs[30];
    printf("Введите товар, который хотите удалить :\n");
    fgets(typs,sizeof(typs),stdin);
    typs[strcspn(typs, "\n")] = 0;
    while(i < PRODUCTS_LIST_SIZE)
    {
        if(applicantIsEmpty(applicants[i]))
        {
            i++;
            continue;
        }
        if(strcmp(typs, products[i].type) == 0)
        {
            memset(&products[i], 0, sizeof(products[i]));
        }
        i++;
    }
    setProducts(products, PRODUCTS_LIST_SIZE);
}

void removeAllApplicants()
{
    int i = 0;
     FILE* f = fopen(APPLICANT_FILEPATH, "w");
     fclose(f);
         memset(applicants, 0, sizeof(applicants));
}

void removeAllProducts()
{
    int i = 0;
     FILE* f = fopen(PRODUCTS_FILEPATH, "w");
     fclose(f);
         memset(products, 0, sizeof(products));
}

void removeRecord()
{
    int ch;
    while(1)
    {
        printf("Выберите параметр для удаления\n");
        printf("1.Удалить участника тендера\n");
        printf("2.Удалить товар\n");
        printf("3.Удалить всех участников\n");
        printf("4.Удалить все товары\n");
        printf("5.Прекратить удаление\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            fflush(stdin);
            getchar();
            removeApplicant();
            break;
        case 2:
            fflush(stdin);
            getchar();
            removeProduct();
            break;
        case 3:
            removeAllApplicants();
            break;
        case 4:
            removeAllProducts();
            break;
        case 5:
            return;
        default:
            printf("Неверный выбор\n");
        }
    }
}

void editRecord()
{
    int ch;
    while(1)
    {
        printf("Выберите параметр для изменения\n");
        printf("1.Изменить данные о участнике тендера\n");
        printf("2.Изменить данные о товаре \n");
        printf("3.Прекратить изменение\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            fflush(stdin);
            getchar();
            editApplicant();
            break;
        case 2:
            fflush(stdin);
            getchar();
            editProduct();
            break;
        case 3:
            return;
        default:
            printf("Неверный выбор\n");
        }
    }
}

void editApplicant()
{
    int sw;
    int i = 0;
    char company[30];
    printf("Введите компанию, которую хотите изменить :\n");
    fgets(company,sizeof(company),stdin);
    company[strcspn(company, "\n")] = 0;
    while(i < APPLICANTS_LIST_SIZE)
    {
        if(applicantIsEmpty(applicants[i]))
        {
            i++;
            continue;
        }
        if(strcmp(company, applicants[i].name) == 0)
        {
            while(1)
            {
                printf("Выберите поле для изменения\n");
                printf("1.Изменить название компании\n");
                printf("2.Изменить электронную почту \n");
                printf("3.Изменить номер телефона\n");
                printf("4.Изменить стоимость\n");
                printf("5.Изменить дату доставки\n");
                printf("6.Изменить дополнительные сведения\n");
                printf("7.Изменить адрес\n");
                printf("8.Завершить изменение\n");

                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                switch(sw)
                {
                case 1:
                    printf("Введите новое название компании :");
                    fgets(applicants[i].name, sizeof(applicants[i].name), stdin);
                    applicants[i].name[strcspn(applicants[i].name, "\n")] = 0;
                break;
                case 2:
                    printf("Введите новую электронную почту :");
                    fgets(applicants[i].email, sizeof(applicants[i].email), stdin);
                    applicants[i].email[strcspn(applicants[i].email, "\n")] = 0;
                break;
                case 3:
                    printf("Введите новое название компании :");
                    fgets(applicants[i].phone, sizeof(applicants[i].phone), stdin);
                    applicants[i].phone[strcspn(applicants[i].phone, "\n")] = 0;
                break;
                case 4:
                    printf("Введите новую стоимость :");
                    fgets(applicants[i].price, sizeof(applicants[i].price), stdin);
                    applicants[i].price[strcspn(applicants[i].price, "\n")] = 0;
                break;
                case 5:
                    printf("Введите новую дату доставки :");
                    fgets(applicants[i].delivery_date, sizeof(applicants[i].delivery_date), stdin);
                    applicants[i].delivery_date[strcspn(applicants[i].delivery_date, "\n")] = 0;
                break;
                case 6:
                    printf("Введите дополнительные сведения :");
                    fgets(applicants[i].remark, sizeof(applicants[i].remark), stdin);
                    applicants[i].remark[strcspn(applicants[i].remark, "\n")] = 0;
                break;
                case 7:
                    printf("Введите новый адрес :\n");
                    printf("Введите страну :");
                    fgets(applicants[i].addr.country, sizeof(applicants[i].addr.country), stdin);
                    applicants[i].addr.country[strcspn(applicants[i].addr.country, "\n")] = 0;
                    printf("Введите город :");
                    fgets(applicants[i].addr.city, sizeof(applicants[i].addr.city), stdin);
                    applicants[i].addr.city[strcspn(applicants[i].addr.city, "\n")] = 0;
                    printf("Введите улицу :");
                    fgets(applicants[i].addr.street, sizeof(applicants[i].addr.street), stdin);
                    applicants[i].addr.street[strcspn(applicants[i].addr.street, "\n")] = 0;
                break;
                case 8:
                    return;
                }
                setApplicants(applicants, APPLICANTS_LIST_SIZE);
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено.\n");
    return;
}

void editProduct()
{
    int sw;
    int i = 0;
    char typs[30];
    printf("Введите товар, который хотите изменить :\n");
    fgets(typs,sizeof(typs),stdin);
    typs[strcspn(typs, "\n")] = 0;
    while(i < PRODUCTS_LIST_SIZE)
    {
        if(productIsEmpty(products[i]))
        {
            i++;
            continue;
        }
        if(strcmp(typs, products[i].type) == 0)
        {
            while(1)
            {
                printf("Выберите поле для изменения\n");
                printf("1.Изменить тип товра \n");
                printf("2.Изменить бренд товара \n");
                printf("3.Изменить модель товара\n");
                printf("4.Изменить характеристики товара\n");
                printf("5.Изменить количество единиц товара\n");
                printf("6.Завершить изменение\n");

                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                switch(sw)
                {
                case 1:
                {
                    printf("Введите тип товара :");
                    fgets(products[i].type, sizeof(products[i].type), stdin);
                    products[i].type[strcspn(products[i].type, "\n")] = 0;
                    break;
                }
                case 2:
                {
                    printf("Введите бренд товара :");
                    fgets(products[i].brand, sizeof(products[i].brand), stdin);
                    products[i].brand[strcspn(products[i].brand, "\n")] = 0;
                    break;
                }
                case 3:
                {
                    printf("Введите модель товара :");
                    fgets(products[i].model, sizeof(products[i].model), stdin);
                    products[i].model[strcspn(products[i].model, "\n")] = 0;
                    break;
                }
                case 4:
                {
                    printf("Введите характеристики товара :");
                    fgets(products[i].stats, sizeof(products[i].stats), stdin);
                    products[i].stats[strcspn(products[i].stats, "\n")] = 0;
                    break;
                }
                case 5:
                {
                    printf("Введите количество единиц товара :");
                    fgets(products[i].count, sizeof(products[i].count), stdin);
                    products[i].count[strcspn(products[i].count, "\n")] = 0;
                    break;
                }
                case 6:
                    return;
                }
                setProducts(products, PRODUCTS_LIST_SIZE);
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено.\n");
    return;
}

void editUser()
{
    int sw;
    int i = 0;
    char log[30];
    printf("Введите имя пользователя, которого нужно изменить :\n");
    fgets(log, sizeof(log), stdin);
    log[strcspn(log, "\n")] = 0;
    while(i < USERS_SIZE)
    {
        if(userIsEmpty(users[i]))
        {
            i++;
            continue;
        }
        if(strcmp(log, users[i].login) == 0)
        {
            while(1)
            {
                printf("Выберите поле для изменения\n");
                printf("1.Изменить имя пользователя \n");
                printf("2.Изменить пароль \n");
                printf("3.Завершить изменение\n");

                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                switch(sw)
                {
                case 1:
                {
                    printf("Введите новое имя пользователя :");
                    fgets(users[i].login, sizeof(users[i].login), stdin);
                    users[i].login[strcspn(users[i].login, "\n")] = 0;
                    break;
                }
                case 2:
                {
                    printf("Введите новый пароль :");
                    fgets(users[i].password, sizeof(users[i].password), stdin);
                    users[i].password[strcspn(users[i].password, "\n")] = 0;
                    break;
                }
                case 3:
                    return;
                }
                setUsers(users, USERS_SIZE);
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено\n");
    return;
}

void removeUser()
{
    int i = 0;
    char log[30];
    printf("Введите пользователя, которого нужно удалить :\n");
    fgets(log,sizeof(log),stdin);
    log[strcspn(log, "\n")] = 0;
    while(i < USERS_SIZE)
    {
        if(userIsEmpty(users[i]))
        {
            i++;
            continue;
        }
        if(strcmp(log, users[i].login) == 0)
        {
            memset(&users[i], 0, sizeof(users[i]));
        }
        i++;
    }
    setUsers(users, USERS_SIZE);
}
