#define NC "\e[0m"
#define RED "\e[0;31m"
#define YELL "\e[0;33m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using namespace std;


class Power
{
public:
    int player = 2;
    string *name;

    int **tab;
    Power();
    void setName();
    void print_tab();
    int **pose(int column, int **tab, int player);
    int verif(int **tab, int &win);
    void winner(int win);
    ~Power();
};

Power::Power()
{
    tab = new int *[6];
    for (int i{0}; i < 6; i++)
        tab[i] = new int[7];
    name = new string[2];
    cout << "Entrez votre nom, joueur numéro " << 1 << std::endl;
    getline(cin, name[0]);
    this->name[1] = "Ordinateur";
}



void Power::winner(int win)
{
    if (win == 3)
        cout << "Vous êtes malheureusement ex-aeqo." << std::endl;
    for (int i = 1; i < 3; i++)
    {
        if (win == i)
            cout << "Bravo à " << name[i - 1] << " pour sa victoire." << std::endl;
    }
}

void Power::print_tab()
{
    system("clear");
    for (int k{0}; k < 7; k++)
    {
        if (k < 6)
            cout << k << "   ";
        else
            cout << k;
    }
    cout << " " << std::endl;
    for (int i{0}; i < 6; i++)
    {
        for (int j{0}; j < 7; j++)
        {
            if (tab[i][j] == 0)
            {
                if (j < 6)
                    cout << "  | ";
                else
                    cout << " ";
            }
            else
            {
                if (tab[i][j] == 1)
                {
                    if (j < 6)
                        cout << YELL << "O" << NC << " | ";
                    else
                        cout << YELL << "O" << NC;
                }
                if (tab[i][j] == 2)
                {
                    if (j < 6)
                        cout << RED << "O" << NC << " | ";
                    else
                        cout << RED << "O" << NC;
                }
            }
        }
        printf("\n");
    }
}

