#ifndef EVENT
#define EVENT

#include <iostream>
using namespace std;

#define ARRIVAL 'A'
#define DEPARTURE 'D'

class Event { 
private:
    int time, duration;
    char type;
public: 
    Event();
    Event(int, int, char);
    Event(const Event&);

    void setTime(int);
    void setDuration(int);
    void setType(char);

    int getTime() const;
    int getDuration() const;
    char getType() const;

    bool operator>(const Event&);
    bool operator<(const Event&);

	friend istream& operator>>(istream&,  Event&);
	friend ostream& operator<<(ostream&,  const Event&);
};  
#endif