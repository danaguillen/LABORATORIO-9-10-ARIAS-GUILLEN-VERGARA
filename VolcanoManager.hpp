#ifndef VOLCANOMANAGER_HPP
#define VOLCANOMANAGER_HPP

#include "List.hpp"
#include "Hierarchy.hpp"

class VolcanoNetworkManager {
private:
    List<GeologicalSensor*> sensorList;

public:
    ~VolcanoNetworkManager() {
        clearAll();
    }

    void addSensorFront(GeologicalSensor* sensor) {
        sensorList.insertFront(sensor);
    }

    void addSensorBack(GeologicalSensor* sensor) {
        sensorList.insertBack(sensor);
    }

    void displayAllSensors() const {
        Node<GeologicalSensor*>* current = sensorList.getHead();
        if (!current) {
            std::cout << "\n[The monitoring network is empty!]\n";
            return;
        }

        int index = 0;
        std::cout << "\n=== VOLCANIC & SEISMIC SENSOR NETWORK ===" << std::endl;
        while (current != nullptr) {
            std::cout << "[" << index++ << "] ";
            current->data->displaySensorStatus();
            current->data->triggerEmergencyProtocol();
            std::cout << "    Risk Index: " << current->data->calculateRiskLevel() << "\n\n";
            current = current->next;
        }
    }

    double calculateAverageRisk() const {
        Node<GeologicalSensor*>* current = sensorList.getHead();
        if (!current) return 0.0;

        double totalRisk = 0.0;
        int count = 0;
        while (current != nullptr) {
            totalRisk += current->data->calculateRiskLevel();
            count++;
            current = current->next;
        }
        return totalRisk / count;
    }

    bool removeSensor(int index) {
        Node<GeologicalSensor*>* current = sensorList.getHead();
        for (int i = 0; current != nullptr && i < index; ++i) {
            current = current->next;
        }

        if (current) {
            delete current->data;
            return sensorList.removeAt(index);
        }
        return false;
    }

    void clearAll() {
        Node<GeologicalSensor*>* current = sensorList.getHead();
        while (current != nullptr) {
            delete current->data;
            current = current->next;
        }
        sensorList.clear();
    }
};

#endif