int **Power::pose(int columns, int **tab, int player)
{
    if (player == 1)
    {
        int i = 0;
        while (tab[5 - i][columns] != 0)
        {
            i++;
            if (i > 5)
                return tab;
        }

        tab[5 - i][columns] = player;
    }
    else
    {
        int inc = 0;
        for (int i = 0; i < 7; i++)
        {
            while (tab[5 - inc][i] != 0)
            {
                inc++;
                if (inc > 5)
                    break;
            }
            if (inc <= 5)
            {
                // si risque de victoire verticale
                if (5 - inc + 3 <= 5)
                {
                    if (tab[5 - inc + 1][i] == 1 && tab[5 - inc + 2][i] == 1 && tab[5 - inc + 3][i] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                // rique de victoire horizontale
                if (i + 3 < 7)
                {
                    if (tab[5 - inc][i + 1] == 1 && tab[5 - inc][i + 2] == 1 && tab[5 - inc][i + 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 3 >= 0)
                {
                    if (tab[5 - inc][i - 1] == 1 && tab[5 - inc][i - 2] == 1 && tab[5 - inc][i - 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                // risque de victoire diagonale
                if (i + 3 < 7 && 5 - inc + 3 <= 5 )
                {
                    if (tab[5 - inc + 1][i + 1] == 1 && tab[5 - inc + 2][i + 2] == 1 && tab[5 - inc + 3][i + 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 3 >= 0 && 5 - inc + 3 <= 5 )
                {
                    if (tab[5 - inc + 1][i - 1] == 1 && tab[5 - inc + 2][i - 2] == 1 && tab[5 - inc + 3][i - 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i + 3 < 7 && 5 - inc - 3 >= 0 )
                {
                    if (tab[5 - inc - 1][i + 1] == 1 && tab[5 - inc - 2][i + 2] == 1 && tab[5 - inc - 3][i + 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 3 >= 0 && 5 - inc - 3 >= 0 )
                {
                    if (tab[5 - inc - 1][i - 1] == 1 && tab[5 - inc - 2][i - 2] == 1 && tab[5 - inc - 3][i - 3] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
            

                if (5 - inc + 3 <= 5)
                {
                    if (tab[5 - inc + 1][i] == 2 && tab[5 - inc + 2][i] == 2 && tab[5 - inc + 3][i] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                // rique de victoire horizontale
                if (i + 3 < 7)
                {
                    if (tab[5 - inc][i + 1] == 2 && tab[5 - inc][i + 2] == 2 && tab[5 - inc][i + 3] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 3 >= 0)
                {
                    if (tab[5 - inc][i - 1] == 2 && tab[5 - inc][i - 2] == 2 && tab[5 - inc][i - 3] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
            }
            inc = 0;
        }
        for (int i = 0; i < 7; i++)
        {
            while (tab[5 - inc][i] != 0)
            {
                inc++;
                if (inc > 5)
                    break;
            }
            if (inc <= 5)
            {
                if (i - 1 >= 0)
                {
                    if (tab[5 - inc][i - 1] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i + 1 <= 0)
                {
                    if (tab[5 - inc][i + 1] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 1 >= 0 && 5 - inc - 1 >= 0)
                {
                    if (tab[5 - inc - 1][i - 1] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i + 1 <= 0 && 5 - inc - 1 >= 0)
                {
                    if (tab[5 - inc - 1][i + 1] == 1)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }

                if (5 - inc - 1 >= 0)
                {
                    if (tab[5 - inc - 1][i] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 1 >= 0)
                {
                    if (tab[5 - inc][i - 1] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i + 1 <= 0)
                {
                    if (tab[5 - inc][i + 1] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i - 1 >= 0 && 5 - inc - 1 >= 0)
                {
                    if (tab[5 - inc - 1][i - 1] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
                if (i + 1 <= 0 && 5 - inc - 1 >= 0)
                {
                    if (tab[5 - inc - 1][i + 1] == 2)
                    {
                        tab[5 - inc][i] = player;
                        return tab;
                    }
                }
            }
            inc = 0;
        }
        int j = 0;
        while (tab[5 - j][columns] != 0)
        {
            j++;
            if (j > 5)
                return tab;
        }

        tab[5 - j][columns] = player;
    }

    return tab;
}

int Power::verif(int **tab, int &win)
{
    int inc2 = 0;
    // verticale
    int inc = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tab[i][j] != 0)
            {
                for (int k = 1; k < 4; k++)
                {
                    if (tab[i][j] == tab[i + k][j])
                        inc++;
                    if (inc == 4)
                    {
                        win = tab[i][j];
                        return win;
                    }
                }
                inc = 1;
            }
        }
    }
    // horizontale
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] != 0)
            {
                for (int k = 1; k < 4; k++)
                {
                    if (tab[i][j] == tab[i][j + k])
                        inc++;
                    if (inc == 4)
                    {
                        win = tab[i][j];
                        return win;
                    }
                }
                inc = 1;
            }
        }
    }
    // diagonale gauche
    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] != 0)
            {
                if (tab[i][j] == tab[i - 1][j + 1])
                {
                    if (tab[i][j] == tab[i - 2][j + 2])
                    {
                        if (tab[i][j] == tab[i - 3][j + 3])
                        {
                            win = tab[i][j];
                            return win;
                        }
                    }
                }
                inc = 1;
            }
        }
    }
    // diagonale droite
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] != 0)
            {
                if (tab[i][j] == tab[i + 1][j + 1])
                {
                    if (tab[i][j] == tab[i + 2][j + 2])
                    {
                        if (tab[i][j] == tab[i + 3][j + 3])
                        {
                            win = tab[i][j];
                            return win;
                        }
                    }
                }
                inc = 1;
            }
        }
    }
    // plus de place
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tab[i][j] == 1 || tab[i][j] == 2)
                inc2++;
        }
    }
    if (inc2 == 42)
    {
        win = 3;
    }
    return win;
}

Power::~Power()
{
    free(tab);
}