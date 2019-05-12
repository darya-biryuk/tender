#include "adminmenu.h"
#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "systools.h"
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
        printf(">> ");
        scanf("%d", &er);
        system("clear");
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
            printf("Списки данных обновлены.\n\n");
            break;
        case 10:
            fflush(stdin);
            getchar();
            printf("Выход в окно авторизации.\n\n");
            return;
        default:
            clearStdin();
            printf("Ошибка выбора.\n\n");
        }
    }
}

void addUser()
{
    struct User newUser;
    memset(&newUser, 0, sizeof(newUser));
    enterField("Введите имя пользователя:", newUser.login, MAX_LOGIN_SIZE, 0);
    newUser.login[strcspn(newUser.login, "\n")] = 0;

    int i = 0;
    while (i < USERS_SIZE)
    {
        if (strcmp(users[i].login, newUser.login) == 0)
        {
            system("clear");
            printf("Ошибка. Пользователь с таким именем уже существует.\n\n");
            return;
        }
        i++;
    }

    enterField("Введите пароль пользователя:", newUser.password, MAX_PASSWORD_SIZE, 0);
    newUser.password[strcspn(newUser.password, "\n")] = 0;

    FILE* f = fopen(SHADOW_FILEPATH, "at");
    fprintf(f, "\n[User]\n");
    fprintf(f, "login=%s\n", newUser.login);
    fprintf(f, "password=%s\n", newUser.password);
    fprintf(f, "[End]\n");
    fclose(f);
    getUsers();
    printf("Пользователь успешно добавлен.\n\n");
    return;
}

