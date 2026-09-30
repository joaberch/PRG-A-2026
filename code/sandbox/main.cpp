#include <iostream>
#include <cstdlib>
#include <array>
#include <limits>
#include <cmath>
#include <iomanip>

void iterate() {
    int iterationNbr;
    int n=2;
    int d=1;
    float approx=1;

    std::cout << "Nombre de iteration : ";
    std::cin >> iterationNbr;

    for (int i=0; i<iterationNbr; i++) {
        std::cout << "Debug : " << approx << "*=" << n << "/" << d << std::endl;
        approx *= float(n)/float(d);
        if (n<d) {
            n=d+1;
        } else {
            d=n+1;
        }
    }

    std::cout << "Approximation : " << approx << " en "
    << iterationNbr << " iteration." << std::endl;
}

void crash() {
    int* p = nullptr;
    *p = 42;
    std::cout << "hello" << std::endl;
}

void debugCrash() {
    std::array a { 1, 2, 3};
    for(int i = 0; i < 10; ++i)
        a.at(i) = i;
    std::cout << "hello" << std::endl;
}

void varNameExo() {
    /*
    int nNbEtudiants = 25; ~ok
    double surface = largeur * hauteur; ok
    const int NB_MAX_ETUDIANTS = 100; ok
    int nombreTotalDeBouteillesDansUnPack = 6; nok
    double x = 13.2 * nb_bouteilles; // poids du pack en grammes - nok
    int nbPacks, nb_bouteilles, PrixUnitaire; nok
    double dblPrix = 2.5; ~nok
    int a = 4, b = 12; (utilisées 40 lignes plus loin, dans un calcul de prix) nok
    double volume_canette_l = 0.33; ok
    int INT = 3; nok
    */
}

void sizeVar() {
    using type = unsigned int;

    int bytes = sizeof(type);
    bool isSigned = std::numeric_limits<type>::is_signed;
    int bits = std::numeric_limits<type>::digits + isSigned;
    //digits get the bits used and is_signed add one if used for the sign
    //else sizeof(type) * CHAR_BIT but not permitted on this exercise
    std::cout << "Taille : " << bytes << " bytes = " << bits << " bits.\n";

    int min = std::numeric_limits<type>::min();
    unsigned long long max = std::numeric_limits<type>::max();
    //unsigned long long to be sure to not have an overflow
    std::cout << "Plage de valeurs : " << min << " -> " << max << std::endl;

    std::cout << "Signe : " << std::boolalpha << isSigned << std::endl;
}

void test() {
    int a = 2147483648u;
    std::cout << a << std::endl;
    std::cout << std::numeric_limits<typeof(a)>::min() << std::endl;
    std::cout << std::numeric_limits<typeof(a)>::max() << std::endl;

    unsigned int aa = 2747483648u;
    signed int b = -1;
    std::cout << std::boolalpha << (aa>b) << std::endl;
}

void mantis() {
    double r = 0;
    double m = 0;
    int b = 0;
    int e = 0;

    std::cout << "Entrez un nombre reel : ";
    std::cin >> r;

    b = 10;
    e = std::floor(std::log(r)/std::log(b));
    m = r/std::pow(b,e);
    std::cout << r << " = " << m << " * " << b << "^" << e << std::endl;

    b = 2;
    e = std::floor(std::log(r)/std::log(b));
    m = r/std::pow(b,e);
    std::cout << r << " = " << m << " * " << b << "^" << e << std::endl;
    //question complementaire : 1 <= m < b donc 1 <= m < 2 si on a une base 2
}

void smallestFloat() {
    /*std::cout << std::setprecision(20);
    short d = std::numeric_limits<float>::digits;
    std::cout << d << std::endl;
    const float a = std::pow(2,d);
    const float b = std::pow(2,d)+1;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::boolalpha <<(a == b) << std::endl;*/

    int n = 16777217;
    std::cout << std::boolalpha << std::setprecision(10);
    std::cout << "1) " << static_cast<float>(n) << std::endl;
    std::cout << static_cast<float>(n) << std::endl;
    std::cout << "2) " << (static_cast<float>(n) == n) << std::endl;
    std::cout << static_cast<int>(static_cast<float>(n)) << std::endl;
    std::cout << "3) " << (static_cast<int>(static_cast<float>(n)) == n) << std::endl;

    /*double d = 0.1;
    std::cout << std::setprecision(200) << d << std::endl;
    std::cout << std::setprecision(200) << 1004.35 << std::endl;
    std::cout << -0u;*/
}

//TODO change from float type (a,b,tolerance) to T interface
bool almost_equal(float a, float b, float tolerance = std::numeric_limits<float>::epsilon()) {
    // Handle NaN cases explicitly
    if (std::isnan(a) || std::isnan(b)) {
        return false;
    }
    // Relative comparison to handle large/small magnitudes
    return std::fabs(a - b) <= tolerance * std::max(std::fabs(a), std::fabs(b));
}

int main () {
    //iterate();
    //crash();
    //debugCrash();
    //sizeVar();
    //test();
    //mantis();
    smallestFloat();
}