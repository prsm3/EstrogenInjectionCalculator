#include <iostream>
#include <conio.h>

float calculate_injection_volume(float desired_dose, float vial_concentration) {
    // error checking
    if(desired_dose <= 0 || vial_concentration <= 0) return -1;
    // calculate the resulting injection volume
    float result = desired_dose / vial_concentration;
    return result;
}

int main(int, char**) {
    // variables used for inputs and calculation
    float desired_dosage, vial_concentration, result;
    desired_dosage = -1;
    vial_concentration = -1;

    // introduction and user prompts
    std::cout << "DIY HRT Injection Volume Calculator\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Formula used for calculation: Desired Dose [mg] / Vial Concentration [mg/mL] = Injection Volume [mL]\n\n";

    std::cout << "Please enter your Desired Dose (usual values are 4-10mg): \n";
    std::cin >> desired_dosage;
    std::cout << "Please enter your Vial Concentration (usual values are 40-80mg/mL): \n";
    std::cin >> vial_concentration;

    // checking input values for validity
    if(desired_dosage <= 0) {
        fprintf(stderr, "error: desired dosage must be a positive number\n");
        exit( EXIT_FAILURE );
    }
    if(vial_concentration <= 0) {
        fprintf(stderr, "error: vial concentration must be a positive number\n");
        exit( EXIT_FAILURE );
    }

    // perform calculation and error checking
    result = calculate_injection_volume(desired_dosage, vial_concentration);
    if(result == -1) {
        fprintf(stderr, "error calculated value is not usable\n");
        exit( EXIT_FAILURE );
    }
    
    // output the result and wait for user input before closing
    std::cout << "Your calculated Injection Volume is: " << result << " mL\n";
    std::cout << "Please double check any results in case you misstyped a value!";
    std::cout << "Press any key to close... ";
    _getch();  // Waits for any key press
    
    return EXIT_SUCCESS;
}
