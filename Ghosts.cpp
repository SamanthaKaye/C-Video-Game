#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Ghosts.h"

ghost::ghost(string xname, string xteam, string xtype, int sniper )
                       : infantry(xname, xteam, xtype)
{
    setSniperRifle(sniper);
    setHealth(100);
    srand(time(NULL));
    cout << "Somebody call for an exterminator? " << endl;
}

        
void ghost::setSniperRifle(int sniper)
{
    sniperRifle = sniper;
}


int ghost::getSniperRifle() const
{
    return sniperRifle;
}




void ghost::fireSniperRifle(infantry* attackedInfantry)
{
    if(sniperRifle!=0 && this->getHealth()!=0 && attackedInfantry->getHealth()!=0)
    {
        
		       
        sniperRifle--;  
                
        attackedInfantry->sniperRifleHit();
        
    }        
}

void ghost::renderAid(infantry* soldierBeingHelped)
{
	cout << "You don't see me.... I was never here. ";
  soldierBeingHelped -> receiveAidFromGhost();   
} 

void ghost::attack (infantry* attackedInfantry)
{
    int x;

       fireSniperRifle(attackedInfantry);
           
   
    
    if (attackedInfantry->getHealth() == 0)
        attackedInfantry->die();
     
}    
   
void ghost::flameThrowerHit(infantry* attackedInfantry)
{	if(1+rand()%5 == 1) {bool cloak = true;}
	else { attackedInfantry->stickyGrenadeHit();}
}

void ghost::assualtRifleHit(infantry* attackedInfantry)
{
    if(1+rand()%5 == 1) {bool cloak = true;}
    else { attackedInfantry->stickyGrenadeHit();}
}

void ghost::stickyGrenadeHit(infantry* attackedInfantry)
{
  if(1+rand()%5 == 1) {bool cloak = true;}
  else { attackedInfantry->stickyGrenadeHit();}
}


void ghost::sniperRifleHit(infantry* attackedInfantry)
{
  if(1+rand()%5 == 1) {bool cloak = true;}
  else { attackedInfantry->stickyGrenadeHit();}

}

void ghost::die()
{
   setSniperRifle(0);

}


void ghost::print() const
{
    cout << endl;
    infantry::print();
    cout << "Sniper Rifle Rounds: " << getSniperRifle() << endl;

        
}  


void ghost::display() const
{
    infantry::display();
    cout << right << setw(5) << " "
         << right << setw(5) << " "
         << right << setw(4) << getSniperRifle()
         << endl;
     
} 
