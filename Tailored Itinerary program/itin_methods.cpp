#include "itin_methods.h"
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

/* class functions */

itinerary::itinerary (){
    file_name = "To Be Set";
    sites_cairo = "0000000";
    sites_luxor = "00000000";
    sites_aswan = "000000";
    sites_hurghada = "0000";
    month_e = month_s = day_e = day_s = year_e = year_s  = 0;
    trip_type = 0;
}

void itinerary::create_itinerary(){
    // after all user input is gathered, generates itinerary txt file. 
    string name_of_itinerary;
    int flag = 0;

    this->set_date();
    this->set_trip_type();
    this->choose_sites();
    //this->choose_add_ons(); -// implement function to decide if hotels, certain meals, nile cruise included.

    cout << "Please Choose a name for this itinerary file: "<<endl;
    do {
        cin >> name_of_itinerary;
        if (this->file_existence_check(name_of_itinerary)){
          cout << "A file with this name already exists. Please choose a different one." << endl;
        }
        else {
            file_name = name_of_itinerary;
            flag = 1;
        }
    } while (!flag);
    this->generate_itinerary(name_of_itinerary);
    cout << "Itinerary Generated. Would You Like to View it?" << endl;
    
    do {
        cout << "Press 1 to view it. Press 9 to exit." << endl;
        cin >> flag;
        if (flag==1){
            this->view_itinerary();
        }
        if (flag==9){
            return;
        }
        else {
            cout << "Invalid_Input" << endl;
            flag = 0;
        }
    }while(!flag);
}

