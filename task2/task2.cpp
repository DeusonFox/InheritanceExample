// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ComputerGame
{
private:
    string name;
public:
    ComputerGame(const string _name) :name(_name) {}
    ComputerGame(const ComputerGame& obj) : name(obj.name) {}
    ~ComputerGame() {}

    string get_name() const
    {
        return name;
    }

    explicit virtual operator string()
    {
        return string(typeid(*this).name()) + ": (" + _print() + ")";
    }

protected:

    virtual string _print()
    {
        return "name of the game: " + name;
    }
};

class character : public ComputerGame
{
private:
    int x, y, HealthPoint, ManaPoint, MaxHealthPoint, MaxManaPoint;
public:
    character(const string _name, const int _maxHealth, const int _maxMana) : ComputerGame(_name), x(0), y(0), HealthPoint(_maxHealth), ManaPoint(_maxMana) {}
    character(const string _name, const int _maxHealth, const int _maxMana, const int _x, const int _y) : ComputerGame(_name), x(_x), y(_y), HealthPoint(_maxHealth), MaxHealthPoint(_maxHealth), ManaPoint(_maxMana), MaxManaPoint(_maxMana) {}
    character(const character& obj) : ComputerGame(obj), x(obj.x), y(obj.y), HealthPoint(obj.MaxHealthPoint), ManaPoint(obj.MaxManaPoint), MaxHealthPoint(obj.MaxHealthPoint), MaxManaPoint(obj.MaxManaPoint) {}

    int getx() const
    {
        return x;
    }

    int gety() const
    {
        return y;
    }

    int gethp() const
    {
        return HealthPoint;
    }

    int getmp() const
    {
        return ManaPoint;
    }

    virtual void move(int dx, int dy) = 0;
    virtual void take_damage(int damage) = 0;
    virtual void mana_use(int mana_cost) = 0;

protected:

    void _move(const int dx, const int dy)
    {
        x += dx;
        y += dy;
    }

    void _take_damage(const int Damage)
    {
        HealthPoint = max(0, HealthPoint - Damage);
    }

    void _mana_use(const int ManaCost)
    {
        ManaPoint = max(0, ManaPoint - ManaCost);
    }

    string _print() override
    {
        return ComputerGame::_print() + ", x: " + to_string(x) + ", y: " + to_string(y) + 
            ", max hp: " + to_string(MaxHealthPoint) + ", max mp: " + to_string(MaxManaPoint) +
            ", hp: " + to_string(HealthPoint) + ", mp: " + to_string(ManaPoint);
    }
    
}; 
class items : public ComputerGame
{
private:
    int Damage;
public:

    items(const string _name, const int _damage) : ComputerGame(_name), Damage(_damage) {}
    items(const items& obj) : ComputerGame(obj), Damage(obj.Damage) {}
    ~items() {}

    int get_damage() const
    {
        return Damage;
    }

protected:
    string _print() override
    {
        return ComputerGame::_print() + ", damage: " + to_string(Damage);
    }
};
class scroll_of_fire : virtual public items
{
private:
    int FireDamage;
public:
    scroll_of_fire(const string _name, const int _damage, const int _firedamage) : items(_name, _damage), FireDamage(_firedamage) {}
    scroll_of_fire(const scroll_of_fire& obj) : items(obj), FireDamage(obj.FireDamage) {}
    ~scroll_of_fire() {}

    int get_firedamage() const
    {
        return FireDamage;
    }

protected:
    string _print() override
    {
        return items::_print() + ", fire damage: " + to_string(FireDamage);
    }
};
class lightning : virtual public items
{
private:
    int LightningDamage;
public:
    lightning(const string _name, const int _damage, const int _lightningdamage) : items(_name, _damage), LightningDamage(_lightningdamage) {}
    lightning(const lightning& obj) : items(obj), LightningDamage(obj.LightningDamage) {}
    ~lightning() {}

    int get_lightningdamage() const
    {
        return LightningDamage;
    }

protected:
    string _print() override
    {
        return items::_print() + ", lightning damage: " + to_string(LightningDamage);
    }
};

class Unicorn : virtual public character
{
private:
    string type;
public:
    Unicorn(const string _name, const string _type, const int _maxhealth, const int _maxmana) : character(_name, _maxhealth, _maxmana), type(_type) {}
    Unicorn(const string _name, const string _type, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y), type(_type) {}
    Unicorn(const Unicorn& obj) : character(obj), type(obj.type) {}
    ~Unicorn() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "Unicorn " + get_name() + " goes to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "Unicorn " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "Unicorn " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }

protected:
    string _print() override
    {
        return character::_print() + ", color: " + type;
    }
};

class GOD : virtual public character
{
private:
    string GODofwhat;
public:
    GOD(const string _name, const int _maxhealth, const int _maxmana, const string _godofwhat) : character(_name, _maxhealth, _maxmana), GODofwhat(_godofwhat) {}
    GOD(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y) {}
    GOD(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y, const string _godofwhat) : character(_name, _maxhealth, _maxmana, _x, _y), GODofwhat(_godofwhat) {}
    GOD(const GOD& obj) : character(obj), GODofwhat(obj.GODofwhat) {}
    ~GOD() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "GOD " + get_name() + " goes to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "GOD " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "GOD " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }

    void voice(const string str)
    {
        cout << get_name() + " shout \"" + str + "\"\n";
    }

protected:
    string _print() override
    {
        return character::_print() + ", kind of magic: " + GODofwhat;
    }
};

class Sith : virtual public character
{
private:
    string kindofmagic;
public:
    Sith(const string _name, const int _maxhealth, const int _maxmana, const string _kindofmagic) : character(_name, _maxhealth, _maxmana), kindofmagic(_kindofmagic) {}
    Sith(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y) {}
    Sith(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y, const string _kindofmagic) : character(_name, _maxhealth, _maxmana, _x, _y), kindofmagic(_kindofmagic) {}
    Sith(const Sith& obj) : character(obj), kindofmagic(obj.kindofmagic) {}
    ~Sith() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "Sith " + get_name() + " moved to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "Sith " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "Sith " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }

protected:
    string _print() override
    {
        return character::_print() + ", kind of magic: " + kindofmagic;
    }
};

int main()
{
    Unicorn new_unicorn("Roach", "Rainbow", 777, 250, -37, 52);
    cout << string(new_unicorn) << endl;  cout << endl;
    Sith new_sith("Palpatine", 1000, 420, 0, 4, "Lightning");
    cout << string(new_sith) << endl; cout << endl;
    new_sith.move(-36, 48);  cout << endl;
    lightning new_lighting("lightning", 500, 500);
    cout << string(new_lighting) << endl; cout << endl;
    new_unicorn.take_damage(500); cout << endl;
    cout << string(new_unicorn) << endl; cout << endl;
    GOD new_god("Hephaestus", 100000, 100000, 50, 50, "Fire");
    cout << string(new_god) << endl; 
    scroll_of_fire new_sof("fire", 999, 999); cout << endl;
    cout << string(new_sof) << endl; cout << endl;
    new_god.voice("For violating the order"); cout << endl;
    new_sith.take_damage(999); cout << endl;
    cout << string(new_sith) << endl;
}
