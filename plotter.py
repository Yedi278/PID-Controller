import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('output.csv', sep=',')

plt.plot(df['Time'], df['Theta'], label='Theta')
plt.plot(df['Time'], df['Velocity'], label='Velocity')
plt.plot(df['Time'], df['Error'], label='Error')
plt.legend()
plt.xlabel('Time (s)')
plt.show()