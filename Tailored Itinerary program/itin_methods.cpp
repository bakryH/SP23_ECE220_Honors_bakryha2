#include "itin_methods.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/* class functions */

itinerary::itinerary (){
    file_name = "To Be Set";
    sites_cairo = sites_aswan = "000000";
    sites_luxor = "0000000";
    month_e = month_s = day_e = day_s = year_e = year_s = trip_type = 0;
}

void itinerary::create_itinerary(){
    // after all user input is gathered, generates itinerary txt file. 
}

void itinerary::set_date(){
    // Consider splitting work of this function into smaller functions. 
    int flag=0;
    int change_date_flag=0;

    cout << "What is the Time Window in Which you Would Like to Visit?\n";
    do {
    cout << "Start Trip as Early as: \n";
    cout << "-----------------------\n";

        do {
            cout << "Year: ";
            cin >> year_s;
            if (year_s < 2023){
                cout << "Please Enter A Valid Year.\n";
                continue;
            }
            if (year_s>2024){
                cout << "Sorry, We Cannot Create Itineraries for More Than 2 Years in the Future.\n";
                continue;
            }
            else {flag=1;}
        } while(!flag);

        flag = 0;

        do {
            cout << "Month: ";
            cin >> month_s;
            if (month_s > 0 && month_s < 13) {flag = 1;}
            else {cout << "Invalid Month. Please Try Again\n";}
        } while(!flag);

        flag = 0;

        do {
            cout << "Day: ";
            cin >> day_s;
            if (day_s<1||day_s>31){
                cout << "Invalid Day. Please Try Again\n";
                continue;
            }
            else if (month_s==2 && day_s>28){
                // does not take into account possibility of a leap year.
                cout << "Invalid Day. Please Try Again\n";
                continue;
            }
            else if ((month_s == 4 || month_s == 6 || month_s == 9 || month_s == 11)&& (day_s>30)){
                cout << "Invalid Day. Please Try Again\n";
                continue;
            }
            else {flag=1;}
        } while (!flag);

        flag = 0;

        do {
            cout << "So You Would Like to Visit as Early as:\n";
            cout << "---------------------------------------\n";
            cout << month_s << "/" << day_s << "/" << year_s << "\n";
            cout << "Is That correct?\n";
            cout << "--Press 1 If that is Correct.\n--Press 2 to Change this Date.\n";
            cin >> change_date_flag;
            if (change_date_flag==2) {
                change_date_flag=0;
                break;
            }
            if (change_date_flag == 1){
               break;
            }
            else {
                change_date_flag = 0;
                cout << "Invalid Input\n";
            }
        }while  (1);

    } while (!change_date_flag);

    change_date_flag = 0;

    do {
        cout << "End Trip As Late As:\n";
        cout << "--------------------\n";

        do {
            cout << "Year: \n";
            cin >> year_e;
            if (year_e<2023){
                cout << "Please Enter A Valid Year.\n";
                continue;
            }
            else if (year_e<year_s){
                cout << "Departure Date Must be After Arrival Date.\n";
                continue;
            }
            else if (year_e>2024){
            cout << "Sorry, We Cannot Create Itineraries for More Than 2 Years in the Future.\n";
            continue; 
            }
            else if (year_e==year_s){flag=1;}
            else if (year_e>year_s && month_s == 12) {flag = 1;}
            else {cout<< "Maximum Length of A Trip Should Not Exceed One Month.\n";}

        } while(!flag);

        flag = 0;

        do {
            cout << "Month: \n";
            cin >> month_e;
            if (month_e>0 && month_e<13){
                if (year_e==year_s){
                    if (month_e==month_s || month_e==month_s+1){
                        flag = 1;
                    }
                    else if (month_e<month_s){
                        cout << "Departure Date Must be After Arrival Date.\n";
                    }
                    else if (month_e>month_s){
                        cout << "Maximum Length of A Trip Should Not Exceed One Month.\n";
                    }
                }
                else if (year_e>year_s && month_e == 1 && month_s == 12){
                    flag = 1;
                }
                else {
                    cout << "Maximum Length of A Trip Should Not Exceed One Month.\n";
                }
            }
            else {
                cout << "Invalid Month. Please Try Again\n";
            }
        } while(!flag);

        flag = 0;

        do {
            cout << "Day: \n";
            cin >> day_e;
            // consider making this a seperate function.
            if (day_e<1||day_e>31){
                cout<<"Invalid Day. Please Try Again.\n";
                continue;
            }
            else if (month_e==2 && day_e>28){
            // does not take into account possibility of a leap year.
            cout << "Invalid Day. Please Try Again\n";
            continue;
            }
            else if ((month_e == 4 || month_e == 6 || month_e == 9 || month_e == 11)&& (day_e>30)){
            cout << "Invalid Day. Please Try Again\n";
            continue;
            }
            if (month_e==month_s){
                if (day_e<day_s+3){
                    cout << "Minimum Length of A Trip Should be 3 Days.\n";
                    continue;
                }
                
            }
            else if (month_e==month_s+1||(month_e==1&&month_s==12)){
                if (month_s == 4 || month_s == 6 || month_s == 9 || month_s == 11){
                    if (30-day_s+day_e >= 3){
                        flag = 1;
                    }
                }
                else if (month_s==2){
                    if (28-day_s+day_e >=3){
                        flag = 1;
                    }
                }
                else {
                    if (31-day_s+day_e>=3){
                        flag = 1;
                    }
                }
                
            }
            else {
                cout << "Invalid Day. Please Try Again.\n";
            }
            
        } while(!flag);

        flag = 0;

        do {
            cout << "So You Would Like Your Trip To End As Late As: \n";
            cout << "----------------------------------------------\n";
            cout << month_e << "/" << day_e << "/" << year_e << "\n";
            cout << "Is That Correct?\n";
            cout << "--Press 1 If that is Correct.\n--Press 2 to Change this Date.\n";
            cin >> change_date_flag;
            if (change_date_flag==2){
                change_date_flag=0;
                break;
                }
            else if (change_date_flag==1){
                break;
            }
            else {
                change_date_flag = 0;
                cout << "Invalid Input.";
            }
        } while (1);

    } while(!change_date_flag);
}

