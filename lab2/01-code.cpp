#include <iostream>
#include <cmath>

static double hypotenuse(const double x, const double y) {
    return std::sqrt(std::pow(x, 2)+std::pow(y, 2));
}

int main() {
    constexpr double s1 = 5;  //km/h
    constexpr double s2 = 2;  //km/h
    constexpr double dy = 10; //km
    constexpr double dx = 3;  //km

    double L1 = 0;  //base value
    std::cout << "Distance L1 (km) :\t";
    std::cin >> L1;

    const double t1 = L1/s1;
    //std::cout << "Time passed on road (hours) : " << t1 << std::endl;

    const double L2 = hypotenuse(dy-L1, dx);
    //std::cout << "Distance L2 : " << L2 << std::endl;

    const double t2 = L2/s2;
    //std::cout << "Time passed on rocks : " << t2 << std::endl;

    std::cout << "Time passed : " << t1 + t2 << std::endl;
}
