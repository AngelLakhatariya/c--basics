    #include <iostream>
    using namespace std;

    class TimeConverter {
        public:
        void secondstoHMS() {
            int totalseconds;
            cout<< "Enter total seconds: ";
            cin>> totalseconds;

            int hours = totalseconds / 3600;
            int minutes = (totalseconds % 3600) / 60;
            int seconds = totalseconds % 60;

            cout<< "HH:MM:SS =>" << hours << ":" << minutes <<":" << seconds << endl;
        }

        void HMStoseconds(){
            int hours, minutes, seconds;
            cout<< "Enter hours: ";
            cin>> hours;
            cout<<"Enter minutes: ";
            cin>> minutes;
            cout<< "Enter seconds: ";
            cin>> seconds;

            int totalseconds = (hours * 3600) + (minutes * 60) + seconds;

            cout<< "Total seconds: "<< totalseconds << endl;
        }
};

        int main() {
            TimeConverter converter ;
            converter.secondstoHMS();
            converter.HMStoseconds();
        }
        
    
