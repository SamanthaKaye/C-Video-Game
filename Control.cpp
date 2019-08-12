#include <iostream>
#include <vector>
using std::vector;
using namespace std;

#include "Infantrys.h"
#include "Other.h"
#include "Firebats.h"
#include "Ghosts.h"
#include "Medics.h"
#include "Marines.h"
#include "Supers.h"


void display_infantrys(infantry* myFirebat, 
                     infantry* myGhost, infantry* myMedic,
                     infantry* myMarine,
                     infantry* mySuper);

int main()
{
    int x;
    
    firebat b1("Blue Firebat","Blue");
    ghost b3("Blue Ghost","Blue");
    medic b4("Blue Medic","Blue"); 
    ghost b5("Blue Marine","Blue");
    super b6("Blue Super","Blue");
    
    firebat r1("Red Firebat","Red");
    ghost r3("Red Ghost","Red");
    medic r4("Red Medic","Red");  
    ghost r5("Red Marine","Red");
    super r6("Red Super","Red");    
        
     infantry* blueFirebat;
     infantry* blueGhost;
     infantry* blueMedic;
     infantry* blueMarine;
     infantry* blueSuper;
     
     infantry* redFirebat;
     infantry* redGhost;
     infantry* redMedic; 
     infantry* redMarine;
     infantry* redSuper;             
     
     blueFirebat = &b1;
     blueGhost = &b3;
     blueMedic = &b4;
     blueMarine = &b5;
     blueSuper = &b6;
     
     redFirebat = &r1;
     redGhost = &r3;
     redMedic = &r4; 
     redMarine = &r5;
     redSuper = &r6;        
     
         
  
     
   
     int turn;
     bool invalid;
     infantry* attackingSoldier;
     infantry* soldierBeingAttacked;
     infantry* helpingSoldier;
     infantry* soldierBeingHelped;
     string choice; string secondChoice;
     char firstChoice;
     
     turn = 0;


     for(turn=0;turn<40;turn++)
     {
     
         if(turn%2==0) 
         {
             system("cls");
                 
             display_infantrys(blueFirebat, blueGhost, blueMedic, blueMarine, blueSuper);  
             display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
                              
          
       
           
           invalid=true;  
           
           while(invalid)
           {
             invalid = false;
             
               cout<< "Render aid or attack? Enter either R or A: ";
        cin >> firstChoice;
        if(firstChoice == 'R'){
        	cout << "Blue Team, Enter the soldier you want help from. ( BF, BG, BS, BMA, BME) ";
        	cin >> secondChoice;
             if(secondChoice=="BF")
                 helpingSoldier = blueFirebat;
             else if(secondChoice=="BG")
                 helpingSoldier = blueGhost;
             else if(secondChoice=="BS")
                 helpingSoldier = blueSuper;
             else if(secondChoice=="BMA")
                 helpingSoldier = blueMarine;
             else if(secondChoice=="BME")
                 helpingSoldier = blueMedic;
             else 
             {
                 invalid=true;
                 cout << "Invalid Soldier" << endl;
                 system("pause");
                              
                 system("cls"); }
        	
		
         if(firstChoice == 'A'){
        
             cout << "Blue Team, Enter your attacking infantry. (BF, BG, BM, BMA, BS): ";
             cin >> choice;
             
             if(choice=="BF")
                 attackingSoldier = blueFirebat;
             else if(choice=="BG")
                 attackingSoldier = blueGhost;
             else if(choice=="BM")
                 attackingSoldier = blueMedic;
             else if(choice=="BMA")
                 attackingSoldier = blueMarine;
             else if(choice=="BS")
                 attackingSoldier = blueSuper;
             else
             {
                 invalid=true;
                 cout << "Invalid Infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blueFirebat, blueGhost, blueMedic, blueMarine, blueSuper);  
                 display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
                                    
             } 
                      
            } }
         

           

           invalid=true;  
           
           while(invalid)
           {
             invalid = false;
             
          cout<< "Render aid or attack? Enter either R or A: ";
        cin >> firstChoice;
        if(firstChoice == 'R'){
        	cout << "Blue Team, Enter the soldier you want to help. ( BF, BG, BS, BMA, BME) ";
        	cin >> secondChoice;
             if(secondChoice=="BF")
                 soldierBeingHelped = blueFirebat;
             else if(secondChoice=="BG")
                 soldierBeingHelped = blueGhost;
             else if(secondChoice=="BS")
                 soldierBeingHelped = blueSuper;
             else if(secondChoice=="BMA")
                 soldierBeingHelped = blueMarine;
             else if(secondChoice=="BME")
                 soldierBeingHelped = blueMedic;
             else
             {
                 invalid=true;
                 cout << "Invalid Soldier" << endl;
                 system("pause");
                              
                 system("cls");
        	
		}
        if(firstChoice == 'A'){
             cout << "Blue Team, Enter the infantry you want to attack. (RF, RG, RM, RMG, RS): ";
             cin >> choice;
             
             if(choice=="RF")
                 soldierBeingAttacked = redFirebat;
             else if(choice=="RG")
                 soldierBeingAttacked = redGhost;
             else if(choice=="RM")
                 soldierBeingAttacked = redMedic;
             else if(choice=="RMG")
                 soldierBeingAttacked = redMarine;
             else if(choice=="RS")
                 soldierBeingAttacked = redSuper;
             else
             {
                 invalid=true;
                 cout << "Invalid Infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blueFirebat, blueGhost, blueMedic, blueMarine, blueSuper);  
                 display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
                    

             } 
                      
            }           
          
          
          
            attackingSoldier->attack(soldierBeingAttacked);
            helpingSoldier -> renderAid(soldierBeingHelped); 
            
            if(infantry::getTotalRedSoldiers()==0)
            {
                system("cls");
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << "                        ";
                cout << "        BLUE TEAM WINS!!!!!      " << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << endl << endl << endl << endl << endl;
                system("pause");
                return 0;
            }
            
            
 // ****************************************************************************************Bue team turn above, Red team turn below *********************************         
          
          }  
         
         
          else if(turn%2==1)  
          {
              
             system("cls");
             
             display_infantrys(blueFirebat, blueGhost, blueMedic, blueMarine, blueSuper);  
             display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
               
           
          
           
           invalid=true;  
           
           while(invalid)
           {
             invalid = false;
             
             
             
                cout<< "Render aid or attack? Enter either R or A: ";
        cin >> firstChoice;
        if(firstChoice == 'R'){
        	cout << "Red Team, Enter the soldier you want help from. (RF, RG, RS, RMA, RME) ";
        	cin >> secondChoice;
            if(secondChoice=="RF")
                 helpingSoldier = redFirebat;
             else if(secondChoice=="RG")
                 helpingSoldier = redGhost;
             else if(secondChoice=="RS")
                 helpingSoldier = redSuper;
             else if(secondChoice=="RMA")
                 helpingSoldier = redMarine;
             else if(secondChoice=="RME")
                 helpingSoldier = redMedic;
             else
             {
                 invalid=true;
                 cout << "Invalid Soldier" << endl;
                 system("pause");
                              
                 system("cls");
        	
		}
        if(firstChoice == 'A'){
        
             cout << "RED Team, Enter your attacking infantry. (RF, RG, RM, RMG, RS): ";
             cin >> choice;
             
             if(choice=="RF")
                 attackingSoldier = redFirebat;
             else if(choice=="RG")
                 attackingSoldier = redGhost;
             else if(choice=="RM")
                 attackingSoldier = redMedic;
             else if(choice=="RMG")
                 attackingSoldier = redMarine;
             else if(choice=="RS")
                 attackingSoldier = redSuper;
             else
             {
                 invalid=true;
                 cout << "Invalid Infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blueFirebat,blueGhost, blueMedic, blueMarine, blueSuper);  
                 display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
                    

             }  
                      
            }    
         

          

           invalid=true;  
           
           while(invalid)
           {
             invalid = false;
             
        cout<< "Render aid or attack? Enter either R or A: ";
        cin >> firstChoice;
        if(firstChoice == 'R'){
        	cout << "Red Team, Enter the soldier you want to help. (RF, RG, RS, RMA, RME) ";
        	cin >> secondChoice;
             if(secondChoice=="RF")
                 soldierBeingHelped = redFirebat;
             else if(secondChoice=="RG")
                 soldierBeingHelped = redGhost;
             else if(secondChoice=="RS")
                 soldierBeingHelped = redSuper;
             else if(secondChoice=="RMA")
                 soldierBeingHelped = redMarine;
             else if(secondChoice=="RME")
                 soldierBeingHelped = redMedic;
             else
             {
                 invalid=true;
                 cout << "Invalid Soldier" << endl;
                 system("pause");
                              
                 system("cls");
        	
		}
        if(firstChoice == 'A'){
        
             cout << "RED Team, Enter the infantry you want to attack. (BF, BG, BM, BMG, BS): ";
             cin >> choice;
             
             if(choice=="BF")
                 soldierBeingAttacked = blueFirebat;
             else if(choice=="BG")
                 soldierBeingAttacked = blueGhost;
             else if(choice=="BM")
                 soldierBeingAttacked = blueMedic;
             else if(choice=="BMG")
                 soldierBeingAttacked = blueMarine;
             else if(choice=="BS")
                 soldierBeingAttacked = blueSuper;
             else
             {
                 invalid=true;
                 cout << "Invalid Infantry" << endl;
                 system("pause");
                              
                 system("cls");
             
                 display_infantrys(blueFirebat, blueGhost, blueMedic, blueMarine, blueSuper);  
                 display_infantrys(redFirebat, redGhost, redMedic, redMarine, redSuper);  
                    
             } 
                      
            }          
          
            attackingSoldier->attack(soldierBeingAttacked);     
            helpingSoldier -> renderAid(soldierBeingHelped); 
 
            if(infantry::getTotalBlueSoldiers()==0)
            {
                system("cls");
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << "                        ";
                cout << "        RED TEAM WINS!!!!!      " << endl;
                cout << "                        ";
                cout << "*********************************" << endl;
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << endl << endl << endl << endl << endl;                system("pause");
                return 0;
            }        
         
     
          }  
          
                          
        } 
                                 
                                                             

    cout << endl;
    system("pause");
    return 0;
       
}}}}}}}}





void display_infantrys(infantry* myFirebat, 
                     infantry* myGhost, infantry* myMedic,
                     infantry* myMarine, infantry* mySuper)
{
    
    cout << endl;
    cout << left
         << setw(17) << "Infantry Name"
         << setw(18) << "Infantry Type"
         << right
         << setw(7) << "Health"
         << setw(5) << "FlameThrower"
         << setw(5) << "SniperRifle"
         << setw(4) << "Booster Shot"
         << setw(4) << "Assualt Rifle"
         << setw(4) << "Sticky Grenade"
         << setw(4) << ""
         << setw(4) << ""
         << setw(4) << ""
         << endl;
         
    cout << "------------------------------------------------------------------------------" << endl;
    
    myFirebat -> display();
    myGhost -> display();
    myMedic -> display();    
    myMarine -> display();
    mySuper -> display();
     
    cout << endl;
    
    if(myFirebat -> getTeam() == "Blue")
        cout << "Total Blue Soldiers Remaining: " << infantry::getTotalBlueSoldiers() << endl << endl;
    else if(myFirebat -> getTeam() == "Red")
        cout << "Total Red Soldiers Remaining: " << infantry::getTotalRedSoldiers() << endl << endl;
        

}   



     
