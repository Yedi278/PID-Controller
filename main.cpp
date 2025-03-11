#include <iostream>
#include <string>

#include "customPID.h"
#include <fstream>

int main(int argc, char** argv){

    double kp = 0.2;
    double ki = 0.2;
    double kd = 0.6;

    double target = 1500;
    double theta = 0;
    
    std::ofstream file;
    file.open("output.csv");
    file << "Time,Theta,Velocity,Error\n";
    
    PID<double, double> pid(kp, ki, kd, target);

    pid.setLimit(255);

    double dt = 0.01;
    double velocity = 255.0f; // from 0 to 255
    
    double time = 0.0;
    
    long int counter = 0;
    while(1){
        
        time += dt;
        velocity = pid.compute(theta, dt);

        theta += (velocity*dt);

        LOG("Theta: " << theta << " Velocity: " << velocity << " Error: " << pid.getError());

        file << time << "," << theta << "," << velocity << "," << pid.getError() <<"\n";
        
        if(counter > 10000){
            break;
        }
        counter++;
    }

    file.close();
    return 0;
}