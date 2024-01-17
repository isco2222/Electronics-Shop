#ifndef store
#define store

#include <iostream>
using namespace std;

enum kind{phone, pc};
enum brand{samsung, apple};

class item{
  protected:
    string name;
    kind category ;
    string description;
    double price;
    brand Brand;

 //Public data memebers
  public:
    string id;

  //Default Constructor
  item(){
      name = id = description = " ";
      category = phone;
      price = 0;
      Brand = apple;}

  //Parameterized Constructor
  item(brand BRAND, string NAME, kind CATEGORY, string ID, string DESC, 
      double PRICE){
      name = NAME;
      id = ID;
      category = CATEGORY;
      description = DESC;
      price = PRICE;
      Brand = BRAND;
    }

    string getName() { return name;}

    void displayItem(){ cout << "Name " <<  name << endl;}
};

#endif