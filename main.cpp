/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on May 5, 2016, 10:51 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Projectile.h"
#include "Rocket.h"
#include "World.h"
#include "Thrust.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argp, char **envp) {
    //Rocket (mass, drag x, drag y, area x, area y, newtons of thrust , burn time , flow rate);
    Rocket rocket(80, .3, .3, 1, 1, 2000, 60, 20);
    /*World ( density of air,  acceleration due to gravity) if this is left blank then it creates a world
        equivalent to earth. */
    World world;
    // Creates array to handle output, first value is distance traveled on  x, then dist on y, then seconds of travel.
    double* out;
    //runs thrust function passing it the rocket, the world it is in, and the angle of launch
    out = thrust(rocket, world, 85);
    printf("Time Taken: %f\n", out[2]);
    delete out;
    //plots in GNUPlot 

    const char *prefix = nullptr;
    // Iterate over envp to find the PREFIX variable
    for (int i = 0; envp[i] != nullptr; ++i) {
        // Check if the current environment variable starts with "PREFIX="
        if (std::strncmp(envp[i], "PREFIX=", 7) == 0) {
            prefix = envp[i] + 7; // Skip the "PREFIX=" part
            break;
        }
    }

    plot(prefix);
    return 0;
}
