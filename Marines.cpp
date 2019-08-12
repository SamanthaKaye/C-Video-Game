#include <iostream>

#include "Marines.h"

using namespace std;

marine::marine(string xname, string xteam, string xtype, 
    int , int , int sniper)
    :infantry(xname,xteam,xtype)
{
     setAssualtRifle(8); 
     setHealth(100);
     cout << "You wanna piece of me, boy? ";
}

void marine::setAssualtRifle(int vassualt)
{
    assualt = vassualt;
}
    
int marine::getAssualtRifle() const
{
    return assualt;
}

void marine::fireAssualtRifle(infantry* attackedInfantry)
{
    if(this->assualt!=0 && this->getHealth()!=0 && attackedInfantry->getHealth()!=0)
    {
        assualt--; 
        attackedInfantry->assualtRifleHit();
    }    
}
void marine::renderAid(infantry* soldierBeingHelped)
{
  soldierBeingHelped -> receiveAidFromMarine();   
} 

void marine::attack (infantry* attackedInfantry)
{
    int x;
  
       fireAssualtRifle(attackedInfantry);
           
    if (attackedInfantry->getHealth() == 0)
        attackedInfantry->die();
     
}    
   

void marine::die()
{
     setAssualtRifle(0);
}



void marine::print() const
{
    cout << endl;
    infantry::print();
    cout << "Assualt Rifle Rounds: " << getAssualtRifle() << endl;
        
}  

void marine::display() const
{
    infantry::display();
    
    cout << right << setw(5) << " "
         << right << setw(5) << " "
         << right << setw(4) << getAssualtRifle()
         << endl;
     
} 