void manageUsers()
{
    int ch;
    while(1)
    {
        printf("Выберите операцию:\n");
        printf("1.Добавление пользователя\n");
        printf("2.Редактирование данных пользователя\n");
        printf("3.Удаление пользователя\n");
        printf("4.Назад\n");
        printf(">> ");
        scanf("%d", &ch);
        fflush(stdin);
        getchar();
        system("clear");
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
            system("clear");
            clearStdin();
            printf("Неверный выбор.\n\n");
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

int checkNoLetters(char str1[])
{
    int p = strlen(str1);
    for (int i = 0; i < p ; i++)
        if (!(str1[i] >= 'a' && str1[i] <= 'z') && !(str1[i] >= 'A' && str1[i] <= 'Z'))
        {
            continue;
        } else return 0;

    return 1;
}

int checkNoNumbers(char str1[])
{
    int p = strlen(str1);
    for (int i = 0; i < p ; i++)
        if (!(str1[i] >= '0' && str1[i] <= '9'))
        {
            continue;
        } else return 0;

    return 1;
}

void enterField(const char* message, char* field, int size, int flags)
{
    memset(field, 0, size);
    while (strlen(field) <= 1)
    {
        printf("%s\n", message);
        fgets(field, size, stdin);
        system("clear");
        if (strlen(field) >= size - 1)
        {
            clearStdin();
            memset(field, 0, size);
            system("clear");
            printf("Превышен допустимый размер ввода.\n\n");
            continue;
        }
        if (flags & NO_LETTERS)
        {
            if (!checkNoLetters(field))
            {
                memset(field, 0, size);
                system("clear");
                printf("Ошибка ввода, поле содержит буквы.\n\n");
                continue;
            }
        }
        if (flags & NO_NUMBERS)
        {
            if (!checkNoNumbers(field))
            {
                memset(field, 0, size);
                system("clear");
                printf("Ошибка ввода, поле содержит цифры.\n\n");
                continue;
            }
        }
    }
}

void addProduct()
{
    struct Product newProduct;
    memset(&newProduct, 0, sizeof(newProduct));
    enterField("Введите вид товара:", newProduct.type, PRODUCT_BUF_SIZE, 0);
    newProduct.type[strcspn(newProduct.type, "\n")] = 0;

    int i = 0;
    while (i < PRODUCTS_LIST_SIZE)
    {
        if (strcmp(products[i].type, newProduct.type) == 0)
        {
            printf("Ошибка. Товар с таким названием уже существует.\n\n");
            return;
        }
        i++;
    }

    enterField("Введите марку товара:", newProduct.brand, PRODUCT_BUF_SIZE, 0);
    enterField("Введите модель товара:", newProduct.model, PRODUCT_BUF_SIZE, 0);
    enterField("Введите характеристики товара:", newProduct.stats, PRODUCT_BUF_SIZE, 0);
    enterField("Введите количество единиц товара:", newProduct.count, PRODUCT_BUF_SIZE, NO_LETTERS);

    FILE* f = fopen(PRODUCTS_FILEPATH, "at");
    fprintf(f, "\n[Product]\n");
    fprintf(f, "type=%s\n", newProduct.type);
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
    memset(&newApplicant, 0, sizeof(newApplicant));
    enterField("Введите название организации:", newApplicant.name, APPLICANT_BUF_SIZE, 0);
    newApplicant.name[strcspn(newApplicant.name, "\n")] = 0;

    int i = 0;
    while (i < APPLICANTS_LIST_SIZE)
    {
        if (strcmp(applicants[i].name, newApplicant.name) == 0)
        {
            printf("Ошибка. Организация с таким названием уже существует.\n\n");
            return;
        }
        i++;
    }

    enterField("Введите электронную почту:", newApplicant.email, APPLICANT_BUF_SIZE, 0);
    enterField("Введите телефон:", newApplicant.phone, APPLICANT_BUF_SIZE, NO_LETTERS);
    enterField("Введите предлагаемую стоимость:", newApplicant.price, APPLICANT_BUF_SIZE, NO_LETTERS);

    //enterField("Введите дату доставки:", newApplicant.delivery_date, APPLICANT_BUF_SIZE, 0);
    enterField("Введите день доставки:", newApplicant.date.day, APPLICANT_BUF_SIZE, NO_LETTERS);
    enterField("Введите месяц доставки:", newApplicant.date.month, APPLICANT_BUF_SIZE, NO_LETTERS);
    enterField("Введите год доставки:", newApplicant.date.year, APPLICANT_BUF_SIZE, NO_LETTERS);

    enterField("Введите страну:", newApplicant.addr.country, APPLICANT_BUF_SIZE, NO_NUMBERS);
    enterField("Введите город:", newApplicant.addr.city, APPLICANT_BUF_SIZE, NO_NUMBERS);
    enterField("Введите улицу:", newApplicant.addr.street, APPLICANT_BUF_SIZE, NO_NUMBERS);
    enterField("Введите дополнительные сведения:", newApplicant.remark, APPLICANT_BUF_SIZE, 0);

    FILE* f = fopen(APPLICANT_FILEPATH, "at");
    fprintf(f, "\n[Applicant]\n");
    fprintf(f, "name=%s\n", newApplicant.name);
    fprintf(f, "email=%s", newApplicant.email);
    fprintf(f, "phone=%s", newApplicant.phone);
    fprintf(f, "price=%s", newApplicant.price);
    fprintf(f, "day=%s", newApplicant.date.day);
    fprintf(f, "month=%s", newApplicant.date.month);
    fprintf(f, "year=%s", newApplicant.date.year);

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
        printf("Выберите параметр для добавления:\n");
        printf("1.Добавить участника тендера\n");
        printf("2.Добавить товар\n");
        printf("3.Назад\n");
        printf(">> ");
        scanf("%d", &ch);
        system("clear");
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
            system("clear");
            clearStdin();
            printf("Неверный выбор.\n\n");
        }
    }
}

void removeApplicant()
{
    int i = 0;
    char company[APPLICANT_BUF_SIZE];
    system("clear");
    enterField("Введите компанию, которую хотите удалить:", company, APPLICANT_BUF_SIZE, 0);
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
            setApplicants(applicants, APPLICANTS_LIST_SIZE);
            printf("Компания удалена.\n\n");
            return;
        }
        i++;
    }
    printf("Компания с заданным названием не найдена.\n\n");
}

