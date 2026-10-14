#include <iostream>
#include <cstdlib>
#include <array>
#include <limits>
#include <cmath>
#include <iomanip>
#include <unordered_map>

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

void references() {
    int var1 = 1;
    int& ref1 = var1;
    //int& ref2;
    var1 = 2;
    ref1 = 3;
    std::cout << var1 << std::endl;
    std::cout << ref1 << std::endl;
    const int& ref2 = var1;
    //ref2 = 4;
    var1 = 4;
    std::cout << ref2 << std::endl;
}

double volumeCylinder(double radius, double height) {
    return radius * radius * height * M_PI;
}

double volumeCone(double radius1, double radius2, double height) {
    return (std::pow(radius1, 2)+std::pow(radius2, 2)+radius1*radius2) * height * M_PI /3; //
}

void litre() {
    double r1 = 0; //cm
    double r2 = 0; //cm
    double h1 = 0; //cm
    double h2 = 0; //cm
    double h3 = 0; //cm
    std::cout << "Entrez le rayon du cylindre 1 [cm]      :";
    std::cin >> r1;
    std::cout << "Entrez le rayon du cylindre 2 [cm]      :";
    std::cin >> r2;
    std::cout << "Entrez la hauteur du cylindre 1 [cm]    :";
    std::cin >> h1;
    std::cout << "Entrez la hauteur du cylindre 2 [cm]    :";
    std::cin >> h2;
    std::cout << "Entrez la hauteur du tronc de cone [cm] :";
    std::cin >> h3;

    double hugeCylinderV = volumeCylinder(r1, h1);
    double smallCylinderV = volumeCylinder(r2, h2);
    double coneV = volumeCone(r1, r2, h3);
    double litreTot = (hugeCylinderV + smallCylinderV + coneV)/1000;
    std::cout << "litre : " << litreTot << std::endl;
}

void convert() {
    constexpr double milesConvert = 0.000621371;
    constexpr double feetConvert = 3.2808399;
    constexpr double inchConvert = 39.3700787;

    std::cout << "Entrez le nombre de metres a convertir (entier > 0) :";
    int meters = 0;
    std::cin >> meters;
    std::cout << meters << " [m]" << std::endl;
    const double miles = meters*milesConvert;
    std::cout << miles << " [mile]" << std::endl;
    const double feet = meters*feetConvert;
    std::cout << feet << " [feet]" << std::endl;
    const double inch = meters*inchConvert;
    std::cout << inch << " [inch]" << std::endl;
}

void dayInMonth() {
    std::cout << "Entrez un no de mois (1-12) : ";
    short no_mois; std::cin >> no_mois;
    std::unordered_map<short,short> map = {
        {1,31},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };

    std::cout << "Ce mois comporte ";

    if (no_mois == 2) {
        std::cout << "28 ou 29";
    } else {
        std::cout << map.at(no_mois);
    }
    // votre code vient ici

    std::cout << " jours." << std::endl;
}

void primeNumberAtkin() {
    std::cout << "Entrez un numero atkin (1) : ";
    int limit; std::cin >> limit;
    bool prime[limit];
    for (int i = 0; i < limit; i++) {
        prime[i] = false;
    }
    prime[2] = true;
    prime[3] = true;

    int n = 0;
    for (int x = 1; x < std::sqrt(limit); x++) {
        for (int y = 1; y < std::sqrt(limit); y++) {
            //1.
            n=4*x*x+y*y;
            if (n<limit&&(n%60==1||n%60==13||n%60==17||n%60==29||n%60==37||n%60==41||n%60==49||n%60==53)) {
                prime[n] = !prime[n];
            }

            //2.
            n=3*x*x+y*y;
            if (n<limit&&(n%60==7||n%60==19||n%60==31||n%60==43)) {
                prime[n] = !prime[n];
            }

            //3.
            n=3*x*x-y*y;
            if (n<limit&&x>y&&(n%60==11||n%60==23||n%60==47||n%60==59)) {
                prime[n] = !prime[n];
            }
        }
    }

    for (int z=5;z<std::sqrt(limit);z++) {
        if (prime[z]) {
            for (int a=1;a<std::sqrt(limit)/z*z;a++) {
                prime[a*z^2] = false;
            }
        }
    }

    int cptr = 0;
    for (int i=0;i<limit;i++) {
        if (prime[i]) {
            cptr++;
            std::cout << std::setw(10) << i;
            if (cptr%5==0) {
                std::cout << std::endl;
            }
        }
    }
}

void primeNumberEratosthene() {
    std::cout << "Entrez un numero erat (1) : ";
    int limit; std::cin >> limit;
    bool prime[limit];
    for (int i = 0; i < limit; i++) {
        prime[i] = true;
    }

    for (int i = 2; i*i < limit; i++) {
        if (prime[i]) {
            for (int m = i*i; m < limit; m+=i) {
                prime[m] = false;
            }
        }
    }

    int cptr = 0;
    for (int i=0;i<limit;i++) {
        if (prime[i]) {
            cptr++;
            std::cout << std::setw(10) << i;
            if (cptr%5==0) {
                std::cout << std::endl;
            }
        }
    }
}

void f(long a) {
    std::cout << a;
}

void f(unsigned long a) {
    std::cout << a;
}

void log(int level);
void log(int level, int destination = 0);

template <typename T>
T maximum(T a, T b) {
    //int&& d = 42;
    return a < b ? b : a;
}

