/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airport.h
 * Author: snbl
 *
 * Created on February 9, 2018, 11:14 AM
 */

#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>



class Airport {
public:
    //Airport();
    Airport(std::string m_name, std::string m_iata, double m_latitude, double m_longitude);
    ~Airport();
    void print();
    const double get_latitude() const;
    const double get_longitude() const;
    const std::string get_iata() const;
private:
    std::string name;
    std::string iata;
    double latitude;
    double longitude;
};

#endif /* AIRPORT_H */

