import os

try:
    os.system('cmd /k "g++ main.cpp implementation.cpp -o main"')
except:
    print("Could not execute")