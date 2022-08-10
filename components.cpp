#include "components.hpp"

ideal_resistor::ideal_resistor(double resistance_input){
    resistance = resistance_input;
    component_name = "Ideal resistor";
    }

double ideal_resistor::get_impedance_mag(double frequency_of_circuit){
    double dummy_mag{0*frequency_of_circuit*resistance};
    return resistance;
}

double ideal_resistor::get_impedance_phase(){
    return 0.0;
}

double ideal_resistor::get_resistance() const{
    return resistance;
}

std::complex<double> ideal_resistor::get_impedance(double frequency_of_circuit){
    auto dummy = frequency_of_circuit * 0;
    std::complex<double> ideal_resistor_impedance (resistance, 0.0);
    return ideal_resistor_impedance;
}

void ideal_resistor::get_component_info(){
    std::cout<<" "<<resistance<<" Ohms"<<std::endl;
}

ideal_capacitor::ideal_capacitor(double capacitance_input){
    capacitance = capacitance_input;
    component_name = "Ideal capacitor";
    }

double ideal_capacitor::get_impedance_mag(double frequency_of_circuit){
    return std::abs(get_impedance(frequency_of_circuit));
}

double ideal_capacitor::get_impedance_phase(){
    return -M_PI / 2;
}

double ideal_capacitor::get_capacitance() const{
    return capacitance;
}

std::complex<double> ideal_capacitor::get_impedance(double frequency_of_circuit){

    double im_part = frequency_of_circuit * capacitance;
    std::complex<double> impedance_reciprocal(0.0, im_part);
    std::complex<double> ideal_capacitor_impedance = std::pow(impedance_reciprocal, -1);

    return ideal_capacitor_impedance;
}

void ideal_capacitor::get_component_info(){
    std::cout<<" "<<capacitance<<" Farads"<<std::endl;
}

ideal_inductor::ideal_inductor(double inductance_input){
    inductance = inductance_input;
    component_name = "Ideal inductor";
    }

double ideal_inductor::get_impedance_mag(double frequency_of_circuit){
    return std::abs(get_impedance(frequency_of_circuit));
}

double ideal_inductor::get_impedance_phase(){
    return M_PI / 2;
}

std::complex<double> ideal_inductor::get_impedance(double frequency_of_circuit){
    std::complex<double> ideal_inductor_impedance (0.0, frequency_of_circuit * inductance);
    return ideal_inductor_impedance;
}

double ideal_inductor::get_inductance() const{
    return inductance;
}

void ideal_inductor::get_component_info(){
    std::cout<<" "<<inductance<<" Henrys"<<std::endl;
}

