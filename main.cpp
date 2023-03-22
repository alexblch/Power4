#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "header.hpp"
#include <ctime>
#include <random>

using namespace std;

int main()
{
    /*random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 6);*/

    srand(time(NULL));
    int columns;
    int win = 0;
    Power *p = new Power();
    
    for (int i = 0; i < 2; i++)
    {
        cout << p->name[i] << std::endl;
    }
    while (win == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            p->print_tab();

            while (columns < 0 || columns > 6)
            {
                if (i % 2 == 0)
                {
                    cout << p->name[i] << ", entrez la colonne dans laquelle vous voulez mettre votre pion (entre 0 et 6):" << std::endl;
                    std::cin >> columns;
                }
                else if (i % 2 == 1)
                {
                    columns = rand() % 7;
                }
            }
            p->tab = p->pose(columns, p->tab, i + 1);
            p->verif(p->tab, win);
            if (win != 0)
                break;
            p->print_tab();
            columns = -1;
        }
    }

    p->print_tab();
    p->winner(win);
    free(p);
    return 0;
}