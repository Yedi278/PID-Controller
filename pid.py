import numpy as np
import time

class PID:

    proportional = 0
    integral = 0
    derivative = 0
    prev_error = 0
    setpoint = 0
    error=0
    output=0

    def __init__(self, kp, ki, kd, setpoint):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.setpoint = setpoint
        self.prev_error = 0

    def compute(self, val, time_interval=0.1):

        self.error = self.setpoint - val

        self.proportional = self.kp * self.error

        self.integral += self.ki * self.error * time_interval

        self.derivative = self.kd * (self.error - self.prev_error) / time_interval

        self.output = self.proportional + self.integral + self.derivative

        self.prev_error = self.error

        return self.output

    def plot():

        pass


if __name__ == '__main__':

    import matplotlib.pyplot as plt

    kp=1
    ki=.7
    kd=.3

    theta = 0
    w = 1
    t = 0

    dt = 0.03
 
    angles = []
    times = []

    pid = PID(kp,ki,kd, 1000)

    count = 0
    while 1:

        theta += w*dt + np.random.randn()

        t+=dt

        w = pid.compute(theta, dt)
        angles.append(theta)
        times.append(t)

        if count>1000:
            break

        count+=1


    i = 0
    f = -1
    plt.plot(times[i:f], angles[i:f])
    plt.show()