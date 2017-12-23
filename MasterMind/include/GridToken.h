#ifndef GRIDTOKEN_H
#define GRIDTOKEN_H

        enum color{

            Red,
            Blue,
            Yellow,
            Green,
            Purple,
            Orange,
            Nothing,
            Black,
            White
        };

class GridToken
{
    public:
        GridToken(int x, int y, int idtemp);

        void setcolor(color newcolor);

        virtual ~GridToken();


        int xpos, ypos, id;


        color tokencolor;


    protected:

    private:


};

#endif // GRIDTOKEN_H
