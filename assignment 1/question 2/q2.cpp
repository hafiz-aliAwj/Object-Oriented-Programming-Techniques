#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// SensorReading class to represent individual sensor data
class SensorReading {
private:
    int sensorId;
    string location;
    string sensorType;
    double value;

public:
    // Constructors
    SensorReading() = default;
    SensorReading(int id, const string& loc, const string& type, double val)
        : sensorId(id), location(loc), sensorType(type), value(val) {}

    // Getters
    int getId() const { return sensorId; }
    string getLocation() const { return location; }
    string getType() const { return sensorType; }
    double getValue() const { return value; }

    // Setter
    void setValue(double val) { value = val; }
};

// Alert class to represent alerts generated from sensor readings
class Alert {
private:
    int priority;    
    string message;
    string alertType;

public:
    // Constructors
    Alert() = default;
    Alert(int p, const string& msg, const string& type)
        : priority(p), message(msg), alertType(type) {}

    // Getters
    int getPriority() const { return priority; }
    string getMessage() const { return message; }
    string getType() const { return alertType; }

    // Comparison operator for priority_queue (max-heap)
    bool operator<(const Alert& other) const {
        return priority < other.priority; // higher priority first
    }
};

// SensorProcessor class to manage sensor readings and alerts
class SensorProcessor {
private:
    unordered_map<int, SensorReading> sensorsById;               
    unordered_map<string, vector<SensorReading>> sensorsByLocation; 
    priority_queue<Alert> alertQueue;                            

public:
// Add a new sensor reading to the processor
void addSensorReading(const SensorReading& reading) {
        sensorsById[reading.getId()] = reading;
        sensorsByLocation[reading.getLocation()].push_back(reading);
    }

// Add a new alert to the priority queue
    void addAlert(const Alert& alert) {
        alertQueue.push(alert);
    }

// Process the next alert in the priority queue
    void processNextAlert() {
        if (alertQueue.empty()) {
            cout << "No alerts to process." << endl;
            return;
        }
        Alert topAlert = alertQueue.top();
        alertQueue.pop();
        cout << "Processing Alert: [" << topAlert.getType() << "] "
             << topAlert.getMessage() << " (Priority: " << topAlert.getPriority() << ")\n";
    }

// Find a sensor reading by its ID
    SensorReading* findSensorById(int sensorId) {
        auto it = sensorsById.find(sensorId);
        if (it != sensorsById.end())
            return &it->second;
        return nullptr;
    }

// Get all sensor readings for a specific location
    vector<SensorReading> getSensorsByLocation(const string& location) {
        auto it = sensorsByLocation.find(location);
        if (it != sensorsByLocation.end())
            return it->second;
        return {}; 
    }
};

// Main function to demonstrate the functionality of SensorProcessor
int main() {
    SensorProcessor processor;

// Adding sensor readings  
    processor.addSensorReading(SensorReading(101, "BuildingA", "Temperature", 25.6));
    processor.addSensorReading(SensorReading(102, "BuildingA", "Humidity", 55.2));
    processor.addSensorReading(SensorReading(201, "BuildingB", "Temperature", 27.3));

// Adding alerts
    processor.addAlert(Alert(3, "Temperature high in BuildingA", "WARNING"));
    processor.addAlert(Alert(5, "Critical system failure in BuildingB", "CRITICAL"));
    processor.addAlert(Alert(2, "Regular maintenance required", "INFO"));

// Processing alerts based on priority
    processor.processNextAlert(); 
    processor.processNextAlert(); 
    processor.processNextAlert(); 
    processor.processNextAlert(); 
    processor.processNextAlert(); 

// Find a sensor by ID
    SensorReading* s = processor.findSensorById(101);
    if (s) cout << "Sensor 101: " << s->getType() << " in " << s->getLocation() << endl;

// Get sensors by location
    vector<SensorReading> buildingA = processor.getSensorsByLocation("BuildingA");
    cout << "Sensors in BuildingA:" << endl;
    for (auto& sensor : buildingA)
        cout << sensor.getId() << " " << sensor.getType() << " = " << sensor.getValue() << endl;

    return 0;
}