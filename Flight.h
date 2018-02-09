/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.h
 * Author: snbl
 *
 * Created on February 9, 2018, 11:14 AM
 */

#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include <string>
#include <vector>


class Flight {
public:
//    Flight();
    Flight(std::string m_flightNumber, Airport* m_start, Airport* m_destination);
    ~Flight();
    void addStopover(Airport* stop);
    const double get_distance() const; 
    void print();
    
    
private:
    std::string flightNumber;
    double distance;
    Airport* start;
    Airport* destination;
    std::vector<Airport*> zwischenstopps;
    void updateDistance();
};

double calcDistance(Airport*, Airport*);


#endif /* FLIGHT_H */

