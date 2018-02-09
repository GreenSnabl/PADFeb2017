/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.cpp
 * Author: snbl
 * 
 * Created on February 9, 2018, 11:14 AM
 */
#include <iostream>


#include "Flight.h"
#include <cmath>

using std::asin; using std::sqrt; using std::cos; using std::sin; using std::pow;


//Flight::Flight()  {}

Flight::Flight(std::string m_flightNumber, Airport* m_start, Airport* m_destination) 
: flightNumber {m_flightNumber}, start{m_start}, destination {m_destination} 
{
    updateDistance();
}


Flight::~Flight() {
}

void Flight::addStopover(Airport* stop)
{
    if (stop == nullptr) return;
    zwischenstopps.push_back(stop);
    updateDistance();
}

void Flight::updateDistance()
{
    double sum = 0;
    if(zwischenstopps.size() > 0)
    {
        sum += calcDistance(start, zwischenstopps[0]);
        for (int i = 1; i < zwischenstopps.size(); ++i)
        {
        sum += calcDistance(zwischenstopps[i-1], zwischenstopps[i]);
        }
        sum += calcDistance(zwischenstopps[zwischenstopps.size()-1], destination);
        distance = sum;
    } 
    else {
        distance = calcDistance(start, destination);
    }
}

double calcDistance(Airport* air1, Airport* air2)
{
    const double r = 6371;
    double result = 0;
    double avgLong = (air2->get_longitude() - air1->get_longitude()) / 2;
    double avgLat = (air2->get_latitude() - air1->get_latitude()) / 2;
    result = 2 * r * asin(sqrt(pow(sin(avgLong),2) + cos(air1->get_longitude()) * cos(air2->get_longitude()) * pow(sin(avgLat),2)));
    return result;
}

const double Flight::get_distance() const
{
    return distance;
}


void Flight::print()
{
    std::cout << "Flugnummer\t\t" << flightNumber << "\n"
            << "Start:\t\t\t";
    start->print();
    std::cout << "Ziel:\t\t\t";
    destination->print();
    std::cout << "\nZwischenstopps:\n";
    for (int i = 0; i < zwischenstopps.size(); ++i)
    {
        std::cout << i + 1 << ".\t\t\t"; 
        zwischenstopps[i]->print();     
    }
    std::cout << "\nGesamte Flugdistanz:\t" << get_distance() << "\n\n" << std::endl;
}