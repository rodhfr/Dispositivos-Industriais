#include <iostream>
#include <thread>
#include <chrono>

class Sensor {
private:
    bool status;
    float temp_atual;

public:
    
    Sensor() : status(false) {}

    
    bool getStatus() const {
        return status;
    }

   
    void setStatus(bool newStatus) {
        status = newStatus;
    }

    void iniciar() {
        setStatus(true); 
        while (getStatus()) {
            temp_atual = getTemperatura();
            std::cout << temp_atual << " temp atual" << std::endl;
            std::cout << "Sensor de temperatura em execução. Status: ativo." << std::endl;
            alerta_temperatura();
            std::cout << "Esperando 1s... Estou dentro de sensor_temperatura.h" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

           
        }
    }


    void parar() {
        setStatus(false);  
    }

    
    float getTemperatura() {
        
        return 25.0f;  
    }

   
    void alerta_temperatura() {
        
        if (temp_atual > 30.0f) {
            std::cout << "ALERTA: Temperatura alta!" << std::endl;
        }
    }
};

int main() {
    Sensor sensor;

    
    std::thread sensorThread([&sensor]() {
        sensor.iniciar();
    });

    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Comando para parar o sensor." << std::endl;
    sensor.parar();  

    
    sensorThread.join();

    return 0;
}

