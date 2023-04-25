#ifndef Itin_Methods_h
#define Itin_Methods_h

#include <fstream>

using namespace std;

class itinerary {
    public:
    itinerary (); // creates new itinerary
    itinerary (string file); // initializes an exisitng itinerary to read or purchase. (calls either function)
    void view_itinerary();
    void purchase_itinerary();
    void refund_itinerary();
    string file_name;
    
};

void listfiles(string folder);
#endif