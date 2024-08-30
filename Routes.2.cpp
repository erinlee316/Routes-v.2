// Assignment 6 (part 2), Routes v.2

// Program will use two classes (leg and route) and will create one array to 
// store 40 objects that contain the start and end city (connected), and 
// approximate distance it takes to travel that path. The other array will 
// incorporate the leg objects and calculate the total distance of each route.
// The program will then sort and output the routes by total distance from 
// longest to shortest, and will sort and display the legs from shortest to longest.

// c++ libraries
#include <iostream>
#include <vector>
#include <algorithm>    // used for sorting
using namespace std;

// c library
#include <cstring>

// class variable for leg
class Leg
{
  // private member variables
  const char* const startCity;
  const char* const endCity;
  const double distance;

  public:
  Leg(const char* const start, const char* const end, const double dist) : startCity(start), 
                                                                           endCity(end), 
                                                                           distance(dist) {}
  Leg& operator=(const Leg&);
  double getDistance() const {return distance;}
  void output(ostream&) const;

  // gives route class access to leg member variables
  friend class Route;
};

// class variable for route
class Route
{
  //private member variables
  vector<const Leg*> legs;
  const double totalDistance;

  public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route& operator=(const Route&);
  double getDistance () const {return totalDistance;}
  void output(ostream&) const;
};

// function prototypes
void id();
ostream& roundingOne(ostream&);
ostream& roundingOff(ostream&);

