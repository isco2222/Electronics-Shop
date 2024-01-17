#include <iostream>
#include "store.cpp"
#include "costumer.cpp"
using namespace std;

int main() {

/*
  string name, id, address;
  int InORUp;
  int first_switcher = 0;
  int first_case1_switcher = 0;
  int first_case2_switcher = 0;
  int first_case3_switcher = 0;
  int first_case4_switcher = 0;

  cout << "Wellcome to our store \n";
  cout << "Enter name, id and address\n";
  getline(cin, name); cin >> id; getline(cin, address);
  costumer AAAA(name, id, address);
  
  
  

  cout << "Press 1: To view gatalog\n";
  cout << "Press 2: To view bag\n";
  cout << "Press 3: To view your orders\n";

  cin >> first_switcher;

  switch (first_switcher){
    case 1: {
      cout << "Catalog: \n";
      cout << "Press 1: To view Gaming gatalog\n";
      cout << "Press 2: To view Appel products\n";
      cout << "Press 3: To view Samsung products\n";
      cout << "Press 4: To view General electronic\n";
      cout << "Go back\n";
      cout << "\n";
      cin >> first_case1_switcher;

      switch (first_case1_switcher)
        case 1:
          cout << "Not implemented yet\n";
    }
    case 2: {
      cout << "BAG: \n";
      cout << "Press 1: To Checkout\n";
      cout << "Press 2: To Remove an item\n";
      cout << "Go back\n";
      cout << "\n";
      cin >> first_case2_switcher;

      switch (first_case2_switcher){
        case 1:
          AAAA.CartCeckout();
        case 2:
          string remove;
          cout << "Type item name \n"; cin >> remove;
          AAAA.RemoveFromCart(remove);
      }
    }

    case 3:
      cout << "Orders: \n";
      cout << "Press 1: To Buy again\n";
      cout << "Press 2: To view details\n";
      cout << "Go back\n";
      cout << "\n";
      cin >> first_case1_switcher;
  }
  */



  //Items
  item s22(samsung, "S22 Ultra", phone,"124578" ,"Best phone in the place", 1199.99);
  item ps5(apple, "PS5", phone,"963852" ,"8th generation consoloe", 499.99);
  item hppc(apple, "hp", pc,"741852" ,"Small laptop", 399.99);
  item GTA5(apple, "GTA5", pc,"789456" ,"New gen Adpt", 59.99);
  item FarCry(apple, "FarCry", phone,"123456" ,"New gen Adpt", 49.99);
  item mac(apple, "MacBook", pc,"456123" ,"Small Laptop", 1299.99);

  //Customers
  costumer abc("Francis", "0123456", "700 university DR");
  
  //ps5.displayItem();//
  abc.viewCart();
  cout << endl << endl;
  abc.addToCart(s22);
  abc.addToCart(ps5);
  abc.addToCart(hppc);
  abc.addToCart(GTA5);
  abc.addToCart(FarCry);
  abc.addToCart(mac);
  abc.viewCart();
  abc.RemoveFromCart("MacBook");///
  cout << endl << endl;
  abc.viewCart();
  

  abc.CartCheckout();
  cout << "\n\n";
  abc.viewCart();
  //cout << "\n\n";
  //abc.returnLast();
  //cout << "\n\n";
  //abc.returnItem("GTA5");  
  //cout << "\n\n";
  //abc.viewOrderList();
  /////
  
  
  return 0;
};