//*Структуры и алгоритмы обработки данных*
//Имеем нагруженное множество очередей целого типа. Нагрузка типа char.
//Множество реализуется на двусвязном списке
//Очередь реализуется на односвязном списке
//Реализовать только на языке C

/*Операции над очередью:
* 1. Начать работу
* 2. Сделать очередь пустой
* 3. Проверка: очередь пуста или нет
* 4. Показать значение элемента в начале очереди
* 5. Удалить начало очереди
* 6. Взять элемент из начала очереди
* 7. Изменить значение элемента в начале очереди
* 8. Добавить элемент в конец очереди
* 9. Распечатать структуру
* 10. Завершить работу с очередью
*
* Операции над нагруженным множеством:
* 1. Начать работу
* 2. Сделать множество пустым
* 3. Проверить: множество пусто или нет
* 4. Удалить элемент из множества
* 5. Взять любой элемент множества
* 6. Добавить элемент множества
* 7. Нагрузить элемент множества
* 8. Проверка: некоторый элемент принадлежит множеству
* 9. Распечатать структуру
* 10. Завершить работу с множеством
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct list { int value; list* next; };
typedef struct queue { list* head, * end; } queue;
/*
head – указатель на начало очереди;
end – указатель на конец очереди
*/
typedef struct Set { queue* data;  char load; Set* next; Set* prev; } Set;

void MenuSet(Set*, Set*, queue*);		                //			   Меню (нагруженное множество)             (DONE)
void createSet(Set**, Set**);		                    //1. Начать работу с нагруженным множеством             (DONE) 
int clearSet(Set**, Set**);	                            //2. Сделать множество пустым                           (DONE) 
int isSetEmpty(Set*);	                                //3. Проверить: множество пусто или нет                 (DONE) 
int removeSetElement(Set**, Set**, Set*);		        //4. Удалить элемент из множества                       (DONE) 
Set* takeSetElement(Set*, Set*);			            //5. Взять любой элемент множества                      (DONE) 
void addSetElement(Set**, Set**, Set*);	                //6. Добавить элемент множества                         (DONE) 
int LoadSetElement(Set**, Set**, char);                 //7. Нагрузить элемент множества                        (DONE) 
int isBelongToSet(Set*, Set*);                          //8. Проверка: некоторый элемент принадлежит множеству  (DONE) 
void printSet(Set*);	                                //9. Распечатать структуру данных                       (DONE) 
int deleteSet(Set**, Set**);	                        //10. Завершить работу с множеством                     (DONE) 

Set* MenuQueue(queue*);		                            //				   Меню (очередь)                       (DONE)
queue* createQueue();		                            //1. Начать работу с очередью                           (DONE)
int clearQueue(queue*);	                                //2. Сделать очередь пустой                             (DONE)
int isQueueEmpty(queue*);	                            //3. Проверка: очередь пуста или нет?                   (DONE)
int showFromQueue(queue*);	                            //4. Показать значение элемента в начале очереди        (DONE)
int removeQueueElement(queue*);		                    //5. Удалить начало очереди                             (DONE)
int takeFromQueue(queue*, int*);                        //6. Взять элемент из начала очереди                    (DONE)
void changeQueueElement(queue*, int);                   //7. Изменить значение элемента в начале очереди        (DONE)
void addToQueue(queue*, int);	                        //8. Добавить элемент в конец очереди                   (DONE)
void printQueue(queue*);     	                        //9. Распечатать структуру данных (очередь)             (DONE)
int deleteQueue(queue**);	                            //10. Закончить работу с очередью                       (DONE)

Set* CreateSet();
queue* CreateQueue();
list* CreateList();

int main() {
    setlocale(LC_ALL, "Rus");
    queue* listQueue = NULL;
    Set* head = NULL;
    Set* end = NULL;
    MenuSet(head, end, listQueue);
}

