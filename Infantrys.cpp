#include <iostream>
using namespace std;

#include "Infantrys.h"

int infantry::totalBlueSoldiers = 0;
int infantry::totalRedSoldiers = 0;

infantry::infantry()
{
    setName("Unknown");
    setType("Unknown"); 
}

infantry::infantry(string xname, string xteam, string xtype)
{
    setName(xname);
    setType(xtype);
    setTeam(xteam);
    
    if(getTeam()=="Blue")
       totalBlueSoldiers++;
    else if(getTeam()=="Red")
       totalRedSoldiers++;
}       

void infantry::setName(string xname)
{
    name = xname;
}
        
string infantry::getName() const
{
    return name;
}
        
void infantry::setType(string xtype)
{
    type = xtype;
}

string infantry::getType() const
{
    return type;
}        

void infantry::setHealth(int h)
{
    health = h;
}

int infantry::getHealth() const
{
    return health;
}
    
void infantry::setTeam(string xteam)
{
    team = xteam;
}
        
string infantry::getTeam() const
{
    return team;
}

int infantry::getTotalBlueSoldiers()
{
    return totalBlueSoldiers;
}

int infantry::getTotalRedSoldiers()
{
    return totalRedSoldiers;
}

void infantry::boostedo_hit()
{
    health = health - 50;  
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
          
       health = 0; 
    }
}
void infantry::rocketLauncherHit()
{
	 health = health - 35;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 
    }
}

void infantry::flameThrowerHit()
{
    health = health - 1;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 
    }
}

void infantry::assualtRifleHit()
{
    health = health - 10;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 
    }
}


void infantry::main_gun_hit()
{
    health = health - 30;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 
    }
}



 
void infantry::sniperRifleHit()
{
    health = health - 5;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 
    }
}    
         

void infantry::stickyGrenadeHit()
{
    health = health - 30;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
    
       health = 0; 

    }
}           
  
   
void infantry::receiveAidFromMarine()
{
	if(health < 75) cout << "You ain't hurt, boy! Now get up and fight! ";
	
	else if(health > 25)
	{
    health = health + 10; }
    else if(health < 25) cout << "Sorry, bro. You ain't gonna make it. ";
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
       health = 0; 
    }
}
void infantry::receiveAidFromMedic()
{
    health = health + 30;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
       health = 0; 
    }
}

void infantry::receiveAidFromGhost()
{
    health = health + 5;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
       health = 0; 
    }
}
  void infantry::receiveAidFromSuper()
{
    health = health + 25;
    if(health < 0)
    {
       if(getTeam()=="Blue")
          totalBlueSoldiers--;
       else if(getTeam()=="Red")
          totalRedSoldiers--;
       health = 0; 
    }
}    
                                     
void infantry::print() const
{
    cout << endl;
    cout << "Infantry Name: " << getName() << endl;
    cout << "Infantry Type: " << getType() << endl;
    cout << "Infantry Health: " << getHealth() << endl;
}


void infantry::display() const
{
    cout << left << setw(17) << getName()
         << left << setw(19) << getType()
         << right << setw(6) << getHealth();   
    
}

