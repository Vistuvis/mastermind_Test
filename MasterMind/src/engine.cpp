#include "engine.h"


engine::engine()
{

}

int s_coordinate(int coordinate);                                               //simplify coordinate
void check(int &a, int &b);

std::vector<GRIDTOKEN_H::color> outcome_return(std::vector<GRIDTOKEN_H::color>);

GRIDTOKEN_H::color compare(int x, int y);                                           //gets the color from the color pallete by location

int engine::run()
{


    int pix = 32;
    float Tries = 20;
    float passwordlength = 4;









    sf::Vector2i mousePosition;






    sf::Font font;
    if(font.loadFromFile("resources/Fonts/clacon.ttf"))
    {
        //error
    }

    sf::RenderWindow window(sf::VideoMode(320, Tries*32), "MasterMind");
    window.setFramerateLimit(10);
    sf::RenderWindow startmenu(sf::VideoMode(320, Tries*32), "Menu", sf::Style::None);


    while(window.isOpen()||startmenu.isOpen())

        {
            window.create(sf::VideoMode(320, Tries*32), "MasterMind");
            startmenu.requestFocus();
        while(startmenu.isOpen())
        {

        sf::Vector2i windowpos(window.getPosition());
        windowpos.x+=8;
        windowpos.y+=31;
        startmenu.setPosition(windowpos);

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
                    {
                        window.create(sf::VideoMode(320, Tries*32), "MasterMind");
                        window.requestFocus();
                        startmenu.close();
                    }
                }
                startmenu.clear();
                startmenu.draw(Title);
                startmenu.draw(Start);
                startmenu.draw(Exit);
                startmenu.display();
            }
        }

    int currentselection = 0;
    int flagselection = 0;
    Selectiongrid select(Tries, passwordlength);
    Selectiongrid Outcomes(Tries, passwordlength);

    GRIDTOKEN_H::color colorselection;

    std::vector<GRIDTOKEN_H color> colorbuffers;
    bool won=false;
    bool lost=false;

    bool eventbuffered = false;
    game game1;
    while(window.isOpen())
    {



        bool selected = false;





        if(currentselection>=Tries*4)
            lost = true;
                                                                                                        //textures

        sf::Texture Background;
        if (Background.loadFromFile("resources/Sprites/MasterMind_Background.png"))
        {
            //error
        }
        sf::Texture BlueTexture;
        if(BlueTexture.loadFromFile("resources/Sprites/MasterMind_Bluebutton.png"))
        {
            //error
        }
        sf::Texture RedTexture;
        if(RedTexture.loadFromFile("resources/Sprites/MasterMind_Redbutton.png"))
        {
            //error
        }
        sf::Texture OrangeTexture;
        if(OrangeTexture.loadFromFile("resources/Sprites/MasterMind_Orangebutton.png"))
        {
            //error
        }
        sf::Texture GreenTexture;
        if(GreenTexture.loadFromFile("resources/Sprites/MasterMind_Greenbutton.png"))
        {
            //error
        }
        sf::Texture PurpleTexture;
        if(PurpleTexture.loadFromFile("resources/Sprites/MasterMind_Purplebutton.png"))
        {
            //error
        }
        sf::Texture YellowTexture;
        if(YellowTexture.loadFromFile("resources/Sprites/MasterMind_Yellowbutton.png"))
        {
            //error
        }
        sf::Texture CheckmarkTexture;
        if(CheckmarkTexture.loadFromFile("resources/Sprites/MasterMind_Check.png"))
        {
            //error
        }
        sf::Texture PartCorrectTexture;
        if(PartCorrectTexture.loadFromFile("resources/Sprites/MasterMind_PartCorrect.png"))
        {
            //error
        }
        sf::Texture Xtexture;
        if(Xtexture.loadFromFile("resources/Sprites/MasterMind_X.png"))
        {
            //error
        }
        sf::Texture choosecolors;
        if (choosecolors.loadFromFile("resources/Sprites/MasterMind_palleteFilled.png"))
        {
            //error
        }
        sf::Texture exitgameTexture;
        if (exitgameTexture.loadFromFile("resources/Sprites/MasterMind_Exit.png"))
        {
            //error
        }
        sf::Texture UndoTexture;
        if (UndoTexture.loadFromFile("resources/Sprites/MasterMind_Undo.png"))
        {
            //error
        }
        sf::Texture EndturnTexture;
        if (EndturnTexture.loadFromFile("resources/Sprites/MasterMind_EndTurn.png"))
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
        sf::Sprite Checkmark;
        Checkmark.setTexture(CheckmarkTexture);
        sf::Sprite Part;
        Part.setTexture(PartCorrectTexture);
        sf::Sprite X;
        X.setTexture(Xtexture);
        sf::Sprite Pallete;
        Pallete.setTexture(choosecolors);
        sf::Sprite Exit;
        Exit.setTexture(exitgameTexture);
        sf::Sprite Undo;
        Undo.setTexture(UndoTexture);
        sf::Sprite Endturn;
        Endturn.setTexture(EndturnTexture);







        Exit.setPosition(0,Tries*32-32);
        Undo.setPosition(16,128+60);
        Endturn.setPosition(90,128+60);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonReleased)
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                selected = false;

                mousePosition = sf::Mouse::getPosition(window);
                mousePosition.x = s_coordinate(mousePosition.x);
                mousePosition.y = s_coordinate(mousePosition.y);

                colorselection = compare(mousePosition.x,mousePosition.y);
                if (colorbuffers.size() <4)
                if(colorselection!=GRIDTOKEN_H::Nothing)
                {
                    select.setcolor(currentselection, colorselection);
                    colorbuffers.push_back(colorselection);
                    currentselection++;
                }
                if (mousePosition.x<2 && mousePosition.y>Tries-2)
                {
                    startmenu.create(sf::VideoMode(320, Tries*32), " ", sf::Style::None);
                    window.close();
                }
                if (colorbuffers.size() > 0)
                if ((sf::Mouse::getPosition(window).x<48 && sf::Mouse::getPosition(window).x>16) && (sf::Mouse::getPosition(window).y<128+60+32 && sf::Mouse::getPosition(window).y>128+60) )
                    {
                        colorbuffers.pop_back();
                        currentselection--;
                        select.setcolor(currentselection, GRIDTOKEN_H::Nothing);
                    }
                if (!(colorbuffers.size() <4))
                if ((sf::Mouse::getPosition(window).x<48+64 && sf::Mouse::getPosition(window).x>16+64) && (sf::Mouse::getPosition(window).y<128+60+32 && sf::Mouse::getPosition(window).y>128+60) )
                    {




                            std::vector<GRIDTOKEN_H::color> currentoutcomes = game1.run_game(colorbuffers);
                            for (int unsigned i=0;i<colorbuffers.size();i++)
                            {
                                Outcomes.setcolor(flagselection+i, currentoutcomes[i]);
                            }

                            flagselection+=4;
                            if(currentoutcomes[0] == GRIDTOKEN_H::Black)
                                if(currentoutcomes[1] == GRIDTOKEN_H::Black)
                                if(currentoutcomes[2] == GRIDTOKEN_H::Black)
                                if(currentoutcomes[3] == GRIDTOKEN_H::Black)
                                    {won = true;
                                    std::cout<<won;

                                    }
                            for (int unsigned i=0;i<currentoutcomes.size();)
                            {
                                currentoutcomes.pop_back();
                                colorbuffers.pop_back();


                            }



                    }

            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                {   mousePosition = sf::Mouse::getPosition(window);
                    mousePosition.x = s_coordinate(mousePosition.x);
                    mousePosition.y = s_coordinate(mousePosition.y);
                    colorselection = compare(mousePosition.x,mousePosition.y);
                    selected = true;
                }





                                                                                                            //rendering
        window.clear();

        for(int i=0; i<Tries;i++){
            Background_S.setPosition(0, i*32);
            window.draw(Background_S);
        }



        window.draw(Pallete);
        window.draw(Exit);
        window.draw(Undo);
        window.draw(Endturn);


        Red.setPosition(0,0);
        window.draw(Red);
        Blue.setPosition(32,0);
        window.draw(Blue);
        Yellow.setPosition(64,0);
        window.draw(Yellow);
        Green.setPosition(96, 0);
        window.draw(Green);
        Purple.setPosition(0,32);
        window.draw(Purple);
        Orange.setPosition(32,32);
        window.draw(Orange);

        if (selected)
        {
            switch (colorselection)
                {

                    case GRIDTOKEN_H::Blue :
                        Blue.rotate(180);
                        Blue.setPosition(64,32);
                        window.draw(Blue);
                        Blue.rotate(180);
                        break;
                    case GRIDTOKEN_H::Red :
                        Red.rotate(180);
                        Red.setPosition(32,32);
                        window.draw(Red);
                        Red.rotate(180);
                        break;
                    case GRIDTOKEN_H::Yellow:
                        Yellow.rotate(180);
                        Yellow.setPosition(96,32);
                        window.draw(Yellow);
                        Yellow.rotate(180);
                        break;
                    case GRIDTOKEN_H::Green:
                        Green.rotate(180);
                        Green.setPosition(128,32);
                        window.draw(Green);
                        Green.rotate(180);
                        break;
                    case GRIDTOKEN_H::Purple:
                        Purple.rotate(180);
                        Purple.setPosition(32,64);
                        window.draw(Purple);
                        Purple.rotate(180);
                        break;
                    case GRIDTOKEN_H::Orange:
                        Orange.rotate(180);
                        Orange.setPosition(64,64);
                        window.draw(Orange);
                        Orange.rotate(180);
                        break;
                    default:
                        break;
                }

        }


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
            int blackposition =0;
            int b2=0;
            int w2=0;
            int x2=0;
            int whiteposition=0;
            int xposition = 0;
        for(int i = 0; i<Tries; i++)
        {

            for(int o = 0; o<passwordlength; o++)
            {

                switch (Outcomes.getcolor(o, i))
                {
                case GRIDTOKEN_H::Black:
                    Checkmark.setPosition((256)+(blackposition*pix/2), (i*32)+(b2*pix/2));
                    window.draw(Checkmark);
                    blackposition++;
                    break;
                case GRIDTOKEN_H::White:
                    Part.setPosition((288)+(whiteposition*pix/2), (i*pix)+(w2*pix/2));
                    window.draw(Part);
                    whiteposition++;
                    break;
                case GRIDTOKEN_H::Nothing:

                    xposition++;
                    break;
                default:
                    break;
                }
                check(blackposition,b2);
                check(whiteposition,w2);
                check(xposition,x2);




            }
            blackposition = 0;
            b2=0;
            whiteposition=0;
            w2=0;

        }
            blackposition = 0;
            b2=0;
            whiteposition=0;
            w2=0;

    sf::Texture loseTexture;
    if (!loseTexture.loadFromFile("resources/Sprites/MasterMind_lose.png"))
    {
        //error
    }
    sf::Texture winTexture;
    if (!winTexture.loadFromFile("resources/Sprites/MasterMind_win.png"))
    {
        //error
    }

    sf::Sprite win;
    win.setTexture(winTexture);
    sf::Sprite lose;
    lose.setTexture(loseTexture);

    if (won)
    {
        window.draw(win);
        std::cout<<" WIN ";
    }
    if (lost)
    {
        window.draw(lose);
    }                                                                                          //Input Drawing


        window.display();




    }
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

    return returnthis;
}

void check (int & a, int & b)
{
    if (a>1)
    {
        a=0;
        b++;
    }
}
std::vector<GRIDTOKEN_H::color> outcome_return(std::vector<GRIDTOKEN_H::color> buffers)
{
    return buffers;
}

engine::~engine()
{
    //dtor
}
