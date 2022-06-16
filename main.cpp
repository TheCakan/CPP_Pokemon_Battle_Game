#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int user_score = 0, cpu_score = 0;

void pok_assign(void);

void pok_display(void);

void pok_display(int);

void play(int);

class POK {
private:
    int power;
    float health;
    int speed;
    int defence;
    int offence;
    char name[10];
    char type[10];

public:
    int pow() { return power; }

    float hlt() { return health; }

    int spd() { return speed; }

    int def() { return defence; }

    int off() { return offence; }

    char *getname() { return name; };

    char *gettype() { return type; };

    void special(int);

    void attack(int);

    void defend(int);

    void Dexterity(int);

    POK() {}

    POK(int p, float h, int s, int d, int o, char n[10], char t[10]) {
        power = p;
        health = h;
        speed = s;
        defence = d;
        offence = o;
        strcpy(name, n);
        strcpy(type, t);
    }

};

//Pokemons
char a[12][10] = {"Voltorb", "Pikachu",
                  "Psyduck", "Blastoise",
                  "Ninetales", "Charizard",
                  "Butterfee", "Spearow",
                  "Alakazam ", "Mr. Mime",
                  "Golem", "Kabutops"
};

char t[10][10] = {"Electric", "Water",
                  "Fire", "Air",
                  "Steel", "Ice"
};

//Pokemon attributes
POK Voltorb(4, 60, 5, 4, 3, a[0], t[0]), Pikachu(7, 80, 6, 5, 8, a[1], t[0]);
POK Psyduck(3, 50, 4, 7, 5, a[2], t[1]), Blastoise(8, 90, 5, 8, 7, a[3], t[1]);
POK Ninetales(7, 70, 8, 5, 6, a[4], t[2]), Charizard(9, 80, 4, 7, 9, a[5], t[2]);
POK Butterfee(6, 50, 8, 3, 6, a[6], t[3]), Spearow(8, 70, 9, 4, 7, a[7], t[3]);
POK Alakazam(7, 80, 4, 5, 9, a[8], t[4]), MrMime(8, 70, 4, 9, 7, a[9], t[4]);
POK Golem(7, 90, 3, 8, 7, a[10], t[5]), Kabutops(9, 70, 6, 9, 8, a[11], t[5]);

class player {
public:
    POK pokemon[4]; //Player has 4 pokemon

} cpu, user;

//Pokemon special power
void POK::special(int pok) {
    //Randomize special power
    int ch = rand() % 4;
    switch (ch) {
        case 0:
            health *= 2;
            cout << "\nHealth Doubled!";
            break;
        case 1:
            speed *= power;
            cout << "\nDexterity Modified!";
            break;
        case 2:
            defence *= power;
            cout << "\nDefence Modified!";
            break;
        case 3:
            offence *= power;
            cout << "\nAttack Modified!";
            break;
    }
    power = 0;
    pok_display(pok);

}

//Pokemon attack
void POK::attack(int pok) {
    //Randomize for CPU, depends on player activities
    int ch = rand() % 4, cpu_val, user_val;
    user_val = user.pokemon[pok].off();
    switch (ch) {
        case 0:
            cout << "\nCPU chose Dexterity";
            cpu_val = cpu.pokemon[pok].spd();
            if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 10;
            else
                cpu.pokemon[pok].health -= 20;
            break;
        case 1:
            cout << "\nCPU chose DEFENCE";
            cpu_val = cpu.pokemon[pok].def();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 10;
            else
                user.pokemon[pok].health -= 20;
            break;
        case 2:
            cout << "\nCPU chose ATTACK";
            cpu_val = cpu.pokemon[pok].off();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 20;
            else if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 20;
            else if (cpu_val > user_val)
                user.pokemon[pok].health -= 10;
            else if (user_val > cpu_val)
                cpu.pokemon[pok].health -= 10;
            break;
        case 3:
            cout << "\nCPU chose SPECIAL";
            cpu.pokemon[pok].special(pok);
            break;
    }
}

//Pokemon defence
void POK::defend(int pok) {

    int ch = rand() % 4, cpu_val, user_val;
    user_val = user.pokemon[pok].def();
    switch (ch) {
        case 0:
            cout << "\nCPU chose Dexterity";
            cpu_val = cpu.pokemon[pok].spd();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 10;
            else
                user.pokemon[pok].health -= 20;
            break;
        case 1:
            cout << "\nCPU chose ATTACK";
            cpu_val = cpu.pokemon[pok].off();
            if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 10;
            else
                cpu.pokemon[pok].health -= 20;
            break;
        case 2:
            cout << "\nCPU chose DEFENCE";
            cpu_val = cpu.pokemon[pok].def();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 20;
            else if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 20;
            else if (cpu_val > user_val)
                user.pokemon[pok].health -= 10;
            else if (user_val > cpu_val)
                cpu.pokemon[pok].health -= 10;
            break;
        case 3:
            cout << "\nCPU chose SPECIAL";
            cpu.pokemon[pok].special(pok);
            break;
    }
}

