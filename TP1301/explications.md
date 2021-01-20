des classes pour différentes formes géométriques.
Il faut des fonctions pour les déplacer dans le repère formé par l'ordinateur et calculer leur surface

Les objets ont une position (x,y) (ce sont des entiers (pixels))

On aura une classe cercle, carré, ellipse, rectangle

cercle (x,y,Rayon R)
carré (x,y,Coté C)
rectangle (x,y, hauteur h, longueur l)

On veut savoir les move(int, int), et calculer leur area()

move utilise les attributs de position. C'est toujours la même chose donc il faut le "factoriser"
area utilise les autres

Donc on fait une classe forme qui a x,y,move(int,int)

On fait d'autres classes carre, cercle, rectangle, qui héritent de cette classe là


On va dériver les classes 
class Forme{};   \\2 entiers en privé + un constructeur qui construit une forme à partir de 2 entiers
class Cercle : 
    public Forme{} \\la classe cercle dérive en public de forme
                    \\on lui donne x,y et un rayon, et elle fait appel à Forme


Toujours dériver en public, en private ça ne sert à rien