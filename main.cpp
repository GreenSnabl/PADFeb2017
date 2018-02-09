/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on February 9, 2018, 11:00 AM
 */

#include "Carrier.h"
#include "Flight.h"
#include "Airport.h"

int main(int argc, char** argv) {
    
    Carrier carrier("ok");
    std::vector<std::string> zwischenstopps = {"DXB", "ORD", "HND", "LAX", "CDG", "DFW"};
    //std::vector<std::string> zwischenstopps2;
    
    carrier.addFlight("123456", "ATL", "PEK", zwischenstopps);
    carrier.addFlight("4234", "DXB", "ORD", zwischenstopps);
    carrier.print_flights();
    
    
    return 0;
}

