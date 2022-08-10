#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#define _USE_MATHS_DEFINES
#include <cmath>

#ifndef components
#define components

class component{
    protected:
    
    std::string component_name;

    public:

    virtual ~component(){};
    
    std::string get_component_name() const{
        return component_name;
    }
    
    virtual void get_component_info() = 0;

    virtual std::complex<double> get_impedance(double) = 0;

};

class ideal_resistor: public component{
    private:
    double resistance{0.0};
    
    public:
    ideal_resistor() = default;
    ideal_resistor(double resistance_input);
    ~ideal_resistor(){std::cout<<"The ideal resistor with resistance "<<this->get_resistance()<<
    " Ohms has been destroyed."<<std::endl;};

    double get_impedance_mag(double);
    double get_impedance_phase();
    double get_resistance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();
};


class ideal_capacitor: public component{
    private:
    double capacitance{0.0};

    public:
    ideal_capacitor() = default;
    ideal_capacitor(double capacitance_input);
    ~ideal_capacitor(){std::cout<<"The ideal capacitor with capacitance "
    <<this->get_capacitance()*pow(10.0, 12)<<" picoFarads has been destroyed."<<std::endl;};
    double get_impedance_mag(double);
    double get_impedance_phase();
    double get_capacitance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();

};

class ideal_inductor: public component{
    private:
    double inductance{0.0};

    public:
    ideal_inductor() = default;
    ideal_inductor(double inductance_input);
    ~ideal_inductor(){std::cout<<"The ideal inductor with inductance "
    <<this->get_inductance()<<" Henrys has been destroyed."<<std::endl;};
    double get_impedance_mag(double);
    double get_impedance_phase();
    double get_inductance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();
};

class non_ideal_resistor: public ideal_resistor{
    private:
    double resistance{0.0};
    double parasitic_inductance{0.0};
    double parasitic_capacitance{0.0};

    public:
    non_ideal_resistor() = default;
    non_ideal_resistor(double resistance_input, double parasitic_capacitance_input, 
    double parasitic_inductance_input);
    ~non_ideal_resistor(){std::cout<<"The non-ideal resistor with resistance "
    <<this->get_resistance()<<" Ohms has been destroyed."<<std::endl;};
    double get_impedance_mag(double);
    double get_impedance_phase(double);
    double get_resistance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();
};

class non_ideal_capacitor: public ideal_capacitor{
    private:
    double capacitance{0.0};
    double parasitic_inductance{0.0};
    double parasitic_resistance{0.0};

    public:
    non_ideal_capacitor() = default;
    non_ideal_capacitor(double capacitance_input, double parasitic_resistance_input, 
    double parasitic_inductance_input);
    ~non_ideal_capacitor(){std::cout<<"The non-ideal capacitor with capacitance "
    <<this->get_capacitance()*pow(10.0, 12)<<" picoFarads has been destroyed."<<std::endl;};
    double get_impedance_mag(double);
    double get_impedance_phase(double);
    double get_capacitance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();
};

class non_ideal_inductor: public ideal_inductor{
    private:
    double inductance{0.0};
    double parasitic_capacitance{0.0};
    double parasitic_resistance{0.0};

    public:
    non_ideal_inductor() = default;
    non_ideal_inductor(double inductance_input, double parasitic_resistance_input, 
    double parasitic_capacitance_input);
    ~non_ideal_inductor(){std::cout<<"The non-ideal inductor with inductance "
    <<this->get_inductance()<<" Henrys has been destroyed."<<std::endl;};
    double get_impedance_mag(double);
    double get_impedance_phase(double);
    double get_inductance() const;
    std::complex<double>get_impedance(double);
    void get_component_info();
};

#endif