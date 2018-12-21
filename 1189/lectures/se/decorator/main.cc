#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "pizza.h"
#include "topping.h"
#include "stuffedcrust.h"
#include "dippingsauce.h"
#include "crustandsauce.h"

int main() {
  Pizza *myPizzaOrder[3];
  myPizzaOrder[0] = new Topping{"pepperoni",
                      new Topping{"cheese", new CrustAndSauce}};
  myPizzaOrder[1] = new StuffedCrust{
                      new Topping{"cheese",
                        new Topping{"mushrooms",
                          new CrustAndSauce}}};
  myPizzaOrder[2] = new DippingSauce{"garlic",
                      new Topping{"cheese",
                        new Topping{"cheese",
                          new Topping{"cheese",
                            new Topping{"cheese",
                              new CrustAndSauce}}}}};

  float total = 0.0;

  for (int i = 0; i < 3; ++i) {
    cout << myPizzaOrder[i]->description()
         << ": " << myPizzaOrder[i]->price() << endl;
    total += myPizzaOrder[i]->price();
  }

  cout << endl << "Total cost: " << total << endl;

  for (int i = 0; i < 3; ++i) {
    delete myPizzaOrder[i];
  }
}
