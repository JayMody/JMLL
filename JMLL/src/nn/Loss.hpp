using namespace std;

////// Header //////
#ifndef Loss_hpp
#define Loss_hpp

// Type Definitions
typedef double (*loss_function)(double, double);

// Loss Functions
double squared_error(double x, double l);
double squared_error_prime(double x, double l);

double categorical_cross_entropy(double x, double l);
double categorical_cross_entropy_prime(double x, double l);
#endif /* Loss_hpp */
