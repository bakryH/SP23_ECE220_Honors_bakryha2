#ifndef Itin_Methods_h
#define Itin_Methods_h

#include <fstream>

using namespace std;

class itinerary {
    public:
    itinerary (); // creates new uninitialized itinerary
    itinerary (string file); // creates new itinerary with initialized filename. May be useless now. Consider removing.
    void create_itinerary();
    void view_itinerary(); // function that prints out an itinerary given it has a file_name
    void purchase_itinerary(); // function that emulates a purchase of an itinerary given a file_name
    void refund_itinerary(); // function emulates a refund process given a file_name
    int calculate_price(); // calculates price of an exisiting itinerary based on number of days
    int file_existence_check(); // checks if a file exists
    void set_file_name(string file_); // changes file_name of object 
    string file_name;
};

void listfiles(string folder);

#endif