//Pokemon Dexterity
void POK::Dexterity(int pok) {

    int ch = rand() % 4, cpu_val, user_val;
    user_val = user.pokemon[pok].spd();
    switch (ch) {
        case 0:
            cout << "\nCPU chose DEFENCE";
            cpu_val = cpu.pokemon[pok].def();
            if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 10;
            else
                cpu.pokemon[pok].health -= 20;
            break;
        case 1:
            cout << "\nCPU chose ATTACK";
            cpu_val = cpu.pokemon[pok].off();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 10;
            else
                user.pokemon[pok].health -= 20;
            break;
        case 2:
            cout << "\nCPU chose Dexterity";
            cpu_val = cpu.pokemon[pok].spd();
            if (user_val - cpu_val > 50)
                cpu.pokemon[pok].health -= 20;
            else if (cpu_val - user_val > 50)
                user.pokemon[pok].health -= 20;
            else if (cpu_val > user_val)
                user.pokemon[pok].health -= 10;
            else if (user_val > cpu_val)
                cpu.pokemon[pok].health -= 10;
            break;
        case 3:
            cout << "\nCPU chose SPECIAL";
            cpu.pokemon[pok].special(pok);
            break;
    }
}

int main() {
    //Starting screen
    int pok;
    restart:
    pok_assign();
    //Player choosing pokemon
    for (int i = 0; i < 4; ++i) {
        pok_display();
        do {
            cout << "\n\nChoose your Pokemon to start battle(1-4): ";
            cin >> pok;
            if (!pok)
                return 0;
            if (pok == 10101)
                goto restart;
        } while (pok > 4 || pok < 0);
        play(--pok);
    }
    //End game text, if player or cpu win the series or draw
    cout << "\n\t\t____________________________________________\n";
    if (user_score > cpu_score)
        cout << "\t\t**********!!!YOU WON THE SERIES!!!**********";
    else if (cpu_score > user_score)
        cout << "\t\t**********!!!CPU WON THE SERIES!!!**********";
    else
        cout << "\t\t**********!!!IT'S DRAW, START AGAIN!!!**********";
    cout << "\n\t\t____________________________________________\n";
    return 0;
}

//
void play(int pok) {
    //Displays cpu and player pokemon name and types
    int choice;
    cout << "\nCPU's Pokemon: " << cpu.pokemon[pok].getname()
         << "\nHealth: " << user.pokemon[pok].hlt()
         << "\nType: " << cpu.pokemon[pok].gettype();
    cout << "\nYour Pokemon : " << user.pokemon[pok].getname()
         << "\nHealth: " << user.pokemon[pok].hlt()
         << "\nType: " << user.pokemon[pok].gettype() << endl;
    //Player choose what to do
    while ((user.pokemon[pok].hlt() > 0) && (cpu.pokemon[pok].hlt() > 0)) {
        do {
            cout << "_____________________________________________";
            cout << "\nChoose from Below: ";
            cout << "\n1.) Dexterity: " << user.pokemon[pok].spd()
                 << "\t\t2.) Attack:  " << user.pokemon[pok].off()
                 << "\n3.) Defence: " << user.pokemon[pok].def()
                 << "\t\t4.) Special: " << user.pokemon[pok].pow();
            cout << "\n\nYour Choice: ";
            cin >> choice;
        } while (choice < 0 || choice > 4);
        //After player choosing activity to make it happen
        switch (choice) {
            case 0:
                exit(0);
            case 1:
                user.pokemon[pok].Dexterity(pok);
                break;
            case 2:
                user.pokemon[pok].attack(pok);
                break;
            case 3:
                user.pokemon[pok].defend(pok);
                break;
            case 4:
                user.pokemon[pok].special(pok);
                break;
        }
        //After battle display both pokemon's status
        cout << "\n\nUSER Pokemon: " << user.pokemon[pok].getname()
             << "\tHealth: " << user.pokemon[pok].hlt()
             << "\nType: " << user.pokemon[pok].gettype();
        cout << "\nCPU Pokemon : " << cpu.pokemon[pok].getname()
             << "\tHealth: " << cpu.pokemon[pok].hlt()
             << "\nType: " << cpu.pokemon[pok].gettype() << endl;
    }
    //If player win this match
    if (user.pokemon[pok].hlt() > cpu.pokemon[pok].hlt()) {
        user_score++;
        cout << "\n\n**********************";
        cout << "\n* You Won this Match *\n";
        cout << "**********************\n\n";
    } else //If CPU win this match
    {
        cpu_score++;
        cout << "\n\n**********************";
        cout << "\n* CPU Won this Match *\n";
        cout << "**********************\n\n";
    }
}

