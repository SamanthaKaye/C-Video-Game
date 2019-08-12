#include <iostream>
#include "Supers.h"

using namespace std;

super::super(string xname, string xteam, string xtype, 
    int dbgun, int bbgun, int mgun, int b,  
    int sniper, int c, int boost, int pistol)
    :infantry(xname,xteam,xtype),firebat(xname,xteam,xtype,dbgun),
     marine(xname,xteam,xtype,mgun,b,bbgun),
     ghost(xname,xteam,xtype,sniper),
     medic(xname,xteam,xtype,boost,pistol)
{
     setStickyGrenade(4);
     setHealth(100);
     cout << "I'm a super soldier " << endl;
}


void super::setStickyGrenade(int sticky )
{
    stickyGrenade = sticky ;
}
    

int super::getStickyGrenade() const
{
    return stickyGrenade;
}



void super::fireStickyGrenade(infantry* attackedInfantry)
{

    if(this->stickyGrenade!=0 && this->getHealth()!=0 && attackedInfantry->getHealth()!= 0)
    {
        stickyGrenade--; 
        attackedInfantry->stickyGrenadeHit();
    }    
}
void super::renderAid(infantry* soldierBeingHelped)
{
  soldierBeingHelped -> receiveAidFromSuper();   
} 

void super::attack (infantry* attackedInfantry)
{
    int x;
    

    firebat::attack (attackedInfantry);
    marine::attack (attackedInfantry);     
    medic::attack (attackedInfantry);
    ghost::attack (attackedInfantry);
    
    if (attackedInfantry->getHealth() == 0)
        attackedInfantry->die();
        
}    


void super::die()
{
     firebat::die();
     marine::die();
     medic::die();
     ghost::die();
     setStickyGrenade(0);
}



void super::print() const
{
    cout << endl;
    infantry::print();
    firebat::print();
    medic::print();
    ghost::print();
    cout << "Sticky Grenade: " << getStickyGrenade() << endl;
        
}  

void super::display() const
{
    infantry::display();
    
    cout << right << setw(5) << firebat::getFlameThrower()
         << right << setw(4) << getSniperRifle()
         << right << setw(4) << getBoosterShot()
         << right << setw(4) << " "
         << right << setw(4) << getStickyGrenade()
         << endl;
     
} 
