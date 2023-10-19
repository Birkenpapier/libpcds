#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double f(double x) {
    // return x*x + 4*x + 4;
    return 2*(x*x*x) + x + 3*(x*x);
}

double simulatedAnnealing() {
    double current_solution = rand() % 1000 - 500;  // Random start within [-500, 500]
    double current_value = f(current_solution);
    
    double temperature = 1000;
    const double cooling_rate = 0.995;
    const double min_temperature = 1e-3;
    
    while (temperature > min_temperature) {
        double new_solution = current_solution + (rand() % 2000 - 1000) * 0.01;  // Move within [-10, 10]
        double new_value = f(new_solution);

        if (new_value < current_value) {
            current_solution = new_solution;
            current_value = new_value;
        } else {
            double acceptance_probability = exp((current_value - new_value) / temperature);
            if (rand() < RAND_MAX * acceptance_probability) {
                current_solution = new_solution;
                current_value = new_value;
            }
        }

        temperature *= cooling_rate;
    }
    
    return current_solution;
}

int main() {
    srand(time(nullptr));
    
    double x_min = simulatedAnnealing();
    std::cout << "Approximated minimum x: " << x_min << std::endl;
    std::cout << "Function value at this x: " << f(x_min) << std::endl;

    return 0;
}
