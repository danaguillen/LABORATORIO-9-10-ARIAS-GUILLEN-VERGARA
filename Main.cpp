#include <iostream>
#include "VolcanoManager.hpp"

void printMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "      SISTEMA DE MONITOREO VOLCANICO     \n";
    std::cout << "=========================================\n";
    std::cout << "1. Agregar Sismografo\n";
    std::cout << "2. Agregar Espectrometro de Gases\n";
    std::cout << "3. Agregar Inclinometro\n";
    std::cout << "4. Mostrar Todos los Sensores\n";
    std::cout << "5. Calcular Indice de Riesgo Promedio de la Red\n";
    std::cout << "6. Eliminar Sensor por Indice\n";
    std::cout << "7. Salir\n";
    std::cout << "Elija una opcion: ";
}

int main() {
    VolcanoNetworkManager network;
    int option = 0;

    do {
        printMenu();
        std::cin >> option;

        if (option == 1) {
            std::string id, loc;
            double depth, mag;
            std::cout << "ID del Sensor: "; std::cin >> id;
            std::cout << "Ubicacion: "; std::cin >> loc;
            std::cout << "Profundidad (km): "; std::cin >> depth;
            std::cout << "Magnitud: "; std::cin >> mag;
            network.addSensorBack(new Seismograph(id, loc, depth, mag));

        }
        else if (option == 2) {
            std::string id, loc;
            double depth, so2;
            std::cout << "ID del Sensor: "; std::cin >> id;
            std::cout << "Ubicacion: "; std::cin >> loc;
            std::cout << "Profundidad (km): "; std::cin >> depth;
            std::cout << "SO2 (ppm): "; std::cin >> so2;
            network.addSensorBack(new GasSpectrometer(id, loc, depth, so2));

        }
        else if (option == 3) {
            std::string id, loc;
            double angle;
            std::cout << "ID del Sensor: "; std::cin >> id;
            std::cout << "Ubicacion: "; std::cin >> loc;
            std::cout << "Angulo de deformacion: "; std::cin >> angle;
            network.addSensorFront(new Tiltmeter(id, loc, angle));

        }
        else if (option == 4) {
            network.displayAllSensors();

        }
        else if (option == 5) {
            std::cout << "\nIndice de riesgo promedio de la red: " << network.calculateAverageRisk() << "\n";

        }
        else if (option == 6) {
            int idx;
            std::cout << "Indice a eliminar: ";
            std::cin >> idx;
            network.removeSensor(idx);
        }

    } while (option != 7);

    network.clearAll();
    return 0;
}