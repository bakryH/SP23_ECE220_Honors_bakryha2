#include<iostream>
#include "itin_methods.h"
#include <string>
#include <filesystem>

using namespace std;
int main(){

int input;
int reciept_number;
string input_file;

cout << "-------------Welcome to Tailored Itinerary-----------\n";
cout << "This program will help you make your own specialized \n";
cout << "itinerary for your visit to Egypt. Make any plan for \n";
cout << " a trip to Egypt using this program and we will make \n";
cout << "it happen.\n";

cout << "\nPress 1 to create a new itinerary\n";
cout << "Press 2 to view template itineraries\n";
cout << "Press 3 to make a transaction on an exisiting itinerary\n";
cout << "press 4 cancel a trip and recieve a refund";
cout << "Press 9 at anytime to quit";

do
{
cin >> input;
if (input==1) {itinerary new_itinerary();}
else if (input==2) {
    cout << "Please Input an Exisitng File Name to View.\n";
    cout << "Available files:\n";
    listfiles("/Itineraries");
    cout << "View : ";
    cin >> input_file;
    itinerary template_itinerary(input_file);
    template_itinerary.view_itinerary();
    }
else if (input==3) {
    cout << "Please Input an Exisitng File Name to Make a Purchase.\n";
    cout << "Available files:\n";
    listfiles("/Itineraries");
    cout << "\nPurchase : ";
    cin >> input_file;
    itinerary purchase_itinerary(input_file);
    purchase_itinerary.purchase_itinerary();
}
else if (input==4) {
    cout << "Please Input Your Receipt Number Below.\n";
    cout << "Reciept Number:";
    cin >> reciept_number;

    // In the future, find a way to check if reciept number is valid by storing
    // all reciept numbers given out to customers in an external database and then 
    // checking with this database at this step. The database would also contain
    // the type of itinerary bought. For now, the code will continue assuming
    // this step is implemented, allowing this to be step to be implemented later 

    itinerary cancel_itinerary("itinerary_from_database");
    cancel_itinerary.refund_itinerary();
}
else if (input==9) {return 0;}
else {cout<<"Please choose one of the above options.\n";}
} while ((input>4&&input<1)||input!=9);

return 0;
}