void itinerary::generate_itinerary(string file_nom){
    // Must fix to disallow alexandria and abu simbel being in days with each other. 
    // also, dont think cairo or hurghada days can bleed into luxor or aswan days.
    int tot_days, cur_day=2;
    string act_1, act_2;
    // int c_nights = 1, l_nights=0, a_nights=0, h_nights=0;
    string line;
    string::iterator it;
    int counter=0;
    ofstream output_file("Itineraries/"+file_nom);
    if (output_file.is_open()){
        // calculate number of days
        tot_days=this->calculate_days();
        // print Itinerary Title
        if (trip_type==1){
            ifstream input_file("Itineraries/Data/title1.txt");
            getline(input_file,line);
            input_file.close();
        }
        else if (trip_type==2){
            ifstream input_file("Itineraries/Data/title2.txt");
            getline(input_file,line);
            input_file.close();
        }
        else if (trip_type==3){
            ifstream input_file("Itineraries/Data/title3.txt");
            getline(input_file,line);
            input_file.close();
        }
        output_file << line << endl << endl;
        // insert arrival text
        output_file << "Day 1: Arrival" << endl;
        ifstream input_file("Itineraries/Data/arrival.txt");
        if (input_file.is_open()&&output_file.is_open()){
            while (getline(input_file, line)){
                output_file << line << endl;
            }
            input_file.close();
        }
        output_file << endl;

        output_file << "Day " << cur_day << ": " ;

        for (it = sites_cairo.begin(); it!= sites_cairo.end(); it++){
            if (*it && counter < 2){
                ifstream input_file("Itineraries/Data/c" +string(1,*it)+ ".txt");
                getline(input_file, line);
                if (counter == 0){
                    act_1 = "c" + string(1,*it);
                    output_file << line;
                }
                else if (counter == 1){
                    act_2 = "c" + string(1,*it);
                    output_file<< " and " << line << endl;
                }
                counter ++;
                input_file.close();
            }
            if (counter==2){
                ifstream input_file_1("Itineraries/Data/" +act_1+ ".txt");
                ifstream input_file_2("Itineraries/Data/" +act_2+ ".txt");
                getline(input_file_1,line);
                getline(input_file_2,line);
                while (getline(input_file_1,line)){
                    output_file << line << endl;
                    input_file_1.close();
                }
                while (getline(input_file_2,line)){
                    output_file << line << endl;
                    input_file_2.close();
                }
                output_file << endl;
                cur_day++;
                counter = 0;
                output_file << "Day " << cur_day << ": " ;
            }
        }

        for (it = sites_luxor.begin(); it != sites_luxor.end();it++){
            if (*it && counter < 2){
                ifstream input_file("Itineraries/Data/l" +string(1,*it)+ ".txt");
                getline(input_file, line);
                if (counter == 0){
                    act_1 = "l" + string(1,*it);
                    output_file << line ;
                }
                else if (counter == 1){
                    act_2 = "l" + string (1,*it);
                    output_file << " and " << line << endl;
                }
                counter++;
                input_file.close();
            }
            if (counter==2){
                ifstream input_file_1("Itineraries/Data/" + act_1 + ".txt");
                ifstream input_file_2("Itineraries/Data/" + act_2 + ".txt");
                getline(input_file_1,line);
                getline(input_file_2,line);
                while (getline(input_file_1,line)){
                    output_file << line << endl;
                    input_file_1.close();
                }
                while (getline(input_file_2,line)){
                    output_file << line << endl;
                    input_file_2.close();
                }
                output_file << endl;
                cur_day++;
                counter = 0;
                output_file << "Day " << cur_day << ": " ;
            }
        }

        for (it = sites_aswan.begin(); it!= sites_aswan.end();it++){
            if (*it && counter < 2){
                ifstream input_file("Itineraries/Data/a" +string(1,*it)+ ".txt");
                getline(input_file, line);
                if (counter == 0){
                    act_1 = "a" + string(1,*it);
                    output_file << line;
                }
                else if (counter == 1){
                    act_2 = "a" + string (1,*it);
                    output_file << " and " << line << endl;
                }
                counter++;
                input_file.close();
            }
            if (counter==2){
                ifstream input_file_1("Itineraries/Data/" + act_1 + ".txt");
                ifstream input_file_2("Itineraries/Data/" + act_2 + ".txt");
                getline(input_file_1,line);
                getline(input_file_2,line);
                while (getline(input_file_1,line)){
                    output_file << line << endl;
                    input_file_1.close();
                }
                while (getline(input_file_2,line)){
                    output_file << line << endl;
                    input_file_2.close();
                }
                output_file << endl;
                cur_day++;
                counter = 0;
                output_file << "Day " << cur_day << ": " ;
            }

        }

        for (it = sites_hurghada.begin(); it!= sites_hurghada.end();it++){
            if (*it && counter < 2){
                ifstream input_file("Itineraries/Data/h" +string(1,*it)+ ".txt");
                getline(input_file, line);
                if (counter == 0){
                    act_1 = "h" + string(1,*it);
                    output_file << line;
                }
                else if (counter == 1){
                    act_2 = "h" + string (1,*it);
                    output_file << " and " << line << endl;
                }
                counter++;
                input_file.close();
            }
            if (counter==2){
                ifstream input_file_1("Itineraries/Data/" + act_1 + ".txt");
                ifstream input_file_2("Itineraries/Data/" + act_2 + ".txt");
                getline(input_file_1,line);
                getline(input_file_2,line);
                while (getline(input_file_1,line)){
                    output_file << line << endl;
                    input_file_1.close();
                }
                while (getline(input_file_2,line)){
                    output_file << line << endl;
                    input_file_2.close();
                }
                output_file << endl;
                cur_day++;
                counter = 0;
                output_file << "Day " << cur_day << ": " ;
            }

        }
        if (counter == 1){
            //just insert day and increment cur_day
            output_file << endl;
            ifstream input_file_1("Itineraries/Data/" + act_1 + ".txt");
            getline(input_file_1,line);
            while (getline(input_file_1,line)){
                    output_file << line << endl;
                    input_file_1.close();
            }
            output_file << endl;
            cur_day ++;
        }

        // insert departure text
        output_file << "Day " << tot_days << ": Departure" << endl;
        ifstream input_file("Itineraries/Data/departure.txt");
        if (input_file.is_open()&&output_file.is_open()){
            while (getline(input_file, line)){
                output_file << line << endl;
            }
            input_file.close();
        }
        output_file << endl;

        // print inclusions.
        ifstream input_file("Itineraries/Data/inclusions.txt");
        if (input_file.is_open()&&output_file.is_open()){
            while (getline(input_file, line)){
                output_file << line << endl;
            }
            input_file.close();
        }
        //print hotel inclusions if applicable
        /* 
        if (hotel_flag){
            ifstream input_file("Itineraries/Data/accomodation.txt");
            if (input_file.is_open()&&output_file.is_open()){
                getline(input_file, line)
                output_file << "- " << tot_nights << " ";
                output_file << line << endl;
                getline(input_file, line))
                output_file << "- 1 " << line << endl;
                input_file.close();
            }
        if (cruise_flag){
            ifstream input_file("Itineraries/Data/cruise.txt");
            if (input_file.is_open()&&output_file.is_open()){
                getline(input_file, line)
                output_file << "- " << l_nights+a_nights << " ";
                output_file << line << endl;
                input_file.close();
            }
        }
        */
        output_file << endl;

        ifstream input_file("Itineraries/Data/exclusions.txt");
        if (input_file.is_open()&&output_file.is_open()){
            while (getline(input_file, line)){
                output_file << line << endl;
            }
            input_file.close();
        }

        output_file.close();
    }
    else {cout << "File existence check function may have not worked." << endl;}
}

