#include "itin_methods.h"
#include <string>
#include <iostream>

using namespace std;

itinerary::itinerary (){


}

itinerary::itinerary (string file){
    file_name =file;
}

void itinerary::view_itinerary(){


}

void itinerary::purchase_itinerary(){


}

void refund_itinerary(){


}

void listfiles(string folder){
    for (const auto & entry : filesystem::directory_iterator(folder))
        cout << entry.path() << endl;
}