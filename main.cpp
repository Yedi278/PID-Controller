#include <iostream>
#include <string>

#include "customPID.h"
#include <fstream>

int main(int argc, char** argv){

    // float kp = 0.1;
    // float ki = 0.1;
    // float kd = 0.1;

    float kp = atof(argv[1]);
    float ki = atof(argv[2]);
    float kd = atof(argv[3]);

    int target = atof(argv[4]);

    std::cout << "kp: " << kp << std::endl;
    std::cout << "ki: " << ki << std::endl;
    std::cout << "kd: " << kd << std::endl;
    std::cout << "target: " << target << std::endl;
    
    std::ofstream file;
    file.open("output.csv");
    file << "Time,Theta,Velocity\n";

    int theta = 0;
    // int target = 100;
    
    float velocity = 1.0f; // from 0 to 255
    
    PID pid(kp, ki, kd, target);
    float dt = 0.1;
    
    float time = 0.0;
    int counter=0;
    while(1){
        
        time += dt;
        velocity = pid.compute(theta, dt);

        theta += (int)velocity*dt;

        if(counter >= 1000){
            break;
        }
        counter++;
        file << time << "," << theta << "," << velocity << "\n";
    }

    file.close();
    return 0;
}