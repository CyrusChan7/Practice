#include <iostream>
using namespace std;

class Character {
    protected:
        int movementSpeed;
    public:
        void setMovementSpeed(int x){
            movementSpeed = x;
        }
        int getMovementSpeed(){
            return movementSpeed;
        }
        virtual void run(){     // templating that all classes inherited from this base class will have a method run
        }
};

class Player: public Character{
    public:
        void run(){
            cout << "Player is running at " << movementSpeed << " speed" << endl;
        }
};

class Monster: public Character{
    public:
        void run(){
            cout << "Monster is running at " << movementSpeed << " speed" << endl;
        }
};


int main(){

    Player cyrus;
    Monster ateliaGuardian; // name of the monster

    Character * char1 = &cyrus;
    char1->setMovementSpeed(190);
    int char1MS = char1->getMovementSpeed();
    cout << "char1's movement speed is " << char1MS << endl;
    // cyrus.run();   // no longer necessary with virtual function in base class 'Character'
    char1->run();

    Character * char2 = &ateliaGuardian;
    char2->setMovementSpeed(100);
    int char2MS = char2->getMovementSpeed();
    cout << "char2's movement speed is " << char2MS << endl;
    // ateliaGuardian.run();
    char2->run();   // no longer necessary with virtual function in base class 'Character'

    return 0;
}
