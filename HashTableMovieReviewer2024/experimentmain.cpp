#include <iostream>
#include <set>
#include <unordered_set>

#include "shphashtable.h"
using namespace std;


int main() {
    cout << "Let's experiment a little bit..." << endl;

    shphashtable table(5);
    table.put("Hello this is Kelly" , 5.0);

    // table.put("Adi");
    // table.put("James");
    // table.put("Sophie");
    // table.put("Adi");
    // table.put("Peyton");
    // table.put("Kelly");
    // table.put("Sophie");
    // table.put("Katherine");
    // table.put("KMo");
    // table.put("Holman");
    //
    //
    // if(table.contains("James"))
    //     cout << "James is there" << endl;
    // if(table.contains("Ario"))
    //     cout << "Ario is there" << endl;

    table.printStats();


    return 0;
}