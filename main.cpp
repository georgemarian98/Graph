#include"Functii.h"

int main()
{
    cout<<R"(Intructiuni:
Se introduce o expresie sub forma 'operand operatie operand'.
Programul functioneaza pentru urmatoarele functii:
    sinus (s)
    cosinus (c)
    logaritm natural (l)
    ridicarea la putere (^)
Exemplu:
    2*x^2-x+5
    s(x^2)
    1/(l(s(x))+x))" <<endl;

    srand(time(NULL));

    int c=1;
    cout<<"Ecuatia "<<c++<<": ";
    char s[100];



    double indice=-30;
    float ratie=0.1;

    ecuatieNoua(s);
    arbore* root=NULL;
    root = tree(s);
    afisare(root);

    sf::RenderWindow window(sf::VideoMode(w, h), "Graficul unei functii");
    window.setFramerateLimit(60);


    sf::CircleShape punct(1.f);
    punct.setFillColor(sf::Color::Green);
    punct.setOrigin(punct.getGlobalBounds().width/2,punct.getGlobalBounds().height/2);

    sf::Color culoare;

    ///Y
    sf::Vertex Y[] =
    {
        sf::Vertex(sf::Vector2f(w/2, 0)),
        sf::Vertex(sf::Vector2f(w/2, h))
    };
    ///X
    sf::Vertex X[] =
    {
        sf::Vertex(sf::Vector2f(0, h/2)),
        sf::Vertex(sf::Vector2f(w, h/2))
    };

    bool inGrafic=false;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        if(peGrafic(punct.getPosition().x,punct.getPosition().y))
            inGrafic=true;

        ///traseaza graficul altei functii
//        if(!peGrafic(punct.getPosition().x,punct.getPosition().y) && inGrafic){
//            cout<<"Ecuatia "<<c++<<": ";
//
//            inGrafic=false;
//            for(int i=0;i<n;i++)
//                delete []polinom[i];
//
//            ecuatieNoua(polinom,n,s,grad,indice,ratie,poz);
//
//            culoare.r=rand()%230+10;
//            culoare.g=rand()%230+10;
//            culoare.b=rand()%230+10;
//
//            punct.setFillColor(culoare);
//        }



        punct.setPosition(5*indice+w/2,-10*eval(root,indice)+h/2);
        indice+=ratie;

        window.draw(punct);
        window.draw(X,2,sf::Lines);
        window.draw(Y,2,sf::Lines);


        window.display();
    }


    return 0;
}