//Assign pokemon's
void pok_assign() {
    //Randomize player starting pokemon's (player can randomize again with typing 10101)
    int uval, cval;
    for (int i = 0; i < 4; ++i) {
        uval = rand() % 12;
        cval = rand() % 12;
        switch (uval) {
            case 0:
                user.pokemon[i] = Voltorb;
                break;
            case 1:
                user.pokemon[i] = Pikachu;
                break;
            case 2:
                user.pokemon[i] = Psyduck;
                break;
            case 3:
                user.pokemon[i] = Blastoise;
                break;
            case 4:
                user.pokemon[i] = Ninetales;
                break;
            case 5:
                user.pokemon[i] = Charizard;
                break;
            case 6:
                user.pokemon[i] = Butterfee;
                break;
            case 7:
                user.pokemon[i] = Spearow;
                break;
            case 8:
                user.pokemon[i] = Alakazam;
                break;
            case 9:
                user.pokemon[i] = MrMime;
                break;
            case 10:
                user.pokemon[i] = Golem;
                break;
            case 11:
                user.pokemon[i] = Kabutops;
                break;
        }
        switch (cval) //Randomize CPU starting pokemons
        {
            case 0:
                cpu.pokemon[i] = Voltorb;
                break;
            case 1:
                cpu.pokemon[i] = Pikachu;
                break;
            case 2:
                cpu.pokemon[i] = Psyduck;
                break;
            case 3:
                cpu.pokemon[i] = Blastoise;
                break;
            case 4:
                cpu.pokemon[i] = Ninetales;
                break;
            case 5:
                cpu.pokemon[i] = Charizard;
                break;
            case 6:
                cpu.pokemon[i] = Butterfee;
                break;
            case 7:
                cpu.pokemon[i] = Spearow;
                break;
            case 8:
                cpu.pokemon[i] = Alakazam;
                break;
            case 9:
                cpu.pokemon[i] = MrMime;
                break;
            case 10:
                cpu.pokemon[i] = Golem;
                break;
            case 11:
                cpu.pokemon[i] = Kabutops;
                break;
        }
    }
}

void pok_display() {
    //After choosing pokemons it will display choosen pokemons attributies
    cout << "\n\nYour Pokemons are:\n"
         << "\n If you want to change your Pokemons just type '10101'\n(But be careful it will randomize every pokemon you have)\n";
    for (int i = 0; i < 4; ++i) {
        cout << "\n" << i + 1 << ") " << user.pokemon[i].getname();
        cout << "\tType: " << user.pokemon[i].gettype();
        cout << "\n\tPower\tHealth\tDexterity\tDefence\tAttack" << endl;
        cout << "\t" << user.pokemon[i].pow()
             << "\t" << user.pokemon[i].hlt()
             << "\t" << user.pokemon[i].spd()
             << "\t" << user.pokemon[i].def()
             << "\t" << user.pokemon[i].off();
    }
}

//Displaying both pokemon's
void pok_display(int i) {

    cout << "\n_____________________________________________";
    cout << "\nPokemon abilities are:\n";
    //For user
    cout << "\nUser: " << user.pokemon[i].getname()
         << "\nType: " << user.pokemon[i].gettype();
    cout << "\n\tPower\tHealth\tDexterity\tDefence\tAttack" << endl;
    cout << "\t" << user.pokemon[i].pow()
         << "\t" << user.pokemon[i].hlt()
         << "\t" << user.pokemon[i].spd()
         << "\t" << user.pokemon[i].def()
         << "\t" << user.pokemon[i].off();
    //For CPU
    cout << "\nCPU : " << cpu.pokemon[i].getname()
         << "\nType: " << cpu.pokemon[i].gettype();
    cout << "\n\tPower\tHealth\tDexterity\tDefence\tAttack" << endl;
    cout << "\t" << cpu.pokemon[i].pow()
         << "\t" << cpu.pokemon[i].hlt()
         << "\t" << cpu.pokemon[i].spd()
         << "\t" << cpu.pokemon[i].def()
         << "\t" << cpu.pokemon[i].off();
}
