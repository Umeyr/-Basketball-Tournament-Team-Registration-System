
#include <string>
using namespace std;


class Team
{
    public:
    Team(string name,string color);
    Team();
    ~Team(); //destructor
    Team( Team &toCopy ); // copy constructor

    void operator=(const Team &toAssign ); // assignment operator

    void addPlyr(string plyrName, string plyrPosition);
    void removePlyr(string plyrName);
    void displayTeam();
    int findPlyr(string plyrName);
    string getPosition(string plyrName);

    string getName();
    string getColor();
    void setName(string name);
    void setColor(string color);

private:
    struct Node
    {
        string n,p;
        Node *next;
    };

    Node *head;

    string TeamName, TeamColor;

};
