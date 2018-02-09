/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carrier.cpp
 * Author: snbl
 * 
 * Created on February 9, 2018, 11:14 AM
 */

#include "Carrier.h"
#include <fstream>

Carrier::Carrier(std::string m_name) : name{m_name}  {
    
    airports.push_back(Airport("Hartsfield-Jackson International Airport Atlanta", "ATL", 33.636667, -84.428056));
    airports.push_back(Airport("Beijing Capital International Airport", "PEK", 40.0725, 116.5975));
    airports.push_back(Airport("Dubai International Airport", "DXB", 25.252778, 55.364444));
    airports.push_back(Airport("Tokyo International Airport", "HND", 35.553333, 139.781111));
    airports.push_back(Airport("Heathrow Airport", "LHR", 51.4775, -0.461389));
    airports.push_back(Airport("Chicago O Hare International Airport", "ORD", 41.978611, -87.904722));
    airports.push_back(Airport("Los Angeles International Airport", "LAX", 33.9425, -118.408056));
    airports.push_back(Airport("Hong Kong International Airport", "HKG",22.308889, 113.914444));
    airports.push_back(Airport("Paris Charles de Gaulle Airport", "CDG", 49.009722, 2.547778));
    airports.push_back(Airport("Dallas International Airport", "DFW", 32.896944, -97.038056));
    airports.push_back(Airport("Istanbul Atatürk Airport", "IST", 40.976111, 28.814167));
    airports.push_back(Airport("Frankfurt Airport", "FRA", 50.033333, 8.570556));    
}


Carrier::~Carrier() {
}

void Carrier::print()
{
    for (int i = 0; i < airports.size(); ++i)
        airports[i].print();

}

void Carrier::print_flights()
{
    for (int i = 0; i < flights.size(); ++i)
    {
        flights[i].print();    
    }

}

Airport* Carrier::get_airport(std::string iata)
{
    Airport* result = nullptr;
    for (int i = 0; i < airports.size(); ++i)
        if (airports[i].get_iata() == iata) 
            result = &airports[i];
    return result;
}



void Carrier::addFlight(std::string flightNumber, std::string from, std::string to, std::vector<std::string> stops)
{
    Flight flight(flightNumber, get_airport(from), get_airport(to));
    for (int i = 0; i < stops.size(); ++i)
        flight.addStopover(get_airport(stops[i]));
    flights.push_back(flight);
}