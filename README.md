# 🚆 Train Passenger Tracking System – C++ Simulation

This project was developed as the **second assignment for the course "Programming Lab I"** (C++).  
It implements a **train management and epidemiological tracking system**, modeling trains, wagons, locomotives, passengers, and travel records. The system applies object-oriented programming, UML class design, exception handling, and advanced C++ features.  

---

## 📌 Project Overview

The program simulates a railway company under COVID-19 restrictions, where passenger capacity is limited and epidemiological tracking is required.

### Main Features
- **Passenger class**: DNI, name, weight, origin/destination stations, boarding and leaving times.  
- **Wagon class**:
  - Unique ID, weight, maximum passenger capacity (reduced to 25% for COVID protocols).  
  - When full, if a new passenger tries to board, one of three things can happen (randomly):  
    1. Passenger cannot board (exception thrown).  
    2. A random passenger is removed to allow boarding.  
    3. Passenger boards anyway, breaking the protocol.  
- **Locomotive class**: Serial number, power, weight, max towing capacity, length.  
- **Train class**:
  - Unique ID, locomotive, list of wagons, and list of trips.  
  - Trips include departure/arrival times and stations.  
  - Methods to add/remove wagons (with exceptions if limits exceeded).  
  - Pre-departure weight checks: if overweight, the heaviest passengers are removed until compliant.  
- **Epidemiological tracking**:
  - A static **Record class** logs passenger travel data (boarding, exiting, train ID, wagon ID).  
  - The system can trace potential contacts of an infected passenger (those sharing the same wagon and overlapping travel times).  

- **Advanced programming requirements**:
  - UML class design  
  - `to_string` and printing methods  
  - Getters and setters  
  - Exception handling  
  - Use of at least one `static` attribute, one `const` attribute, and one `friend` class  

---

## 🛠️ Technologies & Concepts
- Language: **C++**
- Paradigm: **Object-Oriented Programming (OOP)**
- UML class design
- Exception handling
- Static attributes and friend classes
- Dynamic memory management
- Simulation of discrete events

---

## ▶️ How to Run the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/PieriFra/TP2-LAB-PROGRA.git
   cd TP2-LAB-PROGRA

2. Compile the program:
   ```bash
   g++ -o TrainSystem main.cpp

3. Run the simulation:
   ```bash
   ./TrainSystem

## 📊 Example Use Cases
- Add wagons to a train (with restrictions)
- Simulate passenger boarding/unboarding under COVID protocols
- Run trips across different stations
- Generate epidemiological reports for contact tracing
- Enforce locomotive towing capacity rules

## 🎯 Learning Goals
This project put into practice:
- Class design with UML
- Exception handling in C++
- Inheritance, static attributes, and friend classes

Object-oriented simulation

Contact tracing logic using data structures
