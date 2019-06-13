
#include "BasketReg.h"
#include<string>
#include<strings.h>
#include<iostream>

using namespace std;

using std::string;
using std::cout;
using std::endl;
using std::cin;



int main()
{

    /*string name1, color1;
    string plyName, plyPos;

    plyName = "ahmet";
    plyPos = "forver";

    name1 = "Bilkent";
    color1 = "spi";


    Team myTeam(name1,color1);



    myTeam.addPlyr(plyName, plyPos);
    myTeam.addPlyr("nuri", plyPos);
    myTeam.addPlyr("meh1",plyPos);
    myTeam.addPlyr("meh2",plyPos);





    myTeam.removePlyr("meh1");
    myTeam.addPlyr("meh1",plyPos);
    myTeam.removePlyr("meh2");
    myTeam.addPlyr("meh2",plyPos);
    myTeam.removePlyr("nuri");

    myTeam.removePlyr(plyName);
    myTeam.removePlyr(plyName);


    myTeam.displayTeam();


    myTeam.addPlyr("meh1",plyPos);
    myTeam.addPlyr("meh2",plyPos);
    myTeam.removePlyr("meh2");


    myTeam.addPlyr("meh3",plyPos);
    myTeam.addPlyr("meh4",plyPos);
    myTeam.addPlyr("meh5",plyPos);
    myTeam.addPlyr("meh6",plyPos);
    myTeam.addPlyr("meh7",plyPos);
    myTeam.addPlyr("meh8",plyPos);

    myTeam.addPlyr("meh9",plyPos);
    myTeam.addPlyr("meh10",plyPos);
    myTeam.addPlyr("meh11",plyPos);
    myTeam.addPlyr("meh12",plyPos);

myTeam.displayTeam();

    myTeam.removePlyr("meafdh12");


    Team myTeam2;

     myTeam2.displayTeam();

    myTeam2.setName("bilkentiki");
    myTeam2.setColor("pembe");
    myTeam2.addPlyr("yeni adam", "teambel");
    myTeam2.removePlyr("meh12");

    myTeam2 = myTeam;


    myTeam2.removePlyr("meh1");
    myTeam2.removePlyr("meh2");
    myTeam2.removePlyr("meh3");
    myTeam2.removePlyr("meh4");
    myTeam2.removePlyr("meh5");


    myTeam = myTeam2;

    myTeam2.displayTeam();
     myTeam.displayTeam();*/

     //////////////////////////////////

    /*Team myTeam("ali","color1");


   cout << myTeam.getName() << endl;

   Team myTeam2 = Team("aldf", "asldjf");

    cout << myTeam2.getName() << endl;


    Node *myNode = new Node;

    myNode->t.setName("alli");

    cout << myNode->t.getName() << endl;*/

    BasketReg myReg;

    BasketReg yourReg;

    yourReg.addTeam("MeH1", "renk");
    yourReg.addTeam("MEH1", "renk");

     myReg.addTeam("MeH1", "renk");
    myReg.addTeam("MEH1", "renk");
    myReg.addTeam("meh3", "renk");

    myReg.addTeam("meh6", "renk");
    myReg.addTeam("meh7", "renk");
    myReg.addTeam("meh9", "renk");

    cout << " " << endl;
    myReg.displayAllTeams();


    yourReg = myReg;

    myReg.removeTeam("meh1");
    myReg.removeTeam("meh3");
    yourReg.removeTeam("meh1");
    yourReg.removeTeam("meh3");



    cout << " " << endl;
    myReg.displayAllTeams();

    myReg.addTeam("meh4", "renk");
    myReg.addTeam("meh5", "renk");

    cout << " " << endl;
    myReg.displayAllTeams();

    cout << " " << endl;
    myReg.displayTeam("meh5");

    myReg.addPlayer("meh5", "mahmud1" , "center");
    myReg.addPlayer("meh5", "mahmud2" , "center");
    myReg.addPlayer("meh5", "mahmud2" , "center");
    myReg.addPlayer("meh0", "mahmud4" , "center");

    cout << " " << endl;
    myReg.displayTeam("meh5");


    myReg.addPlayer("meh3", "mahmud1" , "center");
    myReg.addPlayer("meh3", "mahmud2" , "center");


    cout << " " << endl;
    myReg.displayTeam("meh3");


    myReg.removePlayer("meh5", "Mahmud1" );
    myReg.removePlayer("meh5", "maHmuD9" );
    myReg.removePlayer("meh5", "mahmud9" );

    cout << " " << endl;
    myReg.displayTeam("meh5");


    cout << " " << endl;
    myReg.displayPlayer("MahMud10");


    BasketReg myReg2;

    myReg2 = myReg;


    cout << " " << endl;
    myReg.displayAllTeams();

    cout << " " << endl;
    myReg2.displayAllTeams();

    cout << " " << endl;
    myReg2.displayPlayer("MahMud2");

    BasketReg myReg3(myReg);

    cout << " " << endl;
    myReg.displayAllTeams();

    cout << " " << endl;
    myReg2.displayAllTeams();

    cout << " " << endl;
    myReg2.displayPlayer("MahMud2");


    return 0;




    myReg.addTeam("meh4", "renk");
    myReg.addTeam("meh5", "renk");


    myReg.removeTeam("meh1");
    myReg.removeTeam("meh2");
    myReg.removeTeam("meh3");
    myReg.removeTeam("meh3");

    myReg.displayAllTeams();

    //myReg.displayTeam("als");
    myReg.displayTeam("meh5");

    myReg.addPlayer("meh5", "mahmud1" , "center");
    myReg.addPlayer("meh5", "mahmud2" , "center");
    myReg.addPlayer("meh5", "mahmud3" , "center");
    myReg.addPlayer("meh5", "mahmud4" , "center");

    myReg.addPlayer("meh4", "mahmud1" , "center");

    myReg.displayTeam("meh5");


    myReg.displayAllTeams();

    //BasketReg myReg2 ;

    /*myReg2.addTeam("meh2", "renk");
    myReg2.addTeam("meh1", "renk");
    myReg2.addTeam("meh4", "renk");
    myReg2.addTeam("meh5", "renk");




    myReg2.addPlayer("meh2", "mahmud1" , "center");
    myReg2.addPlayer("meh1", "mahmud2" , "center");
    myReg2.addPlayer("meh4", "mahmud3" , "center");
    myReg2.addPlayer("meh5", "mahmud4" , "center");



    myReg2 = myReg;

    myReg2.displayAllTeams();*/










    return 0;
}


