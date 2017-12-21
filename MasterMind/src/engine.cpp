#include "engine.h"


engine::engine()
{

}

int s_coordinate(int coordinate);                                                   //simplify coordinate

GRIDTOKEN_H::color compare(int x, int y);                                           //gets the color from the color pallete by location

int engine::run()
{



    float Tries = 20;
    float passwordlength = 4;

    Selectiongrid select(Tries, passwordlength);




    std::vector<GRIDTOKEN_H color> colorbuffers;
    int currentselection = 0;

    sf::Vector2i mousePosition;

    GRIDTOKEN_H::color colorselection;





    sf::Font font;
    if(font.loadFromFile("resources/Fonts/clacon.ttf"))
    {
        //error
    }

    sf::RenderWindow window(sf::VideoMode(320, Tries*32), "MasterMind");
    window.setFramerateLimit(10);
    sf::RenderWindow startmenu(sf::VideoMode(320, Tries*32), " ", sf::Style::None);
    sf::Vector2i windowpos(window.getPosition());
    windowpos.x+=8;
    windowpos.y+=31;
    startmenu.setPosition(windowpos);



    while(window.isOpen())
    {


        while(startmenu.isOpen())
        {
            sf::Texture TitleTexture;
        if (TitleTexture.loadFromFile("resources/Sprites/MasterMind_Title.png"))
        {
            //error
        }
        sf::Texture StartTexture;
        if (StartTexture.loadFromFile("resources/Sprites/MasterMind_StartButton.png"))
        {
            //error
        }
        sf::Texture ExitTexture;
        if (ExitTexture.loadFromFile("resources/Sprites/MasterMind_ExitButton.png"))
        {
            //error
        }

        sf::Sprite Title;
        sf::Sprite Start;
        sf::Sprite Exit;
        Title.setTexture(TitleTexture);
        Start.setTexture(StartTexture);
        Exit.setTexture(ExitTexture);

        Start.setPosition(0,128);
        Exit.setPosition(0,(Tries*32)-128);


            sf::Event event;
            while(startmenu.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        startmenu.close();


                if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Left)
                {   mousePosition = sf::Mouse::getPosition(window);
                    if (mousePosition.y > (Tries*32)-128)
                    {
                        startmenu.close();
                        window.close();
                    }
                    if (mousePosition.y>128 && mousePosition.y<256)
                        startmenu.close();
                }
                startmenu.clear();
                startmenu.draw(Title);
                startmenu.draw(Start);
                startmenu.draw(Exit);
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
        if(BlueTexture.loadFromFile("resources/Sprites/MasterMind_Blue.png"))
        {
            //error
        }
        sf::Texture RedTexture;
        if(RedTexture.loadFromFile("resources/Sprites/MasterMind_Red.png"))
        {
            //error
        }
        sf::Texture OrangeTexture;
        if(OrangeTexture.loadFromFile("resources/Sprites/MasterMind_Orange.png"))
        {
            //error
        }
        sf::Texture GreenTexture;
        if(GreenTexture.loadFromFile("resources/Sprites/MasterMind_Green.png"))
        {
            //error
        }
        sf::Texture PurpleTexture;
        if(PurpleTexture.loadFromFile("resources/Sprites/MasterMind_Purple.png"))
        {
            //error
        }
        sf::Texture YellowTexture;
        if(YellowTexture.loadFromFile("resources/Sprites/MasterMind_Yellow.png"))
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
        sf::Sprite Red;
        Red.setTexture(RedTexture);
        sf::Sprite Yellow;
        Yellow.setTexture(YellowTexture);
        sf::Sprite Green;
        Green.setTexture(GreenTexture);
        sf::Sprite Purple;
        Purple.setTexture(PurpleTexture);
        sf::Sprite Orange;
        Orange.setTexture(OrangeTexture);
        sf::Sprite Pallete;
        Pallete.setTexture(choosecolors);


        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mousePosition = sf::Mouse::getPosition(window);
                mousePosition.x = s_coordinate(mousePosition.x);
                mousePosition.y = s_coordinate(mousePosition.y);

                colorselection = compare(mousePosition.x,mousePosition.y);
                if(colorselection!=GRIDTOKEN_H::Nothing)
                {
                    select.setcolor(currentselection, colorselection);
                    colorbuffers.push_back(colorselection);
                    currentselection++;
                }

            }
        }





                                                                                                            //rendering
        window.clear();

        for(int i=0; i<Tries;i++){
            Background_S.setPosition(0, i*32);
            window.draw(Background_S);
        }

        window.draw(Pallete);




        for(int i = 0; i<passwordlength; i++)
        {
            for(int o = 0; o<Tries; o++)
            {
                switch (select.getcolor(i, o))
                {
                    case GRIDTOKEN_H::Blue :

                        Blue.setPosition((i*32)+128,o*32);
                        window.draw(Blue);
                        break;
                    case GRIDTOKEN_H::Red :
                        Red.setPosition((i*32)+128,o*32);
                        window.draw(Red);
                        break;
                    case GRIDTOKEN_H::Yellow:
                        Yellow.setPosition((i*32)+128,o*32);
                        window.draw(Yellow);
                        break;
                    case GRIDTOKEN_H::Green:
                        Green.setPosition((i*32)+128,o*32);
                        window.draw(Green);
                        break;
                    case GRIDTOKEN_H::Purple:
                        Purple.setPosition((i*32)+128,o*32);
                        window.draw(Purple);
                        break;
                    case GRIDTOKEN_H::Orange:
                        Orange.setPosition((i*32)+128,o*32);
                        window.draw(Orange);
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

int s_coordinate(int coordinate)   //simplify coordinate
{
    return coordinate/32;
}
GRIDTOKEN_H::color compare(int x, int y)
{
    GRIDTOKEN_H::color returnthis = GRIDTOKEN_H::Nothing;
    switch (x)
    {

        case 0:
            switch (y)
            {
                case 0:
                    returnthis = GRIDTOKEN_H::Red;
                    break;
                case 1:
                    returnthis = GRIDTOKEN_H::Purple;
                    break;
                default:
                    returnthis = GRIDTOKEN_H::Nothing;
                break;
            }
            break;
        case 1:
            switch (y)
            {
                case 0:
                    returnthis = GRIDTOKEN_H::Blue;
                    break;
                case 1:
                    returnthis = GRIDTOKEN_H::Orange;
                    break;
                default:
                    returnthis = GRIDTOKEN_H::Nothing;
                break;
            }
            break;
        case 2:
            switch (y)
            {
                case 0:
                    returnthis = GRIDTOKEN_H::Yellow;
                    break;
                default:
                    returnthis = GRIDTOKEN_H::Nothing;
                break;
            }
            break;
        case 3:
            switch (y)
            {
                case 0:
                    returnthis = GRIDTOKEN_H::Green;
                    break;
                default:
                    returnthis = GRIDTOKEN_H::Nothing;
                break;

            }
            break;
        default:
                returnthis = GRIDTOKEN_H::Nothing;
        break;


    }
    std::cout<<"\n"<<x<<" "<<y;

    return returnthis;
}

engine::~engine()
{
    //dtor
}
