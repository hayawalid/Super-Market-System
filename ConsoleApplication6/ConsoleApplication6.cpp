// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<fstream>
#include<Stdlib.h>
#include<string>
using namespace std;


const int NUM_OF_ITEMS = 100;
struct  product
{
    string name;
    int price,discount;
    int quantity,num;


};

product superMarketProduct[NUM_OF_ITEMS];
product shoppingCart[NUM_OF_ITEMS];
product itemlist[NUM_OF_ITEMS];




void update_name() {
    // owner hay-cin string name
    int num = 10;
    bool name_found = false;
    string name_modification, newname;
    cout << " please enter the name of the product " << endl;
    cin >> name_modification;

    for (int i = 0; i < num; i++) {
        if (name_modification == itemlist[i].name) {

            cout << "please enter the new name : " << endl;
            cin >> newname;
            name_found = true;
        }
    }
    if (name_found != true) {
        itemlist[num + 1].name = name_modification;
        cout << "please enter price : " << endl;
        int price;
        cin >> price;
        itemlist[num + 1].price = price;
        num++;
    }
}

void update_price() {

    cout << "please enter the item name : " << endl;
    string name, newname;
    int new_price;
    cin >> name;
    int num = 10;
    for (int i = 0; i < num; i++) {
        if (name == itemlist[i].name) {

            cout << "please enter the new price : " << endl;
            cin >> new_price;
            itemlist[i].price = new_price;

        }
    }
}


void previewCart() {

    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        cout << "the name of product= " << shoppingCart[i].name << endl;
        cout << "the quantity= " << shoppingCart[i].quantity << endl;
        cout << "the price of item = " << shoppingCart[i].price << endl;
        cout << "the amount= " << shoppingCart[i].price * shoppingCart[i].quantity << endl;
        
    }

}


void search_product()
{
    string productName;
    cout << "Enter product name:";
    cin >> productName;
    int itemFound = 0;

    for (int i = 0; i < NUM_OF_ITEMS; i++)
    {
        if (productName == superMarketProduct[i].name)
        {
            cout << "Product Name: " << superMarketProduct[i].name << "\n";
            cout << "Product Price: " << superMarketProduct[i].price << "\n";
            itemFound = 1;
            break;
        }

    }

    if (itemFound != 1)
        cout << "Product " << productName << " Not Found!\n";
  //  add_cart();
}



void total_price()
{
    float totalPrice=0;
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        totalPrice =totalPrice+ shoppingCart[i].price;
    }
    cout <<"total price"<< totalPrice;
}


void add_cart()
{
    int x;
    string productName;
    int counter = 0;
    cout << "Enter product name to add in cart";
    cin >> productName;
    if (productName.empty())
        cout << "Product name cannot be empty.";
    else {
        for (int i = 0; i < NUM_OF_ITEMS; i++)
        {
            if (productName == superMarketProduct[i].name)
            {
                shoppingCart[counter] = superMarketProduct[i];
                counter++;
                cout << "Product added successfully.";
                total_price();
                break;
            }
            else
            {
                cout << "Product not found.";
            }

        }
    }

    cout << "1)preview cart" << endl << "2)search in cart"<<endl;
    cin >> x;

    if(x==1)
    previewCart();
  //  else if(x==2)
    //search_cart();
}

void search_cart()
{

    string productName;
    cout << "Enter product name:";
    cin >> productName;
    int itemFound = 0;

    for (int i = 0; i < NUM_OF_ITEMS; i++)
    {
        if (productName == shoppingCart[i].name)
        {
            cout << "quantity: " << shoppingCart[i].quantity << endl;
            cout << "Product Name: " << shoppingCart[i].name << endl;
            cout << "Total Price: " << shoppingCart[i].quantity * shoppingCart[i].price << endl;
            itemFound = 1;
            break;
        }

    }

    if (itemFound != 1)
        cout << "Product " << productName << " Not Found in the shopping cart!\n";
    add_cart();
}


void creating_List()
{
    char x;
    for (int i = 0; i < 50; i++)
    {
        cout << "Enter the product number: ";
        cin >> superMarketProduct[i].num;
        cout << "Enter the name of the product: ";
        cin >> superMarketProduct[i].name;
        cout << "Enter the discount: ";
        cin >> superMarketProduct[i].discount;
        cout << "Enter the price: ";
        cin >> superMarketProduct[i].price;
        cout << "enter the product quantity";
        cin >> superMarketProduct[i].quantity;
        cout << "The product has been created" << endl;
        cout << "Want to add more (yes or no)? ";
        cin >> x;
        if (x == !'yes')
            break;
    }
}
//preview list of products function
void preview_list_customer()//customer
{
    for (int i = 0; i < NUM_OF_ITEMS; i++)
    {
        cout << "The product number is: " << superMarketProduct[i].num;
        cout << "The name of the product is: " << superMarketProduct[i].name;
        cout << "The discount is: " << superMarketProduct[i].discount;
        cout << "The price is: " << superMarketProduct[i].price;
        cout << "the quantity is : " << superMarketProduct[i].quantity;
    }
    add_cart();
}
void preview_list_owner()//owner
{
    for (int i = 0; i < NUM_OF_ITEMS; i++)
    {
        cout << "The product number is: " << superMarketProduct[i].num;
        cout << "The name of the product is: " << superMarketProduct[i].name;
        cout << "The discount is: " << superMarketProduct[i].discount;
        cout << "The price is: " << superMarketProduct[i].price;
        cout << "the quantity is : " << superMarketProduct[i].quantity;
    }
    
}


int main()
{
    superMarketProduct[0].name = "egg";
    superMarketProduct[0].price = 10;

    superMarketProduct[1].name = "bread";
    superMarketProduct[1].price = 30;

    superMarketProduct[2].name = "milk";
    superMarketProduct[2].price = 50;


    int num, x, y;
    do {
        cout << "1)CUSTOMER\t";
        cout << "2)OWNER\t";
        cout << "3)END\t";
        cout << " Select Your Option (1-3)\t ";
        cin >> num;
        switch (num)

        {
        case '1':
            cout << "1)search for a certain product=\t";
            cout << "2) preview all products\t";
            cout << "select from(1-2)";
            cin >> x;

            if (x == 1)
                search_product();
            else if (x == 2)
                preview_list_customer();
            break;
        case '2':
            cout << "1)Add/creat products to list\t";
            cout << "2)preview all products \t";
            cout << "3)Edit product list\t";
            cin >> y;
            if (y == 1)
                creating_List();
            else if (y == 2)
                preview_list_owner();
            else if (y == 3) {
                update_name();
                update_price();
            }
            break;
        case '3':exit(0);

            break;

        } 

    } while (num != 3);
}





 
    
    
    
   