//Меню нагруженного множества
void MenuSet(Set* head, Set* end, queue* list) {
    int command;
    int enter; //Какое-то введённое значение в процессе работы программы
    int output; //Какой-то вывод значения в процессе работы программы
    Set* takenEl;

    do {
        command = 0;
        enter = NULL;
        output = NULL;
        takenEl = NULL;
        printf("\n\n\tВаше множество:\n");
        printSet(head);
        printf("\n");

        printf("\t\t\t ======== \n");
        printf("\t\t\t = Menu = \n");
        printf("\t\t\t ======== \n\n");

        printf("\t1) Начать работу с нагруженным множеством.\n");
        printf("\t2) Сделать множество пустым.\n");
        printf("\t3) Проверка: множество пусто или нет?\n");
        printf("\t4) Удалить элемент из множества.\n");
        printf("\t5) Взять любой элемент множества.\n");
        printf("\t6) Добавить элемент множества\n");
        printf("\t7) Нагрузить элемент множества.\n");
        printf("\t8) Проверка: некоторый элемент принадлежит множеству.\n");
        printf("\t9) Распечатать структуру данных (нагруженное множество).\n");
        printf("\t10) Закончить работу с нагруженным множеством.\n");
        printf("\t11) Выход из программы.\n");

        printf("\t>> ");
        scanf_s("%d", &command);
        fflush(stdin);
        getchar();

        switch (command) {
        case 1: //Начать работу с очередью 
            system("cls");
            createSet(&head, &end);
            printf("\n\n\tПоздравляем! Ваше множество создано\n");
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 2: //Сделать очередь пустой
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество уже пусто и не нуждается в очистке\n\n");
                }
                else {
                    clearSet(&head, &end);
                    printf("\n\n\tМножество очищено\n");
                    printSet(head);
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 3: //Проверка: очередь пуста или нет?
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество пусто\n\n");
                }
                else {
                    printf("\n\n\tВаше множество НЕ пусто\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 4: //Удалить элемент из множества
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество пусто\n\n");
                }
                else {
                    printf("\n\n\tВаше множество:\n");
                    printSet(head);
                    printf("\n\n\tСейчас вы будете перенесены в меню для подробного описания удаляемого элемента множества:\n\n");
                    Set* deletedEl = MenuQueue(list);
                    removeSetElement(&head, &end, deletedEl);
                    printf("\n\n\tВаше множество:\n");
                    printSet(head);
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 5: //Взять любой элемент множества  
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество пусто\n\n");
                }
                else {
                    printf("\n\n\tВаше множество:\n");
                    printSet(head);
                    printf("\n\n\tСейчас вы будете перенесены в меню для подробного описания элемента множества:\n\n");
                    Set* selected = MenuQueue(list);
                    Set* takenEl = takeSetElement(head, selected);
                    printf("\n\n\tВы взяли: ");
                    printSet(takenEl);
                    if (isBelongToSet(head, selected)) {
                        removeSetElement(&head, &end, takenEl);
                    }
                    printSet(head);
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 6: //Добавить элемент множества
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n\n"); }
            else {
                printf("\n\n\tВаше множество:\n");
                printSet(head);
                printf("\n\n\tСейчас вы будете перенесены в меню для подробного описания вашего нового элемента множества:\n\n");
                Set* newEl = MenuQueue(list);
                if (!isSetEmpty(head)) {
                    if (!isBelongToSet(head, newEl)) {
                        addSetElement(&head, &end, newEl);
                    }
                    else {
                        printf("\n\n\tДанный элемент уже присутствует в вашем множестве.\n\n");
                    }
                }
                else {
                    addSetElement(&head, &end, newEl);
                }
                printf("\n\n\tВаше множество:\n");
                printSet(head);
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 7: //Нагрузить элемент множества
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество пусто\n\n");
                }
                else {
                    printf("\n\n\tВаше множество:\n");
                    printSet(head);
                    printf("\n\n\tСейчас вы будете перенесены в меню для подробного описания вашего элемента множества,\n который вы бы желали нагрузить: \n\n");
                    Set* selected = MenuQueue(list);
                    printf("\n\n\tВы выбрали: ");
                    printSet(selected);
                    if (isBelongToSet(head, selected)) {
                        printf("\n\n\tВведите символ для нагрузки данного элемента множества: ");
                        char load = NULL;
                        load = getchar();
                        LoadSetElement(&head, &selected, load);
                        printf("\n\n\t*** Вы успешно нагрузили один из элементов множества! ***\n");
                        printf("\n\n\tВаше множество:\n");
                        printSet(head);
                        fflush(stdin);
                        getchar();
                    }
                    else {
                        printf("\n\n\tВ вашем множестве нет подобных элементов:\n");
                        printSet(head);
                    }
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 8: //Проверка: некоторый элемент принадлежит множеству?
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n\n"); }
            else {
                if (isSetEmpty(head)) {
                    printf("\n\n\tВаше множество пусто\n\n");
                }
                else {
                    printf("\n\n\tВаше множество:\n");
                    printSet(head);
                    printf("\n\n\tСейчас вы будете перенесены в меню для подробного описания проверяемого элемента множества:\n\n");
                    Set* chosen = MenuQueue(list);
                    if (isBelongToSet(head, chosen)) {
                        printf("\n\n\tДанный элемент принадлежит множеству\n\n");
                    }
                    else {
                        printf("\n\n\tДанный элемент НЕ принадлежит множеству\n\n");
                    }
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 9: //Распечатать структуру данных (очередь)
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n"); }
            else {
                printf("\n\n\tВаше множество:\n");
                printSet(head);
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 10: //Закончить работу с очередью
            system("cls");
            if (head == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с множеством\n"); }
            else {
                deleteSet(&head, &end);
                printf("\n\n\tПоздравляем! Работа с множеством успешно завершена!\n");
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 11: //Выйти из программы
            system("cls");
            if (head) {
                printf("\n\n\tВы всё ещё работаете с нагруженным множеством!\n\tЗакончите работу, прежде чем выходить из программы\n");
            }
            else {
                printf("\n\n\tЗавершаем работу с множеством!\n");
            }
            fflush(stdin);
            getchar();
            break;
        default: //В случае если пользователь попытался ввести несуществующий пункт или некорректное значение
            printf("\t\tTry again! \n");
            printf("\t\tPress Enter to continue...");
            fflush(stdin);
            getchar();
            break;
        }
        system("cls");
    } while ((command != 11) || (head));
}

//Очистка множества
int clearSet(Set** head, Set** end) {
    if (!head) return 0;
    if (head == NULL) return 0;
    Set* tmp = *head, * t;
    while (tmp->next != NULL)
    {
        t = tmp;
        tmp = t->next;
        deleteQueue(&(t->data));
    }
    (*head)->next = NULL;
    (*head)->prev = NULL;
    (*head)->load = NULL;
    (*head)->data = NULL;
    *end = *head;
    return 1;
}

//Создание нагруженного множества
void createSet(Set** head, Set** end) {
    *head = CreateSet();
    *end = CreateSet();
    (*head)->next = NULL;
    (*head)->prev = NULL;
    (*head)->load = NULL;
    (*head)->data = NULL;
    *end = *head;

}

//Проверка, пусто ли множество
int isSetEmpty(Set* head)
{
    if (head == NULL) return 1;
    if (head->data == NULL) return 1;
    return 0;
}

//Удалить элемент из множества
int removeSetElement(Set** head, Set** end, Set* chosen) {
    if (isSetEmpty(*head) || isSetEmpty(chosen)) {
        printf("\n\n\tВаше множество пусто\n\n");
        return 0;
    }
    Set* ptr = *head;
    Set* ptrChosen = chosen;
    list* tmp = (*head)->data->head;
    list* tmpChosen = chosen->data->head;
    short check = 0;

    if (isBelongToSet(ptr, chosen)) {
        while (ptr) {
            tmp = ptr->data->head;
            while (tmp && tmpChosen)
            {
                if (tmp->value == tmpChosen->value) {
                    check = 1;
                }
                else {
                    check = 0;
                    break;
                }
                tmpChosen = tmpChosen->next;
                tmp = tmp->next;
                //Если один из списков закончился раньше другого
                if ((!tmp && tmpChosen) || (!tmpChosen && tmp)) {
                    check = 0;
                }
            }
            if (check == 1) {
                Set* ptr_prev = ptr->prev;
                Set* ptr_next = ptr->next;

                if (!ptr_next && !ptr_prev){
                    deleteQueue(&(ptr->data));
                    free(ptr);
                    (*head)->prev = NULL;
                    (*head)->next = NULL;
                    (*head)->data = NULL;
                    (*head)->load = NULL;
                } else if (!ptr_prev) {
                    (*head) = ptr_next;
                    deleteQueue(&(ptr->data));
                    free(ptr);
                    (*head)->prev = NULL;
                } else if (!ptr_next) {
                    (*end) = ptr_prev;
                    deleteQueue(&(ptr->data));
                    free(ptr);
                    (*end)->next = NULL;
                }
                else {
                    if (ptr_prev)
                        ptr_prev->next = ptr_next;
                    if (ptr_next)
                        ptr_next->prev = ptr_prev;
                    deleteQueue(&(ptr->data));
                }
                return 1;
            }
            tmpChosen = chosen->data->head;
            ptrChosen = chosen;
            ptr = ptr->next;
        }
    }
    printf("\n\n\tДанный элемент НЕ принадлежит множеству\n\n");
    return 0;
}

//Взять любой элемент множества (не забываем удалить элемент)
Set* takeSetElement(Set* head, Set* chosen) {
    if (isSetEmpty(head) || isSetEmpty(chosen)) {
        printf("\n\n\tВаше множество пусто\n\n");
        return 0;
    }
    Set* ptr = head;
    Set* ptrChosen = chosen;
    list* tmp = head->data->head;
    list* tmpChosen = chosen->data->head;
    short check = 0;

    if (isBelongToSet(ptr, chosen)) {
        while (ptr) {
            tmp = ptr->data->head;
            while (tmp && tmpChosen)
            {
                if (tmp->value == tmpChosen->value) {
                    check = 1;
                }
                else {
                    check = 0;
                    break;
                }
                tmpChosen = tmpChosen->next;
                tmp = tmp->next;
                //Если один из списков закончился раньше другого
                if ((!tmp && tmpChosen) || (!tmpChosen && tmp)) {
                    check = 0;
                }
            }
            if (check == 1) {
                return ptr;
            }
            tmpChosen = chosen->data->head;
            ptrChosen = chosen;
            ptr = ptr->next;
        }

    }
    printf("\n\n\tДанный элемент НЕ принадлежит множеству\n\n");
    return 0;
}

//Добавить элемент множества (в конец)
void addSetElement(Set** head, Set** end, Set* iEl) {
    if (!isQueueEmpty(iEl->data)) {
        Set* tmp = iEl;
        if ((*head)->data != NULL) {
            (*end)->next = tmp;
            tmp->prev = (*end);
            (*end) = tmp;
        }
        else if ((*end)->data != NULL) {
            (*end)->next = tmp;
            tmp->prev = (*end);
        }
        else {
            (*head) = tmp;
            (*end) = tmp;
        }
    }
    else {
        printf("\n\n\tДобавляемый элемент пуст. Попробуйте повторить операцию\n\n");
    }
}

//Нагрузить элемент множества 
int LoadSetElement(Set** head, Set** chosen, char load) {
    if (isSetEmpty(*head) || isSetEmpty(*chosen)) {
        printf("\n\n\tВаше множество пусто\n\n");
        return 0;
    }
    Set* ptr = *head;
    Set* ptrChosen = *chosen;
    list* tmp = (*head)->data->head;
    list* tmpChosen = (*chosen)->data->head;
    short check = 0;

    if (isBelongToSet(ptr, *chosen)) {
        while (ptr) {
            tmp = ptr->data->head;
            while (tmp && tmpChosen)
            {
                if (tmp->value == tmpChosen->value) {
                    check = 1;
                }
                else {
                    check = 0;
                    break;
                }
                tmpChosen = tmpChosen->next;
                tmp = tmp->next;
                //Если один из списков закончился раньше другого
                if ((!tmp && tmpChosen) || (!tmpChosen && tmp)) {
                    check = 0;
                }
            }
            if (check == 1) {
                ptr->load = load;
                return 1;
            }
            tmpChosen = (*chosen)->data->head;
            ptrChosen = *chosen;
            ptr = ptr->next;
        }

    }
    printf("\n\n\tДанный элемент НЕ принадлежит множеству\n\n");
    return 0;
}

//Проверка: некоторый элемент принадлежит множеству
int isBelongToSet(Set* head, Set* chosen) {
    if (isSetEmpty(head) || isSetEmpty(chosen)) {
        printf("\n\n\tВаше множество пусто\n\n");
        return 0;
    }
    if (head->data == NULL) return 0;
    Set* ptr = head;
    Set* ptrChosen = chosen;
    list* tmp = head->data->head;
    list* tmpChosen = chosen->data->head;
    short check = 0;

    while (ptr) {
        tmp = ptr->data->head;
        while (tmp && tmpChosen)
        {
            if (tmp->value == tmpChosen->value) {
                check = 1;
            }
            else {
                check = 0;
                break;
            }
            tmpChosen = tmpChosen->next;
            tmp = tmp->next;
            //Если один из списков закончился раньше другого
            if ((!tmp && tmpChosen) || (!tmpChosen && tmp)) {
                check = 0;
            }
        }
        if (check == 1) {
            return 1;
        }
        tmpChosen = chosen->data->head;
        ptrChosen = chosen;
        ptr = ptr->next;
    }
    return 0;
}

//Вывести множество на экран
void printSet(Set* head) {
    Set* ptr = head;
    int countOfelements = 0;
    if (!(head == NULL)) {
        if (isSetEmpty(head)) { printf("\n\n\tВаше множество пусто! Попробуйте добавить в него немного элементов\n"); }
        else {
            countOfelements = 1;
            while (ptr) {
                printf("\t%d элемент: ", countOfelements);
                printQueue(ptr->data);
                if (ptr->load == NULL) {
                    printf(" (Нагрузка: НЕТ)\n");
                }
                else {
                    printf(" (Нагрузка: %c)\n", ptr->load);
                }
                ptr = ptr->next;
                countOfelements++;
            }
        }
    }
    else {
        printf("\n\n\tНевозможно вывести множество, т.к. оно не существует \n");
    }

}

//Удалить множество
int deleteSet(Set** head, Set** end) {
    clearSet(head, end);
    *head = NULL;
    *end = NULL;
    return 1;
}

/*----------------------------------------------------------------------------------------------------------------------*/

//Меню очереди
Set* MenuQueue(queue* list) {
    int command;
    int enter;
    int output;
    Set* head = NULL;
    Set* end = NULL;
    queue* takenEl;

    do {
        command = 0;
        enter = NULL;
        output = NULL;
        takenEl = NULL;
        printf("\n\n");
        printf("\tВаша очередь: ");
        printQueue(list);
        printf("\n\n");

        printf("\t\t\t ======== \n");
        printf("\t\t\t = Menu = \n");
        printf("\t\t\t ======== \n\n");

        printf("\t1) Начать работу с очередью.\n");
        printf("\t2) Сделать очередь пустой.\n");
        printf("\t3) Проверка: очередь пуста или нет?\n");
        printf("\t4) Показать значение элемента в начале очереди.\n");
        printf("\t5) Удалить начало очереди.\n");
        printf("\t6) Взять элемент из начала очереди.\n");
        printf("\t7) Изменить значение элемента в начале очереди.\n");
        printf("\t8) Добавить элемент в конец очереди.\n");
        printf("\t9) Распечатать структуру данных (очередь).\n");
        printf("\t10) Закончить работу с очередью.\n");
        printf("\t11) Выход из меню очереди. Завершить редактирование \n");

        printf("\t>> ");

        //command = getchar();
        scanf_s("%d", &command);
        fflush(stdin);
        getchar();

        switch (command) {
        case 1: //Начать работу с очередью 
            system("cls");
            list = createQueue();
            printf("\n\n\tПоздравляем! Ваша очередь создана\n\n");
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 2: //Сделать очередь пустой
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь уже пуста и не нуждается в очистке\n\n");
                }
                else {
                    clearQueue(list);
                    printf("\n\n\tОчередь очищена \n\n");
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 3: //Проверка: очередь пуста или нет?
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь пуста\n\n");
                }
                else {
                    printf("\n\n\tВаша очередь НЕ пуста\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 4: //Показать значение элемента в начале очереди
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь пуста\n\n");
                }
                else {
                    output = showFromQueue(list);
                    printf("\n\n\tЭлемент со значением %d находится в начале очереди\n\n", output);
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 5: //Удалить начало очереди  
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь уже пуста\n\n");
                }
                else {
                    removeQueueElement(list);
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 6: //Взять элемент из начала очереди
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь пуста\n\n");
                }
                else {
                    takeFromQueue(list, &output);
                    printf("Элемент со значением %d был взят из начала очереди", output);
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 7: //Изменить значение элемента в начале очереди
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь пуста\n\n");
                }
                else {
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                    printf("\n\n\tВведите ваше число (только одно): ");
                    if (!scanf_s("%d", &enter))
                    {
                        printf("\n\n\tИзвините. Похоже, введённое вами значение не является числом.\n\n");
                    }
                    else {
                        changeQueueElement(list, enter);
                    }
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 8: //Добавить элемент в конец очереди 
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                printf("\n\n");
                printf("\tВаша очередь: ");
                printQueue(list);
                printf("\n\n");
                //if (list == NULL) list = createQueue();
                printf("\n\n\tВведите ваше число (только одно): ");
                if (!scanf_s("%d", &enter))
                {
                    printf("\n\n\tИзвините. Похоже, введённое вами значение не является числом.\n\n");

                    system("pause");
                }
                else {
                    addToQueue(list, enter);
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 9: //Распечатать структуру данных (очередь)
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                if (isQueueEmpty(list)) {
                    printf("\n\n\tВаша очередь пуста\n\n");
                }
                else {
                    printf("\n\n");
                    printf("\tВаша очередь: ");
                    printQueue(list);
                    printf("\n\n");
                }
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 10: //Закончить работу с очередью
            system("cls");
            if (list == NULL) { printf("\n\n\tИзвините. Похоже, что вы ещё не начали работать с очередью\n\n"); }
            else {
                deleteQueue(&list);
                printf("\n\n\tПоздравляем! Работа с очередью успешно завершена!\n\n");
            }
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 11: //Выйти из меню очереди
            createSet(&head, &end);
            if (head != NULL) {
                head->data = list;
                end->data = list;
            }
            else {
                head->data->head = NULL;
                head->data->end = NULL;
            }
            return head;
            system("cls");
            break;
        default: //В случае если пользователь попытался ввести несуществующий пункт или некорректное значение
            printf("\t\tTry again! \n");
            printf("\t\tPress Enter to continue...\n\n");
            fflush(stdin);
            getchar();
            break;
        }
        system("cls");
    } while ((command != 11));
}

//Создание очереди
queue* createQueue() {
    queue* q;
    q = CreateQueue();
    q->head = NULL;
    q->end = NULL;
    return q;
}

//Очистка очереди
int clearQueue(queue* q) {
    if (!q) return 0;
    if (q->head == NULL) return 0;
    list* tmp, * t;
    tmp = q->head;
    while (tmp->next != NULL)
    {
        t = tmp;
        tmp = t->next;
        free(t);
    }
    q->head = NULL;
    q->end = NULL;
    return 1;
}

//Проверка, пуста ли очередь
int isQueueEmpty(queue* q)
{
    if (q == NULL) return 1;
    if (q->head == NULL) return 1;
    return 0;
}

//Получение первого элемента в очереди без его удаления
int showFromQueue(queue* q) {
    if (isQueueEmpty(q)) { printf("\n\n\tВаша очередь пуста! Попробуйте добавить немного элементов\n"); }
    else {
        int x;
        x = q->head->value;
        return x;
    }
}

//Удалить элемент в начале списка (очередь)
int removeQueueElement(queue* q) {
    if (isQueueEmpty(q)) { printf("\n\n\tВаша очередь пуста! Попробуйте добавить немного элементов\n"); }
    else {
        struct list* temp;
        int x;
        if (isQueueEmpty(q) == 1) {
            printf("Очередь пуста!\n");
            return 0;
        }
        x = q->head->value;
        temp = q->head;
        q->head = q->head->next;
        free(temp);
        return x;
    }
}

//Взять элемент в начале списка (из очереди)
int takeFromQueue(queue* q, int* iEl)
{
    if (isQueueEmpty(q)) { printf("\n\n\tВаша очередь пуста! Попробуйте добавить немного элементов\n"); }
    else {
        if (q->head == NULL) return 0;
        list* tmp;
        tmp = q->head;
        *iEl = tmp->value;
        q->head = tmp->next;
        free(tmp);
        if (q->head == NULL) q->end = NULL;
        return 1;
    }
}

//Изменить элемент в начале списка (очередь)
void changeQueueElement(queue* q, int iEl) // взять из очереди
{
    if (isQueueEmpty(q)) { printf("\n\n\tВаша очередь пуста! Попробуйте добавить немного элементов\n"); }
    else {
        q->head->value = iEl;
    }
}

//Добавить элемент в конец очереди
void addToQueue(queue* q, int iEl)
{
    list* tmp;
    tmp = CreateList();
    tmp->next = NULL;
    tmp->value = iEl;
    if (q->end != NULL)
        q->end->next = tmp;
    else
        q->head = tmp;
    q->end = tmp;
}

//Вывести очередь на экран
void printQueue(queue* q)
{
    if (!(q == NULL)) {
        if (isQueueEmpty(q)) { printf("\n\n\tВаша очередь пуста! Попробуйте добавить немного элементов\n"); }
        else {
            queue* tmp = createQueue();
            int iEl;
            while (!(q->head == NULL))
            {
                takeFromQueue(q, &iEl);
                printf("%d ", iEl);
                addToQueue(tmp, iEl);
            }
            while (!(tmp->head == NULL))
            {
                takeFromQueue(tmp, &iEl);
                addToQueue(q, iEl);
            }
        }
    }
    else {
        printf("\n\n\tНевозможно вывести очередь, т.к. она не существует \n");
    }
}

//Удалить очередь
int deleteQueue(queue** q)
{
    clearQueue(*q);
    *q = NULL;
    return 1;
}

queue* CreateQueue() {

    //Выделяем память под новый узел
    queue* result = (queue*)malloc(sizeof(queue));

    if (!result) { printf("Error: memory is no allocated"); exit(-1); }

    //Передаём значения
    result->head = NULL;
    result->end = NULL;

    return result;
}

list* CreateList() {

    //Выделяем память под новый узел
    list* result = (list*)malloc(sizeof(list));

    if (!result) { printf("Error: memory is no allocated"); exit(-1); }

    //Передаём значения
    result->value = NULL;
    result->next = NULL;

    return result;
}

Set* CreateSet() {
    //Выделяем память под новый узел
    Set* result = (Set*)malloc(sizeof(Set));

    if (!result) { printf("Error: memory is no allocated"); exit(-1); }

    //Передаём значения
    result->load = NULL;
    result->next = NULL;
    result->prev = NULL;
    result->data = NULL;

    return result;
}