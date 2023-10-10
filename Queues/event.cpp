#include "event.h"

Event::Event(){
    time = 0;
    duration = 0;
    type = ' ';
}
Event::Event(int newTime, int newDuration, char newType){
    setTime(newTime);
    setDuration(newDuration);
    setType(newType);
}
Event::Event(const Event& rhs){
    setTime(rhs.time);
    setDuration(rhs.duration);
    setType(rhs.type);
}

void Event::setTime(int newTime){
    if(newTime >= 0){
        time = newTime;
    }
    else{
        time = 0;
    }
}
void Event::setDuration(int newDuration){
    if(newDuration >= 0){
        duration = newDuration;
    }
    else{
        duration = 0;
    }
}
void Event::setType(char newType){
    switch (newType){
        case 'A':
        case 'a':
            type = ARRIVAL;
            break;
        case 'D':
        case 'd':
            type = DEPARTURE;
            break;        
        default:
            type = ' ';
            break;
    }
}

int Event::getTime() const{
    return time;
}
int Event::getDuration() const{
    return duration;
}
char Event::getType() const{
    return type;
}

bool Event::operator>(const Event& rhs){
    return time < rhs.time;
}
bool Event::operator<(const Event& rhs){
    return time > rhs.time;
}

istream& operator>>(istream& in, Event& event){
    in >> event.time >> event.duration;
    event.setType(ARRIVAL);
    return in;
}
ostream& operator<<(ostream& out, const Event& event){
    out << event.type << ": " << event.time << " " << event.duration << endl;
    return out;
}