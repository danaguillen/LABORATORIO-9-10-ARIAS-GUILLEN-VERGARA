#ifndef HIERARCHY_HPP
#define HIERARCHY_HPP

#include <iostream>
#include <string>

class GeologicalSensor {
protected:
    std::string sensorId;
    std::string location;

public:
    GeologicalSensor(std::string id, std::string loc) : sensorId(id), location(loc) {}
    virtual ~GeologicalSensor() {}

    virtual void displaySensorStatus() const = 0;
    virtual double calculateRiskLevel() const = 0;
    virtual void triggerEmergencyProtocol() const = 0;

    std::string getSensorId() const { return sensorId; }
    std::string getLocation() const { return location; }
};

class SeismicStation : public GeologicalSensor {
protected:
    double depthKm;

public:
    SeismicStation(std::string id, std::string loc, double depth)
        : GeologicalSensor(id, loc), depthKm(depth) {
    }

    void displaySensorStatus() const override {
        std::cout << "Sensor ID: " << sensorId << " | Location: " << location
            << " | Depth: " << depthKm << " km";
    }
};

class Seismograph : public SeismicStation {
private:
    double richterMagnitude;

public:
    Seismograph(std::string id, std::string loc, double depth, double magnitude)
        : SeismicStation(id, loc, depth), richterMagnitude(magnitude) {
    }

    void displaySensorStatus() const override {
        SeismicStation::displaySensorStatus();
        std::cout << " | Type: Seismograph | Magnitude: " << richterMagnitude << " Richter" << std::endl;
    }

    double calculateRiskLevel() const override {
        return richterMagnitude * 15.5 + (depthKm * 0.5);
    }

    void triggerEmergencyProtocol() const override {
        std::cout << "[Alert - Seismograph]: Issuing early seismic wave warning!" << std::endl;
    }
};

class GasSpectrometer : public SeismicStation {
private:
    double so2Ppm;

public:
    GasSpectrometer(std::string id, std::string loc, double depth, double so2)
        : SeismicStation(id, loc, depth), so2Ppm(so2) {
    }

    void displaySensorStatus() const override {
        SeismicStation::displaySensorStatus();
        std::cout << " | Type: Gas Spectrometer | SO2: " << so2Ppm << " ppm" << std::endl;
    }

    double calculateRiskLevel() const override {
        return so2Ppm * 0.25;
    }

    void triggerEmergencyProtocol() const override {
        std::cout << "[Alert - Gas Spectrometer]: High sulfur dioxide levels detected!" << std::endl;
    }
};

class Tiltmeter : public GeologicalSensor {
private:
    double angleMicroradians;

public:
    Tiltmeter(std::string id, std::string loc, double angle)
        : GeologicalSensor(id, loc), angleMicroradians(angle) {
    }

    void displaySensorStatus() const override {
        std::cout << "Sensor ID: " << sensorId << " | Location: " << location
            << " | Type: Tiltmeter | Ground Deformation: " << angleMicroradians << " microradians" << std::endl;
    }

    double calculateRiskLevel() const override {
        return angleMicroradians * 3.2;
    }

    void triggerEmergencyProtocol() const override {
        std::cout << "[Alert - Tiltmeter]: Ground inflation detected!" << std::endl;
    }
};

#endif