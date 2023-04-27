#include "itin_methods.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/* class functions */

itinerary::itinerary (){

    // will need tons of helper functions. Definitely most difficult function to write. 

}

itinerary::itinerary (string file){
    file_name = file;
}

void itinerary::view_itinerary(){
    string line;
    ifstream file;
    file.open("/Itineraries/"+file_name);

    if (file.is_open()){
    while (getline(file,line)){
        cout << line;
    }
    }
    else {
        cout << "File does not exist";
    }
    file.close();
}

void itinerary::purchase_itinerary(){



}

void itinerary::refund_itinerary(){


}
 // base 1200 + count number of days of itinerary x 300 
int itinerary::calculate_price(){

    int price=1200;
    int word_counter=0;
    int i;
    int first_digit=0;
    int second_digit=0;
    string word;
    ifstream file;

    file.open("/Itineraries/"+file_name);
    while (1){
    file >> word;
    if (word == "Departure"){ 
        break;}
    else {word_counter ++;}
    }
    file.close();

    file.open("/Itineraries/"+file_name);
    for (i=0;i<word_counter;i++){
        file >> word;
    }
    
    first_digit = word[0];
    if (word[1]<58 && word[1]>47){
        second_digit=word[1];
        }
    
    price = price + 250 *(first_digit+second_digit) ;

    cout << "The Total Cost For This Trip With All Inclusions Listed in";
    cout << "the Itinerary Will be: $"<< price <<endl;

}

/* Other Functions */

void listfiles(string folder){
    for (const auto & entry : filesystem::directory_iterator(folder))
        cout << entry.path() << endl;
}