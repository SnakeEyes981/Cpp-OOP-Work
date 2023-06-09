#include<iostream>
#include<iomanip>

using namespace std;
class Time{
	private:
		int hour, min, sec;
		char mode;
	public:
		//Default Constructor
		Time(): hour(0), min(0), sec(0), mode('a'){
		}
		// Param. Constructor
		Time(int _hour, int _min, int _sec, char _mode): hour(_hour), min(_min), sec(_sec), mode(_mode){
		}
		// Param. Constructor
		Time(int _hour, int _min, int _sec): hour(_hour), min(_min), sec(_sec){
//			if(_sec > 60){
//				_min += (_sec / 60);
//				min = _min;
//				sec = _sec % 60;
//			}
//			if(_min > 60){
//				_hour += (_min / 60);
//				hour = _hour;
//				min = _min % 60;
//			}
//			if(_hour > 12){
//				hour = _hour - 12;
//				mode = 'p';
//				}
		}
		// Param. Constructor
		Time (const Time& t1): hour(t1.hour), min(t1.min), sec(t1.sec), mode(t1.mode){
		}
		int getHours(){
			return hour;
		}
		int getMinutes(){
			return min;
		}
		int getSeconds(){
			return sec;
		}
		char getMode(){
			return mode;
		}
		void setHours(int _hour){
			hour += _hour;
			if(hour > 12){
				hour = hour % 12;
				mode = 'a';
			}
		}
		void setMinutes(int _min){
			min += _min;
			if(min >= 60){
				hour += (min / 60);
				if(hour > 12){
					if( mode == 'a') mode = 'p';	else mode = 'a';
					hour = hour % 12;
				}
				min = min % 60;
			}
		}
		void setSeconds(int _sec){
			sec += _sec;
			if(sec >= 60){
				min += sec / 60;
				if(min >= 60){
					hour += (min / 60);
					if(hour > 12){
						if( mode == 'a') mode = 'p';	else mode = 'a';
						hour = hour % 12;
					}
					min = min % 60;
				}
				sec = sec % 60;
			}
		}
		void setMode(char _mode){
			mode == _mode;
		}
		void displayTime(){
			cout<<setw(25)<<"Hours : Minutes : Seconds"<<endl;
			cout<<setw(3)<<hour<<setw(4)<<":"<<setw(5)<<min<<setw(5)<<":"<<setw(5)<<sec<<" "<<setw(4);
			if(mode == 'a' || hour >= 12) cout<<"    AM\n";
			if(mode == 'p' || hour >= 12) cout<<"    PM\n";
		}
		double convertToSeconds(){
			sec += min * 60;
			sec += hour * 3600;
			return sec;
		}
		double convertToMinutes(){
			min += sec / 60;
			min += hour * 60;
			return min;
		}
		double convertToHours(){
			min += sec / 60;
			hour += min / 60;
		}
		void convertTo24HourFormat(){
			if(mode == 'p'){
				cout<<setw(25)<<"*24 Hour Format*\n";
				cout<<setw(25)<<"Hours : Minutes : Seconds"<<endl;
				cout<<setw(3)<<hour+12<<setw(4)<<":"<<setw(5)<<min<<setw(5)<<":"<<setw(5)<<sec<<" "<<setw(4);
			}
		}
		void incrementSeconds(int _sec){
			sec += _sec;
			if(sec > 60){
				min += sec / 60;
				if(min > 60){
					hour += min / 60;
					if(hour > 12){
					hour = hour % 12;
					if(hour < 12)
						if(mode == 'p') mode = 'a';
						else mode = 'p';
					else if (hour > 12) 
						if( mode == 'a') mode = 'p';
						else mode = 'a';
					}
				sec = sec % 60;
				}	
			}
		}
		void incrementMinutes(int _min){
			min += _min;
			if(min > 60){
				hour += min / 60;
				if(hour > 12){
					hour = hour % 12;
					if(hour < 12)
						if(mode == 'p') mode = 'a';
						else mode = 'p';
					else if (hour > 12) 
						if( mode == 'a') mode = 'p';
						else mode = 'a';
				}
				min = min % 60;
			}
		}
};
void insertLine(){
	cout<<"--------------------------------"<<endl;
}
int main(){
	int hours, mins, sec, temp;
	char mode = 'o';
	
	// Getting & Validating Input From User To Pass onto Constructor
	cout<<"Please Enter Time in Following Format [HH:MM:SS]: "<<endl;
	insertLine();
	do{
		cout<<"Hours (Between 1-12): ";
		cin>>hours;
		if(hours > 12 || hours <= 0)
			cout<<"Enter Value Between 1-12!"<<endl;
	}while(hours > 12 || hours <= 0);
	insertLine();
	do{
		cout<<"Minutes (Between 0-59): ";
		cin>>mins;
		if(mins > 59 || mins <= 0)
			cout<<"Enter Value Between 0-59!"<<endl;
	}while(mins > 59 || mins <= 0);
	insertLine();
	do{
		cout<<"Seconds (Between 0-59): ";
		cin>>sec;
		if(sec > 59 || sec <= 0)
			cout<<"Enter Value Between 0-59!"<<endl;
	}while(sec > 59 || sec <= 0);
	insertLine();
	do{
		cout<<"Press 'a' for AM\nOR\n'p' for PM"<<endl;
		cin>>mode;
		if(mode != 'a' && mode != 'p')
			cout<<"Select a or p only!"<<endl; insertLine();
	}while(mode != 'a' && mode != 'p');
	
	Time t1(hours,mins,sec,mode);
	
	insertLine();
	t1.displayTime();
	
//Updating Minutes =>
//	cout<<"How Many Minutes You Want to Add? ";
//	cin>>temp;
//	t1.incrementMinutes(temp);

//Setting Minutes =>
	t1.setSeconds(1);
	t1.setMinutes(1);
	insertLine();
	t1.displayTime();
	insertLine();
	t1.convertTo24HourFormat();
}
