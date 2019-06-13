
#include<string>
#include<iostream>

using namespace std;

using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "BasketReg.h"

        BasketReg::BasketReg()
        {
            head = NULL;
            teamNo = 0;
        }
        BasketReg::~BasketReg()
        {

            //delete the current teams in the system
            while(head != NULL)
            {

                Node *del = head;

                if(head->next == NULL)
                {
                    Node *newPtr = head;
                    head = NULL;
                    delete newPtr;
                }
                else
                {

                    while(del->next->next != NULL)
                    {
                        del = del->next;
                    }

                    Node *newPtr = del->next;
                    del->next = NULL;
                    delete newPtr;
                }
            }
            head = NULL;
            teamNo = 0;
        }


        BasketReg::BasketReg( const BasketReg &systemToCopy )
        {

            head = NULL;
            teamNo = systemToCopy.teamNo;
            Node *cur = systemToCopy.head;

            Node *lastInserted;


            while(cur != NULL)
            {
                Node *tmp = new Node;


                tmp->t = cur->t;


                if(head == NULL)
                    head = tmp;
                else
                    lastInserted->next = tmp;

                lastInserted = tmp;
                cur = cur->next;
            }

            if(head != NULL)
            {
                lastInserted->next = NULL;
            }
        }



        void BasketReg::operator=( const BasketReg &right )
        {

            //delete the current teams in the system
            while(head != NULL)
            {

                Node *del = head;

                if(head->next == NULL)
                {
                    Node *newPtr = head;
                    head = NULL;
                    delete newPtr;
                }
                else
                {

                    while(del->next->next != NULL)
                    {
                        del = del->next;
                    }

                    Node *newPtr = del->next;
                    del->next = NULL;
                    delete newPtr;
                }
            }

            head = NULL;
            teamNo = right.teamNo;
            Node *cur = right.head;

            Node *lastInserted;


            while(cur != NULL)
            {
                Node *tmp = new Node;


                tmp->t = cur->t;


                if(head == NULL)
                    head = tmp;
                else
                    lastInserted->next = tmp;

                lastInserted = tmp;
                cur = cur->next;
            }

            if(head != NULL)
            {
                lastInserted->next = NULL;
            }




        }



        // add a new team to the system
        void BasketReg::addTeam( string teamName, string teamColor )
        {
            // first make the teamName lower case
            teamName[0] = toupper(teamName[0]);

            for (int i = 1; teamName[i]; i++)
                {
                    teamName[i] = tolower(teamName[i]);

                }

                // first make the teamName lower case
            teamColor[0] = toupper(teamColor[0]);

            for (int i = 1; teamColor[i]; i++)
                {
                    teamColor[i] = tolower(teamColor[i]);

                }



            if( findTeam(teamName) != NULL)
            {
                cout << "The team " << teamName << " is already exist in the system " << endl;
            }
            else
            {
                Node *cur = head;

                if(cur == NULL)
                {
                        Node *tmp = new Node;

                        tmp->t.setName(teamName);
                        tmp->t.setColor(teamColor);
                        tmp->next = NULL;
                        head = tmp;

                }
                else
                {
                    while(cur->next!=NULL)
                    {
                        cur = cur->next;
                    }

                    Node *tmp = new Node;
                    tmp->t.setName(teamName);
                    tmp->t.setColor(teamColor);
                    cur->next = tmp;
                    cur->next->next = NULL;
                }
            }

        }


        void BasketReg::removeTeam( string teamName )
        {

            // first make the teamName lower case
            teamName[0] = toupper(teamName[0]);

            for (int i = 1; teamName[i]; i++)
                {
                    teamName[i] = tolower(teamName[i]);

                }

            if(findTeam(teamName) == NULL)
            {
                cout << "There is not any team having the name " << teamName << " in the system" << endl;
             }
             else
             {
                 Node *cur = head;


                 if(head->t.getName() == teamName)
                 {
                        Node *newPtr = head;
                        head = head->next;
                        delete newPtr;
                 }
                 else
                 {
                     while(cur != NULL  )
                     {
                         if(cur->next->t.getName() == teamName)
                         {
                             Node *newPtr = cur->next;
                             cur->next = cur->next->next;
                             delete newPtr;
                             break;
                         }
                         cur = cur->next;
                     }
                 }

             }

        }



        void BasketReg::displayAllTeams()
        {

            if (head == NULL)
                cout << "--EMPTY--" << endl;
            else
            {
                for(Node *cur = head; cur != NULL; cur = cur->next)
                {
                    cout << cur->t.getName() << ", " << cur->t.getColor() << endl;
                }
            }

        }
        void BasketReg::addPlayer( string teamName, string playerName, string playerPosition )
        {
                // first make the teamName lower case
            teamName[0] = toupper(teamName[0]);

            for (int i = 1; teamName[i]; i++)
                {
                    teamName[i] = tolower(teamName[i]);

                }

                //  make the playerName lower case
            playerName[0] = toupper(playerName[0]);

            for (int i = 1; playerName[i]; i++)
                {
                    playerName[i] = tolower(playerName[i]);

                }

                Node *cur = findTeam(teamName);

                if( cur == NULL)
                    cout << "There is not any team with the name " << teamName << " in the system" << endl;
                else
                {
                    cur->t.addPlyr(playerName, playerPosition);
                }

        }




        void BasketReg::removePlayer( string teamName, string playerName )
        {
             // first make the teamName lower case
            teamName[0] = toupper(teamName[0]);

            for (int i = 1; teamName[i]; i++)
                {
                    teamName[i] = tolower(teamName[i]);

                }

                //  make the playerName lower case
            playerName[0] = toupper(playerName[0]);

            for (int i = 1; playerName[i]; i++)
                {
                    playerName[i] = tolower(playerName[i]);

                }

            Node *cur = findTeam(teamName);

            if(cur == NULL)
            {
                cout << "There is not any team with the name " << teamName << " in the system" << endl;
             }
             else
             {
                 cur->t.removePlyr(playerName);

             }

        }



        void BasketReg::displayTeam( string teamName )
        {

            // first make the teamName lower case
            teamName[0] = toupper(teamName[0]);

            for (int i = 1; teamName[i]; i++)
                {
                    teamName[i] = tolower(teamName[i]);

                }


            Node *newPtr = findTeam(teamName);
            if(newPtr != NULL )
            {
                 newPtr->t.displayTeam();
            }
            else
            {

                cout << teamName << endl;
                cout <<    "--EMPTY--" <<  endl;
            }

        }


        void BasketReg::displayPlayer( string playerName )
        {


             //  make the playerName lower case
            playerName[0] = toupper(playerName[0]);

            for (int i = 1; playerName[i]; i++)
                {
                    playerName[i] = tolower(playerName[i]);

                }



            cout <<playerName << endl;

            if(head == NULL)
            {
                cout <<  "--EMPTY--" << endl;
            }
            else
            {
                Node *cur = head;
                int un = 0;

                while(cur != NULL)
                {
                    if(cur->t.findPlyr(playerName) == 1)
                    {
                        cout << cur->t.getPosition(playerName) << ", " << cur->t.getName() << ", " << cur->t.getColor() << endl;
                        un = 1;
                    }
                    cur = cur->next;
                }
                if (un ==0)
                    cout << "--EMPTY--" << endl;
            }


        }

        BasketReg::Node* BasketReg::findTeam(string teamName)
        {


            if(head == NULL)
                return NULL;


            for(Node * cur = head; cur != NULL; cur = cur->next)
            {
                if(cur->t.getName() == teamName)
                    return cur;

            }


            return NULL;

        }
