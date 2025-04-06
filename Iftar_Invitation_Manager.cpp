#include <iostream>
#include <cstdlib>
#include <string>

#define RED_ "\033[91m"
#define GREEN_ "\033[92m"
#define BLUE_ "\033[94m"
#define YELLOW_ "\033[93m"
#define MAGENTA_ "\033[95m"
static constexpr const char *RESET = "\033[0m";

using namespace std;

class Guest
{
    private:
    string name;
    string contact;
    string iftar_date;
    public:
      Guest(string Name,string Contact,string Date)
      {
          name=Name;
          contact=Contact;
          iftar_date=Date;
      }
      void  display_guest()
      {
         cout<<"Guest: "<<name<<" , Contact:"<<contact<<", Iftar Date:"<<iftar_date<<endl;
      }
      void update_invitatation(const string& New_date)
      {

          iftar_date=New_date;
      }
      string GetName()
      {
          return name;
      }
      string GetDate()
      {
          return iftar_date;
      }
      string GetContact()
      {
          return contact;
      }
};
class IftarManger
{
private:
    Guest** guest_list;
    int sizex;
    int number;

    int DateConvert(const string& date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return year * 10000 + month * 100 + day;
    }


public:
    IftarManger()
    {
        sizex=12;
        number=0;
        guest_list = new Guest*[sizex];
    }


    void add_guest(Guest* New_guest)
    {
      if (number==sizex)
        {
            sizex= sizex +50;
            Guest** new_list = new Guest*[sizex];
            for (int i = 0; i < number; i++) {
                new_list[i] = guest_list[i];
            }
            delete[] guest_list;
            guest_list = new_list;
        }
        guest_list[number++] = New_guest;
    }



    void display_all_guests()
    {

        for(int i=0;i<number;i++)
        {
            guest_list[i]->display_guest();
        }

    }
    void update_guest_invitation(const string& name,const string& new_date)
    {
        cout<<endl;
        cout << YELLOW_;
        cout<<"         Invitation Date Update "<<endl;
        cout << RESET;
        for(int i=0;i<number;i++)
        {
            if(guest_list[i]->GetName()==name)
            {
                guest_list[i]->update_invitatation(new_date);
                cout<<MAGENTA_;
                cout<<"The new date is "<<new_date <<endl;
                cout<<RESET;
                return;
            }
        }

    }
    ////////////////////
void send_reminders(const string& date)
 {
     cout<<endl;
     cout << YELLOW_;
    cout<<"         Reminders "<<endl;
    cout << RESET;
     int counter=0;
    for(int i=0;i<number;i++)
        {
            if(guest_list[i]->GetDate()==date)
            {

            string x=guest_list[i]->GetName();
                cout<< GREEN_;
                cout<<"reminder to " << x<<" you are invited for iftar at my  house on "<< date;
                cout<<RESET;
                cout<<endl;
                counter++;
            }
        }
            if(counter ==0)
            {
                cout<< RED_;
                cout<<"No one is Invited in this Day "<<date<<"!!";
                cout<<RESET;
                cout<<endl;
            }

}
//////////////////////////
    void sort_guest_list()
    {
         cout<<endl;
         cout << YELLOW_;
        cout<<"         Sorted  "<<endl;
        cout <<     RESET;
           for (int i= 0; i <number- 1; i++)
            {
            for (int z =0; z <number-i- 1; z++)
            {
                if (DateConvert(guest_list[z]->GetDate())>DateConvert(guest_list[z + 1]->GetDate()))
                {

                    Guest* temp = guest_list[z];
                    guest_list[z] = guest_list[z + 1];
                    guest_list[z + 1] = temp;
                }
            }
        }
    }

 ~IftarManger()
    {
        for (int i = 0; i <number; i++)
            {
            delete guest_list[i];
            }
        delete[] guest_list;
    }


};

int main()
{
    IftarManger MalakIftar;

   Guest* guest1=new Guest("Aisha", "malakmohamedrefaat4@gmail.com", "2025-03-20");
   Guest* guest2 =new Guest("Omar", "omar@example.com", "2025-03-18");
    Guest* guest3 =new Guest("Zainab", "zainab@example.com", "2025-03-20");
    Guest* guest4 =new Guest("Malak", "malak@example.com", "2025-03-22");
    Guest* guest5 =new Guest("Nada", "nada@example.com", "2025-03-22");
    Guest* guest6 =new Guest("reem", "Reem@example.com", "2025-03-22");
    guest2-> display_guest();
    guest2->update_invitatation("2005-05-1");
    guest2-> display_guest();
    cout<<endl;
    MalakIftar.add_guest(guest1);
    MalakIftar.add_guest(guest2);
    MalakIftar.add_guest(guest3);
    MalakIftar.add_guest(guest4);
    MalakIftar.add_guest(guest5);
    MalakIftar.add_guest(guest6);
    MalakIftar.display_all_guests();
    MalakIftar.update_guest_invitation("Omar","2025-02-2");
    MalakIftar.display_all_guests();
    MalakIftar.sort_guest_list();
    MalakIftar.display_all_guests();
    MalakIftar.send_reminders("2025-03-20");
    MalakIftar.send_reminders("2025-07-20");
    MalakIftar.send_reminders("2025-03-22");
    return 0;
}
