#include <iostream>

using namespace std;

#include "Medics.h"

medic::medic(string xname, string xteam, string xtype, int boost, int )
                       : infantry(xname, xteam, xtype)
{
    setBoosterShot(boost);
    setHealth(100);
    cout << " Prepped and Ready";
}

void medic::setBoosterShot(int boost)
{
    boostedo = boost;
}


int medic::getBoosterShot() const
{
    return boostedo;
}



void medic::fire_boostedo(infantry* attackedInfantry)
{
    
}

void medic::renderAid(infantry* soldierBeingHelped)
{

if(boostedo!=0 && this->getHealth()!=0)
    {
        boostedo--;   
        soldierBeingHelped -> receiveAidFromMedic(); 
    }    

    
} 

void medic::attack (infantry* attackedInfantry)
{
       
    if (attackedInfantry->getHealth() == 0)
        attackedInfantry->die();
       
}        


void medic::die()
{
     setBoosterShot(0);
}




void medic::print() const
{
    cout << endl;
    infantry::print();
    cout << "BoosterShots: " << getBoosterShot() << endl;

        
}  

void medic::display() const
{
    infantry::display();
    cout << right << setw(5) << " "
         << right << setw(5) << " "
         << right << setw(4) << " "
         << right << setw(4) << getBoosterShot()
         << endl;
} 