non_ideal_resistor::non_ideal_resistor(double resistance_input, double parasitic_capacitance_input, 
double parasitic_inductance_input){

        resistance = resistance_input;
        parasitic_capacitance = parasitic_capacitance_input;
        parasitic_inductance = parasitic_inductance_input;
        component_name = "Non-ideal resistor";
    }

    std::complex<double> non_ideal_resistor::get_impedance(double frequency_of_circuit){
        
        std::complex<double> non_ideal_resistor_resistance (resistance, 0);
        std::complex<double> impedance_rc_ciruit_denom (1, (frequency_of_circuit*resistance*parasitic_capacitance));
        std::complex<double> impedance_rc_circuit;
        impedance_rc_circuit = non_ideal_resistor_resistance / impedance_rc_ciruit_denom;
        std::complex<double> impedance_of_inductor (0, (frequency_of_circuit*parasitic_inductance));
        std::complex<double> non_ideal_resistor_impedance = impedance_of_inductor + impedance_rc_circuit;
        
        return non_ideal_resistor_impedance;
    }

    double non_ideal_resistor::get_impedance_mag(double frequency_of_circuit){
        
        return std::abs(get_impedance(frequency_of_circuit));
    }

    double non_ideal_resistor::get_resistance() const{
        return resistance;
    }

    double non_ideal_resistor::get_impedance_phase(double frequency_of_circuit){
        return std::arg(get_impedance(frequency_of_circuit));
    }

    void non_ideal_resistor::get_component_info(){

        std::vector<double> component_info;
        component_info.push_back(resistance);
        component_info.push_back(parasitic_capacitance);
        component_info.push_back(parasitic_inductance);
        
        int j;
        std::vector<std::string> units;
        units.push_back(" Ohms,");
        units.push_back(" Farads,");
        units.push_back(" Henrys");
        
        for(const auto &i: component_info){
            std::cout<<" "<<i;
            std::cout<<units[j];
            j++;
        }
        std::cout<<std::endl;
    }

    non_ideal_capacitor::non_ideal_capacitor(double capacitance_input, 
    double parasitic_resistance_input, double parasitic_inductance_input){
        capacitance = capacitance_input;
        parasitic_resistance = parasitic_resistance_input;
        parasitic_inductance = parasitic_inductance_input;
        component_name = "Non-ideal capacitor";
    }

    std::complex<double> non_ideal_capacitor::get_impedance(double frequency_of_circuit){

        double real_part{parasitic_resistance};

        double im_part{frequency_of_circuit * parasitic_inductance - 
        (1 / (frequency_of_circuit * capacitance))};

        std::complex<double> non_ideal_capacitor_impedance{(real_part, im_part)};

        return non_ideal_capacitor_impedance;
    }

    double non_ideal_capacitor::get_impedance_mag(double frequency_of_circuit){
        
        return std::abs(get_impedance(frequency_of_circuit));
    }

    double non_ideal_capacitor::get_capacitance() const{
        return capacitance;
    }

    double non_ideal_capacitor::get_impedance_phase(double frequency_of_circuit){
        return std::arg(get_impedance(frequency_of_circuit));
    }

    void non_ideal_capacitor::get_component_info(){
        
        std::vector<double> component_info;
        component_info.push_back(capacitance);
        component_info.push_back(parasitic_resistance);
        component_info.push_back(parasitic_inductance);
        
        int j;
        std::vector<std::string> units;
        units.push_back(" Farads,");
        units.push_back(" Ohms,");
        units.push_back(" Henrys");
        
        for(const auto &i: component_info){
            std::cout<<" "<<i;
            std::cout<<units[j];
            j++;
        }
        std::cout<<std::endl;
    }

    non_ideal_inductor::non_ideal_inductor(double inductance_input, 
    double parasitic_resistance_input, double parasitic_capacitance_input){
        inductance = inductance_input;
        parasitic_resistance = parasitic_resistance_input;
        parasitic_capacitance = parasitic_capacitance_input;
        component_name = "Non-ideal inductor";
    }

    std::complex<double> non_ideal_inductor::get_impedance(double frequency_of_circuit){

        std::complex<double> impedance_1(parasitic_resistance, (frequency_of_circuit * inductance));
        std::complex<double> impedance_2(0, (frequency_of_circuit * parasitic_capacitance));
        std::complex<double> total_impedance_reciprocal = (std::pow(impedance_1, -1) + impedance_2);
        std::complex<double> non_ideal_inductor_impedance = std::pow(total_impedance_reciprocal, -1);

        return non_ideal_inductor_impedance;
    }

    double non_ideal_inductor::get_impedance_mag(double frequency_of_circuit){
        
        return std::abs(get_impedance(frequency_of_circuit));
    }

    double non_ideal_inductor::get_inductance() const{
        return inductance;
    }

    double non_ideal_inductor::get_impedance_phase(double frequency_of_circuit){
        return std::arg(get_impedance(frequency_of_circuit));
    }

    void non_ideal_inductor::get_component_info(){
        
        std::vector<double> component_info;
        component_info.push_back(inductance);
        component_info.push_back(parasitic_resistance);
        component_info.push_back(parasitic_capacitance);
        
        int j;
        std::vector<std::string> units;
        units.push_back(" Henrys,");
        units.push_back(" Ohms,");
        units.push_back(" Farads");
        
        for(const auto &i: component_info){
            std::cout<<" "<<i;
            std::cout<<units[j];
            j++;
        }
        std::cout<<std::endl;
    }
    