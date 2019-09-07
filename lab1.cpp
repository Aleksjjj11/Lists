#include <iostream>
#include <locale.h>

using namespace std;

struct ListItem{
    ListItem *prev = NULL;
    ListItem *next = NULL;    
};

struct List {
    ListItem *head = NULL;
    ListItem *tail = NULL;
};
//возвращаемое значение нужно для отладки
int addItem(List *list, ListItem *item);
void printList(List *list);
int countList(List *list);
int getIndexByPointer(List *list, ListItem *search);
ListItem* getPointerByIndex(List *list, int index);
int deleteItem(List *list, int index);
ListItem* remove(List *list, int index);
int clearList(List *list);
int insertItem(List *list, ListItem *item, int index);

int menu(List *list);

int main(){
    setlocale(LC_CTYPE, "rus");
    int result = 0;
    List *listLoc = new List;
    do 
        result = menu(listLoc); 
    while (result > 0);
    return 0;
}

int menu(List *list){
    int chooseAction = 0;
    
    do {
        #ifdef WIN32
        system("cls");
        #else
        system("clear");
        #endif
        cout << "1. Add item" << endl
            << "2. Count list" << endl
            << "3. Get index by pointer" << endl
            << "4. Get pointer by index" << endl
            << "5. Delete item" << endl
            << "6. Remove item" << endl
            << "7. Clear list" << endl
            << "8. Insert item" << endl
            << "9. Print all list" << endl
            << "0. Exit" << endl;
        cin >> chooseAction;
    }
    while (chooseAction < 0 || chooseAction > 9);
    switch (chooseAction)
    {
    case 0:
        exit(0);
        break;
    case 1: {
        ListItem *itemLoc = new ListItem;
        return addItem(list, itemLoc);
        //break;
    }
    case 2: {
        int count = countList(list);
        cout << "Count list = " << count << endl;
        getchar(); getchar();
        return 1;
        //break;
    }
    case 3:{
        ListItem *itemLoc;
        scanf("%p", &itemLoc);
        int result = getIndexByPointer(list, itemLoc);
        if (result > 0)
            cout << "Index = " << result;
        else 
            cout << "Error: " << result;
        getchar(); getchar();
        return result;
    }
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break; 
    case 9:
        printList(list);
        break;
    default:
        break;
    }
    return 1;
}

int addItem(List *list, ListItem *item) {
    if (list == NULL) return -1;
    if (item == NULL) return -2;
    
    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        item->prev = list->tail;
        list->tail->next = item;

        item->next = NULL;
        list->tail = item;
    }
    printf("Added list item %p\n", item);
    getchar(); getchar();
    return 1;
}

void printList(List *list) {
    if (list == NULL || list->head == NULL) {
        cout << "List empty." << endl; 
        getchar(); getchar();
        return;
    }
    //printItem(list->head);
    ListItem *med = list->head;
    int i = 0;
    do {
        printf("%i. %p\n", i, med);
        med = med->next;
        i++;
    } while (med != NULL);
    getchar(); getchar();
}

int countList(List *list) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }
    int count = 0;
    ListItem *med = list->head;
    do {
        count++;
        med = med->next;
    } while (med != NULL);
    return count;
}

int getIndexByPointer(List *list, ListItem *search) {
    if (list == NULL) return -1;
    if (search == NULL) return -2;
    ListItem *med = list->head;
    int index = 0, count = countList(list);
    while(index < count && search != med) {
        index++;
        med = med->next;
    }
    if (index >= count) return -3;
    return index;
}

ListItem* getPointerByIndex(List *list, int index) {
    if (list == NULL) return NULL;
    if (index < 0 || index > countList(list)) return NULL;
    int i = 0;
    while (i < index) {
        
    }
}