/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airport.cpp
 * Author: snbl
 * 
 * Created on February 9, 2018, 11:14 AM
 */

#include "Airport.h"
#include <iostream>

using std::cout;


//Airport::Airport() : name {""}, iata {""}, longitude {-1}, latitude {-1} {}

Airport::Airport(std::string m_name, std::string m_iata, double m_latitude, double m_longitude) : name {m_name}, iata {m_iata}, latitude {m_latitude}, longitude {m_longitude} {}

Airport::~Airport() {
}

const double Airport::get_latitude() const
{
    return latitude;
}
const double Airport::get_longitude() const
{
    return longitude;
}
const std::string Airport::get_iata() const
{
    return iata;
}


void Airport::print() {
    cout << "Flughafen " << name << " (" << iata << ")\n"; 
}