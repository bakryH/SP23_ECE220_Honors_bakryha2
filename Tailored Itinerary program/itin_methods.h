#ifndef Itin_Methods_h
#define Itin_Methods_h

#include <fstream>

using namespace std;

class itinerary {
    public:
    //functions
    itinerary (); // creates new uninitialized itinerary

    void create_itinerary(); // calls different functions to create itinerary;
    void set_date(); // sets date of itinerary
    void set_trip_type(); // chooses trip type. Will be used as my itinerary title.
    void choose_sites(); // takes user input and generates the string that tells what sites the user will visit
    void generate_itinerary(string file);
    int calculate_days();

    void view_itinerary(); // function that prints out an itinerary given it has a file_name
    void purchase_itinerary(); // function that emulates a purchase of an itinerary given a file_name
    void refund_itinerary(); // function emulates a refund process given a file_name
    int calculate_price(); // calculates price of an exisiting itinerary based on number of days
    int file_existence_check(string file); // checks if a file exists
    void set_file_name(string file_); // changes file_name of object 
    int valid_string(string sites, int max_length, int length); // checks if string user enters is valid
    // Data
    string file_name; // file name of itinerary
    string sites_cairo; // sites to visit in cairo
    string sites_luxor;
    string sites_aswan;
    string sites_hurghada;
    int price_of_itinerary;
    int month_s, day_s, year_s; // starting date of trip
    int month_e, day_e, year_e; // ending date of trip
    int trip_type;  // Itinerary Title
    //int cruise_flag;
    //int hotel_flag;
};

void listfiles(string folder);

#endif