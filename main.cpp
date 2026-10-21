#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class PhuongTrinhBac1 {
private:
    double a, b; 

public:
    PhuongTrinhBac1() : a(0), b(0) {}
    PhuongTrinhBac1(double a, double b) : a(a), b(b) {}

    double getA() const { return a; }
    void setA(double a) { this->a = a; }

    double getB() const { return b; }
    void setB(double b) { this->b = b; }

    void solve() const {
        cout << "\n--- Giai Phuong Trinh Bac 1: " << a << "x + " << b << " = 0 ---" << endl;
        if (a == 0) {
            if (b == 0) {
                cout << "Phuong trinh co vo so nghiem." << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        } else {
            double x = -b / a;
            cout << "Phuong trinh co 1 nghiem duy nhat: x = " << fixed << setprecision(4) << x << endl;
        }
    }
};

class PhuongTrinhBac2 {
private:
    double a, b, c; 

public:
    PhuongTrinhBac2() : a(0), b(0), c(0) {}
    PhuongTrinhBac2(double a, double b, double c) : a(a), b(b), c(c) {}

    double getA() const { return a; }
    void setA(double a) { this->a = a; }

    double getB() const { return b; }
    void setB(double b) { this->b = b; }

    double getC() const { return c; }
    void setC(double c) { this->c = c; }

    void solve() const {
        cout << "\n--- Giai Phuong Trinh Bac 2: " << a << "x^2 + " << b << "x + " << c << " = 0 ---" << endl;
        if (a == 0) {
            PhuongTrinhBac1 ptb1(b, c);
            ptb1.solve();
            return;
        }

        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem (trong tap so thuc)." << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x1 = x2 = " << fixed << setprecision(4) << x << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << fixed << setprecision(4) << x1 << endl;
            cout << "x2 = " << fixed << setprecision(4) << x2 << endl;
        }
    }
};

class PhuongTrinhBac3 {
private:
    double a, b, c, d; 

public:
    PhuongTrinhBac3() : a(0), b(0), c(0), d(0) {}
    PhuongTrinhBac3(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    double getA() const { return a; }
    void setA(double a) { this->a = a; }

    double getB() const { return b; }
    void setB(double b) { this->b = b; }

    double getC() const { return c; }
    void setC(double c) { this->c = c; }

    double getD() const { return d; }
    void setD(double d) { this->d = d; }

    void solve() const {
        cout << "\n--- Giai Phuong Trinh Bac 3: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0 ---" << endl;
        if (a == 0) {
            PhuongTrinhBac2 ptb2(b, c, d);
            ptb2.solve();
            return;
        }

        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
        double discriminant = (q * q) / 4.0 + (p * p * p) / 27.0;

        double shift = -b / (3 * a);

        if (discriminant > 0) {
            double u = cbrt(-q / 2.0 + sqrt(discriminant));
            double v = cbrt(-q / 2.0 - sqrt(discriminant));
            double y = u + v;
            cout << "Phuong trinh co 1 nghiem thuc duy nhat:" << endl;
            cout << "x = " << fixed << setprecision(4) << y + shift << endl;
        } else if (discriminant == 0) {
            double u = cbrt(-q / 2.0);
            double y1 = 2 * u;
            double y2 = -u;
            cout << "Phuong trinh co cac nghiem thuc:" << endl;
            cout << "x1 = " << fixed << setprecision(4) << y1 + shift << endl;
            cout << "x2 = x3 = " << fixed << setprecision(4) << y2 + shift << endl;
        } else {
            double r = sqrt(-p * p * p / 27.0);
            double phi = acos(-q / (2 * r));
            double y1 = 2 * cbrt(r) * cos(phi / 3.0);
            double y2 = 2 * cbrt(r) * cos((phi + 2 * M_PI) / 3.0);
            double y3 = 2 * cbrt(r) * cos((phi + 4 * M_PI) / 3.0);
            cout << "Phuong trinh co 3 nghiem phan biet:" << endl;
            cout << "x1 = " << fixed << setprecision(4) << y1 + shift << endl;
            cout << "x2 = " << fixed << setprecision(4) << y2 + shift << endl;
            cout << "x3 = " << fixed << setprecision(4) << y3 + shift << endl;
        }
    }
};

int main() {
    PhuongTrinhBac1 pt1(2, -4);
    pt1.solve();

    PhuongTrinhBac2 pt2(1, -5, 6);
    pt2.solve();

    PhuongTrinhBac3 pt3(1, -6, 11, -6);
    pt3.solve();

    cout << "\n--- Vi du thay doi gia tri bang Setter ---" << endl;
    PhuongTrinhBac1 ptCustom;
    ptCustom.setA(3);
    ptCustom.setB(9);
    cout << "Phuong trinh moi: " << ptCustom.getA() << "x + " << ptCustom.getB() << " = 0" << endl;
    ptCustom.solve();

    return 0;
}