void fa(const double& j) {
    //j = 42;
}

void ects() {
    std::cout << "Entrez la note UNIGE : ";
    double input; std::cin >> input;
    if (input > 6 || input < 1) {
        std::cout << "Erreur";
    }

    char note = 'G';
    if (input >= 5.25) {
        note = 'A';
    } else if (input >= 4.75) {
        note = 'B';
    } else if (input >= 4.5) {
        note = 'C';
    } else if (input >= 4.25) {
        note = 'D';
    } else if (input >= 4) {
        note = 'E';
    } else {
        note = 'F';
    }

    std::cout << "La note ECTS est : " << note;
}

void equations() {
    std::cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";
    double a, b, c;
    std::cin >> a >> b >> c;

    double delta = b*b-4*a*c;
    if (delta < 0) {
        std::cout << "Aucune solution";
        return;
    }
    if (delta > 0) {
        double s1 = (-b+std::sqrt(delta))/(2*a);
        double s2 = (-b-std::sqrt(delta))/(2*a);
        std::cout << "2 solutions : " << s1 << " et " << s2 << std::endl;
    } else {
        if (std::isnan(-b/(2*a))) {
            std::cout << "x = R";
        }
        std::cout << "1 solution : " << -b/(2*a) << std::endl;
    }
}

void bank() {
    double initial;
    double final;
    double interest;
    std::cout << "Entrez le montant initial > "; std:: cin >> initial;
    std::cout << "Entrez le montant cible > "; std:: cin >> final;
    std::cout << "Entrez le taux d'interet annuel en % > "; std:: cin >> interest;

    int year = 0;
    if (interest < 0) {
        std::cout << "Impossible";
    }
    while (initial < final) {
        year++;
        initial = initial*(1+interest/100);
    }
    std::cout << "Le montant cible est atteint apres " << year << " ans.";
}

void bank2() {
    double initial;
    double interest;
    int year;
    std::cout << "Entrez le montant initial > "; std:: cin >> initial;
    std::cout << "Entrez le nombre d'annees > "; std:: cin >> year;
    std::cout << "Entrez les interets > "; std:: cin >> interest;

    double final = initial;
    for (int i = 0; i < year; i++) {
        final = final*(1+interest/100);
    }

    std::cout << "Le montant cible est de " << final << " ans.";
}

void bank3() {
    double initial;
    double interest;
    int year;
    do {
        std::cout << "Entrez le montant initial > "; std:: cin >> initial;
    } while (initial < 1000);
    do {
        std::cout << "Entrez le nombre d'annees > "; std:: cin >> year;
    } while (year <=0);
    do {
        std::cout << "Entrez les interets > "; std:: cin >> interest;
    } while (interest < -5||interest > 50);

    double final = initial;
    for (int i = 0; i < year; i++) {
        final = final*(1+interest/100);
    }

    std::cout << "Le montant cible est de " << final << " ans.";
}

void bounce() {
    const double gravitation = 9.81;

    double coeff;
    do {
        std::cout << "Coefficient de rebond (0 <= coeff < 1) :";
        std::cin >> coeff;
    } while (coeff < 0 || coeff >= 1);

    double height;
    do {
        std::cout << "Hauteur initiale [m]  (h0 >= 0)        :";
        std::cin >> height;
    } while (height < 0);

    double bounceNbr;
    do {
        std::cout << "Nombre de rebonds     (n >= 0)         :";
        std::cin >> bounceNbr;
    } while (bounceNbr < 0);

    double currentHeight;
    for (int i = 0; i < bounceNbr; i++) {
        const double impactSpeed = std::sqrt(2*gravitation*height);
        const double speedBounce = coeff*impactSpeed;
        height = (speedBounce*speedBounce)/(2*gravitation);
    }

    std::cout << "La hauteur atteinte apres " << bounceNbr << " rebonds : " << height << " [m]";
}

void starTriangle() {
    int height = 0;
    do {
        std::cout << "Hauteur du triangle (h > 0) : ";
        std::cin >> height;
    } while (height <= 0);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height*2+1; j++) {
            if (j+i>=height-1&&j-i<=height-1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int pgcd(int a, int b) {
    while (b!=0) {
        const int tmp = b;
        b = a%b;
        a = tmp;
    }
    return std::abs(a);
}

void ppmc() {
    int n1;
    int n2;
    do {
        std::cout << "Donnez 2 nombres entiers positifs :";
        std::cin >> n1;
        std::cin >> n2;
    } while (n1<0 || n2<0);

    int res = std::abs(n1*n2)/pgcd(n1,n2);

    printf("Le PPMC de %d et %d est : %d\n", n1, n2, res);
}

void volPyramide(const double base, const double largeur, const double hauteur) {
    double volume = base*largeur*hauteur/3.;
    printf("Le volume de la pyramide de base %.f, largeur : %.f, hauteur : %.f est %.1f\n", base, largeur, hauteur, volume);
}

bool isLeapYear(int year) {
    return (year%4==0 && year%100!=0) || year%400==0;
}

bool listChar(const char a, const char b) {
    if (a>b) {
        return false;
    }
    for (char i = a; i <= b; i++) {
        std::cout << i;
    }
    return true;
}

void permutation(double& a, double& b, double& c) {
    double temp = a;
    a = b;
    b = c;
    c = temp;
}

int main () {
    double a = 1, b = 2, c = 3;
    permutation(a, b, c);
    std::cout << a << " " << b << " " << c << std::endl;
}