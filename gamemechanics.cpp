#include "gamemechanics.h"
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLabel>
#include <QMouseEvent>
//#include <QtDebug>

GameMechanics::GameMechanics(QWidget *parent) :
        QWidget(parent)
{
    imageName = new QString();
        pieceCount = 2;
    array = new qwaqwa*[pieceCount];
        for (int i = 0; i < pieceCount; i++)
        array[i] = new qwaqwa[pieceCount];

    for (int x = 0; x<pieceCount;x++)
        for(int y = 0; y<pieceCount;y++)
        {
            array[x][y].x=x;
            array[x][y].y=y;
        }
    emptyImagePos.setX(pieceCount-1);
    emptyImagePos.setY(pieceCount-1);
    typeOfPainting = empty;
    winflag = true;
    whiteBlock = new QImage("whiteblock.jpg");

}

//-----------------------------------------

void GameMechanics::mixArray()
    //Начинаем перемешивать части картинок по алгоритму
{
    int mas[2] = {-1,1};
    int x,y;
    for(int i = 0; i<51; i++)
    {
        x = abs((mas[rand()%2]+emptyImagePos.x())%pieceCount);
        y = abs((mas[rand()%2]+emptyImagePos.x())%pieceCount);
        if (!swapEmpty(x,emptyImagePos.y())) i--;
        else repaint();
        if (!swapEmpty(emptyImagePos.x(),y)) i--;
        else repaint(); //Анимируем перестановку ~
    }
}

//-----------------------------------------


void GameMechanics::newGame()
{
    pieceWidth = this->width() / pieceCount;
    pieceHeight = this->height() / pieceCount;
    typeOfPainting = fullImage;
    QImage temp(*imageName);
    temp = temp.scaled(QSize(this->width(),this->height()));
    image = &temp;
    for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                array[x][y].img = image->copy(pieceWidth*x,pieceHeight*y,pieceWidth,pieceHeight);
    emptyImagePos.setX(pieceCount-1);
    emptyImagePos.setY(pieceCount-1);
    typeOfPainting = pieces;
    winflag = false;
    repaint();
    mixArray();
}

//----------------------------------------

void GameMechanics::hint()
{
    typeOfPainting = fullImage;
    repaint();
}

//----------------------------------------

GameMechanics::~GameMechanics()
{
    //delete imageName; TODO: хз почему, но тут прога выбрасывает исключение
    //delete image;
        for (int i = 0; i < pieceCount; i++)
                delete[] array[i];
        delete[] array;
}

//----------------------------------------

void GameMechanics::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.begin(this);
    switch(typeOfPainting)
    {
    case pieces:
        pieceWidth = this->width()/pieceCount;
        pieceHeight = this->height()/pieceCount;
        //рисуем картинки
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                //if( !( (array[x][y].x == emptyImagePos.x()) && (array[x][y].y == emptyImagePos.y()) ) )
                    painter.drawImage(pieceWidth*x,pieceHeight*y,array[x][y].img);
        painter.setPen(QColor(0,0,0));
        painter.setBrush(QColor(255,255,255));
        painter.drawRect(pieceWidth*emptyImagePos.x(),pieceHeight*emptyImagePos.y(),pieceWidth,pieceHeight);
        //рисуем линии между картинками

        for(int x = pieceWidth; x < this->width();x+=pieceWidth)
            painter.drawLine(x,0,x,this->height());
        for(int y = pieceHeight; y < this->height();y+=pieceHeight)
            painter.drawLine(0,y,this->width(),y);
        break;

    case fullImage:
        for(int x = 0; x < pieceCount; x++)
            for(int y = 0; y < pieceCount; y++)
                painter.drawImage(pieceWidth*array[x][y].x,pieceHeight*array[x][y].y,array[x][y].img);
        break;

    default:
        painter.drawText(this->width()/2-70,this->height()/2-15,"Begin the game, please!");//Please, begin the game! так по английски не говорят))
        break;
    };
    painter.end();
}

//----------------------------------------

void GameMechanics::mousePressEvent(QMouseEvent *event)
{
    imagePressed(event->posF());
}

//----------------------------------------

void GameMechanics::imagePressed(QPointF pos)
//Подаем элементы массива того
//И все равно, мне кажется это странным
{
    if(typeOfPainting == pieces)
    {
        int x = (int)pos.x(); //% pieceWidth;
        int y = (int)pos.y(); //% pieceHeight;
        x /= pieceWidth;
        y /= pieceHeight;
        if ( x == emptyImagePos.x() && y == emptyImagePos.y()) return;
        //Условие монструозно, но штоподелать, если нет исключающего "или"?
        //if( ((abs(x - emptyImagePos.x()) == 1) || (abs(y - emptyImagePos.y()) == 1)) && !((abs(x - emptyImagePos.x()) == 1) && (abs(y - emptyImagePos.y()) == 1)) )
        swapEmpty(x,y);
        repaint();
        if(checkArray())
        {
            win();
        }/* ПОБЕДИЛ */;
    }
    if(typeOfPainting == fullImage)
    {
        typeOfPainting = pieces;
        repaint();
    }
}

int GameMechanics::swapEmpty(int x, int y)
{
    if( (abs(x-emptyImagePos.x())==1 && y==emptyImagePos.y()) || (abs(y-emptyImagePos.y())==1 && x==emptyImagePos.x()) )
    {
        qwaqwa tempPiece = array[x][y];
        array[x][y]= array[emptyImagePos.x()][emptyImagePos.y()];
        array[emptyImagePos.x()][emptyImagePos.y()] = tempPiece;
        emptyImagePos.setX(x);
        emptyImagePos.setY(y);
        return 1;
    }
    else return 0;
}

bool GameMechanics::checkArray()
{
    for(int x = 0; x < pieceCount; x++)
        for(int y = 0; y < pieceCount; y++)
            if(array[x][y].x != x || array[x][y].y != y) return 0;
    winflag = true;
    return 1;
}

//----------------------------------------

/*void GameMechanics::win()
{
    //Урааааааааа
}*/
