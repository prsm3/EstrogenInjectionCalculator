#include <iostream>

float calculate_injection_volume(float desired_dose, float vial_concentration) {
    float result = desired_dose / vial_concentration;
    return result;
}

int main(int, char**) {
    std::cout << "Hello, from EstrogenInjectionCalculator!\n";
    return 0;
}