void removeProduct()
{
    int i = 0;
    char typs[PRODUCT_BUF_SIZE];
    system("clear");
    enterField("Введите товар, который хотите удалить:", typs, PRODUCT_BUF_SIZE, 0);
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
            setProducts(products, PRODUCTS_LIST_SIZE);
            printf("Товар удален.\n\n");
            return;
        }
        i++;
    }
    printf("Товар с заданным названием не найден.\n\n");
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
        printf("5.Назад\n");
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
            system("clear");
            printf("Все участники были удалены.\n\n");
            break;
        case 4:
            removeAllProducts();
            system("clear");
            printf("Все товары были удалены.\n\n");
            break;
        case 5:
            system("clear");
            return;
        default:
            system("clear");
            clearStdin();
            printf("Неверный выбор.\n\n");
        }
    }
}

void editRecord()
{
    int ch;
    while(1)
    {
        printf("Выберите параметр для изменения:\n");
        printf("1.Изменить данные о участнике тендера\n");
        printf("2.Изменить данные о товаре \n");
        printf("3.Назад\n");
        printf(">> ");
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
            system("clear");
            return;
        default:
            system("clear");
            clearStdin();
            printf("Неверный выбор.\n\n");
        }
    }
}

void editApplicant()
{
    int sw;
    int i = 0;
    char company[APPLICANT_BUF_SIZE];
    system("clear");
    enterField("Введите компанию, которую хотите изменить:", company, APPLICANT_BUF_SIZE, 0);
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
                printf("Выберите поле для изменения:\n");
                printf("1.Изменить название компании\n");
                printf("2.Изменить электронную почту \n");
                printf("3.Изменить номер телефона\n");
                printf("4.Изменить стоимость\n");
                printf("5.Изменить дату доставки\n");
                printf("6.Изменить дополнительные сведения\n");
                printf("7.Изменить адрес\n");
                printf("8.Назад\n");
                printf(">> ");
                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                system("clear");
                switch(sw)
                {
                case 1:
                    enterField("Введите новое название компании:", applicants[i].name, APPLICANT_BUF_SIZE, 0);
                    applicants[i].name[strcspn(applicants[i].name, "\n")] = 0;
                break;
                case 2:
                    enterField("Введите новую электронную почту:", applicants[i].email, APPLICANT_BUF_SIZE, 0);
                    applicants[i].email[strcspn(applicants[i].email, "\n")] = 0;
                break;
                case 3:
                    enterField("Введите номер телефона:", applicants[i].phone, APPLICANT_BUF_SIZE, NO_LETTERS);
                    applicants[i].phone[strcspn(applicants[i].phone, "\n")] = 0;
                break;
                case 4:
                    enterField("Введите новую стоимость:", applicants[i].price, APPLICANT_BUF_SIZE, NO_LETTERS);
                    applicants[i].price[strcspn(applicants[i].price, "\n")] = 0;
                break;
                case 5:
                    enterField("Введите день доставки:", applicants[i].date.day, APPLICANT_BUF_SIZE, NO_LETTERS);
                    applicants[i].date.day[strcspn(applicants[i].date.day, "\n")] = 0;

                    enterField("Введите месяц доставки:", applicants[i].date.month, APPLICANT_BUF_SIZE, NO_LETTERS);
                    applicants[i].date.month[strcspn(applicants[i].date.month, "\n")] = 0;

                    enterField("Введите год доставки:", applicants[i].date.year, APPLICANT_BUF_SIZE, NO_LETTERS);
                    applicants[i].date.year[strcspn(applicants[i].date.year, "\n")] = 0;
                break;
                case 6:
                    enterField("Введите дополнительные сведения:", applicants[i].remark, APPLICANT_BUF_SIZE, 0);
                    applicants[i].remark[strcspn(applicants[i].remark, "\n")] = 0;
                break;
                case 7:
                    enterField("Введите страну:", applicants[i].addr.country, APPLICANT_BUF_SIZE, NO_NUMBERS);
                    applicants[i].addr.country[strcspn(applicants[i].addr.country, "\n")] = 0;
                    enterField("Введите город:", applicants[i].addr.city, APPLICANT_BUF_SIZE, NO_NUMBERS);
                    applicants[i].addr.city[strcspn(applicants[i].addr.city, "\n")] = 0;
                    enterField("Введите улицу:", applicants[i].addr.street, APPLICANT_BUF_SIZE, NO_NUMBERS);
                    applicants[i].addr.street[strcspn(applicants[i].addr.street, "\n")] = 0;
                break;
                case 8:
                    return;
                }
                setApplicants(applicants, APPLICANTS_LIST_SIZE);
                printf("Изменения сохранены.\n\n");
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено.\n\n");
    return;
}

