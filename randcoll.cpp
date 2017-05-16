/*
 * TODO Items:
 *   1. Fix std::vector definition for the object array named "objects"
 *   2. Add 2 cubes and 2 spheres to the objects array.
 *   3. Implement collides_with member methods for all object types.
 *      ie. cube <=> cube, cube <=> sphere and sphere <=> sphere
 *      The functions themselves are to be EMPTY!. no actual collision
 *      detection code is requested. Just make them return true or false
 *      randomly!
 */


#include <time.h>
#include <vector>
#include <random>
#include <iostream>
#include <typeinfo>


bool true_or_false() {
    return std::rand() % 2;
}


class Object;
class Sphere;
class Cube;

class Object {
public:
    explicit Object()
            : m_object_id(++s_num_objects) {

    }

    int get_object_id() const {
        return m_object_id;
    }

    static int get_num_objects() {
        return s_num_objects;
    }

    bool operator==(const Object &other) const {
        return m_object_id == other.get_object_id();
    }

    virtual bool collides_with(Object &obj) = 0;
  

private:
    static int s_num_objects;
    int m_object_id;
};
int Object::s_num_objects = 0;  

class Sphere: public Object {
    /* TODO 3 */
    	bool collides_with(Sphere &obj)
		{
			std::cout<<"check Sphere<=>Sphere";
			return true_or_false();
		}
		bool collides_with(Cube &obj)
		{
			std::cout<<"check Sphere<=>Cube";
			return true_or_false();
		}
    
};

class Cube: public Object {
    /* TODO 3 */
   	bool collides_with(Cube &obj)
	{
		std::cout<<"check Cube<=>Cube";
		return true_or_false();
	}
	bool collides_with(Sphere &obj)
	{
		std::cout<<"check Cube<=>Sphere";
		return true_or_false;
	}
    
};

std::vector<Object*> objects; // FIXME 1: Fix the object type here.


int main(void) {
    srand(time(NULL));

    /* TODO 2: add two spheres and two cubes to the objects array */
    Cube* cube1;
    Cube* cube2;
    Sphere* sphere1;
    Sphere* sphere2;
    objects.push_back(cube1);
    objects.push_back(cube2);
    objects.push_back(sphere1);
    objects.push_back(sphere2);

    for(int i = 0; i < objects.size(); ++i) {
        auto &obj1 = objects.at(i);
        for(int j = i; j < objects.size(); ++j) {
            auto &obj2 = objects.at(j);
            if (obj1 == obj2) {
                continue;
            }

            if (obj1.collides_with(obj2)) {
               
                std::cout
                    << "object id " << obj1.get_object_id()
                    << " of type " << typeid(obj1).name()
                    << " collides with "<<obj1.collides_with(obj2)
                    << "object id " << obj2.get_object_id()
                    << " of type " << typeid(obj2).name();
            }
            else {
                
                std::cout
                    << "object id " << obj1.get_object_id()
                    << " of type " << typeid(obj1).name()
                    << " does NOT collide with "<<obj1.collides_with(obj2)
                    << "object id " << obj2.get_object_id()
                    << " of type " << typeid(obj2).name();
            }
        }
    }

    return 0;
}
