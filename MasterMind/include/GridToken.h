#ifndef GRIDTOKEN_H
#define GRIDTOKEN_H

        enum color{

            Red,
            Yellow,
            Blue,
            Green,
            Orange,
            Purple,
            Nothing
        };

class GridToken
{
    public:
        GridToken(int x, int y, int idtemp);

        setcolor(color newcolor);

        virtual ~GridToken();


        int xpos, ypos, id;


        color tokencolor;


    protected:

    private:


};

#endif // GRIDTOKEN_H
