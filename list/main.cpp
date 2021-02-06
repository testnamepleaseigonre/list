#include <iostream>
using namespace std;
void menu()
{
    cout << "-----------------List-------------------" << endl;
    cout << "1  - Sukurti sarasa" << endl;
    cout << "2  - Atspausdinti nuo pradzios" << endl;
    cout << "3  - Atspausdinti nuo pabaigos" << endl;
    cout << "4  - Iterpti pagal pozicija" << endl;
    cout << "5  - Iterpti pries elementa" << endl;
    cout << "6  - Koreguoti pagal pozicija" << endl;
    cout << "7  - Istrinti reiksme" << endl;
    cout << "8  - Istrinti pagal pozicija" << endl;
    cout << "9  - Istrinti sarasa" << endl;
    cout << "10 - Elemento paieska" << endl;
    cout << "0 - Exit" << endl;
    cout << "----------------------------------------" << endl;
}
struct data
{
    data* front;
    int num;
    data* end;
};
void list_creation(data* &beginning_list_adress, data* &end_list_adress)
{
    if(beginning_list_adress == NULL)
    {
        int choice = 0;
        while(choice < 3)
        {
            cout << "Enter the number of items in the list (min 3) - ";
            cin >> choice;
            if(choice < 3)
            {
                cout << "There was a mistake!" << endl;
            }
        }
        if(choice == 3)
        {
            beginning_list_adress = new data;
            beginning_list_adress -> front = NULL;
            cout << "Element 1 data: ";
            cin >> beginning_list_adress -> num;
            data* temp = new data;
            beginning_list_adress -> end = temp;
            temp -> front = beginning_list_adress;
            cout << "Element 2 data: ";
            cin >> temp -> num;
            end_list_adress = new data;
            temp -> end = end_list_adress;
            end_list_adress -> front = temp;
            cout << "Element 3 data: ";
            cin >> end_list_adress -> num;
            end_list_adress -> end = NULL;
        }
        else
        {
            beginning_list_adress = new data;
            beginning_list_adress -> front = NULL;
            cout << "Element 1 data: ";
            cin >> beginning_list_adress -> num;
            data* standing = beginning_list_adress;
            for(int i = 2; i < choice ; i++)
            {
                data* temp = new data;
                standing -> end = temp;
                temp -> front = standing;
                cout << "Element " << i << " data: ";
                cin >> temp -> num;
                standing = standing -> end;
            }
            data* temp = new data;
            standing -> end = temp;
            temp -> front = standing;
            cout << "Element " << choice << " data: ";
            cin >> temp -> num;
            temp -> end = NULL;
            end_list_adress = temp;
        }
    }
    else
    {
        cout << "List already created!" << endl;
    }
}
void print_beginning(data* beginning_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        cout << "-----------------List-------------------" << endl;
        while(beginning_list_adress != NULL)
        {
            cout << beginning_list_adress -> num << endl;
            beginning_list_adress = beginning_list_adress -> end;
        }
        cout << "----------------------------------------" << endl;
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void print_end(data* end_list_adress)
{
    if(end_list_adress != NULL)
    {
        cout << "------------List Backwards--------------" << endl;
        while(end_list_adress != NULL)
        {
            cout << end_list_adress -> num << endl;
            end_list_adress = end_list_adress -> front;
        }
        cout << "----------------------------------------" << endl;
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void insert_position(data* &beginning_list_adress, data* &end_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        int choice = 0;
        while(choice < 1)
        {
            cout << "Enter position: ";
            cin >> choice;
            if(choice < 1)
            {
                cout << "Something went wrong!" << endl;
            }
        }
        if(choice == 1)
        {
            data* temp = new data;
            temp -> front = NULL;
            cout << "Enter element: ";
            cin >> temp -> num;
            temp -> end = beginning_list_adress;
            beginning_list_adress -> front = temp;
            beginning_list_adress = temp;
        }
        else
        {
            bool check = true;
            data* before = beginning_list_adress;
            data* standing = beginning_list_adress -> end;
            for(int i = 2; i < choice; i++)
            {
               if(before -> end == NULL)
               {
                   check = false;
                   break;
               }
               else
               {
                   standing = standing -> end;
                   before = before -> end;
               }
            }
            if(check == true)
            {
                if(before -> end == NULL)
                {
                    data* temp = new data;
                    end_list_adress -> end = temp;
                    temp -> front = end_list_adress;
                    cout << "Enter element: ";
                    cin >> temp -> num;
                    temp -> end = NULL;
                    end_list_adress = temp;
                }
                else
                {
                    data* temp = new data;
                    before -> end = temp;
                    temp -> front = before;
                    temp -> end = standing;
                    standing -> front = temp;
                    cout << "Enter element: ";
                    cin >> temp -> num;
                }
            }
            else
            {
                cout << "Something went wrong!" << endl;
            }
        }
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void insert_bynumber(data* &beginning_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        int choice;
        cout << "Enter a number to put data before: ";
        cin >> choice;
        if(beginning_list_adress -> num == choice)
        {
            data* temp = new data;
            temp -> front = NULL;
            cout << "Enter element: ";
            cin >> temp -> num;
            temp -> end = beginning_list_adress;
            beginning_list_adress -> front = temp;
            beginning_list_adress = temp;
        }
        else
        {
            data* standing = beginning_list_adress;
            while(standing != NULL)
            {
                if(standing -> num == choice)
                {
                    data* temp = new data;
                    standing -> front -> end = temp;
                    temp -> front = standing -> front;
                    temp -> end = standing;
                    standing -> front = temp;
                    cout << "Enter element: ";
                    cin >> temp -> num;
                    break;
                }
                else
                {
                    standing = standing -> end;
                }
            }
            if(standing == NULL)
            {
                cout << "Something went wrong!" << endl;
            }
        }
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void modify_position(data* beginning_list_adress)
{
    int choice = 0;
    while(choice < 1)
    {
        cout << "Enter position: ";
        cin >> choice;
        if(choice < 1)
        {
            cout << "Something went wrong!" << endl;
        }
    }
    if(choice == 1)
    {
        cout << "Enter data to change: ";
        cin >> beginning_list_adress -> num;
        cout << "Data succesfully changed!" << endl;
    }
    else
    {
        bool check = true;
        data* standing = beginning_list_adress;
        for(int i = 1; i < choice; i++)
        {
            if(standing -> end == NULL)
            {
                check = false;
                break;
            }
            else
            {
                standing = standing -> end;
            }
        }
        if(check == true)
        {
            cout << "Enter data to change: ";
            cin >> standing -> num;
            cout << "Data succesfully changed!" << endl;
        }
        else
        {
            cout << "Something went wrong!" << endl;
        }
    }
}
void delete_number(data* &beginning_list_adress, data* &end_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        if(beginning_list_adress -> end -> end -> end != NULL)
        {
            int choice;
            cout << "Enter a number to delete: ";
            cin >> choice;
            data* temp;
            if(beginning_list_adress -> num == choice)
            {
                temp = beginning_list_adress;
                beginning_list_adress = beginning_list_adress -> end;
                beginning_list_adress -> front = NULL;
                temp -> num = 0;
                temp -> end = NULL;
                delete temp;
                cout << "Data succesfully deleted!" << endl;
            }
            else
            {
                if(end_list_adress -> num == choice)
                {
                    temp = end_list_adress;
                    end_list_adress = end_list_adress -> front;
                    end_list_adress -> end = NULL;
                    temp -> num = 0;
                    temp -> front = NULL;
                    delete temp;
                    cout << "Data succesfully deleted!" << endl;
                }
                else
                {
                    temp = beginning_list_adress;
                    while(temp != NULL)
                    {
                        if(temp -> num == choice)
                        {
                            break;
                        }
                        else
                        {
                            temp = temp -> end;
                        }
                    }
                    if(temp != NULL)
                    {
                        temp -> front -> end = temp -> end;
                        temp -> end -> front = temp -> front;
                        temp -> front = NULL;
                        temp -> end = NULL;
                        temp -> num = 0;
                        delete temp;
                        cout << "Data succesfully deleted!" << endl;
                    }
                    else
                    {
                        cout << "Something went wrong!" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "ERROR (minimum 3 elements)!" << endl;
        }
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void delete_byposition(data* &beginning_list_adress, data* &end_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        if(beginning_list_adress -> end -> end -> end != NULL)
        {
            int choice = 0;
            while(choice < 1)
            {
                cout << "Enter position: ";
                cin >> choice;
                if(choice < 1)
                {
                    cout << "Something went wrong!" << endl;
                }
            }
            if(choice == 1)
            {
                data* temp = beginning_list_adress;
                beginning_list_adress = beginning_list_adress -> end;
                beginning_list_adress -> front = NULL;
                temp -> num = 0;
                temp -> end = NULL;
                delete temp;
                cout << "Data succesfully deleted!" << endl;
            }
            else
            {
                bool check = true;
                data* standing = beginning_list_adress;
                for(int i = 1; i < choice; i++)
                {
                    if(standing -> end == NULL)
                    {
                        check = false;
                        break;
                    }
                    else
                    {
                        standing = standing -> end;
                    }
                }
                if(check == true)
                {
                    if(standing -> end == NULL)
                    {
                        standing -> num = 0;
                        standing = standing -> front;
                        standing -> end -> front = NULL;
                        delete standing -> end;
                        standing -> end = NULL;
                        end_list_adress = standing;
                        cout << "Data succesfully deleted!" << endl;
                    }
                    else
                    {
                        standing -> end -> front = standing -> front;
                        standing -> front -> end = standing -> end;
                        standing -> front = NULL;
                        standing -> num = 0;
                        standing -> end = NULL;
                        delete standing;
                        cout << "Data succesfully deleted!" << endl;
                    }
                }
                else
                {
                    cout << "Something went wrong!" << endl;
                }
            }
        }
        else
        {
            cout << "ERROR (minimum 3 elements)!" << endl;
        }
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void list_delete(data* &beginning_list_adress, data* &end_list_adress)
{
    if(beginning_list_adress != NULL)
    {
        data* temp = beginning_list_adress;
        beginning_list_adress = beginning_list_adress -> end;
        while(temp -> end != NULL)
        {
            temp -> front = NULL;
            temp -> num = 0;
            temp -> end = NULL;
            delete temp;
            temp = beginning_list_adress;
            beginning_list_adress = beginning_list_adress -> end;
        }
        temp -> num = 0;
        temp -> end = NULL;
        temp -> front = NULL;
        end_list_adress = NULL;
        cout << "List succesfully deleted!" << endl;
    }
    else
    {
        cout << "List was not created!" << endl;
    }
}
void find_number(data* beginning_list_adress, data* end_list_adress)
{
    int choice;
    int place = 1;
    bool atleast = false;
    cout << "Enter element: ";
    cin >> choice;
    data* temp = beginning_list_adress;
    cout << "----------------------------------------" << endl;
    while(temp != NULL)
    {
        if(temp -> num == choice)
        {
            atleast = true;
            cout << "Value: " << temp -> num << " ";
            cout << "Place: " << place << endl;
            temp = temp -> end;
        }
        else
        {
            temp = temp -> end;
            place++;
        }
    }
    if(atleast == false)
    {
        cout << "No data found!" << endl;
        cout << "----------------------------------------" << endl;
    }
    else
    {
        cout << "----------------------------------------" << endl;
    }
}
int main()
{
    data* beginning_list_adress = NULL;
    data* end_list_adress = NULL;
    bool main_menu = true;
    int choice;
    menu();
    while(main_menu == true)
    {
        cout << "Which menu option do you choose? - ";
        cin >> choice;
        switch(choice)
        {
            case 0 :
            main_menu = false;
            break;
            case 1 :
            list_creation(beginning_list_adress, end_list_adress);
            break;
            case 2 :
            print_beginning(beginning_list_adress);
            break;
            case 3 :
            print_end(end_list_adress);
            break;
            case 4 :
            insert_position(beginning_list_adress, end_list_adress);
            break;
            case 5 :
            insert_bynumber(beginning_list_adress);
            break;
            case 6 :
            modify_position(beginning_list_adress);
            break;
            case 7 :
            delete_number(beginning_list_adress, end_list_adress);
            break;
            case 8 :
            delete_byposition(beginning_list_adress, end_list_adress);
            break;
            case 9 :
            list_delete(beginning_list_adress, end_list_adress);
            break;
            case 10 :
            find_number(beginning_list_adress, end_list_adress);
            break;
            default :
            cout << "No such option!" << endl;
            break;
        }
    }
    return 0;
}