void editProduct()
{
    int sw;
    int i = 0;
    char typs[PRODUCT_BUF_SIZE];
    system("clear");
    enterField("Введите товар, который хотите изменить:", typs, PRODUCT_BUF_SIZE, 0);
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
                printf("Выберите поле для изменения:\n");
                printf("1.Изменить тип товра\n");
                printf("2.Изменить бренд товара\n");
                printf("3.Изменить модель товара\n");
                printf("4.Изменить характеристики товара\n");
                printf("5.Изменить количество единиц товара\n");
                printf("6.Назад\n");
                printf(">> ");
                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                system("clear");
                switch(sw)
                {
                case 1:
                {
                    enterField("Введите тип товара:", products[i].type, PRODUCT_BUF_SIZE, 0);
                    products[i].type[strcspn(products[i].type, "\n")] = 0;
                    break;
                }
                case 2:
                {
                    enterField("Введите бренд товара:", products[i].brand, PRODUCT_BUF_SIZE, 0);
                    products[i].brand[strcspn(products[i].brand, "\n")] = 0;
                    break;
                }
                case 3:
                {
                    enterField("Введите модель товара:", products[i].model, PRODUCT_BUF_SIZE, 0);
                    products[i].model[strcspn(products[i].model, "\n")] = 0;
                    break;
                }
                case 4:
                {
                    enterField("Введите характеристики товара:", products[i].stats, PRODUCT_BUF_SIZE, 0);
                    products[i].stats[strcspn(products[i].stats, "\n")] = 0;
                    break;
                }
                case 5:
                {
                    enterField("Введите количество единиц товара:", products[i].count, PRODUCT_BUF_SIZE, 0);
                    products[i].count[strcspn(products[i].count, "\n")] = 0;
                    break;
                }
                case 6:
                    system("clear");
                    return;
                }
                setProducts(products, PRODUCTS_LIST_SIZE);
                printf("Изменения сохранены.\n\n");
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено.\n\n");
    return;
}

void editUser()
{
    int sw;
    int i = 0;
    char log[MAX_LOGIN_SIZE];
    system("clear");
    enterField("Введите имя пользователя, которого нужно изменить:", log, MAX_LOGIN_SIZE, 0);
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
                printf("2.Изменить пароль\n");
                printf("3.Завершить изменение\n");
                printf(">> ");
                scanf("%d", &sw);
                fflush(stdin);
                getchar();
                system("clear");
                switch(sw)
                {
                case 1:
                {
                    enterField("Введите новое имя пользователя:", users[i].login, MAX_LOGIN_SIZE, 0);
                    users[i].login[strcspn(users[i].login, "\n")] = 0;
                    break;
                }
                case 2:
                {
                    enterField("Введите новый пароль:", users[i].password, MAX_PASSWORD_SIZE, 0);
                    users[i].password[strcspn(users[i].password, "\n")] = 0;
                    break;
                }
                case 3:
                    system("clear");
                    return;
                }
                setUsers(users, USERS_SIZE);
                printf("Изменения сохранены");
            }
        }
        i++;
    }
    printf("Совпадений не обнаружено.\n\n");
    return;
}

void removeUser()
{
    int i = 0;
    char log[MAX_LOGIN_SIZE];
    system("clear");
    enterField("Введите пользователя, которого нужно удалить:", log, MAX_LOGIN_SIZE, 0);
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
            setUsers(users, USERS_SIZE);
            printf("Пользователь удален.\n\n");
            return;
        }
        i++;
    }
    printf("Пользователь с таким именем не найден.\n\n");
}