void itinerary::set_trip_type(){
    
    int flag=0;

    cout << "Great. You will visit sometime between:\n";
    cout << "---------------------------------------\n";
    cout << month_s << "/" << day_s << "/" << year_s << endl;
    cout << "and\n";
    cout << month_s << "/" << day_s << "/" << year_s << endl;
    // consider doing while loop for all of the above.

    do {
        cout << "What Kind of Trip are you Thinking of having?\n";
        cout << "---------------------------------------------" << endl;
        cout << "Press 1 for : A Classical Luxury Historical Trip." << endl;
        cout << "Press 2 for : A Relaxed Luxury Seaside Trip." << endl;
        cout << "Press 3 for : A Luxury Historical and Seaside Trip" << endl;
        cout << "Press 4 for : A Medical Trip" << endl;

        cin >> trip_type;
        if (trip_type<1 || trip_type>4){
            cout << "Invalid Input." << endl;
            break;
        }
    } while (!flag);

}

void itinerary::choose_sites(){

    // ideas:
    // enter letter after number to read a decription of the site/activity.
    // choose site/activity by entering numbers consecutively in ascending order.
    int flag=0;
    cout << "Lets now go over some popular cities to visit and see ";
    cout << "if you'd like to do some of the activities there!" << endl;

    
    cout << "Sites in Cairo:" << endl;
    cout << "--------------------" << endl;
    cout << "1. Giza Pyramids & Sphinx." << endl;
    cout << "2. Egyptian museum." << endl;
    cout << "3. Civilization Museum." << endl;
    cout << "4. Saqqara Necropolis." << endl;
    cout << "5. Islamic Cairo" << endl;
    cout << "6. Old Cairo" << endl;

    cout << "Enter the Number Next to the Sites you Would Like to Visit in Ascending Order With no Spaces: ";
    do {
        cin >> sites_cairo; 
        if (this->valid_string(sites_cairo)){
        flag = 1;
        }
        else {
            cout << "Please Enter Valid Numbers in Ascending Order With no Spaces:";
        }
    } while (!flag);

    cout << "Sites in Luxor:" << endl;
    cout << "---------------" << endl;
    cout << "1. Karnak Temple." << endl;
    cout << "2. Dendara Temple." << endl; 
    cout << "3. Valley of the Kings." << endl;
    cout << "4. Hatshepsut Temple." << endl;
    cout << "5. Colossi of Memnon." << endl;
    cout << "6. Hot Air Balloon Ride." << endl;
    cout << "7. Abu Simbel Day Trip." << endl;

    cout << "Sites in Aswan:" << endl;
    cout << "---------------" << endl;
    cout << "1. Edfu Temple." << endl;
    cout << "2. Kom Ombo Temple." << endl;
    cout << "3. Philae Temple." << endl;
    cout << "4. Crocodile Museum." << endl;
    cout << "5. Unfinished Obelisk." << endl;
    cout << "6. Felucca Boat Ride." << endl;

    cout << "Sites & Activities in Hurghada:" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Snorkeling Day Trip." << endl;
    cout << "2. Scuba Diving Day Trip." << endl;
    cout << "3. Beach Day." << endl;
    cout << "4. Safari Trip." << endl;


}

int itinerary::valid_string(string sites){

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

int itinerary::file_existence_check(){
    ifstream file;
    file.open("/Itinerary/"+file_name);
    if (file.is_open()){
        file.close();
        return 1;
    }
    else {
        //file.close();
        return 0;
    }
}

void itinerary::set_file_name(string file_){
    file_name = file_;
}

/* Other Functions */

void listfiles(string folder){
    for (const auto & entry : filesystem::directory_iterator(folder))
        cout << entry.path() << endl;
}