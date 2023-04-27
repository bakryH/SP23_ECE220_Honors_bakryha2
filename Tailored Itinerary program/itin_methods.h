#ifndef Itin_Methods_h
#define Itin_Methods_h

#include <fstream>

using namespace std;

class itinerary {
    public:
    itinerary (); // creates new itinerary
    itinerary (string file); // initializes an exisiting itinerary to read or purchase. (calls either function)
    void view_itinerary(); // function that prints out an itinerary given it has a file_name
    void purchase_itinerary(); // function that emulates a purchase of an itinerary given a file_name
    void refund_itinerary(); // function emulates a refund process given a file_name
    int calculate_price();
    string file_name;
    //private:
    //int flag_to_verify_purchase;
};

void listfiles(string folder);

#endif