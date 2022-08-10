#include "components.hpp"
#include <memory>
#include <algorithm>

#ifndef circuit_hpp
#define circuit_hpp

class circuit: public component{
    friend std::ostream& operator<<(std::ostream&, circuit const&);
    private:
    std::vector<std::pair<std::shared_ptr<component>, int>> component_container_pair;

    std::string circuit_name;

    public:
    circuit() = default;

    circuit(
        std::vector<std::pair<std::shared_ptr<component>, int>> temp_component_container_pair, 
        std::string circuit_name_input);

    ~circuit(){};

    std::complex<double> get_circuit_impedance(std::vector<std::pair<std::shared_ptr<component>, 
     int>> circuit_container_hierarchy,
     std::complex<double> temp_impedance, double circuit_frequency, int index_input);

    std::vector<std::pair<std::shared_ptr<component>, int>> make_circuit_container_hierarchy();


    std::string get_circuit_name() const;

    std::vector<std::pair<std::shared_ptr<component>, int>> get_components_with_conn_types() const;

    void print_impedance_info_for_components_in_circuit(double circuit_frequency);

    void print_circuit_diagram(std::vector<std::pair<std::shared_ptr<component>, int>> circuit_hierarchy);

    std::complex<double> get_impedance(double){
         return 0.0;
     }

    void get_component_info(){
        return ;
    }

};

class two_circuit: public circuit{
    private:

    std::vector<circuit> two_circuit_2d_vector_of_pairs;

    std::string two_circuit_circuit_name;

    public:

    two_circuit() = default;

    two_circuit(circuit circuit_1, 
        circuit circuit_2, std::string two_circuit_circuit_name_input);
    
    //construct nested circuit from anoher nested circuit and a circuit
    two_circuit(two_circuit two_circuit_input, circuit circuit_to_be_added, 
                std::string new_two_circuit_name_input);
    
    ~two_circuit(){};

    std::complex<double> two_circuit_impedance(double circuit_frequency_input);

    std::string get_two_circuit_name() const;

    void print_impedance_info_for_components_in_circuit(double circuit_frequency);

    void print_two_circuit();

};


#endif