int itinerary::calculate_days(){
    int num_of_days=0;
    string::iterator it;
    for (it=sites_cairo.begin();it!=sites_cairo.end();it++){
        if (*it){num_of_days++;}
    }
    for (it=sites_luxor.begin();it!=sites_luxor.end();it++){
        if (*it){num_of_days++;}
    }
    for (it=sites_aswan.begin();it!=sites_aswan.end();it++){
        if (*it){num_of_days++;}
    }
    for (it=sites_hurghada.begin();it!=sites_hurghada.end();it++){
        if (*it){num_of_days++;}
    }
    // what if odd number of days? then one day there will be one activity. consider adding it to departure 
    // instead.
    // also find way to print messagge that number of activities will not fit time window you indicated. 
    if (num_of_days%2 == 0){return num_of_days/2 +2;}
    else {return num_of_days/2;+3;}
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

    cout << "Great. You will visit sometime between:\n";
    cout << "---------------------------------------\n";
    cout << month_s << "/" << day_s << "/" << year_s << endl;
    cout << "and\n";
    cout << month_s << "/" << day_s << "/" << year_s << endl;
    // consider doing while loop for all of the above.
}

void itinerary::set_trip_type(){
    
    int flag=0;
    int tybe;

   
        cout << "What Kind of Trip are you Thinking of having?\n";
        cout << "---------------------------------------------" << endl;
        cout << "Press 1 for : A Classical Luxury Historical Trip." << endl;
        cout << "Press 2 for : A Relaxed Luxury Seaside Trip." << endl;
        cout << "Press 3 for : A Luxury Historical and Seaside Trip." << endl;
    do {
        cin >> tybe;
        if (tybe<1 || tybe>3){
            cout << "Invalid Input." << endl;
        }
        else {flag = 1;}
    } while (!flag);
    trip_type = tybe;
}

void itinerary::choose_sites(){

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
    cout << "7. Alexandria Day Trip" << endl;

    cout << "Enter the Number Next to the Sites you Would Like to Visit With no Spaces: ";
    do {
        cin >> sites_cairo; 
        sort(sites_cairo.begin(),sites_cairo.end());
        if (this->valid_string(sites_cairo, 7, sites_cairo.length())){
            flag = 1;
        }
        else {
            cout << "Please Enter Valid Numbers With no Spaces:";
        }
    } while (!flag);

    flag = 0;

    cout << "Sites in Luxor:" << endl;
    cout << "---------------" << endl;
    cout << "1. Karnak Temple." << endl;
    cout << "2. Dendara Temple." << endl; 
    cout << "3. Luxor Temple." << endl;
    cout << "4. Valley of the Kings." << endl;
    cout << "5. Hatshepsut Temple." << endl;
    cout << "6. Colossi of Memnon." << endl;
    cout << "7. Hot Air Balloon Ride." << endl;
    cout << "8. Abu Simbel Day Trip." << endl;

    cout << "Enter the Number Next to the Sites you Would Like to Visit With no Spaces: ";
    do {
        cin >> sites_luxor; 
        sort(sites_luxor.begin(),sites_luxor.end());
        if (this->valid_string(sites_luxor, 8, sites_luxor.length())){
            flag = 1;
        }
        else {
            cout << "Please Enter Valid Numbers With no Spaces: ";
        }
    } while (!flag);

    flag = 0;

    cout << "Sites in Aswan:" << endl;
    cout << "---------------" << endl;
    cout << "1. Edfu Temple." << endl;
    cout << "2. Kom Ombo Temple." << endl;
    cout << "3. Philae Temple." << endl;
    cout << "4. Crocodile Museum." << endl;
    cout << "5. Unfinished Obelisk." << endl;
    cout << "6. Felucca Boat Ride." << endl;

    cout << "Enter the Number Next to the Sites you Would Like to Visit With no Spaces: ";
    do {
        cin >> sites_aswan; 
        sort(sites_aswan.begin(),sites_aswan.end());
        if (this->valid_string(sites_aswan, 6, sites_aswan.length())){
            flag = 1;
        }
        else {
            cout << "Please Enter Valid Numbers With no Spaces: ";
        }
    } while (!flag);

    flag = 0;

    cout << "Sites & Activities in Hurghada:" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Snorkeling Day Trip." << endl;
    cout << "2. Scuba Diving Day Trip." << endl;
    cout << "3. Beach Day." << endl;
    cout << "4. Safari Trip." << endl;

    cout << "Enter the Number Next to the Sites you Would Like to Visit With no Spaces: ";
    do {
        cin >> sites_hurghada; 
        sort(sites_hurghada.begin(),sites_hurghada.end());
        if (this->valid_string(sites_hurghada, 4, sites_hurghada.length())){
            flag = 1;
        }
        else {
            cout << "Please Enter Valid Numbers With no Spaces: ";
        }
    } while (!flag);

    // sites to visit acquired.
}

