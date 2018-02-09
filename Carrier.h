/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carrier.h
 * Author: snbl
 *
 * Created on February 9, 2018, 11:14 AM
 */

#ifndef CARRIER_H
#define CARRIER_H

#include "Airport.h"
#include "Flight.h"

class Carrier {
public:
    Carrier(std::string airportName);
   ~Carrier();
    void print();
    void print_flights();
    Airport* get_airport(std::string iata);
    void addFlight(std::string flightNumber, std::string from, std::string to, std::vector<std::string> stops);



private:
    std::string name;
    std::vector<Airport> airports;
    std::vector<Flight> flights;
};

#endif /* CARRIER_H */

