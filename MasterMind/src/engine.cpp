#include "engine.h"


engine::engine()
{

}

int engine::run()
{



    float Tries = 10;
    float passwordlength = 4;

    Selectiongrid select(Tries, passwordlength);

    select.setcolor(9, GRIDTOKEN_H::Blue);

    sf::Font font;
    if(font.loadFromFile("resources/Fonts/clacon.ttf"))
    {
        //error
    }

    sf::RenderWindow window(sf::VideoMode(320, 640), "MasterMind");
    window.setFramerateLimit(60);
    sf::RenderWindow startmenu(sf::VideoMode(320, 640), " ", sf::Style::None);
    sf::Vector2i windowpos(window.getPosition());
    windowpos.x+=8;
    windowpos.y+=31;
    startmenu.setPosition(windowpos);



    while(window.isOpen())
    {


        while(startmenu.isOpen())
        {


            sf::Event event;
            while(startmenu.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    startmenu.close();
                }
                startmenu.clear();
                startmenu.display();

            }
        }



                                                                                                        //textures

        sf::Texture Background;
        if (Background.loadFromFile("resources/Sprites/MasterMind_Background.png"))
        {
            //error
        }
        sf::Texture BlueTexture;
        if(BlueTexture.loadFromFile("resources/Sprites/MasterMind_Questiongrid.png"))
        {
            //error
        }
        sf::Texture choosecolors;
        if (choosecolors.loadFromFile("resources/Sprites/MasterMind_palleteFilled.png"))
        {
            //error
        }

                                                                                                            //sprites

        sf::Sprite Background_S;
        Background_S.setTexture(Background);
        sf::Sprite Blue;
        Blue.setTexture(BlueTexture);
        sf::Sprite Pallete;
        Pallete.setTexture(choosecolors);


        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }





                                                                                                            //rendering
        window.clear();

        for(int i=0; i<Tries;i++){
            Background_S.setPosition(0, i*32);
            window.draw(Background_S);
        }

        window.draw(Pallete);




        for(int i = 0; i<Tries; i++)
        {
            for(int o = 0; o<passwordlength; o++)
            {
                switch (select.getcolor(i, o))
                {
                    case GRIDTOKEN_H::Blue :

                        Blue.setPosition((i*32)+128,o*32);
                        window.draw(Blue);

                    break;
                    default:
                        break;

                }

            }
        }

                                                                                                            //Input Drawing



        window.display();
    }



    return 0;
}

engine::~engine()
{
    //dtor
}
