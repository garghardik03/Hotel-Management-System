#include <bits/stdc++.h>
using namespace std;
class room_booking
{
public:
    int room_no;
    float room_rent;
    int room_availability;
    int number_of_beds;
    room_booking()
    {
        room_no = 0;
        room_rent = 0;
        room_availability = 0;
        number_of_beds = 0;
    }
    room_booking(int room_no, float room_rent, int number_of_beds)
    {
        this->room_no = room_no;
        this->room_rent = room_rent;
        this->number_of_beds = number_of_beds;
        this->room_availability = 0;
    }
    void display_room_details()
    {
        cout << "..........Room details.........." << endl;
        cout << "Room No: " << this->room_no << endl;
        cout << "Room Rent: " << this->room_rent << endl;
        cout << "Number of Beds: " << this->number_of_beds << endl;
        if (this->room_availability == 0)
        {
            cout << "Availability: Available" << endl;
        }
        else
        {
            cout << "Availability: Not Available" << endl;
        }
    }
    void empty_room(int room_no)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->room_no == room_no)
            {
                this->room_availability = 0;
            }
        }
    }
};
class Date
{
public:
    int d, m, y;
    Date()
    {
        d = 0;
        m = 0;
        y = 0;
    }
};
class customer_details : public Date
{
public:
    string customer_first_name;
    string customer_last_name;
    string customer_aadhar_number;
    string customer_contact_number;
    string customer_email_id;
    string customer_address;
    int nummber_of_people_accompanied;
    int number_of_days;
    Date dt1[1];
    Date dt2[1];
    string s3;
    string customer_id;
    customer_details()
    {
        this->customer_first_name = " ";
        this->customer_last_name = " ";
        this->customer_aadhar_number = " ";
        this->customer_contact_number = " ";
        this->customer_email_id = " ";
        this->customer_address = " ";
        this->nummber_of_people_accompanied = 0;
        this->number_of_days = 0;
        this->customer_id = " ";
    }
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countLeapYears(Date d)
    {
        int years = d.y;
        if (d.m <= 2)
            years--;
        return years / 4 - years / 100 + years / 400;
    }
    int getDifference(Date dt1, Date dt2)
    {
        long int n1 = dt1.y * 365 + dt1.d;
        for (int i = 0; i < dt1.m - 1; i++)
            n1 += monthDays[i];
        n1 += countLeapYears(dt1);
        long int n2 = dt2.y * 365 + dt2.d;
        for (int i = 0; i < dt2.m - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(dt2);
        return (n2 - n1);
    }
    void generateID()
    {
        static const char m[] = "abcdefghijklmnopqrstuvwxyz";
        int i;

        for (i = 0; i < 6; i++)
        {
            customer_id = customer_id + m[rand() % (sizeof(m) - 1)];
        }
    }
    void set_details()
    {
        cout << "..........Sir/Ma'am, Please enter your details.........." << endl;
        cout << endl;
        cout << "Kindly Enter Your First Name: ";
        cin >> this->customer_first_name;
        cout << "Kindly Enter Your Last Name: ";
        cin >> this->customer_last_name;
        cout << "Kindly Enter Your Contact Number: ";
        cin >> this->customer_contact_number;
        if (this->customer_contact_number.length() != 10)
        {
            cout << "Invalid Contact Number" << endl;
            cout << "Kindly Enter Your Contact Number Again: ";
            cin >> this->customer_contact_number;
        }
        cout << "Kindly Enter Your Aadhar Number: ";
        cin >> this->customer_aadhar_number;
        if (this->customer_aadhar_number.length() != 12)
        {
            cout << "Invalid Aadhar Number" << endl;
            cout << "Kindly Enter Your Aadhar Number Again: ";
            cin >> this->customer_aadhar_number;
        }
        cout << "Kindly Enter Your Email Id without a White Space: ";
        cin >> this->customer_email_id;
        cout << "Kindly Enter Your Address without a White Space: ";
        cin >> this->customer_address;
        cout << "Kindly Enter The Number of People Accompanied: ";
        cin >> this->nummber_of_people_accompanied;
        cout << "Enter the check_in date in the format date month year" << endl;
        for (int i = 0; i < 1; i++)
        {
            cin >> dt1[i].d >> dt1[i].m >> dt1[i].y;
        }
        cout << "Enter the check-out date in the format date month year" << endl;
        for (int i = 0; i < 1; i++)
        {
            cin >> dt2[i].d >> dt2[i].m >> dt2[i].y;
        }
        this->number_of_days = getDifference(dt1[0], dt2[0]);
    }
    virtual void display_details()
    {
        cout << endl;
        cout << "..........Your details are as follows!!!! Kindly confirm.........." << endl;
        cout << endl;
        cout << "Customer Name: ";
        s3 = this->customer_first_name + " " + this->customer_last_name;
        cout << s3 << endl;
        cout << "Customer ID: " << this->customer_id << endl;
        cout << "Customer Aadhar Number: " << this->customer_aadhar_number << endl;
        cout << "Customer Contact Number: " << this->customer_contact_number << endl;
        cout << "Customer Email Id: " << this->customer_email_id << endl;
        cout << "Customer Address: " << this->customer_address << endl;
        cout << "Number of people accompanied: " << this->nummber_of_people_accompanied << endl;
        cout << "Check-in Date: " << dt1[0].d << "/" << dt1[0].m << "/" << dt1[0].y << endl;
        cout << "Check-out Date: " << dt2[0].d << "/" << dt2[0].m << "/" << dt2[0].y << endl;
        cout << "Number of days: " << this->number_of_days << endl;
        cout << endl;
        cout << "Do you want to confirm the above details? Enter 1 for Yes and 2 for No(1.Y 2.N)!!!" << endl;
        int choice;
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            cout << "..........Thank you for choosing us.........." << endl;
            cout << endl;
            fstream cust;
            cust.open("customer_details.txt", ios::out | ios::app);
            cust << s3 << endl;
            cust << this->customer_aadhar_number << endl;
            cust << this->customer_contact_number << endl;
            cust << this->customer_email_id << endl;
            cust << this->customer_address << endl;
            cust << this->nummber_of_people_accompanied << endl;
            cust << this->number_of_days << endl;
            cust.close();
        }
        else if (choice == 2)
        {
            cout << "..........Please enter your details again.........." << endl;
            this->set_details();
        }
    }
};
class room_customer : public customer_details, public room_booking
{
public:
    double rbill;
    room_booking r;
    customer_details c;
    int amount_of_each_room[5] = {7500, 5000, 4000, 3000, 0};
    int room_price[5];
    string room_type;
    int tax, finalbill;
    room_customer()
    {
        this->rbill = 0;
    }
    void payment()
    {
        cout << "Sir/Ma'am, What mode of payment would you like opt?" << endl;
        cout << endl;
        cout << "1. Cash" << endl;
        cout << "2. Card" << endl;
        cout << "3. Debit Card" << endl;
        cout << "4. Credit Card" << endl;
        cout << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Payment Successful" << endl;
        }
        else if (choice == 2)
        {
            cout << "Payment Successful" << endl;
        }
        else if (choice == 3)
        {
            cout << "Payment Successful" << endl;
        }
        else if (choice == 4)
        {
            cout << "Payment Successful" << endl;
        }
        else
        {
            cout << "Payment Failed" << endl;
        }
    }
    void room_allocation()
    {
        cout << "..........Sir/Ma'am, We have the following rooms.........." << endl;
        cout << endl;
        cout << "............Kindly select the room you want to book............" << endl;
        cout << endl;
        cout << "(The choice will be the SNo of the particular room)" << endl;
        cout << endl;
        cout << "SNo. Room Type   Room Price" << endl;
        cout << "1.   Taj         7500" << endl;
        cout << "2.   Qutub       5000" << endl;
        cout << "3.   Lal         4000" << endl;
        cout << "4.   Minar       3000" << endl;
        cout << "5.   Charity     0000" << endl;
        int choice;
        cin >> choice;
        fstream room;
        fstream cust;
        deque<int> Taj_room;
        deque<int> Qutub_room;
        deque<int> Lal_room;
        deque<int> Minar_room;
        deque<int> Charity_room;
        deque<int> Taj_room_alloted;
        deque<int> Qutub_room_alloted;
        deque<int> Lal_room_alloted;
        deque<int> Minar_room_alloted;
        deque<int> Charity_room_alloted;
        Taj_room.push_back(101);
        Taj_room.push_back(102);
        Taj_room.push_back(103);
        Taj_room.push_back(104);
        Taj_room.push_back(105);
        Qutub_room.push_back(201);
        Qutub_room.push_back(202);
        Qutub_room.push_back(203);
        Qutub_room.push_back(204);
        Qutub_room.push_back(205);
        Lal_room.push_back(301);
        Lal_room.push_back(302);
        Lal_room.push_back(303);
        Lal_room.push_back(304);
        Lal_room.push_back(305);
        Minar_room.push_back(401);
        Minar_room.push_back(402);
        Minar_room.push_back(403);
        Minar_room.push_back(404);
        Minar_room.push_back(405);
        Charity_room.push_back(501);
        Charity_room.push_back(502);
        Charity_room.push_back(503);
        Charity_room.push_back(504);
        Charity_room.push_back(505);
        cust.open("customer_details.txt", ios::out | ios::app);
        room.open("room_details.txt", ios::out | ios::app);
        switch (choice)
        {
        case 1:
            if (Taj_room.empty())
            {
                cout << "Sorry Sir/Ma'am, All the rooms of Taj are booked" << endl;
                cout << "Please choose another room" << endl;
                room_allocation();
            }
            else
            {
                int room_number_taj;
                room_type = "Taj";
                room_price[0] = amount_of_each_room[0];
                room << room_type << " " << room_price[0] << endl;
                cust << room_type << " ";
                cust << "Room Price of Taj is :" << room_price[0] << endl;
                room_number_taj = Taj_room.front();
                Taj_room_alloted.push_back(room_number_taj);
                Taj_room.pop_front();
                cout << "Your room number is: " << room_number_taj << endl;
                cout << "..........Enjoy Your Stay..........!!!" << endl;
                cout << endl;
                room << "The room " << room_number_taj << "is booked for now" << endl;
                cust << "The room alloted to : " << room_number_taj << endl;
                cust.close();
                room.close();
                break;
            }
        case 2:
            if (Qutub_room.empty())
            {
                cout << "Sorry Sir/Ma'am, All the rooms of Qutub are booked" << endl;
                cout << "Please choose another room" << endl;
                room_allocation();
            }
            else
            {
                room_type = "Qutub";
                room_price[1] = amount_of_each_room[1];
                room << room_type << " " << room_price[1] << endl;
                int room_number_qutub;
                room_number_qutub = Qutub_room.front();
                Qutub_room_alloted.push_back(room_number_qutub);
                Qutub_room.pop_front();
                cout << "Your room number is: " << room_number_qutub << endl;
                cout << "..........Enjoy Your Stay..........!!!" << endl;
                cout << endl;
                room << "The room " << room_number_qutub << "is booked for now" << endl;
                cust << "The room alloted to : " << room_number_qutub << endl;
                cust.close();
                room.close();
                break;
            }
        case 3:
            if (Lal_room.empty())
            {
                cout << "Sorry Sir/Ma'am, All the rooms of Lal are booked" << endl;
                cout << "Please choose another room" << endl;
                room_allocation();
            }
            else
            {
                room_type = "Lal";
                room_price[2] = amount_of_each_room[2];
                room << room_type << " " << room_price[2] << endl;
                int room_number_lal;
                room_number_lal = Lal_room.front();
                Lal_room_alloted.push_back(room_number_lal);
                Lal_room.pop_front();
                cout << "Your room number is: " << room_number_lal << endl;
                cout << "..........Enjoy Your Stay..........!!!" << endl;
                cout << endl;
                room << "The room " << room_number_lal << "is booked for now" << endl;
                cust << "The room alloted to : " << room_number_lal << endl;
                cust.close();
                room.close();
                break;
            }
        case 4:
            if (Minar_room.empty())
            {
                cout << "Sorry Sir/Ma'am, All the rooms of Minar are booked" << endl;
                cout << "Please choose another room" << endl;
                room_allocation();
            }
            else
            {
                room_type = "Minar";
                room_price[3] = amount_of_each_room[3];
                room << room_type << " " << room_price[3] << endl;
                int room_number_minar;
                room_number_minar = Minar_room.front();
                Minar_room_alloted.push_back(room_number_minar);
                Minar_room.pop_front();
                cout << "Your room number is: " << room_number_minar << endl;
                cout << "..........Enjoy Your Stay..........!!!" << endl;
                cout << endl;
                room << "The room " << room_number_minar << "is booked for now" << endl;
                cust << "The room alloted to : " << room_number_minar << endl;
                cust.close();
                room.close();
                break;
            }
        case 5:
            if (Charity_room.empty())
            {
                cout << "Sorry Sir/Ma'am, All the rooms of Charity are booked" << endl;
                cout << "Please choose another room" << endl;
                room_allocation();
            }
            else
            {
                room_type = "Charity";
                room_price[4] = amount_of_each_room[4];
                room << room_type << " " << room_price[4] << endl;
                int room_number_charity;
                room_number_charity = Charity_room.front();
                Charity_room_alloted.push_back(room_number_charity);
                Charity_room.pop_front();
                cout << "Your room number is: " << room_number_charity << endl;
                cout << "..........Enjoy Your Stay..........!!!" << endl;
                cout << endl;
                room << "The room " << room_number_charity << "is booked for now" << endl;
                cust << "The room alloted to : " << room_number_charity << endl;
                cust.close();
                room.close();
                break;
            }
        }
    }
    void print_room_bill(customer_details c)
    {
        cout << ".........Thank You for choosing us.........." << endl;
        cout << "..........Your Bill is.........." << endl;
        cout << endl;
        cout << "Name: " << c.s3 << endl;
        cout << "Room Type: " << room_type << endl;
        cout << "Check-in Date: " << c.dt1[0].d << "/" << c.dt1[0].m << "/" << c.dt1[0].y << endl;
        cout << "Check-out Date: " << c.dt2[0].d << "/" << c.dt2[0].m << "/" << c.dt2[0].y << endl;
        if (room_type == "Taj")
        {
            cout << "Room Price: " << room_price[0] << endl;
            cout << "Number of days you stayed: " << c.number_of_days << endl;
            rbill = room_price[0] * c.number_of_days;
            cout << "Your sub-total is: " << rbill << endl;
            tax = rbill * 0.18;
            cout << "Your tax is: " << tax << endl;
            finalbill = rbill + tax;
            cout << "Your final bill is: " << finalbill << endl;
            cout << endl;
        }
        else if (room_type == "Qutub")
        {
            cout << "Room Price: " << room_price[1] << endl;
            cout << "Number of days you stayed: " << c.number_of_days << endl;
            rbill = room_price[1] * c.number_of_days;
            cout << "Your sub-total is: " << rbill << endl;
            tax = rbill * 0.18;
            cout << "Your tax is: " << tax << endl;
            finalbill = rbill + tax;
            cout << "Your final bill is: " << finalbill << endl;
            cout << endl;
        }
        else if (room_type == "Lal")
        {
            cout << "Room Price: " << room_price[2] << endl;
            cout << "Number of days you stayed: " << c.number_of_days << endl;
            rbill = room_price[2] * c.number_of_days;
            cout << "Your sub-total is: " << rbill << endl;
            tax = rbill * 0.18;
            cout << "Your tax is: " << tax << endl;
            finalbill = rbill + tax;
            cout << "Your final bill is: " << finalbill << endl;
            cout << endl;
        }
        else if (room_type == "Minar")
        {
            cout << "Room Price: " << room_price[3] << endl;
            cout << "Number of days you stayed: " << c.number_of_days << endl;
            rbill = room_price[3] * c.number_of_days;
            cout << "Your sub-total is: " << rbill << endl;
            tax = rbill * 0.18;
            cout << "Your tax is: " << tax << endl;
            finalbill = rbill + tax;
            cout << "Your final bill is: " << finalbill << endl;
            cout << endl;
        }
        else if (room_type == "Charity")
        {
            cout << "Room Price: " << room_price[4] << endl;
            cout << "Number of days you stayed: " << c.number_of_days << endl;
            rbill = room_price[4] * c.number_of_days;
            cout << "Your sub-total is: " << rbill << endl;
            tax = rbill * 0.18;
            cout << "Your tax is: " << tax << endl;
            finalbill = rbill + tax;
            cout << "Your final bill is: " << finalbill << endl;
            cout << endl;
        }
    }
    void askFeedback()
    {
        int f;
        string cname;
        ofstream feedback;
        cout << endl;
        cout << "Sir/Ma'am, we would like to have a feedback of yours!!!" << endl;
        cout << endl;
        feedback.open("feedback.txt", ios::app);
        feedback << "Customer Name\t : ";
        cout << "Can you help me with your name please?\n";
        cin >> cname;
        cout << endl;
        feedback << cname << "\t\t\t";
        cout << "How likely are you to recommend Hotel Dandelion to a Friend or Colleague? Rate on a scale of 1-10\n";
        cin >> f;
        feedback << "Feedback\t: ";
        feedback << f << "\n";
        feedback.close();
        cout << endl;
        cout << " Thanks for your valuable feedback!!!" << endl;
    }
};
class Dish
{
public:
    string dishName;
    double price;
    string dishType;
    Dish(string dishName, double price, string dishType)
    {
        this->dishName = dishName;
        this->price = price;
        this->dishType = dishType;
    }
    Dish()
    {
    }
};
class restraunt : public Dish
{
public:
    Dish dish[30] = {{"ChickenBiryani", 200, "Main Course"}, {"ChickenTikka", 150, "Main Course"}, {"ChickenKarahi", 250, "Main Course"}, {"ChickenHandi", 300, "Main Course"}, {"ChickenQorma", 350, "Main Course"}, {"ChickenShashlik", 400, "Main Course"}, {"Pasta", 450, "Main Course"}, {"ChickenNihari", 500, "Main Course"}, {"ChickenHaleem", 550, "Main Course"}, {"ChickenKofta", 600, "Main Course"}, {"ChickenKebab", 650, "Main Course"}, {"ChickenTandoori", 700, "Main Course"}, {"ChickenTikkaMasala", 750, "Main Course"}, {"ChickenBiryani", 200, "Main Course"}, {"ChickenTikka", 150, "Main Course"}, {"ChickenKarahi", 250, "Main Course"}, {"Mexican Sizzler", 300, "Main Course"}, {"ChickenQorma", 350, "Main Course"}, {"ChickenShashlik", 400, "Main Course"}, {"ChickenKorma", 450, "Main Course"}, {"ChickenNihari", 500, "Main Course"}, {"ChickenHaleem", 550, "Main Course"}, {"ChickenKofta", 600, "Main Course"}, {"ChickenKebab", 650, "Main Course"}, {"ChickenTandoori", 700, "Main Course"}, {"PaneerTikkaMasala", 750, "Main Course"}, {"VegBiryani", 200, "Main Course"}, {"PaneerTikka", 150, "Main Course"}, {"PaneerKadai", 250, "Main Course"}, {"PaneerHandi", 300, "Main Course"}};
    void displayMenu()
    {
        fstream file;
        file.open("HotelMenu.txt", ios::in | ios::out);
        cout << "..........HotelMenu.........." << endl;
        cout << endl;
        cout << endl;
        cout << "..........Breakfast.........." << endl;
        cout << endl;
        file << "..........HotelMenu.........." << endl;
        file << "..........Breakfast.........." << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << dish[i].dishName << "        " << dish[i].price << "      " << dish[i].dishType << "     " << endl;
            file << dish[i].dishName << "        " << dish[i].price << "      " << dish[i].dishType << "     " << endl;
        }
        cout << endl;
        cout << "..........Lunch.........." << endl;
        cout << endl;
        file << "..........Lunch.........." << endl;
        for (int i = 10; i < 20; i++)
        {
            cout << dish[i].dishName << "        " << dish[i].price << "       " << dish[i].dishType << "     " << endl;
            file << dish[i].dishName << "        " << dish[i].price << "       " << dish[i].dishType << "     " << endl;
        }
        cout << endl;
        cout << "..........Dinner.........." << endl;
        cout << endl;
        file << "..........Dinner.........." << endl;
        for (int i = 20; i < 30; i++)
        {
            cout << dish[i].dishName << "         " << dish[i].price << "       " << dish[i].dishType << "    " << endl;
            file << dish[i].dishName << "         " << dish[i].price << "       " << dish[i].dishType << "    " << endl;
        }
    }
    void takeorder()
    {
        bool check = true;
        string course[30];
        int quantity[30];
        int gst;
        fstream order;
        order.open("Order.txt", ios::in | ios::out);
        double total_bill = 0;
        int i = 0;
        cout << endl;
        cout << "Can I have your order sir??" << endl;
        cout << endl;
        cout << "Enter the dish name" << endl;
        cin >> course[0];
        cout << "Enter the quantity" << endl;
        cin >> quantity[0];
        for (i = 1; i < 30; i++)
        {
            cout << "Do you want to order more dishes?" << endl;
            cout << "Enter 1 for yes and 0 for no" << endl;
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the dish name" << endl;
                cin >> course[i];
                cout << "Enter the quantity" << endl;
                cin >> quantity[i];
            }
            if (choice == 0)
            {
                break;
            }
        }
        // BILL GENERATION
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (dish[i].dishName == course[j])
                {
                    total_bill = total_bill + (dish[i].price * quantity[j]);
                }
            }
        }
        cout << "..........Hotel Dandelion.........." << endl;
        cout << endl;
        cout << "..........Bill Summary.........." << endl;
        cout << endl;
        cout << "Dish Name "
             << "\t"
             << "Price "
             << "\t"
             << "Quantity " << endl;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (dish[i].dishName == course[j])
                {
                    cout << dish[i].dishName << "\t" << dish[i].price << "\t" << quantity[j] << endl;
                }
            }
        }
        cout << endl;
        cout << "......................................................." << endl;
        cout << endl;
        cout << "Sub-Total : " << total_bill << endl;
        cout << endl;
        gst = total_bill * 0.05;
        cout << "......................................................." << endl;
        cout << endl;
        cout << "GST: " << gst << endl;
        cout << endl;
        cout << "......................................................." << endl;
        cout << endl;
        cout << "Total Bill: " << total_bill + gst << endl;
        cout << endl;
        cout << "......................................................." << endl;
        cout << endl
             << endl
             << endl;
        cout << "..........Hope You Enhoyed The Food.........." << endl;
        cout << endl;
    }
    void askFeedback()
    {
        int f;
        string cname;
        ofstream feedback;
        feedback.open("feedback.txt", ios::app);
        feedback << "Customer Name\t : ";
        cout << "Sir/Ma'am, we would like to have a feedback of yours!!!" << endl;
        cout << endl;
        cout << "Enter your Name" << endl;
        cin >> cname;
        feedback << cname << "\t\t\t";
        cout << "Thanks for your time! \nHow likely are you to recommend Hotel Dandelion to a Friend or Colleague? \nRate on a scale of 1-10\n";
        cin >> f;
        feedback << "Feedback\t: ";
        feedback << f << "\n";
        feedback.close();
        cout << "Thanks for your valuable feedback!" << endl;
    }
};
class Employee
{
public:
    virtual int performDuty() = 0;
    virtual ~Employee()
    {
    }
};
class RoomService : public Employee
{
public:
    int performDuty()
    {
        cout << "Employee XYZ arriving at your doorstep...\n\n";
    }
    virtual ~RoomService()
    {
    }
};
class Waiter : public Employee
{
public:
    int performDuty()
    {

        cout << "\n\nEmployee ABC arriving at your table to take your Order\n\n";
    }
    virtual ~Waiter()
    {
    }
};

