#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include<vector>

class Shape{
    public : 
        void move(int a, int b){
            abs=abs+a;
            ord=ord+b;
        }

        int abscisse(){
            return abs;
        }

        int ordonnee(){
            return ord;
        }


        virtual double area() = 0;
    private : 
        int abs;
        int ord;

    protected :
        Shape(int x, int y) : abs(x), ord(y) {};
};

class Cercle : public Shape{
        public:
            double area(){
                return M_PI*rayon*rayon;
            }
            Cercle(int x, int y, int r) : Shape(x,y), rayon(r) {
            }
        private:
            int rayon;  
    };

class Rectangle : public Shape{
        public:
            double area(){
                return longueur*largeur;
            }
            Rectangle(int x, int y, int l, int L) : Shape(x,y), longueur(L), largeur(l){
            }
        private:
            int longueur;
            int largeur;    
    };

class Carre : public Shape{
        public : 
            double area(){
                return cote*cote;
            }
            Carre(int x, int y, int c) : Shape(x,y), cote(c){
            }
        private : 
            int cote;  
    };