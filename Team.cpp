
#include<string>
#include<iostream>

using namespace std;

using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "Team.h"


Team::Team(string name,string color)
{

    // first make the teamName lower case
            name[0] = toupper(name[0]);

            for (int i = 1; name[i]; i++)
                {
                    name[i] = tolower(name[i]);

                }

    // first make the teamName lower case
            color[0] = toupper(color[0]);

            for (int i = 1; color[i]; i++)
                {
                    color[i] = tolower(color[i]);

                }


    TeamName = name;
    TeamColor = color;
    head = NULL;
}

Team::Team()
{
    head = NULL;
}

//destructor
Team::~Team()
{
    if(head != NULL)
        while(head->next != NULL)
        {
            Node *cur = head;

            while(cur->next->next != NULL )
            {
                cur = cur->next;
            }

            Node *newPtr = cur->next;
            cur->next = NULL;
            delete newPtr;
        }



    if(head != NULL)
    {
        delete head;
        head = NULL;
    }

}

//copy constructor
Team::Team( Team &toCopy )
{
        TeamName = toCopy.getName();
        TeamColor = toCopy.getColor();

        head = NULL;
        Node *cur = toCopy.head;

        Node *lastInserted;


        while(cur != NULL)
        {
            Node *tmp = new Node;
            tmp->p = cur->p;
            tmp->n = cur->n;

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

//asignment operator
void Team::operator=(const Team &toAssign )
{

            TeamName = toAssign.TeamName;
            TeamColor = toAssign.TeamColor;

            //delete the current roster of the team
            while(head != NULL)
            {

                Node *del = head;

                if(head->next == NULL)
                {
                    Node *newPtr = head->next;
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
                    del->next = del->next->next;
                    delete newPtr;
                }
            }




            head = NULL;
            Node *cur = toAssign.head;

            Node *lastInserted;


            while(cur != NULL)
            {
                Node *tmp = new Node;
                tmp->p = cur->p;
                tmp->n = cur->n;

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

void Team::addPlyr(string plyrName, string plyrPosition)
{
    // convert the player name to lower case

    plyrName[0] = toupper(plyrName[0]);

    for (int i = 1; plyrName[i]; i++)
        {
            plyrName[i] = tolower(plyrName[i]);
        }



        if( findPlyr(plyrName) != 0)
        {
            cout << "The player " << plyrName << " is already exist in the team " << TeamName << endl;
        }
        else
        {
            Node *cur = head;

            if(cur == NULL)
            {
                    Node *tmp = new Node;
                    tmp->n = plyrName;
                    tmp->p = plyrPosition;
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
                tmp->n = plyrName;
                tmp->p = plyrPosition;
                cur->next = tmp;
                cur->next->next = NULL;
            }
        }
}

void Team::removePlyr(string plyrName)
{
    // convert the player name to lower case

    plyrName[0] = toupper(plyrName[0]);

    for (int i = 1; plyrName[i]; i++)
        {
            plyrName[i] = tolower(plyrName[i]);
        }


        if(findPlyr(plyrName) == 0)
        {
            cout << "There is not any player having the name " << plyrName << " in the " << TeamName << " team" << endl;
         }
         else
         {
             Node *cur = head;


             if(head->n == plyrName)
             {
                    Node *newPtr = head;
                    head = head->next;
                    delete newPtr;
             }
             else
             {
                 while(cur != NULL  )
                 {
                     if(cur->next->n == plyrName)
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
void Team::displayTeam()
{
        cout << TeamName << ", " << TeamColor << endl;

        if (head == NULL)
            cout << "--EMPTY--" << endl;
        else
        {
            for(Node *cur = head; cur != NULL; cur = cur->next)
            {
                cout << cur->n << ", " << cur->p << endl;
            }
        }
}

int Team::findPlyr(string plyrName)
{
    if(head == NULL)
    {
        return 0;
    }


    for(Node * cur = head; cur != NULL; cur = cur->next)
    {
        if(cur->n == plyrName)
            return 1;
    }

    return 0;


}
string Team::getPosition(string plyrName)
{

    Node *cur = head;

    while(cur != NULL)
    {
        if(cur->n == plyrName)
          return cur->p;
        cur = cur->next;
    }


}



void Team::setName(string name)
{
    TeamName = name;
}

void Team::setColor(string color)
{
    TeamColor = color;
}

string Team::getName()
{
    return TeamName;
}

string Team::getColor()
{
    return TeamColor;
}

