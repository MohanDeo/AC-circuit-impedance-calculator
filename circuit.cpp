#include "circuit.hpp"

circuit::circuit(std::vector<std::pair<std::shared_ptr<component>, int>> temp_component_container_pair, 
        std::string circuit_name_input){
    component_container_pair = temp_component_container_pair;
    circuit_name = circuit_name_input;
}


std::complex<double> circuit::get_circuit_impedance(std::vector<std::pair<std::shared_ptr<component>, 
int>> circuit_container_hierarchy,
     std::complex<double> temp_impedance, double circuit_frequency, int index_input){
         std::complex<double> new_temp_impedance;
         int first_index_input = circuit_container_hierarchy.size() - 1;

         if(index_input == first_index_input){
            temp_impedance += circuit_container_hierarchy[index_input].first->get_impedance(circuit_frequency);
         }

         if(index_input==0){
            new_temp_impedance = temp_impedance;
             return new_temp_impedance;
         }
         if(circuit_container_hierarchy[index_input].second == circuit_container_hierarchy[index_input - 1].second){
            //calculate impedance in series
            auto temp = circuit_container_hierarchy[index_input - 1].first->get_impedance(circuit_frequency);
            new_temp_impedance = temp + temp_impedance;
            auto impedance = get_circuit_impedance(circuit_container_hierarchy, new_temp_impedance, circuit_frequency, 
            index_input - 1);
            return impedance;
        } else{
            //calculate impedance in parallel
            auto new_temp_impedance_reciprocal = std::pow(circuit_container_hierarchy[index_input - 1].first->get_impedance(
                circuit_frequency), -1) + std::pow(temp_impedance, -1);
            new_temp_impedance = std::pow(new_temp_impedance_reciprocal, -1);
            return get_circuit_impedance(circuit_container_hierarchy, new_temp_impedance, circuit_frequency, index_input - 1);
        }
    }

    std::vector<std::pair<std::shared_ptr<component>, int>> circuit::make_circuit_container_hierarchy(){
            
            std::vector<std::pair<std::shared_ptr<component>, int>> circuit_container_hierarchy;
            for(int i{0}; i < component_container_pair.size(); ++i){

                if(i==0){
                    circuit_container_hierarchy.push_back(std::make_pair(component_container_pair[i].first, 0));

                }else{
                auto value = component_container_pair[i].second + circuit_container_hierarchy[i - 1].second;
                circuit_container_hierarchy.push_back(std::make_pair(component_container_pair[i].first, value));
            }

            }

            return circuit_container_hierarchy;
        }

        std::string circuit::get_circuit_name() const{
                return  circuit_name;
            }

        std::vector<std::pair<std::shared_ptr<component>, int>> circuit::get_components_with_conn_types() const{
            return component_container_pair;
        }

        void circuit::print_impedance_info_for_components_in_circuit(double circuit_frequency){
            for(const auto &i: component_container_pair){
                            std::cout<<i.first->get_component_name()<<std::endl;
                            i.first->get_component_info();
                            auto component_impedance = i.first->get_impedance(circuit_frequency);
                            std::cout<<"Impedance: "<<component_impedance<<std::endl;
                            std::cout<<"Phase-shift: "<<std::arg(component_impedance)<<std::endl;
                            std::cout<<"Magnitude: "<<std::abs(component_impedance)<<std::endl;
                            std::cout<<std::endl;
                    }
        }

        std::ostream & operator<<(std::ostream &os, circuit const &circuit_for_output){
            std::cout<<"This circuit contains ";
            std::cout<<circuit_for_output.get_components_with_conn_types().size();
            std::cout<<" components"<<std::endl;

            for(const auto &i: circuit_for_output.get_components_with_conn_types()){
                            std::cout<<i.first->get_component_name()<<std::endl;
                            i.first->get_component_info();
                            std::cout<<std::endl;
                    }
            
            return os;
        }

        void circuit::print_circuit_diagram(std::vector<std::pair<std::shared_ptr<component>, 
        int>> circuit_hierarchy){

            std::string resistor_string{"Ideal resistor"};
            std::string capacitor_string{"Ideal capacitor"};
            std::string inductor_string{"Ideal inductor"};
            std::string non_ideal_resistor_string{"Non-ideal resistor"};
            std::string non_ideal_capacitor_string{"Non-ideal capacitor"};
            std::string non_ideal_inductor_string{"Non-ideal inductor"};

            for(const auto &i: circuit_hierarchy){
                std::string component_name = i.first->get_component_name();

                if(component_name == resistor_string){
                    std::cout<<"R";
                }else if(component_name == capacitor_string){
                    std::cout<<"C";
                }else if(component_name == inductor_string){
                    std::cout<<"I";
                }else if(component_name == non_ideal_resistor_string){
                    std::cout<<"R!";
                }else if(component_name == non_ideal_capacitor_string){
                    std::cout<<"C!";
                }else if(component_name == non_ideal_inductor_string){
                    std::cout<<"I!";
                }

                int no_dashes = i.second;
                for(int j{0}; j < no_dashes; j++){
                    std::cout<<"'";
                }

                std::cout<<"--";

            }
        }

        two_circuit::two_circuit(circuit circuit_1, 
        circuit circuit_2, 
        std::string two_circuit_circuit_name_input){
            std::vector<circuit> temp_two_circuit_vector_of_pairs;

            temp_two_circuit_vector_of_pairs.push_back(circuit_1);
            temp_two_circuit_vector_of_pairs.push_back(circuit_2);
            two_circuit_2d_vector_of_pairs = temp_two_circuit_vector_of_pairs;
            two_circuit_circuit_name = two_circuit_circuit_name_input;
        }

        two_circuit::two_circuit(two_circuit two_circuit_input, circuit circuit_to_be_added, 
        std::string new_two_circuit_name_input){

            for(int i{0}; i<two_circuit_input.two_circuit_2d_vector_of_pairs.size(); i++){
                two_circuit_2d_vector_of_pairs.push_back(two_circuit_input.two_circuit_2d_vector_of_pairs[i]);
            }

            two_circuit_2d_vector_of_pairs.push_back(circuit_to_be_added);
            
            two_circuit_circuit_name = new_two_circuit_name_input;

        }


        std::complex<double> two_circuit::two_circuit_impedance(double circuit_frequency_input){
                std::complex<double> two_circuit_temp_imepdance;

                for(int i{0}; 
                i<two_circuit_2d_vector_of_pairs.size();
                 i++){

                    std::vector<std::pair<std::shared_ptr<component>, 
                    int>> two_circuit_section_hierarchy = two_circuit_2d_vector_of_pairs[
                        i].make_circuit_container_hierarchy();


                    std::complex<double> two_circuit_dummy_impedance = (0, 0);
                    int index_of_max = two_circuit_section_hierarchy.size();
                    
                    //+= as circuits added in series
                    two_circuit_temp_imepdance += get_circuit_impedance(two_circuit_section_hierarchy,
                    two_circuit_dummy_impedance, circuit_frequency_input, 
                    index_of_max - 1);//max value lies at the last index
                }
                return two_circuit_temp_imepdance;
            }

        std::string two_circuit::get_two_circuit_name() const{
            return two_circuit_circuit_name;
        }

        void two_circuit::print_impedance_info_for_components_in_circuit(double circuit_frequency){

            for(int i{0}; i<two_circuit_2d_vector_of_pairs.size(); i++){
                two_circuit_2d_vector_of_pairs[
                    i].print_impedance_info_for_components_in_circuit(circuit_frequency);
            }
        }

        void two_circuit::print_two_circuit(){

            std::cout<<"This nested circuit consists of "<<two_circuit_2d_vector_of_pairs.size();
            std::cout<<" circuits joined in series"<<std::endl;

            for(int i{0}; i<two_circuit_2d_vector_of_pairs.size(); i++){
                std::cout<<" For circuit "<<i+1<<":";
                std::cout<<two_circuit_2d_vector_of_pairs[
                    i].get_circuit_name()<<std::endl;
                std::cout<<std::endl;
                std::cout<<two_circuit_2d_vector_of_pairs[
                    i]<<std::endl;
                auto circuit_hierarchy = two_circuit_2d_vector_of_pairs[
                    i].make_circuit_container_hierarchy();
                print_circuit_diagram(circuit_hierarchy);
                std::cout<<std::endl;
            }
        }