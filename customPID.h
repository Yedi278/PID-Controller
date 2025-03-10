#ifndef CUSTOM_PID_H
#define CUSTOM_PID_H

#include <iostream>


class PID{

private:
    float kp_;      // Proportional term
    float ki_;      // Integral term
    float kd_;      // Derivative term

    
    float proportional_;
    float integral_;
    float derivative_;
    
    int target_;

    float error_;
    float error_old;

public:

    PID(float kp, float ki, float kd, int target): kp_(kp), ki_(ki), kd_(kd), 
        proportional_(0), integral_(0), derivative_(0), error_(0), error_old(0), target_(target_)
        {
            std::cout << "PID Controller Initialized" << std::endl;
        }
    
    float compute(int input, float time_interval=0.1){

        error_ = (float)(target_ - input);

        proportional_ = kp_ * error_;
        integral_    += ki_ * error_ * time_interval;
        derivative_   = kd_ * (error_ - error_old) / time_interval;

        return kp_*proportional_ + ki_*integral_ + kd_*derivative_;
    }
    
    ~PID(){
        
    }
    
private:

};

#endif // CUSTOM_PID_H