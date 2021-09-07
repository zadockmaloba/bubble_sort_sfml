#include <iostream>
#include <SFML/Graphics.hpp>

#define M_WINSIZE 300
#define M_NUMRECT 9

static void printArray(int *xArr)
{
    std::cout<<"[ARR] : \n";
    for(int i=0; i< M_NUMRECT; i++) {std::cout<<xArr[i]; std::cout<<",";};
    std::cout<< "\n";
}
static void m_swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
static void bubbleSort(int *xArr)
{
    for(int i=0; i<M_NUMRECT; i++)
    {
        if(xArr[i] > xArr[i+1]) m_swap(&xArr[i], &xArr[i+1]);
    }
    printArray(xArr);
}

static void init_window(sf::RenderWindow* winPtr);
static void draw_rect(sf::RenderWindow* winPtr);
static sf::RectangleShape get_rect(sf::Vector2f pos, float width, float height);
static int arr1[M_NUMRECT] = {5,3,6,2,1,7,4,8,9};

int main(int argc, char **argv) 
{
    sf::RenderWindow mainWin(sf::VideoMode({M_WINSIZE,M_WINSIZE}), "Bubble-Sort SFML", sf::Style::Close);
    init_window(&mainWin);
    return 0;
}

void init_window(sf::RenderWindow* winPtr)
{
    while(winPtr->isOpen())
    {
        winPtr->clear();
        sf::Event m_evnts;
        while(winPtr->pollEvent(m_evnts))
        {
            if(m_evnts.type == sf::Event::Closed)
            {
                winPtr->close();
            }
            if(m_evnts.type == sf::Event::KeyPressed)
            {
                if(m_evnts.key.code == sf::Keyboard::Enter) bubbleSort(arr1);
            }
        }
        draw_rect(winPtr);
        winPtr->display();
    }
}

void draw_rect(sf::RenderWindow* winPtr)
{
    double rectWidth = winPtr->getSize().x/M_NUMRECT;
    int y_pos=200;//winPtr->getSize().y;
    int x_pos_arr[M_NUMRECT];
    for(int i=0; i< M_NUMRECT; i++)
    {
        x_pos_arr[i] = i * rectWidth;
    }
    for(int i=0; i< M_NUMRECT; i++)
    {
        winPtr->draw(get_rect({(float)x_pos_arr[i], (float)y_pos},rectWidth, arr1[i]*20));
    }
}

sf::RectangleShape get_rect(sf::Vector2f pos, float width, float height)
{
    sf::RectangleShape box;
    box.setPosition(pos);
    box.setSize(sf::Vector2f{width, height});
    box.setOrigin(0,height);
    return box;
}


