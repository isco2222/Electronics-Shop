#ifndef COSTUMER
#define COSTUMER

#include "store.cpp"
#include <iostream>
using namespace std;

struct OrderList {
  item Items;
  OrderList *next;
};

struct cart {
  item ItemInCart;
  cart *nextToCart;
};

class costumer {
private:
  string name;
  string ID;
  string Address;
  // item Items;
  OrderList *head;
  cart *cartHead;

public:
  // constructors
  costumer() { name = ID = Address = ""; }

  costumer(string Name, string id, string addss) {
    name = Name;
    ID = id;
    Address = addss;
  }

  // display
  void costumerDisplay(item check) { check.displayItem(); }

  // CART FUNCTIONS

  // View the items in the cart
  void viewCart() {
    cart *temp;
    if (cartHead == NULL) {
      cout << "Your cart is empty!\n";
    } else {
      temp = cartHead;
      cout << "CART\n\n";
      while (temp != NULL) {
        costumerDisplay(temp->ItemInCart);
        cout << "\n";
        temp = temp->nextToCart;
      }
    }
  }

  // Add an item in the cart
  void addToCart(item ToCart) {
    cart *NewItemToCart = new cart;
    NewItemToCart->ItemInCart = ToCart;
    NewItemToCart->nextToCart = NULL;

    if (cartHead == NULL) {
      cartHead = NewItemToCart;
    }

    else {
      NewItemToCart->nextToCart = cartHead;
      cartHead = NewItemToCart;
    }
  }
  // Remove an item from the cart
  void RemoveFromCart(string ItemToRemove)
    {
      if (cartHead->ItemInCart.getName() == ItemToRemove)
      {
        delete cartHead;
        cartHead = cartHead->nextToCart;
        return;
      }

      if (cartHead->nextToCart == NULL)
      {
        if (cartHead->ItemInCart.getName() == ItemToRemove)
        {
          delete cartHead;
          cartHead = NULL;
          return;
        }
        cout << "You don't have this item in your cart" << endl;
        return;
      }

      cart* temp = cartHead;
      while(temp->nextToCart != NULL)
      {

        if (temp->nextToCart->ItemInCart.getName() == ItemToRemove)
        {
          cart* temp_ptr = temp->nextToCart->nextToCart;
          delete temp->nextToCart;
          temp->nextToCart = temp_ptr;
          return;
        }
        temp = temp->nextToCart;
      }

      cout << "You don't have this item in your cart" << endl;
    }


  // Checkout for individual items
  void Checkout(item ItemToCheckout) {
    cout << "Thank you for your purchse!\n";
    // ItemToCheckout.displayItem();
    //addToOrderList(ItemToCheckout);           // Add the item to the list
    RemoveFromCart(ItemToCheckout.getName()); // Delete item from the cart
  }

  // Checkout  for all the items in the cart
  void CartCheckout() {
    cart *tempo = cartHead;
    if (cartHead == NULL) {
      cout << "Your cart is empty!\n";
    } 
    else {
      while (tempo != NULL) {
        Checkout(tempo->ItemInCart);
        tempo = tempo->nextToCart;
      }
    }
  }

  // Include bought items to the order list
  void addToOrderList(item ITEM) {
    OrderList *NewItem = new OrderList;

    NewItem->Items = ITEM;
    NewItem->next = NULL;

    if (head == NULL) {
      head = NewItem;
    }

    else {
      NewItem->next = head;
      head = NewItem;
    }
  }

  // Return an item to the store
  void returnItem(string retItem) {
    OrderList *temp;
    if (head == NULL) {
      cout << "You have no purchases yet!\n";
    } else {
      temp = head;
      string checker = temp->next->next->Items.id;
      while (temp->next != NULL) {
        if (checker == retItem) {
          OrderList *temp_P = temp->next->next;
          delete temp->next;
          temp->next = temp_P;

          cout << "Your return was successful made\n";
        } else {
          cout << "You never purchased this Item\n";
        }
        //////////////////////note: RETURN TO STOCK!!!!!
      }
    }
  }

  void viewOrderList() {
    OrderList *temp;
    if (head == NULL) {
      cout << "You have no purchased yet!\n";
    } else {
      temp = head;
      cout << "Previus Purchases\n\n";
      while (temp != NULL) {
        temp->Items.displayItem();
        cout << "\n";
        temp = temp->next;
      }
    }
  }

  // return
  void returnLast() {
    OrderList *temp;
    if (head == NULL) {
      cout << "You have no purchased yet!\n";
    } else {
      temp = head;
      head = head->next;
      delete temp;

      cout << "Your return was successfuly made\n";
    }
  }
};

#endif