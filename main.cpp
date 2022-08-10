#include "circuit.hpp"


int main(){


    std::vector<circuit> user_constructed_circuits;
    std::vector<two_circuit> user_constructed_two_circuits;
    std::vector<std::shared_ptr<component>> user_constructed_components;

    //to demonstrate code functionality without user input
    //uncomment below code and select from options when prompted
    /*user_constructed_components.push_back(std::make_shared<ideal_inductor>(
                                3.2));
    user_constructed_components.push_back(std::make_shared<non_ideal_resistor>(
                                7.0, 0.00000000005, 2));
    user_constructed_components.push_back(std::make_shared<ideal_resistor>(3.0));
    user_constructed_components.push_back(std::make_shared<non_ideal_capacitor>(
        0.000000000006, 0.004, 0.0003));

    std::vector<std::pair<std::shared_ptr<component>, int>> temp_component_container_pair_demo_1;

    temp_component_container_pair_demo_1.push_back(std::make_pair(
                            user_constructed_components[0], 0));
    temp_component_container_pair_demo_1.push_back(std::make_pair(
                            user_constructed_components[1], 1));
    temp_component_container_pair_demo_1.push_back(std::make_pair(
                            user_constructed_components[0], 1));
    temp_component_container_pair_demo_1.push_back(std::make_pair(
                            user_constructed_components[3], 0));

    user_constructed_circuits.push_back(circuit(
        temp_component_container_pair_demo_1, "Test1"));


    std::vector<std::pair<std::shared_ptr<component>, int>> temp_component_container_pair_demo_2;

    temp_component_container_pair_demo_2.push_back(std::make_pair(
                            user_constructed_components[3], 0));
    temp_component_container_pair_demo_2.push_back(std::make_pair(
                            user_constructed_components[1], 1));
    temp_component_container_pair_demo_2.push_back(std::make_pair(
                            user_constructed_components[2], 0));
    temp_component_container_pair_demo_2.push_back(std::make_pair(
                            user_constructed_components[0], 1));
    
    user_constructed_circuits.push_back(
        circuit(temp_component_container_pair_demo_2, "Test2"));

    user_constructed_two_circuits.push_back(two_circuit(user_constructed_circuits[
                        0], user_constructed_circuits[
                            1], "Test 1 and Test 2"));
    
    user_constructed_two_circuits.push_back(two_circuit(user_constructed_two_circuits[
                        0], user_constructed_circuits[
                            0], "Test 1 and Test 2 with Test 1 again"));
    */
    
    std::string program_exit{"y"};
    
    while(program_exit=="y"){
    
        int user_intention = 0;//keep setting to zero as next loop interation does not take it out of scope

        std::cout<<"What would you like to do?"<<std::endl;
        std::cout<<"(1) Create a new component"<<std::endl;
        std::cout<<"(2) Create a new circuit"<<std::endl;
        std::cout<<"(3) Calculate circuit impedance"<<std::endl;
        std::cout<<"(4) Create a nested circuit"<<std::endl;
        std::cout<<"(5) Print a circuit"<<std::endl;
        std::cout<<"(6) Exit the program"<<std::endl;

        std::cin>>user_intention;

        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Please enter an integer from the displayed options."<<std::endl;
            std::cout<<"Please try again."<<std::endl;
            std::cin>>user_intention;
        }

        switch(user_intention){

            default:{
                std::cout<<"There was no match for your input. Please pick from one of the numbers";
                std::cout<<" above to choose what you would like to do."<<std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"Would you like to try again? (y/n)"<<std::endl;
                std::cin>>program_exit;

                std::string str1("y"), str2("n");
                while(program_exit != str1 && program_exit != str2  || 
                std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Please enter y/n."<<std::endl;
                    std::cout<<"Please try again."<<std::endl;
                    std::cin>>program_exit;
                }
                break;
            }

            case 1:{
                std::string component_constructor_loop{"y"};
    
                while(component_constructor_loop=="y"){
                    std::cout<<"What components would you like to create?"<<std::endl;
                    std::cout<<"Please select from the following options: \n"<<std::endl;
                    int component_specifier = 0;
                    std::cout<<"1 for ideal resistor, 2 for ideal capacitor or 3 for ideal inductor"<<std::endl;
                    std::cout<<"4 for non-ideal resistor, 5 for non-ideal capacitor or 6 for non-ideal "; 
                    std::cout<<"inductor"<<std::endl;
                    std::cin>>component_specifier;

                    while(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter an integer from the displayed options."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>component_specifier;
                    }

                    switch(component_specifier){
                        
                        default:{
                            std::cout<<"There was no match for your answer. Please input one of the"; 
                            std::cout<<" numbers shown."<<std::endl;
                            break;
                        }

                        case 1:{
                            double ideal_resistance_input;
                            std::cout<<"Please input the resistance as a double in Ohms."<<std::endl;
                            std::cin>>ideal_resistance_input;

                            while(ideal_resistance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero resistance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>ideal_resistance_input;
                            }

                            user_constructed_components.push_back(std::make_shared<ideal_resistor>(
                                ideal_resistance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }

                        case 2:{
                            double ideal_capacitance_input;
                            std::cout<<"Please input the capacitance as a double in Farads."<<std::endl;
                            std::cin>>ideal_capacitance_input;

                            while(ideal_capacitance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero capacitance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>ideal_capacitance_input;
                            }
                            
                            user_constructed_components.push_back(std::make_shared<ideal_capacitor>(
                                ideal_capacitance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }

                        case 3:{
                            double ideal_inductance_input;
                            std::cout<<"Please input the inductance as a double in Henrys."<<std::endl;
                            std::cin>>ideal_inductance_input;

                            while(ideal_inductance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero inductance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>ideal_inductance_input;
                            }
                            
                            user_constructed_components.push_back(std::make_shared<ideal_inductor>(
                                ideal_inductance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }

                        case 4:{
                            double non_ideal_resistance_value_input;
                            double parasitic_capacitance_input;
                            double parasitic_inductance_input;

                            std::cout<<"Please input the resistance as a double in Ohms."<<std::endl;
                            std::cin>>non_ideal_resistance_value_input;
                            
                            while(non_ideal_resistance_value_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero resistance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>non_ideal_resistance_value_input;
                            }

                            std::cout<<"Please input the parasitic capacitance in Farads."<<std::endl;
                            std::cin>>parasitic_capacitance_input;

                            while(parasitic_capacitance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero capacitance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_capacitance_input;
                            }

                            std::cout<<"Please input the parasitic inductance in Henrys."<<std::endl;
                            std::cin>>parasitic_inductance_input;
                            
                            while(parasitic_inductance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero inductance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_inductance_input;
                            }

                            user_constructed_components.push_back(std::make_shared<non_ideal_resistor>(
                                non_ideal_resistance_value_input, parasitic_capacitance_input, 
                                parasitic_inductance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }

                        case 5:{
                            double non_ideal_capacitance_value_input;
                            double parasitic_resistance_input;
                            double parasitic_inductance_input;

                            std::cout<<"Please input the capacitance as a double in Farads."<<std::endl;
                            std::cin>>non_ideal_capacitance_value_input;

                            while(non_ideal_capacitance_value_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero capacitance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>non_ideal_capacitance_value_input;
                            }

                            std::cout<<"Please input the parasitic resistance in Ohms."<<std::endl;
                            std::cin>>parasitic_resistance_input;

                            while(parasitic_resistance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero resistance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_resistance_input;
                            }

                            std::cout<<"Please input the parasitic inductance in Henrys."<<std::endl;
                            std::cin>>parasitic_inductance_input;

                            while(parasitic_inductance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero inductance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_inductance_input;
                            }
                            
                            user_constructed_components.push_back(std::make_shared<non_ideal_capacitor>(
                                non_ideal_capacitance_value_input, parasitic_resistance_input, 
                                parasitic_inductance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }
                        case 6:{
                            double non_ideal_inductance_value_input;
                            double parasitic_resistance_input;
                            double parasitic_capacitance_input;

                            std::cout<<"Please input the inductance as a double in Henrys."<<std::endl;
                            std::cin>>non_ideal_inductance_value_input;

                            while(non_ideal_inductance_value_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero inductance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>non_ideal_inductance_value_input;
                            }

                            std::cout<<"Please input the parasitic resistance in Ohms."<<std::endl;
                            std::cin>>parasitic_resistance_input;

                            while(parasitic_resistance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero resistance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_resistance_input;
                            }

                            std::cout<<"Please input the parasitic capacitance in Farads."<<std::endl;
                            std::cin>>parasitic_capacitance_input;

                            while(parasitic_capacitance_input <= 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please enter a positive, non-zero capacitance."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>parasitic_capacitance_input;
                            }
                            
                            user_constructed_components.push_back(std::make_shared<non_ideal_inductor>(
                                non_ideal_inductance_value_input, parasitic_resistance_input, 
                                parasitic_capacitance_input));

                            std::cout<<"Would you like to create another component? ";
                            std::cout<<"Type y if so. Type anything else if not."<<std::endl;
                            std::cin>>component_constructor_loop;
                            break;
                        }
                    }

                }

                std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                std::cin>>program_exit;
                std::string str1("y"), str2("n");
                while(program_exit != str1 && program_exit != str2  || 
                std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Please enter y/n."<<std::endl;
                    std::cout<<"Please try again."<<std::endl;
                    std::cin>>program_exit;
                }
                break;

            }
            
            case 2:{
                std::string temp_circuit_name;

                std::cout<<"What would you like to name the circuit?"<<std::endl;
                std::cin>>temp_circuit_name;

                //create temporary vector of circuit components without a connection type to each other
                //they need connection types to construct circuit object
                std::vector<std::shared_ptr<component>> temp_circuit_components_vec;

                std::string circuit_constructor_loop{"y"};
    
                while(circuit_constructor_loop=="y"){

                    if(user_constructed_components.size() == 0){
                    std::cout<<"Please construct a component first"<<std::endl;
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;

                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                }
                    std::cout<<"What component would you like to add to your circuit?"<<std::endl;
                    std::cout<<"Please select components in the order you wish them";
                    std::cout<<" to be connected"<<std::endl;
                    std::cout<<"Please select from the following options: \n"<<std::endl;
                    for(int i{0}; i < user_constructed_components.size(); i++){
                        std::cout<<"("<<i<<") "<<user_constructed_components[i]->get_component_name();
                        user_constructed_components[i]->get_component_info();
                    }
                    int component_specifier = 0;
                    std::cin>>component_specifier;

                    while(component_specifier < 0 || 
                    component_specifier >= user_constructed_components.size() || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Please select a component from the list."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>component_specifier;
                    }

                    temp_circuit_components_vec.push_back(user_constructed_components[component_specifier]);
                        
                    std::cout<<"Would you like to add another component to the circuit? (y/n) "<<std::endl;
                    std::cin>>circuit_constructor_loop;

                    std::string str1("y"), str2("n");
                    while(circuit_constructor_loop != str1 && circuit_constructor_loop != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>circuit_constructor_loop;
                    }
                }

                    std::vector<std::pair<std::shared_ptr<component>, int>> temp_component_container_pair;

                    for(int i{0}; i < temp_circuit_components_vec.size(); i++){

                        int connection_type = 0; //default is series

                        if(i==0){
                            std::cout<<"The first component has been placed";
                            std::cout<<" in the circuit for you."<<std::endl;
                            temp_component_container_pair.push_back(std::make_pair(
                            temp_circuit_components_vec[i], connection_type));
                        }else{
                            
                            std::cout<<"Would you like the "<<temp_circuit_components_vec[
                            i]->get_component_name();
                            temp_circuit_components_vec[i]->get_component_info();
                            std::cout<<" to be connected in series (0) or parallel (1) ";
                            std::cout<<"with the previous component?"<<std::endl;
                            std::cin>>connection_type;

                            while(connection_type > 1 || connection_type < 0 || std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                std::cout<<"Your connection type must be 1 or 0."<<std::endl;
                                std::cout<<"Please try again."<<std::endl;
                                std::cin>>connection_type;
                            }

                            temp_component_container_pair.push_back(std::make_pair(
                            temp_circuit_components_vec[i], connection_type));
                        }
                    }


                //constructing a new circuit
                user_constructed_circuits.push_back(circuit(temp_component_container_pair, 
                temp_circuit_name));
                

                std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                std::cin>>program_exit;

                std::string str1("y"), str2("n");
                while(program_exit != str1 && program_exit != str2  || 
                std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Please enter y/n."<<std::endl;
                    std::cout<<"Please try again."<<std::endl;
                    std::cin>>program_exit;
                }
                break;
            }

            case 3:{
                
                std::string circuit_type_specifier;

                std::cout<<"Is this circuit made of two or more other circuits (y/n)?"<<std::endl;
                std::cin>>circuit_type_specifier;

                if (circuit_type_specifier=="n")
                {
                    if(user_constructed_circuits.size() == 0){
                        std::cout<<"Please construct a circuit first"<<std::endl;
                        std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                        std::cin>>program_exit;

                        std::string str1("y"), str2("n");
                        while(program_exit != str1 && program_exit != str2  || 
                        std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout<<"Please enter y/n."<<std::endl;
                            std::cout<<"Please try again."<<std::endl;
                            std::cin>>program_exit;
                        }
                        break;
                    }
                    std::cout<<"Which circuit would you like to calculate the ";
                    std::cout<<"impedence for?"<<std::endl;

                    int circuit_impedance_specifier = 0;

                    for(int i{0}; i < user_constructed_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_circuits[i].get_circuit_name()<<std::endl;
                    }
                    std::cin>>circuit_impedance_specifier;

                    while(circuit_impedance_specifier < 0 || 
                    circuit_impedance_specifier >= user_constructed_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>circuit_impedance_specifier;
                    }
                    
                    double input_freq_hz;
                    std::cout<<"For what value in Hz would you like to investigate";
                    std::cout<<" the impedance? Please enter as a double. "<<std::endl;
                    std::cin>>input_freq_hz;

                    while(input_freq_hz <= 0 || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter a positive non-zero frequency."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>input_freq_hz;
                    }

                    double input_freq = input_freq_hz * 2 * M_PI;
                    
                    //making the circuit hierarchy which ranks which components to calculate impedance for first
                    //then using this to calculate impedance of the whole circuit
                    std::vector<std::pair<std::shared_ptr<component>, 
                    int>> temp_circuit_container_hierarchy = user_constructed_circuits[
                        circuit_impedance_specifier].make_circuit_container_hierarchy();
                   
                    int index_of_max = temp_circuit_container_hierarchy.size();
                    std::complex<double> dummy_impedance;
                    std::complex<double> circuit_impedence = user_constructed_circuits[
                        circuit_impedance_specifier].get_circuit_impedance(
                            temp_circuit_container_hierarchy, dummy_impedance, input_freq, index_of_max - 1);

                    std::cout<<"The impedance of "<<user_constructed_circuits[
                        circuit_impedance_specifier].get_circuit_name()<<": ";
                    std::cout<<circuit_impedence<<std::endl;

                    if(std::real(circuit_impedence)==INFINITY || 
                    std::imag(circuit_impedence)!= std::imag(circuit_impedence)){
                        std::cout<<"Please enter more appropriate component data for this circuit"<<std::endl;
                    }
                
                    std::cout<<"The phase-shift is: ";
                    std::cout<<std::arg(circuit_impedence)<<std::endl;
                    std::cout<<"As a magnitude: ";
                    std::cout<<std::abs(circuit_impedence)<<std::endl;
                    std::cout<<"For each component: "<<std::endl;
                    user_constructed_circuits[
                        circuit_impedance_specifier].print_impedance_info_for_components_in_circuit(
                            input_freq);
                    
                    
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;

                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;

                } else if(circuit_type_specifier=="y"){

                    if(user_constructed_two_circuits.size() == 0){
                        std::cout<<"Please construct a nested circuit first"<<std::endl;
                        std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                        std::cin>>program_exit;

                        std::string str1("y"), str2("n");
                        while(program_exit != str1 && program_exit != str2  || 
                        std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout<<"Please enter y/n."<<std::endl;
                            std::cout<<"Please try again."<<std::endl;
                            std::cin>>program_exit;
                        }
                        break;
                    }

                    std::cout<<"Which circuit would you like to calculate the ";
                    std::cout<<"impedence for?"<<std::endl;

                    int two_circuit_impedance_specifier = 0;

                    for(int i{0}; i < user_constructed_two_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_two_circuits[i].get_two_circuit_name()<<std::endl;
                        //do not need to make hierararchy for two_circuit as it is contained in its impedance function
                    }
                    std::cin>>two_circuit_impedance_specifier;

                    while(two_circuit_impedance_specifier < 0 || 
                    two_circuit_impedance_specifier >= user_constructed_two_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>two_circuit_impedance_specifier;
                    }

                    double input_freq_hz;
                    std::cout<<"For what value in Hz would you like to investigate";
                    std::cout<<" the impedance? Please enter as a double. "<<std::endl;
                    std::cin>>input_freq_hz;

                    while(input_freq_hz <= 0 || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter a positive non-zero frequency."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>input_freq_hz;
                    }

                    double input_freq = input_freq_hz * 2 * M_PI;
                    

                    std::complex<double> two_circuit_impedence = user_constructed_two_circuits[
                        two_circuit_impedance_specifier].two_circuit_impedance(input_freq);
                        std::cout<<"The impedance of "<<user_constructed_two_circuits[
                        two_circuit_impedance_specifier].get_two_circuit_name()<<": ";
                        std::cout<<two_circuit_impedence<<std::endl;

                        if(std::real(two_circuit_impedence)==INFINITY || 
                        std::imag(two_circuit_impedence)!= std::imag(two_circuit_impedence)){

                            std::cout<<"Please enter more appropriate component data for this circuit"<<std::endl;
                        }

                        std::cout<<"The phase-shift is: ";
                        std::cout<<std::arg(two_circuit_impedence)<<std::endl;
                        std::cout<<"As a magnitude: ";
                        std::cout<<std::abs(two_circuit_impedence)<<std::endl;
                        std::cout<<"For each component: "<<std::endl;
                        user_constructed_two_circuits[
                            two_circuit_impedance_specifier].print_impedance_info_for_components_in_circuit(
                                input_freq);
                    
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;
                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                }else{
                    std::cout<<"Your input was not recognised"<<std::endl;
                    std::cout<<"Would you like to try again? (y/n)"<<std::endl;
                    std::cin>>program_exit;
                    break;
                }
                
            }

            case 4:{
                std::string circuit_type_specifier;
                std::cout<<"Would you like to add a circuit to nested circuit (y/n)?"<<std::endl;
                std::cin>>circuit_type_specifier;

                if(circuit_type_specifier=="y"){
                    if(user_constructed_two_circuits.size() == 0){
                        std::cout<<"Please create a nested circuit first."<<std::endl;
                        std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                        std::cin>>program_exit;

                        std::string str1("y"), str2("n");
                        while(program_exit != str1 && program_exit != str2  || 
                        std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout<<"Please enter y/n."<<std::endl;
                            std::cout<<"Please try again."<<std::endl;
                            std::cin>>program_exit;
                        }
                        break;
                    }
                    std::cout<<"Which nested circuit would you like to select?"<<std::endl;

                    int nested_circuit_specifier = 0;

                    for(int i{0}; i < user_constructed_two_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_two_circuits[i].get_two_circuit_name()<<std::endl;
                    }
                    
                    std::cin>>nested_circuit_specifier;

                    while(nested_circuit_specifier < 0 || 
                    nested_circuit_specifier >= user_constructed_two_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>nested_circuit_specifier;
                    }

                    std::cout<<"Which circuit would you like to add?"<<std::endl;

                    int sub_circuit_specifier = 0;

                    for(int i{0}; i < user_constructed_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_circuits[i].get_circuit_name()<<std::endl;
                    }
                    std::cin>>sub_circuit_specifier;

                    while(sub_circuit_specifier < 0 || 
                    sub_circuit_specifier >= user_constructed_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>sub_circuit_specifier;
                    }

                    std::string two_circuit_name;
                    std::cout<<"What would you like this new circuit to be called?"<<std::endl;
                    std::cin>>two_circuit_name;

                    user_constructed_two_circuits.push_back(two_circuit(user_constructed_two_circuits[
                        nested_circuit_specifier], user_constructed_circuits[
                            sub_circuit_specifier], two_circuit_name));
                    
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;
                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                }

                else if(circuit_type_specifier=="n"){
                    
                    if(user_constructed_circuits.size() > 0){
                    std::cout<<"Which circiuit(s) would you like to select to be";
                    std::cout<<" added together?"<<std::endl;

                    int sub_circuit_specifier_1 = 0;

                    std::cout<<"Please pick a subcircuit."<<std::endl;
                    for(int i{0}; i < user_constructed_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_circuits[i].get_circuit_name()<<std::endl;
                    }
                    std::cin>>sub_circuit_specifier_1;

                    while(sub_circuit_specifier_1 < 0 || 
                    sub_circuit_specifier_1 >= user_constructed_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>sub_circuit_specifier_1;
                    }

                    int sub_circuit_specifier_2 = 0;

                    std::cout<<"Please pick another subcircuit"<<std::endl;
                    for(int i{0}; i < user_constructed_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_circuits[i].get_circuit_name()<<std::endl;
                    }
                    std::cin>>sub_circuit_specifier_2;

                    while(sub_circuit_specifier_2 < 0 || 
                    sub_circuit_specifier_2 >= user_constructed_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>sub_circuit_specifier_2;
                    }

                    std::string two_circuit_name;
                    std::cout<<"What would you like this new circuit to be called?"<<std::endl;
                    std::cin>>two_circuit_name;

                    user_constructed_two_circuits.push_back(two_circuit(user_constructed_circuits[
                        sub_circuit_specifier_1], user_constructed_circuits[
                            sub_circuit_specifier_2], two_circuit_name));
                    
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;
                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;

                    }else{
                    std::cout<<"You must construct at least 2 normal circuits to use this"; 
                    std::cout<<" function."<<std::endl;

                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;
                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                    }
                }else{
                    std::cout<<"Your input was not recognised"<<std::endl;
                    std::cout<<"Would you like to try again? (y/n)"<<std::endl;
                    std::cin>>program_exit;
                    break;
                }

            }
            case 5:{
                std::string circuit_type_specifier;
                if(user_constructed_circuits.size() == 0){
                    std::cout<<"Please construct a circuit first"<<std::endl;
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;

                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                }
                std::cout<<"Is this circuit made of two or more other circuits (y/n)?"<<std::endl;
                std::cin>>circuit_type_specifier;
                if(circuit_type_specifier=="n"){
                    std::cout<<"Which circuit would you like to print?"<<std::endl;
                    int circuit_specifier;
                    for(int i{0}; i < user_constructed_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_circuits[i].get_circuit_name()<<std::endl;
                    }
                    std::cin>>circuit_specifier;

                    while(circuit_specifier < 0 || 
                    circuit_specifier >= user_constructed_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>circuit_specifier;
                    }

                    std::cout<<user_constructed_circuits[circuit_specifier]<<std::endl;
                    auto circuit_hierarchy = user_constructed_circuits[
                        circuit_specifier].make_circuit_container_hierarchy();
                    
                    user_constructed_circuits[
                        circuit_specifier].print_circuit_diagram(circuit_hierarchy);
                    
                    std::cout<<std::endl;
                    
                }else if (circuit_type_specifier=="y"){

                    if(user_constructed_two_circuits.size() == 0){
                    std::cout<<"Please construct a nested circuit first"<<std::endl;
                    std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                    std::cin>>program_exit;

                    std::string str1("y"), str2("n");
                    while(program_exit != str1 && program_exit != str2  || 
                    std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please enter y/n."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>program_exit;
                    }
                    break;
                }
                    std::cout<<"Which circuit would you like to print?"<<std::endl;
                    int circuit_specifier;
                    for(int i{0}; i < user_constructed_two_circuits.size(); i++){
                        std::cout<<"("<<i<<") ";
                        std::cout<<user_constructed_two_circuits[i].get_two_circuit_name()<<std::endl;
                    }
                    std::cin>>circuit_specifier;

                    while(circuit_specifier < 0 || 
                    circuit_specifier >= user_constructed_two_circuits.size() || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout<<"Please select a circuit from the list."<<std::endl;
                        std::cout<<"Please try again."<<std::endl;
                        std::cin>>circuit_specifier;
                    }

                    user_constructed_two_circuits[circuit_specifier].print_two_circuit();
                }else{
                    std::cout<<"Your input was not recognised"<<std::endl;
                    std::cout<<"Would you like to try again? (y/n)"<<std::endl;
                    std::cin>>program_exit;
                    break;
                }


                std::cout<<"Would you like to do anything else?(y/n)"<<std::endl;
                std::cin>>program_exit;
                std::string str1("y"), str2("n");
                while(program_exit != str1 && program_exit != str2  || 
                std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Please enter y/n."<<std::endl;
                    std::cout<<"Please try again."<<std::endl;
                    std::cin>>program_exit;
                }
                break;

            }
            case 6:{
                std::cout<<"Thank you for using the program."<<std::endl;
                program_exit="n";

            }


        }

    }







    return 0;
}