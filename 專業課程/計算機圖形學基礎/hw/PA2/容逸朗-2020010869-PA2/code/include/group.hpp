#ifndef GROUP_H
#define GROUP_H


#include "object3d.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <iostream>
#include <vector>


// FINISH (PA2): Implement Group - copy from PA1
class Group : public Object3D {

public:

    Group() {
        size = 0;
    }

    explicit Group (int num_objects) {
        size = num_objects;
    }

    ~Group() override {
        for (int i = 0; i < size; i++) delete objects[i];
    }

    bool intersect(const Ray &r, Hit &h, float tmin) override {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (objects[i]->intersect(r, h, tmin)) flag = true;
        }
        return flag;
    }

    void addObject(int index, Object3D *obj) {
        indexs.push_back(index);
        objects.push_back(obj);
    }

    int getGroupSize() {
        return size;
    }

    void drawGL() override {
        for (auto *obj : objects) {
            obj->drawGL();
        }
    }

private:
    int size;
    std::vector<Object3D*> objects;
    std::vector<int> indexs;
};

#endif
	
