/*
Each flight must store the following information:
1) Flight number
2) Destination
3) Scheduled departure time
4) Current time
5) Delay time in minutes
6) Whether the flight is cancelled
7) Flight status

You must write a function that converts military time (HHMM) into minutes since midnight.
Examples:
0900 → 540 minutes
1345 → 825 minutes
1500 → 900 minutes
All flight times must be converted using this function.

The flight status must be represented using an enumerator with the following possible values:
1) ON_TIME
2) DELAYED
3) BOARDING
4) DEPARTED
5) CANCELLED

Write a function that determines the correct flight status using the rules below.
These rules must be applied in the correct order.
1) If the flight is cancelled, the status is CANCELLED.
2) If the current time is equal to or later than the scheduled departure time, the status is DEPARTED.
3) If the flight has a delay (delay time greater than 0) and the current time is before the scheduled departure time, the status is DELAYED.
4) If the current time is within 30 minutes of the scheduled departure time, but still before departure, and the flight is not delayed, the status is BOARDING.
5) If none of the above conditions apply, the flight is ON_TIME.

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// =====================
// Enum for flight status
// =====================
enum status { ON_TIME, DELAYED, BOARDING, DEPARTED, CANCELLED };

// =====================
// Struct for flight data
// =====================
struct Flight {
    string flightNumber;
    string destination;
    int scheduledDeparture;
    int currentTime;
    int delayMinutes;
    bool isCancelled;
    status status;
};

// =====================
// Function prototypes
// =====================
// ** Please add the proper parameters **
int militaryToMinutes(int time) {
    
	int minutes = (time / 100) * 60 + (time % 100);

    return minutes;
}
void updateFlightStatus(Flight& flight) {

    if (flight.isCancelled) {
        flight.status = CANCELLED;
    }
    else if (flight.delayMinutes > 0) {
        flight.status = DELAYED;
    }
    else if (flight.currentTime > flight.scheduledDeparture) {
        flight.status = DEPARTED;
    }
    else if (flight.currentTime > flight.scheduledDeparture - 30 && flight.currentTime < flight.scheduledDeparture) {
        flight.status = BOARDING;
    }
    else {
        flight.status = ON_TIME;
    }
}
string statusToString(status status) {

    string sStatus;

    switch (status) {

    case ON_TIME:
        sStatus = "On time";
        break;

    case DELAYED:
        sStatus = "Delayed";
        break;

    case DEPARTED:
        sStatus = "Departed";
        break;

    case CANCELLED:
        sStatus = "Cancelled";
        break;

    case BOARDING:
        sStatus = "Boarding";
        break;
    }

    return sStatus;
}
int displayFlight(Flight flight) {
    
    //stringstream ss;

    //ss >> "Flight Number: " >> flight.flightNumber >> "\nFlight Destination: " >> flight.destination >> "\nFlight Scheduled Departure: " >> flight.scheduledDeparture >> "\nCurrent Time: " >> flight.currentTime >> "Delay Time: " >> flight.delayMinutes >> "\nFlight Status: " >> statusToString(flight.status);
    
   
    cout << "Flight Number: " << flight.flightNumber << endl;
    cout << "Flight Destination: " << flight.destination << endl;
    cout << "Flight Scheduled Departure: " << flight.scheduledDeparture << endl;
    cout << "Current Time: " << flight.currentTime << endl;
    cout << "Delay Time: " << flight.delayMinutes << endl;
    cout << "Flight Status: " << statusToString(flight.status) << endl;
    

    //string str = ss.str();
    return 0;
}

// =====================
// Main
// =====================
int main() {

    Flight flight1;
    flight1.flightNumber = "UA101";
    flight1.destination = "Denver";
    flight1.scheduledDeparture = militaryToMinutes(1500);
    flight1.currentTime = militaryToMinutes(1300);
    flight1.delayMinutes = 0;
    flight1.isCancelled = false;
    flight1.status = ON_TIME;

    Flight flight2;
    flight2.flightNumber = "DL202";
    flight2.destination = "Atlanta";
    flight2.scheduledDeparture = militaryToMinutes(1400);
    flight2.currentTime = militaryToMinutes(1345);
    flight2.delayMinutes = 0;
    flight2.isCancelled = false;
    flight2.status = ON_TIME;

    Flight flight3;
    flight3.flightNumber = "AA303";
    flight3.destination = "Dallas";
    flight3.scheduledDeparture = militaryToMinutes(1600);
    flight3.currentTime = militaryToMinutes(1500);
    flight3.delayMinutes = 45;
    flight3.isCancelled = false;
    flight3.status = ON_TIME;

    Flight flight4;
    flight4.flightNumber = "SW404";
    flight4.destination = "Phoenix";
    flight4.scheduledDeparture = militaryToMinutes(1200);
    flight4.currentTime = militaryToMinutes(1230);
    flight4.delayMinutes = 0;
    flight4.isCancelled = false;
    flight4.status = ON_TIME;

    Flight flight5;
    flight5.flightNumber = "BA505";
    flight5.destination = "London";
    flight5.scheduledDeparture = militaryToMinutes(1800);
    flight5.currentTime = militaryToMinutes(1600);
    flight5.delayMinutes = 0;
    flight5.isCancelled = true;
    flight5.status = ON_TIME;

    updateFlightStatus(flight1);
    displayFlight(flight1);
    cout << endl;

    updateFlightStatus(flight2);
    displayFlight(flight2);
    cout << endl;

    updateFlightStatus(flight3);
    displayFlight(flight3);
    cout << endl;

    updateFlightStatus(flight4);
    displayFlight(flight4);
    cout << endl;

    updateFlightStatus(flight5);
    displayFlight(flight5);

    return 0;
}