int main()
{
  // function call for identification information
  id();

  // declare array with 40 leg obejcts
  Leg l[] = 
  {
    Leg("Miami", "Orlando", 236.3),
    Leg("Orlando", "Atlanta", 437.8),
    Leg("Atlanta", "Augusta", 145.0),
    Leg("Augusta", "Memphis", 536.5),
    Leg("Memphis", "Philadelphia", 1015.2),
    Leg("Philadelphia", "Pittsburgh", 305.2),
    Leg("Pittsburgh", "Erie", 127.8),
    Leg("Erie", "New Haven", 474.0),
    Leg("New Haven", "Princeton", 130.9),
    Leg("Princeton", "Jersey City", 47.4),
    Leg("San Francisco", "Berkeley", 13.6),
    Leg("San Francisco", "Walnut Creek", 25.0),
    Leg("San Francisco", "San Jose", 48.8),
    Leg("San Francisco", "Concord", 31.4),
    Leg("San Francisco", "Sacramento", 87.9),
    Leg("Los Angeles", "San Diego", 120.2),
    Leg("Los Angeles", "Irvine", 39.7),
    Leg("Los Angeles", "Santa Monica", 16.2),
    Leg("Los Angeles", "Pasadena", 10.0),
    Leg("Los Angeles", "Riverside", 56.0),
    Leg("New York City", "Albany", 152.2),
    Leg("New York City", "Syracuse", 246.6),
    Leg("New York City", "Ithaca", 222.4),
    Leg("New York City", "Rochester", 332.7),
    Leg("New York City", "Buffalo", 372.8),
    Leg("Boston", "Quincy", 10.4),
    Leg("Boston", "Cambridge", 3.1),
    Leg("Boston", "Amherst", 94.4),
    Leg("Boston", "New Bedford", 59.2),
    Leg("Boston", "Worcester", 47.5),
    Leg("Austin", "Houston", 165.3),
    Leg("Austin", "Dallas", 195.2),
    Leg("Austin", "San Antonio", 79.6),
    Leg("Austin", "Texas City", 209.9),
    Leg("Austin", "Fort Worth", 189.8),
    Leg("Chicago", "Springfield", 201.9),
    Leg("Chicago", "Rockford", 88.9),
    Leg("Chicago", "Champaign", 135.4),
    Leg("Chicago", "Illinois City", 196.9),
    Leg("Chicago", "Naperville", 33.0)
  };

  // declare array with 40 route objects
  Route r[] =
  {
    Route(l[0]),
    Route(r[0], l[1]),
    Route(r[1], l[2]),
    Route(r[2], l[3]),
    Route(r[3], l[4]),
    Route(r[4], l[5]),
    Route(r[5], l[6]),
    Route(r[6], l[7]),
    Route(r[7], l[8]),
    Route(r[8], l[9]),    
    Route(r[9], l[10]),
    Route(r[10], l[11]),
    Route(r[11], l[12]),
    Route(r[12], l[13]),
    Route(r[13], l[14]),
    Route(r[14], l[15]),
    Route(r[15], l[16]),
    Route(r[16], l[17]),
    Route(r[17], l[18]),
    Route(r[18], l[19]),
    Route(r[19], l[20]),
    Route(r[20], l[21]),
    Route(r[21], l[22]),
    Route(r[22], l[23]),
    Route(r[23], l[24]),
    Route(r[24], l[25]),
    Route(r[25], l[26]),
    Route(r[26], l[27]),
    Route(r[27], l[28]),
    Route(r[28], l[29]),
    Route(r[29], l[30]),
    Route(r[30], l[31]),
    Route(r[31], l[32]),
    Route(r[32], l[33]),
    Route(r[33], l[34]),
    Route(r[34], l[35]),
    Route(r[35], l[36]),
    Route(r[36], l[37]),
    Route(r[37], l[38]),
    Route(r[38], l[39])
 };

  // declare and initialize integer with size of route object array
  const int ROUTE_SIZE = sizeof(r) / sizeof(r[0]);

  // sort all objects by total distance from longest to shortest
  // move through all objects in bag
  for (int i = 0; i < ROUTE_SIZE; i++)
  {
    // compare current object type with all other object types
    for (int j = i + 1; j < ROUTE_SIZE; j++)
    {
      // object's distance at index i is smaller than object's distance at index j
      // switch places to make object at index j smaller
      if (r[i].getDistance() < r[j].getDistance())
        swap(r[i], r[j]);
    }
  }

  // display console output
  cout << "\n*****There are total 40 routes*****" << endl;

  // display sorted routes
  for (int k = 0; k < ROUTE_SIZE; k++)
    r[k].output(cout);

  // declare and initialize integer with size of leg object array
  const int LEG_SIZE = sizeof(l) / sizeof(l[0]);

  // sort all objects by distance from shortest to longest
  // move through all objects in bag
  for (int i = 0; i < LEG_SIZE; i++)
  {
    // compare current object type with all other object types
    for (int j = i + 1; j < LEG_SIZE; j++)
    {
      // object's distance at index j is smaller than object's distance at index i
      // switch places to make object at index i smaller
        if (l[j].getDistance() < l[i].getDistance())
        swap(l[i], l[j]);
    }
  }

  // add newline to console output
  cout << endl;

  // display sorted legs
  for (int k = 0; k < LEG_SIZE; k++)
  {
    l[k].output(cout);
  }

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will round numbers to one decimal digit
ostream& roundingOne(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(1);
  return out;
}

// function will turn off rounding back to default
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

// getter function will display output to console 
void Leg::output(ostream& out) const
{
  out << "Leg: " << startCity << " to " << endCity << ", " 
      << distance << " miles." << endl;
}

// assignment operator function for leg class
// used for copying information from one leg object to another leg object
Leg& Leg::operator=(const Leg& copyThis)
{
  // declare reference variable to host object
  Leg& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host and assign copy to parameter 
  if (this != &copyThis)
  {
    const_cast<const char*&>(host.startCity) = copyThis.startCity;
    const_cast<const char*&>(host.endCity) = copyThis.endCity;
    const_cast<double&>(host.distance) = copyThis.distance;
  }

  // return reference variable
  return host;
}

// route constructor will append address of parameter as last object in bag 
Route::Route(const Leg& l) : totalDistance(l.getDistance()) 
{
  legs.push_back(&l);
}

// route constructor creates new route by adding new leg to existing route
// only works if cities in new leg match end cities of last leg 
Route::Route(const Route& r, const Leg& l) : legs(r.legs), 
                                             totalDistance(r.totalDistance + l.distance)
{
  // use try catch to catch error and exception
  try
  {
    // check if endCity of last leg in route and startCity of leg parameter are the same
    if (strcmp(legs.back()->endCity, l.startCity) != 0)

      // throw exception if they are different
      throw "Cities don't match!";

    // append address of parameter as last object in bag
    legs.push_back(&l);

    // remove const factor and update total distance of route
    const_cast<double&>(totalDistance) += l.getDistance();
  }

  // exception
  catch(const char* ex)
  {
    cout << ex << endl;
  }
}

// getter function will output routes
void Route::output(ostream& out) const
{
  // declare and initialize variable
  double total = 0;

  out << "Route: ";
  
  // move through entire leg array
  for (int i = 0; i < legs.size(); i++)
  {
    // check if current leg is last leg in route
    // if not, output start city
    if (i != legs.size() - 1)
      out << legs[i]->startCity << " to ";

    // if last leg in route, output start and end city
    else  
      out << legs[i]->startCity << " to " << legs[i]->endCity << ", ";

    // calculate and update total distance of route
    total += legs[i]->getDistance();
  }

  // output connecting routes with total distance
  out << roundingOne << total << roundingOff << " miles." << endl;
}

// assignment operator function for route class
// used for copying information from one route object to another route object
Route& Route::operator=(const Route& copyThis)
{
  // declare reference variable to host object
  Route& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host's member variables and assign to parameter's member variables
  if (this != &copyThis)
  {
    host.legs = copyThis.legs;
    const_cast<double&>(host.totalDistance) = copyThis.getDistance();
  }

  // return reference variable
  return host;
}