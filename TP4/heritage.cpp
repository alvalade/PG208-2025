#include <iostream>

class Rectangle
{
public:
    Rectangle();

    virtual void whoamI();

protected:
    std::string color;

private:
    std::string size;
};

class Square: public Rectangle
{
public:
    Square();

    virtual void whoamI() override;
};

Rectangle
::Rectangle()
: color("bleu"), // Autre syntaxe pour ecrire un constructeur
  size("grand")  // Chacune de ces lignes est equivalente a mettre
                   // `variable = valeur` entre les accolades
{}

void Rectangle
::whoamI()
{
    std::cout << "Je suis un " << size << " rectangle " << color << "..." << std::endl;
}

Square
::Square()
: Rectangle() // Initialiation de la classe parent
              // La valeur de color est directement heritee du Rectangle
              // Size est privee dans ce contexte, donc le carre n'y a pas acces
{}

void Square
::whoamI()
{
    std::cout << "Je suis un carre " << color << "..." << std::endl;
    // Si vous voulez empecher la compilation, essayez d'acceder a size au lieu de color
}


int main()
{
    Rectangle r {};
    Square s {};

    r.whoamI();
    s.whoamI();
}