class SelectEmployee
{
    // protected:
    Employee *e;

public:
    SelectEmployee(Employee *e1)
    {
        e = e1;
    }

    int performDuty()
    {
        e->performDuty();
    }
};
int main()
{
    cout << "..........Welcome to Hotel Dandelion.........." << endl;
    cout << endl;
    cout << "..........Here are the services we offer.........." << endl;
    cout << endl;
    cout << "1. Book a room" << endl;
    cout << "2. Dine in the restaurant" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cout << endl;
    cout << "Kindly Select One from the Options Above!!!!!" << endl;
    cout << endl;
    cin >> choice;
    room_customer r;
    RoomService rs;
    Waiter w;
    if (choice == 1)
    {
        customer_details c;
        c.set_details();
        c.display_details();
        r.room_allocation();
        SelectEmployee *se = new SelectEmployee(&rs);
        se->performDuty(); // This is for room service if want to add later
        // r.deallocation(r);
        r.print_room_bill(c);
        r.payment();
        r.askFeedback();
    }
    else if (choice == 2)
    {
        restraunt r;
        r.displayMenu();
        SelectEmployee *se = new SelectEmployee(&w);
        se->performDuty();
        r.takeorder();
        r.askFeedback();
    }
    else if (choice == 3)
    {
        cout << "Thanks a lot Sir!!! Hope you had a great experience with us!!!" << endl;
    }
    return 0;
}

/*int vacateRoom(intrno)
{
    int i, j = 0;
    for (i = 0; i < 6; i++)
    {

        if (room[i].roomNo == rno)
        {
            j = 1;
            room[i].status = 0;
            cout << "Thank You! visit Again.\n"
                 << endl;
        }
    }
    if (j == 0)
        throw Exception(8, "Sorry! Room Not Found, or occupied at the moment\n");
}*/