//returns 1 if valid, 0 otherwise
int itinerary::valid_string(string sites, int max_length, int length){
    if (length <= max_length){
    for(string::iterator it = sites.begin(); it!=sites.end();it++){
        if (*it<48 || *it> (length+48)){
            return 0;
        }
    }
    return 1;
    }
    else {return 0;}

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

    int input;
    int flag = 0;
    int credit_num, sec_code, exp_date;
    string email;

    do {
    cout << "Choose method of payment: \n";
    cout << "1. Credit Card." << endl;
    cout << "2. Paypal." << endl;
    cout << "3. E-check." << endl;
    cout << "To quit, press 9" << endl;

    cin >> input;

    if (input == 1){
        flag = 1;
        cout << "Please Enter your credit card number: " << endl;
        cin >> credit_num;
        cout << "Please Enter the security code: " << endl;
        cin >> sec_code;
        cout << "Please Enter the Expiration date: " << endl;
        cin >> exp_date;
        cout << "Please Enter your Email Address: " << endl;
        cin >> email;
        cout << "Thank you for your payment. You will recieve a confirmation email shortly." << endl;
    }
    if (input == 2){
        cout << "Redirecting you to PayPal..." << endl;
        sleep(6);
        cout << "Thank you for your payment." << endl;
    }
    if (input == 3){
        cout << "Redirecting you to a secure website..." << endl;
        sleep(6);
        cout << "Thank you for your payment." << endl;
    }
    if (input == 9){return;}
    else {cout << "Invalid Input." << endl;}
    } while (!flag);

}

void itinerary::refund_itinerary(){
    int input;
    cout << "Are you sure you want to request a refund?"<<endl;
    cout << "Press 1 if yes.\nPress 9 to cancel and quit";
    cin >> input;
    do {
    if (input == 1){
        cout << "Sorry to hear that. Your refund will be proccessed within 5-7 business days." << endl;
        return;
    }
    else if (input==9){return;}
    else {
        input = 0;
        cout << "Invalid Input. Please Try Again." << endl;
    }
    } while (!input);
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
    if (word == "Departure"){break;}
    else {word_counter ++;}
    }
    file.close();

    file.open("/Itineraries/"+file_name);
    for (i=0;i<word_counter;i++){file >> word;}
    first_digit = word[0];
    if (word[1]<58 && word[1]>47){
        second_digit=word[1];
        }
    
    price = price + 250 *(first_digit+second_digit);

    price_of_itinerary = price;

    cout << "The Total Cost For This Trip With All Inclusions Listed in";
    cout << "the Itinerary Will be: $" << price << "." << endl;

}

// returns 1 if file exists
int itinerary::file_existence_check(string file_of_itinerary){
    ifstream file;
    file.open("/Itinerary/"+file_of_itinerary);
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