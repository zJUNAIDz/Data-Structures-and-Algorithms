#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Hero
{
  // properties
private:
  int health;

public:
  char level;
  char *name;
  /*
   *static data maember (no need to create object to access this)
   *then initializing outside the class(and not inside the main(){})
   */

  static int timeToComplete;
  Hero()
  {
    cout << "default constructor called" << endl;
  }
  Hero(string name, int health, int level)
  {
    this->name = new char[100];
    this->health = health;
    this->level = level;
  }
  void print()
  {
    cout << name;
  }
  ~Hero()
  {
    cout << "destructor bhai called" << endl;
  }
};
// initialzing static datamember
int Hero::timeToComplete = 7;
int main()
{
  // Static
  Hero ShontyBhaiya("shonty bhaiya", 1000, 'A');
  /// Dynamic allocation
  Hero *Chhotey = new Hero();
  // deallocation
  delete Chhotey;
  /*
   *will work without obj accessing(we're accessing it directly through class name)
   *we are accessing the property of a "Class" and not an "Object".
   */

  cout << Hero::timeToComplete;
  // can be called this way too but not recommended
  //  cout << Chhotey->timeToComplete;
  //  won't work
  //   cout<< Hero::level;

  /*
   !static members can be updated by any object too but will refect same value to every object
   Chhotey.timeToComplete = 10;
   */

  return 0;
}